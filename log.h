#include <stdio.h>
#include <stdlib.h>
#include <time.h>




time_t t;
struct tm *lt;

char * getTime()
{
time(&t);
lt = localtime(&t);
return asctime(lt);
}


void cetfprint(int choose,char a[],int position,char id[])
{
	FILE *log = fopen("log.txt","a");
	fputs(getTime(),log);
	fputs(":",log);

	if(choose==1&&position==1)
	fprintf(log,"一位管理员把学号为%s的成员设置成部长\n",id);
	else
	fprintf(log,"一位管理员把学号为%s的成员设置成部员\n",id);

        if(choose==2)
        fprintf(log,"一位管理员把学号为%s的成员的电话号码设置为%s\n",id,a);

	if(choose==3)
	fprintf(log,"一位管理员把学号为%s的成员的部门设置为%s\n",id,a);

	if(choose==4)
	fprintf(log,"一位管理员把学号为%s的成员的密码设置为%s\n",id,a);

	if(choose==5)
	fprintf(log,"一位管理员把学号为%s的成员的姓名设置为%s\n",id,a);

	fclose(log);
}
