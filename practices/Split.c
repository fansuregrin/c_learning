#include <stdio.h>
#include<stdlib.h> 
#define SHORT 17
#define LONG 21
#define TOTAL 150 
//�������ϡ����ϳ��ȡ�ԭ�ϳ�����Ϊ����

int main()
{
	void SplitA(int, int);
	void SplitB(int, int);
	//���ݶ̡����ϸ��������������и��  
	FILE *fp=fopen("text.txt","w");//��ֻд�ļ���ʽ�����ļ�text.txt 
	fclose(fp);//�ر��ļ� 
	int m, n;
	printf("����������Ҫ�Ķ��ϡ����ϸ�����");
	scanf("%d %d",&m,&n);
	if(m*3.0/5<=n*1.0)//����SplitA��SplitB������ 
		SplitA(m, n);
	else
		SplitB(m, n);
	//fclose(fp);
	return 0;
} 

void SplitA(int m, int n) 
{
	FILE *fp=fopen("text.txt","a");
	//������ֻд�ļ�text.txt���������ݽ���д����ļ�
	int i,m1,n1,count=0,sur;
	m1=m;n1=n;
	printf("\n����\t������\t������\tʣ�೤��\n");
	printf("==============================\n");
 	for(count=0;m>=5&&n>=3;)
	 //����m��n =5��3��ÿһ��ԭ�ϣ�ֱ��������ϲ���5��
 	{
		m-=5;
	 	n-=3;
		count++;//��¼Ŀǰ���õ�ԭ���� 
		printf("��%02d��\t5\t3\t2\n", count);
		//��¼�ԣ�5��3����ʽ��ԭ�Ͼ��巽�� 
		fprintf(fp,"��%02d��\t5\t3\t2\n",count);//д���ļ� 
 	}		
 	switch(m)
 	//������ϣ������費��5��ʱ
 	//��Զ��ϸ����ԣ�5��3�� ��3��4����2��5����1��6����ʽ���꣬ʹ�������Ϊ0 
 	{
		case 4:{//m=4ʱ�ԣ�5��3���� 
			count++;
			if(n<3)
			{
				printf("��%02d��\t4\t%d\t%d\n", count, n, TOTAL-SHORT*4-LONG*n);
				fprintf(fp,"��%02d��\t4\t%d\t%d\n",count, n, TOTAL-SHORT*4-LONG*n);
				m=0;
				n=0;
			}
	 		else
			{
				printf("��%02d��\t4\t3\t19\n", count);//������ԣ�4��3�� ������� 
				fprintf(fp,"��%02d��\t4\t3\t19\n", count);
				m=0;
				n-=3;
			}
	 		break;
		}
		
	 	case 3:{//m=3ʱ�ԣ�3��4���� 
			count++;
			if(n<4)//n��=4ʱ����ʱ���ϡ������ѽ��꣬��ͬ�� 
			{
				printf("��%02d��\t3\t%d\t%d\n", count, n, TOTAL-SHORT*3-LONG*n);
				fprintf(fp,"��%02d��\t3\t%d\t%d\n",count, n, TOTAL-SHORT*3-LONG*n);
				m-=3;
				n=0;
			}
	 		else// n>4ʱ��������ϣ����������ʣ�೤�� ����ͬ�� 
			{
				printf("��%02d��\t3\t4\t15\n", count);
				fprintf(fp,"��%02d��\t3\t4\t15\n", count);
				m-=3;
				n-=4;
			}
	 		break;
	 	}
 		case 2:{//m=2ʱ�ԣ�2��5���� 
			count++;//����mȡ��ֵ��ÿ��ѡ�������1�Σ�ԭ���ܸ�������1 
			if(n<5)
			{
				printf("��%02d��\t2\t%d\t%d\n", count, n, TOTAL-SHORT*2-LONG*n);
				fprintf(fp,"��%02d��\t2\t%d\t%d\n", count, n, TOTAL-SHORT*2-LONG*n);
				m-=2;
				n=0;
			}
	 		else
			{
				printf("��%02d��\t2\t5\t11\n", count);
				fprintf(fp,"��%02d��\t2\t5\t11\n", count);
				m-=2;
				n-=5;
			}
	 		break;
	 	}
	 	case 1:{//m=1ʱ�ԣ�1��6���� 
			count++;
			if(n<6)
			{
				printf("��%02d��\t1\t%d\t%d\n", count, n, TOTAL-SHORT*1-LONG*n);
				fprintf(fp,"��%02d��\t1\t%d\t%d\n", count, n, TOTAL-SHORT*1-LONG*n);
				m-=1;
				n=0;
			}
	 		else
			{
				printf("��%02d��\t1\t6\t7\n", count);
				fprintf(fp,"��%02d��\t1\t6\t7\n", count);
				m-=1;
				n-=6;
			}
	 		break;
	 	}
	}
	for(i=0;n>0;i++)//���������Ϊ0�����賤��ȫ�ԣ�0��7��ȡ�� 
	{
		count++;//��¼����ԭ������ 
		if(n<7)//�б�һ��ԭ���ܷ���껹�賤���� 
		{
			printf("��%02d��\t0\t%d\t%d\n", count, n, TOTAL-LONG*n);
			fprintf(fp,"��%02d��\t0\t%d\t%d\n", count, n, TOTAL-LONG*n);
			n=0;
		}
		else
		{
			printf("��%02d��\t0\t7\t3\n", count);
			fprintf(fp,"��%02d��\t0\t7\t3\n", count);
			n-=7;
		}		
	}
	printf("==============================\n");
	fprintf(fp,"==============================\n");
 	sur=count*TOTAL-m1*SHORT-n1*LONG;//��¼�����ʣ��ԭ����֮�� 
 	printf("�������%d��\n",count);
 	printf("������Ϊ%d\n",sur);
 	fprintf(fp,"�������%d��\n������Ϊ%d\n",count,sur);
 	fclose(fp);
}

void SplitB(int m, int n)
{
	FILE *fp=fopen("text.txt","a");
	int i,m1,n1,count=0,sur;
	
	m1=m;n1=n;
	printf("\n����\t������\t������\tʣ�೤��\n");
	printf("==============================\n");
	fprintf(fp,"\n����\t������\t������\tʣ�೤��\n==============================\n");
 	for(count=0;m>=5&&n>=3;)
 	 //����m��n =5��3��ÿһ��ԭ�ϣ�ֱ�����賤�ϲ���3��
 	{
	 	count++;
		printf("��%02d��\t5\t3\t2\n", count);
		fprintf(fp,"��%02d��\t5\t3\t2\n", count);
		m-=5;
	 	n-=3;
 	}			
 	switch(n)
	//���賤�ϣ������費��3��ʱ
 	//��Զ��ϸ����ԣ�6��2�� ��7��1����ʽ���꣬ʹ���賤��Ϊ0 
 	{
 		case 2://n=2ʱ�ԣ�6��2���� 
		{
			count++;
			if(m<6)//m��=6ʱ����ʱ���ϡ������ѽ��꣬��ͬ�� 
			{
				printf("��%02d��\t%d\t2\t%d\n", count, m, TOTAL-SHORT*m-2*LONG);
				fprintf(fp,"��%02d��\t%d\t2\t%d\n", count, m, TOTAL-SHORT*m-2*LONG);
				m=0;
				n-=2;
			}
			else// m>6ʱ��������ϣ����������ʣ�೤�� ����ͬ�� 
			{
				printf("��%02d��\t6\t2\t6\n", count);
				fprintf(fp,"��%02d��\t6\t2\t6\n", count);
	 			m-=6;
				n-=2;
			}
	 		break;
	 	}
	 	case 1://n=1ʱ�ԣ�7��1���� 
		{
			count++;//����nȡ��ֵ��ÿ��ѡ�������1�Σ�ԭ���ܸ�������1 
			if(m<7)
			{
				printf("��%02d��\t%d\t1\t%d\n", count, m, TOTAL-SHORT*m-LONG);
				fprintf(fp,"��%02d��\t%d\t1\t%d\n", count, m, TOTAL-SHORT*m-LONG);
				m=0;
				n-=1;
			}
			else
			{
				printf("��%02d��\t7\t1\t10\n", count);
				fprintf(fp,"��%02d��\t7\t1\t10\n", count);
	 			m-=7;
				n-=1;
			}
	 		break;
	 	}
	}
	for(i=0;m>0;i++)//���賤����Ϊ0���������ȫ�ԣ�8��0��ȡ�� 
	{
		count++;
		if(m<8)//�б�һ��ԭ���ܷ���껹������� 
		{
			printf("��%02d��\t%d\t0\t%d\n", count, m, TOTAL-SHORT*m);
			fprintf(fp,"��%02d��\t%d\t0\t%d\n", count, m, TOTAL-SHORT*m);
			m=0;
		}
		else
		{
			printf("��%02d��\t8\t0\t14\n", count);
			fprintf(fp,"��%02d��\t8\t0\t14\n", count);
			m-=8;
		}
	}
	printf("==============================\n");
	fprintf(fp,"==============================\n");
 	sur=count*TOTAL-m1*SHORT-n1*LONG;
 	printf("�������%d��\n",count);
 	printf("������Ϊ%d\n",sur);
 	fprintf(fp,"�������%d��\n������Ϊ%d\n",count,sur);
 	fclose(fp);
}