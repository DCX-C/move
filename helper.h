#include <stdio.h>



//����ƥ��
int searchId(char goal[],char actual[])
{

	int bool=1;
	for(int i=0;i<15;i++)
	if(goal[i]!=actual[i])
	{
	bool=0;
	break;
	}
	return bool;
}

void codeGet(char code[],int n,char id[])
{
	char a;
	for(int i=0;i<20;i++){
        a=getch();
	if(a==8)
	{
	i--;
	code[i]=0;
	i--;
	system("cls");
	puts("��������������������������������������������������������������������������������������������");
        puts("��������������������������������������Ӳ���뻥����Э���¼ϵͳ������������������������������");
        printf("������������������������������������ǰ����%d����Ա������������������������������������������\n",n);
        printf("��������������ѧ�ź����뷽�ɵ�¼ϵͳ\n");
        puts("����������������ѧ��");
        printf("%s\n",id);
        puts("��������������������");
	for(int o=0;code[o]!=0;o++)
	printf("*");
	continue;
	}
	else if(a==13)
	break;
	else if(a>=32&&a<=126){
	code[i]=a;
	printf("*");
	}
	else
	;
        }

}



//�����Զ�ȡ�ַ���,���ܣ�������ȡ�ַ�����ֵ������ֱ������  '{'   ';'   '\n'   '}'
void fgetId(char a[],FILE *fp)
{
	char temp;
	temp=getc(fp);
	for(int i = 0;temp!='{';i++)
	{
	a[i] = temp;
	temp=getc(fp);
        }
}

void fgetPhone(char a[],FILE *fp)
{
	char temp;
	temp=getc(fp);
	for(int i = 0;temp!=';';i++)
	{
	a[i] = temp;
	temp=getc(fp);
        }
}

void fgetName(char a[],FILE *fp)
{
	char temp;
	temp=getc(fp);
	for(int i = 0;temp!=';';i++)
	{
	a[i] = temp;
	temp=getc(fp);
        }
}

void fgetApart(char a[],FILE *fp)
{
	char temp;
	temp=getc(fp);
	for(int i = 0;temp!=';';i++)
	{
	a[i] = temp;
	temp=getc(fp);
        }
}

void fgetCode(char a[],FILE *fp)
{
	char temp;
	temp=getc(fp);
	for(int i = 0;temp!='}';i++)
	{
	a[i] = temp;
	temp=getc(fp);
        }
}

char *stringMovel(char a[])   //����
{
	for(int i = 0;i<15;i++)
		if(a[i]!=0)
		a[i]-=1;
	return a;
}

char *stringMover(char a[])    //��ԭ
{
	for(int i = 0;i<15;i++)
		if(a[i]!=0)
		a[i]+=1;
	return a;
}


