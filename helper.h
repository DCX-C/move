#include <stdio.h>



//搜索匹配
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
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
        puts("■■■■■■■■■■■■■■这里是智能硬件与互联网协会登录系统■■■■■■■■■■■■■■■");
        printf("■■■■■■■■■■■■■■■■■当前共有%d名成员■■■■■■■■■■■■■■■■■■■■■\n",n);
        printf("您必须输入您的学号和密码方可登录系统\n");
        puts("现在请您输入您的学号");
        printf("%s\n",id);
        puts("现在请您输入您的密码");
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



//辅助性读取字符串,功能：持续读取字符并赋值至数组直到遇到  '{'   ';'   '\n'   '}'
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

char *stringMovel(char a[])   //改造
{
	for(int i = 0;i<15;i++)
		if(a[i]!=0)
		a[i]-=1;
	return a;
}

char *stringMover(char a[])    //复原
{
	for(int i = 0;i<15;i++)
		if(a[i]!=0)
		a[i]+=1;
	return a;
}


