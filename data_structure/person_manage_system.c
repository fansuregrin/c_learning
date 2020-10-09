#include <stdio.h>
#include <stdlib.h>

/* 节点结构 */
struct Person
{
	char		name[22];			//姓名
	unsigned int index; 			//序号
	struct Person	*next;			//指针域
};
typedef struct Person * PerNode;
char c;

PerNode initList();												//初始化链表
PerNode addPerson( PerNode );									//添加指定个节点
void showAllPerson( PerNode );									//输出所有节点
PerNode delPerson( PerNode, PerNode );							//删除指定节点
void clear() {while ((c=getchar()) != EOF && c != '\n');}		//清空键盘缓冲区的功能
void searchPerson( PerNode, PerNode );							//搜索指定节点
void insertPerson( PerNode, PerNode );							//在指定节点前插入一个节点
void numbering( PerNode );										//重新编号
void editPerson( PerNode, PerNode );							//修改某个节点

int main( int argc, char *argv[] )
{
	/*处理用户输入的指令*/
	int instru = 0;												

	printf( "Welcom to Person Manager System!\n" );
	PerNode pHead	= initList();								//初始化链表并返回头节点
	PerNode pEnd	= pHead;									//初始化后只有一个头节点，也是我们的初始尾节点
	while ( 1 )
	{
		printf( "================================\n" );
		printf( "[ 1 ]------show all persons\n" );
		printf( "[ 2 ]------add some persons\n" );
		printf( "[ 3 ]------delete a person\n" );
		printf( "[ 4 ]------search a person\n" );
		printf( "[ 5 ]------insert a person\n" );
		printf( "[ 6 ]------edit a person\n" );
		printf( "[ 0 ]------exit system\n" );
		printf( "\nyour instruction: " );
		/*处理用户的输入的指令*/
		while ( scanf( "%d", &instru ) != 1 ){
			clear();
			printf( "invalid input, input your instruction again: " );
		};
		clear();

		/*清屏*/
		system("clear");
		
		/*根据指令执行不同的操作*/
		switch ( instru )
		{
		case 1:
			showAllPerson( pHead );
			break;
		case 2:
			pEnd = addPerson( pEnd );
			break;
		case 3:
			pEnd = delPerson(pHead, pEnd);
			break;
		case 4:
			searchPerson(pHead, pEnd);
			break;
		case 5:
			insertPerson(pHead, pEnd);
			break;
		case 6:
			editPerson(pHead, pEnd);
			break;
		case 0:
			printf( "*************************\n" );
			printf( "*                       *\n" );
			printf( "*          bye!         *\n" );
			printf( "*                       *\n" );
			printf( "*************************\n" );
			return(0);
		default:
			printf( "invalid instruction!\n" );
			break;
		}
	}

	return(0);
}

/* 初始化链表 */
PerNode initList()
{
	PerNode p = (PerNode) malloc( sizeof(struct Person) );
	p->index = 0;
	p->next = NULL;

	return(p);
}

/* 添加指定个节点 */
PerNode addPerson( PerNode pEnd )
{
	int	num; 									/* person number to add */
	PerNode temp = pEnd;						/* 初始为尾指针，后面添加节点后需要移动 */

	printf("-----------------Add Some Person---------------\n");
	printf( "How many person do you want to add: " );
	while (scanf( "%d", &num ) != 1){
		clear();
		printf("invalid input, try again: ");
	};
	clear();

	for ( int i = 0; i < num; i++ )				/* 添加节点（核心部分） */
	{
		PerNode p = (PerNode) malloc( sizeof(struct Person) );
		if (p == NULL){
			printf("there takes place some errors...\n");
			exit(-1);
		}
		printf( "person %d, input name: ", i + 1 );
		scanf( "%[^\n]%*c", p->name );
		p->index = temp->index + 1;
		p->next = NULL;

		temp->next	= p;
		temp		= p;
	}
	
	printf("add %d person(s) successfully!\n", num);

	return(temp);								/*按顺序添加后，返回尾节点*/
}

/* 输出所有节点 */
void showAllPerson( PerNode pHead )
{
	PerNode p	= pHead;
	int	i	= 1;
	
	printf("-----------------Show All Person---------------\n");
	printf( "\n******************************\n" );
	if ( p->next == NULL )
		printf( "------list is empty------\n" );
	while ( p->next != NULL )
	{
		p = p->next;
		printf( "No.%03d  %s\n", p->index, p->name );
		i++;
	}
	printf( "\n             total %d person(s)\n", i - 1 );
	printf( "*******************************\n" );
}

/* 删除指定节点 */
PerNode delPerson(PerNode pHead, PerNode pEnd){
	int index;
	PerNode p = pHead;
	PerNode pBef = pHead;
	
	printf("----------------------Delete Person---------------------------\n");
	printf("which one would you want to delete?\n");
	printf("input index [index>0] or [0] for quir: ");
	
	while (scanf("%d", &index) != 1){
		printf("invalid index, try again: ");
		clear();
	};
	clear();

	if (index < pHead->index || index > pEnd->index)
		printf("the index out of range...\n");
	else if (index == 0){
		printf("you quit delete person...\n");
		return pEnd;
	}
	else {
		while (p->index != index){
			pBef = p;
			p = p->next;
		}
		pBef->next = p->next;
		printf("Delete 'No.%d  %s' Person Successfully!\n", p->index, p->name);
		free(p);
		numbering(pHead);
	}

	if (pBef->next == NULL)
		return (pEnd = pBef);
	else 
		return pEnd;
	/* old code
	int i=0;
	for (; i<index; i++){
		if (p->next == NULL){
			printf("the index out of range...\n");
			return ;
		}
		pBef = p; 
		p = p->next;
		if (p->index == index){
			pBef->next = p->next;
			printf("Delete 'No.%d  %s' Person Successfully!\n", p->index, p->name);
			free(p);
		}
	}*/
} 

/* 搜索指定节点 */
void searchPerson(PerNode pHead, PerNode pEnd){
	int index;
	PerNode p = pHead;

	printf("----------------Search Person--------------------\n");
	printf("which one would you want to search?\n");
	printf("input index [index>0] or [0] for quit: ");
	
	while (scanf("%d", &index) != 1){
		printf("invalid index, try again: ");
		clear();
	};
	clear();
	
	/* 处理index */
	if (index < pHead->index || index > pEnd->index){
		printf("the index out of range...\n");
	}
	else if (index == 0){
		printf("you quit search operation...\n");
		return ;
	}
	else {
		while (p->index != index){
			p = p->next;
		}	
		printf("No.%d  %s\n", p->index, p->name);
	}	
	
	/* old code	
	int i=0;
	for (; i<index; i++){
		p = p->next;
		if (p == NULL){
			printf("the index out of range...\n");
			return ;
		}
		if (p->index == index)
			printf("No.%d  %s\n", p->index, p->name);
	}*/
}

/*void insertPerson(PerNode pHead, int index){
	PerNode p = pHead;
	while (p != NULL && p->index <= index){
		
	}
}*/

/* 在指定节点前插入一个节点*/
void insertPerson(PerNode pHead, PerNode pEnd){
	int index;
	PerNode p = pHead;
	PerNode pBef = pHead;;

	printf("------------------Insert Person----------------\n");
	printf("insert a person before an index\n");
	printf("input index [index>0] or [0] for quit: ");
	
	while (scanf("%d", &index) != 1){
		printf("invalid index, try again: ");
		clear();
	};
	clear();

	if (index < pHead->index || index > pEnd->index){
		printf("the index out of range...\n");
	}
	else if (index == 0){
		printf("you quit search operation...\n");
		return ;
	}
	else {
		while (p->index != index){
			pBef = p;
			p = p->next;
		}
		PerNode new = (PerNode)malloc(sizeof(struct Person));
		if (new == NULL){
			printf("there takes place some errors, faied to insert a person...\n");
			exit(-1);
		}
		printf( "input name: ");
		scanf( "%[^\n]%*c", new->name );
		pBef->next = new;
		new->next = p;
		numbering(pHead);
		printf("insert 'No.%03d %s' successfully!\n ", index, new->name);
	}
}

/* 重新编号 */
void numbering(PerNode pHead){
	PerNode p = pHead;
	int i=0;
	
	while (p != NULL){
		p->index = i;
		p = p->next;
		i++;
	}
}

/* 修改指定节点 */
void editPerson(PerNode pHead, PerNode pEnd){
	int index;
	PerNode p = pHead;

	printf("------------------Edit Person----------------\n");
	printf("edit a person by index\n");
	printf("input index [index>0] or [0] for quit: ");
	
	while (scanf("%d", &index) != 1){
		printf("invalid index, try again: ");
		clear();
	};
	clear();

	if (index < pHead->index || index > pEnd->index){
		printf("the index out of range...\n");
	}
	else if (index == 0){
		printf("you quit edit operation...\n");
		return ;
	}
	else {
		while (p->index != index){
			p = p->next;
		}
		char * oldName = p->name;
		printf( "input a new name for this person: ");
		scanf( "%[^\n]%*c", p->name );
		printf("edit 'No.%03d %s' to '%s' successfully!\n", p->index, oldName, p->name);
	}
}
