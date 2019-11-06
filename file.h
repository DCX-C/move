#include <stdio.h>
#include "list.h"
#include <stdlib.h>


//储存链表数据至文件
void savel(node head)               //变换
{
	FILE *fp = fopen("data.txt","w");
	fclose(fp);
	fp = fopen("data.txt","a");
	node curren = head;
	if(curren!=NULL)
	while(curren!=NULL)
	{
	fputs(stringMovel(curren->id),fp);
	putc('{',fp);
	putc('\n',fp);

	fputs(stringMovel(curren->name),fp);
	putc(';',fp);
	putc('\n',fp);

	fputs(stringMovel(curren->phone),fp);
	putc(';',fp);
	putc('\n',fp);

	fputs(stringMovel(curren->apartment),fp);
	putc(';',fp);
	putc('\n',fp);

	fprintf(fp,"%d",curren->position);
	putc(';',fp);
	putc('\n',fp);

	fputs(stringMovel(curren->code),fp);
	putc('}',fp);
	putc('\n',fp);


	stringMover(curren->id);
	stringMover(curren->name);
	stringMover(curren->phone);
	stringMover(curren->apartment);
	stringMover(curren->code);
	curren=curren->next;
	}
	fclose(fp);
}
void saver(node head)               //复原
{
	FILE *fp = fopen("temp.txt","w");
	fclose(fp);
	fp = fopen("temp.txt","a");
	node curren = head;
	if(curren!=NULL)
	while(curren!=NULL)
	{
	fputs(stringMover(curren->id),fp);
	putc('{',fp);
	putc('\n',fp);

	fputs(stringMover(curren->name),fp);
	putc(';',fp);
	putc('\n',fp);

	fputs(stringMover(curren->phone),fp);
	putc(';',fp);
	putc('\n',fp);

	fputs(stringMover(curren->apartment),fp);
	putc(';',fp);
	putc('\n',fp);

	fprintf(fp,"%d",curren->position);
	putc(';',fp);
	putc('\n',fp);

	fputs(stringMover(curren->code),fp);
	putc('}',fp);
	putc('\n',fp);


	stringMovel(curren->id);
	stringMovel(curren->name);
	stringMovel(curren->phone);
	stringMovel(curren->apartment);
	stringMovel(curren->code);

	curren=curren->next;
	}
	fclose(fp);


}


//程序初始化，读取一个块
void blockRead(int mode,FILE *fp,struct number **list){
int position;
char name[15]={0};
char phone[15]={0};
char id[15]={0};
char apartment[15]={0};
char code[15]={0};


fgetId(id,fp);
fseek(fp,2L,SEEK_CUR);
fgetName(name,fp);
fseek(fp,2L,SEEK_CUR);
fgetPhone(phone,fp);
fseek(fp,2L,SEEK_CUR);
fgetApart(apartment,fp);
fseek(fp,2L,SEEK_CUR);
position=fgetc(fp);
position-=48;
fseek(fp,3L,SEEK_CUR);
fgetCode(code,fp);
fseek(fp,2L,SEEK_CUR);

if(mode==1)
*list = initial(position,name,phone,apartment,code,id);

if(mode==2)
addNode(*list,position,name,phone,apartment,code,id);

}

//程序初始化,全文件读取
node allRead(char a[]){

struct number *list = NULL;

 FILE *fp = fopen(a,"r");
 blockRead(1,fp,&list);

 while(getc(fp)!=EOF)
 {
	fseek(fp,-1L,SEEK_CUR);
	blockRead(2,fp,&list);
 }

 fclose(fp);

 return list;
}




