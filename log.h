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
	fprintf(log,"һλ����Ա��ѧ��Ϊ%s�ĳ�Ա���óɲ���\n",id);
	else
	fprintf(log,"һλ����Ա��ѧ��Ϊ%s�ĳ�Ա���óɲ�Ա\n",id);

        if(choose==2)
        fprintf(log,"һλ����Ա��ѧ��Ϊ%s�ĳ�Ա�ĵ绰��������Ϊ%s\n",id,a);

	if(choose==3)
	fprintf(log,"һλ����Ա��ѧ��Ϊ%s�ĳ�Ա�Ĳ�������Ϊ%s\n",id,a);

	if(choose==4)
	fprintf(log,"һλ����Ա��ѧ��Ϊ%s�ĳ�Ա����������Ϊ%s\n",id,a);

	if(choose==5)
	fprintf(log,"һλ����Ա��ѧ��Ϊ%s�ĳ�Ա����������Ϊ%s\n",id,a);

	fclose(log);
}
