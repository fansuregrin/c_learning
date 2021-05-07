#include <stdio.h>
#include<stdlib.h> 
#define SHORT 17
#define LONG 21
#define TOTAL 150 
//声明短料、长料长度、原料长度作为常量

int main()
{
	void SplitA(int, int);
	void SplitB(int, int);
	//依据短、长料个数，声明两种切割方案  
	FILE *fp=fopen("text.txt","w");//以只写文件形式创建文件text.txt 
	fclose(fp);//关闭文件 
	int m, n;
	printf("请输入所需要的短料、长料个数：");
	scanf("%d %d",&m,&n);
	if(m*3.0/5<=n*1.0)//区分SplitA和SplitB的条件 
		SplitA(m, n);
	else
		SplitB(m, n);
	//fclose(fp);
	return 0;
} 

void SplitA(int m, int n) 
{
	FILE *fp=fopen("text.txt","a");
	//打开已有只写文件text.txt，后续数据将被写入该文件
	int i,m1,n1,count=0,sur;
	m1=m;n1=n;
	printf("\n根数\t短料数\t长料数\t剩余长度\n");
	printf("==============================\n");
 	for(count=0;m>=5&&n>=3;)
	 //先以m：n =5：3截每一根原料，直至还需短料不足5根
 	{
		m-=5;
	 	n-=3;
		count++;//记录目前已用的原料数 
		printf("第%02d根\t5\t3\t2\n", count);
		//记录以（5，3）方式截原料具体方案 
		fprintf(fp,"第%02d根\t5\t3\t2\n",count);//写入文件 
 	}		
 	switch(m)
 	//还需短料，但所需不足5根时
 	//针对短料个数以（5，3） （3，4）（2，5）（1，6）方式截完，使还需短料为0 
 	{
		case 4:{//m=4时以（5，3）截 
			count++;
			if(n<3)
			{
				printf("第%02d根\t4\t%d\t%d\n", count, n, TOTAL-SHORT*4-LONG*n);
				fprintf(fp,"第%02d根\t4\t%d\t%d\n",count, n, TOTAL-SHORT*4-LONG*n);
				m=0;
				n=0;
			}
	 		else
			{
				printf("第%02d根\t4\t3\t19\n", count);//输出仍以（4，3） 方案输出 
				fprintf(fp,"第%02d根\t4\t3\t19\n", count);
				m=0;
				n-=3;
			}
	 		break;
		}
		
	 	case 3:{//m=3时以（3，4）截 
			count++;
			if(n<4)//n＜=4时，此时短料、长料已截完，下同理 
			{
				printf("第%02d根\t3\t%d\t%d\n", count, n, TOTAL-SHORT*3-LONG*n);
				fprintf(fp,"第%02d根\t3\t%d\t%d\n",count, n, TOTAL-SHORT*3-LONG*n);
				m-=3;
				n=0;
			}
	 		else// n>4时，截完短料，还需继续截剩余长料 ，下同理 
			{
				printf("第%02d根\t3\t4\t15\n", count);
				fprintf(fp,"第%02d根\t3\t4\t15\n", count);
				m-=3;
				n-=4;
			}
	 		break;
	 	}
 		case 2:{//m=2时以（2，5）截 
			count++;//不论m取何值，每种选择仅进行1次，原料总根数增加1 
			if(n<5)
			{
				printf("第%02d根\t2\t%d\t%d\n", count, n, TOTAL-SHORT*2-LONG*n);
				fprintf(fp,"第%02d根\t2\t%d\t%d\n", count, n, TOTAL-SHORT*2-LONG*n);
				m-=2;
				n=0;
			}
	 		else
			{
				printf("第%02d根\t2\t5\t11\n", count);
				fprintf(fp,"第%02d根\t2\t5\t11\n", count);
				m-=2;
				n-=5;
			}
	 		break;
	 	}
	 	case 1:{//m=1时以（1，6）截 
			count++;
			if(n<6)
			{
				printf("第%02d根\t1\t%d\t%d\n", count, n, TOTAL-SHORT*1-LONG*n);
				fprintf(fp,"第%02d根\t1\t%d\t%d\n", count, n, TOTAL-SHORT*1-LONG*n);
				m-=1;
				n=0;
			}
	 		else
			{
				printf("第%02d根\t1\t6\t7\n", count);
				fprintf(fp,"第%02d根\t1\t6\t7\n", count);
				m-=1;
				n-=6;
			}
	 		break;
	 	}
	}
	for(i=0;n>0;i++)//还需短料已为0，还需长料全以（0，7）取完 
	{
		count++;//记录所需原料总数 
		if(n<7)//判别一根原料能否截完还需长料数 
		{
			printf("第%02d根\t0\t%d\t%d\n", count, n, TOTAL-LONG*n);
			fprintf(fp,"第%02d根\t0\t%d\t%d\n", count, n, TOTAL-LONG*n);
			n=0;
		}
		else
		{
			printf("第%02d根\t0\t7\t3\n", count);
			fprintf(fp,"第%02d根\t0\t7\t3\n", count);
			n-=7;
		}		
	}
	printf("==============================\n");
	fprintf(fp,"==============================\n");
 	sur=count*TOTAL-m1*SHORT-n1*LONG;//记录截完后剩余原料量之和 
 	printf("共需材料%d根\n",count);
 	printf("余料量为%d\n",sur);
 	fprintf(fp,"共需材料%d根\n余料量为%d\n",count,sur);
 	fclose(fp);
}

void SplitB(int m, int n)
{
	FILE *fp=fopen("text.txt","a");
	int i,m1,n1,count=0,sur;
	
	m1=m;n1=n;
	printf("\n根数\t短料数\t长料数\t剩余长度\n");
	printf("==============================\n");
	fprintf(fp,"\n根数\t短料数\t长料数\t剩余长度\n==============================\n");
 	for(count=0;m>=5&&n>=3;)
 	 //先以m：n =5：3截每一根原料，直至还需长料不足3根
 	{
	 	count++;
		printf("第%02d根\t5\t3\t2\n", count);
		fprintf(fp,"第%02d根\t5\t3\t2\n", count);
		m-=5;
	 	n-=3;
 	}			
 	switch(n)
	//还需长料，但所需不足3根时
 	//针对短料个数以（6，2） （7，1）方式截完，使还需长料为0 
 	{
 		case 2://n=2时以（6，2）截 
		{
			count++;
			if(m<6)//m＜=6时，此时短料、长料已截完，下同理 
			{
				printf("第%02d根\t%d\t2\t%d\n", count, m, TOTAL-SHORT*m-2*LONG);
				fprintf(fp,"第%02d根\t%d\t2\t%d\n", count, m, TOTAL-SHORT*m-2*LONG);
				m=0;
				n-=2;
			}
			else// m>6时，截完短料，还需继续截剩余长料 ，下同理 
			{
				printf("第%02d根\t6\t2\t6\n", count);
				fprintf(fp,"第%02d根\t6\t2\t6\n", count);
	 			m-=6;
				n-=2;
			}
	 		break;
	 	}
	 	case 1://n=1时以（7，1）截 
		{
			count++;//不论n取何值，每种选择仅进行1次，原料总根数增加1 
			if(m<7)
			{
				printf("第%02d根\t%d\t1\t%d\n", count, m, TOTAL-SHORT*m-LONG);
				fprintf(fp,"第%02d根\t%d\t1\t%d\n", count, m, TOTAL-SHORT*m-LONG);
				m=0;
				n-=1;
			}
			else
			{
				printf("第%02d根\t7\t1\t10\n", count);
				fprintf(fp,"第%02d根\t7\t1\t10\n", count);
	 			m-=7;
				n-=1;
			}
	 		break;
	 	}
	}
	for(i=0;m>0;i++)//还需长料已为0，还需短料全以（8，0）取完 
	{
		count++;
		if(m<8)//判别一根原料能否截完还需短料数 
		{
			printf("第%02d根\t%d\t0\t%d\n", count, m, TOTAL-SHORT*m);
			fprintf(fp,"第%02d根\t%d\t0\t%d\n", count, m, TOTAL-SHORT*m);
			m=0;
		}
		else
		{
			printf("第%02d根\t8\t0\t14\n", count);
			fprintf(fp,"第%02d根\t8\t0\t14\n", count);
			m-=8;
		}
	}
	printf("==============================\n");
	fprintf(fp,"==============================\n");
 	sur=count*TOTAL-m1*SHORT-n1*LONG;
 	printf("共需材料%d根\n",count);
 	printf("余料量为%d\n",sur);
 	fprintf(fp,"共需材料%d根\n余料量为%d\n",count,sur);
 	fclose(fp);
}