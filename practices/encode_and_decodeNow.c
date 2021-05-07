#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EXIT 1

/* �洢�û�ѡ��Ĺ��� */
int Option;  
/* ��¼�û��Ƿ������������ */
int Cotinue; 
/* ����û���ǰ�������Ƿ���Ч */ 
int Invalid=0;
/* ����clear������������������뻺����������Ԫ�� */
void clear(void);

int main(void)
{   
    /*����encode���� �û�������빦��*/ 
    void encode(void);
    /*����decode���� �û��������빦��*/ 
    void decode(void);
    /*����welcome���� ����ʹ�ý��� */ 
    void welcome(void);
    /*����bye���� �������н���*/ 
    void bye(void);
    /*����setContinue���� �û�һ��������ɶ��ִ�г���*/ 
    void setContinue(int *);
    
    while (1)//����������ѭ�� ����֤�û����ظ���α�������� 
    {
        welcome();
        scanf("%c", &Option);
        clear();//�ݴ������û����롰0/1/2+�������ַ���ʱ (1aaaa) ������Ҳ���������� 

        switch (Option)
        {
        case '1':
            /* ����1������빦�� */
            do
            {   
                encode();
                setContinue(&Cotinue);
            } while (Cotinue);
            break;
        case '2':
            /* ����2�������빦�� */
            do
            {
                decode();
                setContinue(&Cotinue);
            } while (Cotinue);
            break;   
        case '0':
        	/*����0�˳�����ʹ��*/ 
            bye();
            return (EXIT);  
        default:
        	/*�������������������ʾ*/ 
            Invalid = 1;           
            break;
        }
    }
    return 0;
}

void encode(void)//˵��encode����������� 
{   
    unsigned char ch; //�û������ַ�
    int j=0;
	 
    system("cls");//���� 
    printf("������Ҫ����ľ��ӣ� ");
    while ( (ch = getchar()) && (ch != '\n') )//���뻺������һ�λ�ȡһ���ֽ��Ҳ��ǻ��з�ʱ����ѭ�� 
    {
        int bits =8;//һ���ֽڳ���8λ 
    	int i;
    	unsigned char str[bits];//��������Ķ�������ʽ��ASCII�������
    	while (bits > 0) 
    	/*�������str����0-7λ��8λ�������ö�������ʮ����ת�����ƣ�����0��1��ֵ*/ 
		{
	 		str[bits-1] = ch % 2;
	 		ch = ch / 2;
			bits--; 
   		}
    	for (i=0; i<8; i++)
    	/*��str����0-7λÿһλ�������*/ 
	 	{
       		 printf("%u", str[i]); 
	 	}	
   		printf(" ");//һ���ֽ�8λ�����Ϻ�ո�ֿ� 
   		j++;
   		/*�޶�һ��6���ֽ�*/ 
   		if(j==6)
	 	{
	  		printf("\n");
	  		j=0;	
		}
    }
    printf("\n==============================================================\n");    
}

void decode(void)//˵��decode����������� 
{
    int fake_byte;//�û�����Ķ�������ʽASCII�������
    int real_byte=0;//�û�����Ķ���������ת��Ϊ��ʮ������ 
    /*��չ�������ޡ����ı�string��������ɵ��ֽ��� */
    char string[10];//��������������� 
    int bit;
    int count = 0;
    system("cls");//���� 
    printf("������Ҫ����ľ��Ӳ���#��β��");
    while (scanf("%d", &fake_byte))
   	/*����û�����Ķ�������ת��Ϊ��Ӧʮ������*/ 
    {
        int i;
        for (i=0; i<8; i++)
        {
            bit = fake_byte%10;//ȡһ�������ֽ����һλ�ϵ�0��1 
            fake_byte = fake_byte/10;//����������ֽڽ��С����ơ����� 
            real_byte += bit * pow(2, i);//�ۼӼ�����������ֽڶ�Ӧ��ʮ������ 
        }
        string[count] =real_byte;//��string����ĵ�countλ=ʮ��������ӦԪ�� 
        real_byte = 0;//real_byte���������һ���ۼ� 
        count++;
    }
    string[count] = '\0';// ��string����ֹͣ���� 
    printf("%s\n", string);
    printf("\n==============================================================\n");
    clear();//������뻺���� 
}

void bye(void)
/*˵��bye������ʾ����*/
{   
    system("cls");     
    printf("�� �� ��\n");
    system("timeout 1 > log");
    printf("�� ��\n");
    system("timeout 1 > log");
    printf("�� �� �� �� <�������Ļ����混������> �� Ʒ\n");
    system("timeout 1 > log");
    printf("�� �� �� �� �� 3 �� �� �� ��...\n");
    system("timeout 3 > log");
}

void welcome(void)
/*˵��welcome������ʾ����*/ 
{
    system("cls");
    printf("��==============================================================��\n");
    printf("��=======================���������========================��\n");
    printf("��                                                             ��\n");
    printf("��                      �Զ������������                       ��\n");
    printf("��                      Eencode & Decode                       ��\n");
    printf("��                             ��                              ��\n");
    printf("��                           ����                            ��\n");
    printf("��                          �����                           ��\n");
    printf("��                                                             ��\n");
    printf("��                        ����С���Ʒ                         ��\n");
    printf("��                   �������Ļ����混������                    ��\n");
    printf("��                                                             ��\n");
    printf("��==============================================================��\n");
    printf("��                                                             ��\n");                            
    printf("��        \\ \\ͺ/ /                                             ��\n");
    printf("��        (   -  -)_________                                   ��\n");
    printf("��    ____(______/         /                                   ��\n");
    printf("��             \\/_________/                                    ��\n");
    printf("��                                                             ��\n");
	printf("��               �����룺                                      ��\n");
    printf("��                      1------------����                      ��\n");
    printf("��                      2------------����                      ��\n");
    printf("��                      0------------�˳�                      ��\n");
    printf("��==============================================================��\n");
    if (Invalid) //��������0��1��2����if��1������ 
    {
        printf("��������!!!\n����������: "); //��ʾ�û����¸����Ϸ���ѡ�� 
        Invalid = 0;
    }
    else
    {
        printf("���������ѡ��(0��1��2)��");//��ʾ�û�����ѡ�� 
    }
}

void setContinue(int * Continue)
/*˵��setContinue����ѡ�����*/ 
{
    printf("�Ƿ�Ҫ������\n");
    printf("          1------��\n");
    printf("          0------��\n");
    printf("       ���ѡ���ǣ�");
   	while (!scanf("%d", Continue) || (*Continue != 0 && *Continue != 1) ) 
	/* ����û�����Ĳ���0��1�������������� */
    {
        printf("(- -)��������...\n������һ�ΰɣ�");
        clear();//�ݴ������û����롰0/1/2+�������ַ���ʱ ������Ҳ���������� 
    }
    clear();//������뻺���� 
}

void clear(void)
/* clear��������������뻺����������Ԫ�� */
{
    char c;
    while ( (c = getchar()) != EOF && c != '\n'){}
	//Ԫ�ز����ļ����������з�����������ȡ��ֱ�����뻺������� 
}