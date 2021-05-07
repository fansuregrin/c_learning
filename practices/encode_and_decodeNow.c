#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EXIT 1

/* 存储用户选择的功能 */
int Option;  
/* 记录用户是否决定继续操作 */
int Cotinue; 
/* 检测用户当前的输入是否有效 */ 
int Invalid=0;
/* 声明clear函数，作用是清除输入缓冲区内所有元素 */
void clear(void);

int main(void)
{   
    /*声明encode函数 用户进入编码功能*/ 
    void encode(void);
    /*声明decode函数 用户进入译码功能*/ 
    void decode(void);
    /*声明welcome函数 开启使用界面 */ 
    void welcome(void);
    /*声明bye函数 宣告运行结束*/ 
    void bye(void);
    /*声明setContinue函数 用户一次启动后可多次执行程序*/ 
    void setContinue(int *);
    
    while (1)//无条件进入循环 ，保证用户可重复多次编码或译码 
    {
        welcome();
        scanf("%c", &Option);
        clear();//容错处理，当用户输入“0/1/2+无意义字符”时 (1aaaa) ，程序也可正常运行 

        switch (Option)
        {
        case '1':
            /* 输入1进入编码功能 */
            do
            {   
                encode();
                setContinue(&Cotinue);
            } while (Cotinue);
            break;
        case '2':
            /* 输入2进入译码功能 */
            do
            {
                decode();
                setContinue(&Cotinue);
            } while (Cotinue);
            break;   
        case '0':
        	/*输入0退出程序使用*/ 
            bye();
            return (EXIT);  
        default:
        	/*输入其它输出无意义提示*/ 
            Invalid = 1;           
            break;
        }
    }
    return 0;
}

void encode(void)//说明encode函数编码规则 
{   
    unsigned char ch; //用户输入字符
    int j=0;
	 
    system("cls");//清屏 
    printf("请输入要编码的句子： ");
    while ( (ch = getchar()) && (ch != '\n') )//输入缓冲区内一次获取一个字节且不是换行符时进入循环 
    {
        int bits =8;//一个字节长度8位 
    	int i;
    	unsigned char str[bits];//程序输出的二进制形式的ASCII码或内码
    	while (bits > 0) 
    	/*对输出的str数组0-7位共8位数字利用二除法，十进制转二进制，进行0或1赋值*/ 
		{
	 		str[bits-1] = ch % 2;
	 		ch = ch / 2;
			bits--; 
   		}
    	for (i=0; i<8; i++)
    	/*对str数组0-7位每一位进行输出*/ 
	 	{
       		 printf("%u", str[i]); 
	 	}	
   		printf(" ");//一个字节8位输出完毕后空格分开 
   		j++;
   		/*限定一排6个字节*/ 
   		if(j==6)
	 	{
	  		printf("\n");
	  		j=0;	
		}
    }
    printf("\n==============================================================\n");    
}

void decode(void)//说明decode函数译码规则 
{
    int fake_byte;//用户输入的二进制形式ASCII码或内码
    int real_byte=0;//用户输入的二进制数可转化为的十进制数 
    /*拓展译码上限——改变string数组可容纳的字节数 */
    char string[10];//程序输出的译码结果 
    int bit;
    int count = 0;
    system("cls");//清屏 
    printf("请输入要译码的句子并以#结尾：");
    while (scanf("%d", &fake_byte))
   	/*针对用户输入的二进制数转化为相应十进制数*/ 
    {
        int i;
        for (i=0; i<8; i++)
        {
            bit = fake_byte%10;//取一个输入字节最后一位上的0或1 
            fake_byte = fake_byte/10;//对这个输入字节进行“右移”操作 
            real_byte += bit * pow(2, i);//累加计算这个输入字节对应的十进制数 
        }
        string[count] =real_byte;//令string数组的第count位=十进制数对应元素 
        real_byte = 0;//real_byte清零进行下一次累加 
        count++;
    }
    string[count] = '\0';// 对string数组停止读入 
    printf("%s\n", string);
    printf("\n==============================================================\n");
    clear();//清空输入缓冲区 
}

void bye(void)
/*说明bye函数显示规则*/
{   
    system("cls");     
    printf("拜 拜 咯\n");
    system("timeout 1 > log");
    printf("朋 友\n");
    system("timeout 1 > log");
    printf("本 程 序 由 <格子衫文化宇宙贩卖中心> 出 品\n");
    system("timeout 1 > log");
    printf("本 程 序 将 在 3 秒 内 退 出...\n");
    system("timeout 3 > log");
}

void welcome(void)
/*说明welcome函数显示规则*/ 
{
    system("cls");
    printf("┌==============================================================┐\n");
    printf("‖=======================◇◇◇◆◇◇◇========================‖\n");
    printf("‖                                                             ‖\n");
    printf("‖                      自动编码译码程序                       ‖\n");
    printf("‖                      Eencode & Decode                       ‖\n");
    printf("‖                             ☆                              ‖\n");
    printf("‖                           ☆★☆                            ‖\n");
    printf("‖                          ☆★★☆                           ‖\n");
    printf("‖                                                             ‖\n");
    printf("‖                        第六小组出品                         ‖\n");
    printf("‖                   格子衫文化宇宙贩卖中心                    ‖\n");
    printf("‖                                                             ‖\n");
    printf("├==============================================================┤\n");
    printf("‖                                                             ‖\n");                            
    printf("‖        \\ \\秃/ /                                             ‖\n");
    printf("‖        (   -  -)_________                                   ‖\n");
    printf("‖    ____(______/         /                                   ‖\n");
    printf("‖             \\/_________/                                    ‖\n");
    printf("‖                                                             ‖\n");
	printf("‖               请输入：                                      ‖\n");
    printf("‖                      1------------编码                      ‖\n");
    printf("‖                      2------------译码                      ‖\n");
    printf("‖                      0------------退出                      ‖\n");
    printf("└==============================================================┘\n");
    if (Invalid) //如果输入非0或1或2，即if（1）恒真 
    {
        printf("输入有误!!!\n请重新输入: "); //提示用户重新给出合法的选择 
        Invalid = 0;
    }
    else
    {
        printf("请输入你的选择(0或1或2)：");//提示用户给出选择 
    }
}

void setContinue(int * Continue)
/*说明setContinue函数选择规则*/ 
{
    printf("是否要继续？\n");
    printf("          1------是\n");
    printf("          0------否\n");
    printf("       你的选择是：");
   	while (!scanf("%d", Continue) || (*Continue != 0 && *Continue != 1) ) 
	/* 如果用户输入的不是0或1，令其重新输入 */
    {
        printf("(- -)输入有误...\n再输入一次吧：");
        clear();//容错处理，当用户输入“0/1/2+无意义字符”时 ，程序也可正常运行 
    }
    clear();//清除输入缓冲区 
}

void clear(void)
/* clear函数用于清除输入缓冲区内所有元素 */
{
    char c;
    while ( (c = getchar()) != EOF && c != '\n'){}
	//元素不是文件结束符或换行符将被持续读取，直至输入缓冲区清空 
}