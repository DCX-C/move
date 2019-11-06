#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"
#include "log.h"


struct number      //成员结构体
{
int position;
char name[15];
char phone[15];
char id[15];
char apartment[15];
char code[15];
struct number *next;
};

typedef struct number * node;

//构建一个成员链表,返回链表头;
node initial(int position,char name[],char phone[],char apartment[],char code[],char id[]){

node a = malloc(sizeof(struct number));

a->position=position;
memcpy(a->name,name,15*sizeof(char));
memcpy(a->phone,phone,15*sizeof(char));
memcpy(a->apartment,apartment,15*sizeof(char));
memcpy(a->code,code,15*sizeof(char));
memcpy(a->id,id,15*sizeof(char));
a->next = NULL;

return a;
}

//查看成员数量
int check(node head)
{


int i=1;

while(head->next!=NULL)
{
head = head->next;
i++;
}

return i;
}


//匹配成员学号，返回成员指针

node match(struct number *head,char id[])
{

	int n=check(head);


	for(int i=0;i<n;i++)
	{
	if(searchId(id,head->id))
	break;
	else
	head = head->next;
	}

	return head;
}



//增加成员
void addNode(node head,int position,char name[],char phone[],char apartment[],char code[],char id[])
{
	int n=check(head);
	node curren=head;

	for(int i=1;i<n;i++)
	curren=curren->next;

	curren->next = initial(position,name,phone,apartment,code,id);
}

void newAdd(node head,int position,char name[],char phone[],char apartment[],char code[],char id[])
{
	int n=check(head);
	node curren=head;

	for(int i=1;i<n;i++)
	curren=curren->next;

	curren->next = initial(position,name,phone,apartment,code,id);

	FILE *log = fopen("log.txt","a");
	fputs(getTime(),log);
	fputs(":",log);
	fprintf(log,"一位管理员添加了一个学号为%s的成员\n",id);
	fclose(log);



}



void betterAdd(node list)
{
	int position;
	char name[15] = {0};
	char phone[15] = {0};
	char id[15] = {0};
	char apartment[15] = {0};
	char code[15] = {0};


        puts("输入该成员的学号");
        gets(id);
        puts("输入该成员的名字");
	gets(name);
	puts("输入该成员的部门");
        gets(apartment);
        puts("输入该成员的密码");
	gets(code);
	puts("输入该成员的电话");
        gets(phone);
        puts("输入该成员的职位");
	scanf("%d",&position);
        getchar();
        newAdd(list,position,name,phone,apartment,code,id);
        printf("成功添加\n");

}
void qBetterAdd(node list)
{

	char id[15] = {0};

        puts("输入该成员的学号");
        gets(id);

        newAdd(list,"0","0","0","0","123456",id);
        printf("成功添加\n");

}


//删除成员
void deleteNode(node *head,char id[])
{
	int n=check(*head);
	node curren = *head;
	node pre = *head;
	node temptr;
        int curptr;


	for(int i=1;i<=n;i++)//搜索对应id人员在第几个node
	{
	if(searchId(id,curren->id))
	{
	curptr = i;
	break;
	}
	else
	{
	pre = curren;
	curren = curren->next;
	}
	}

	//三种情况
	if(curptr==1)
	{
	if((*head)->next==NULL)
	free(*head);
	else
	{
        temptr = *head;
	*head = (*head)->next;
	free(temptr);
	}
	}

	else if(curptr==n)
	{
	pre->next = NULL;
	free(curren);
	}

	else
	{
	pre->next = curren->next;
	free(curren);
	}





}

void betterDelete(node head)
{
	char a[15] = {0};
	puts("输入待删除的成员学号");
	gets(a);

        node exist = match(head,a);

        if(exist==NULL)
	printf("无该成员");

	else{
	deleteNode(&head,a);
	FILE *log = fopen("log.txt","a");
	fputs(getTime(),log);
	fputs(":",log);
	fprintf(log,"一位管理员删除了一个学号为%s的成员\n",a);
	fclose(log);
        printf("成功删除\n");
	printf("当前成员数量%d\n",check(head));
	}

}

//修改成员属性
void corretNode(node head,char id[])
{
node curren = match(head,id);
printf("1.修改职位\n");
printf("2.修改电话\n");
printf("3.修改部门\n");
printf("4.修改密码\n");
printf("5.修改姓名\n");
int choose;
scanf("%d",&choose);

char nothing[10];
gets(nothing);

if(choose==1)
{
	puts("输入1为部长0为部员");
	int choosee;
	scanf("%d",&choosee);
	curren->position=choosee;
	cetfprint(choose,"1",choosee,id);
}
if(choose==2)
{
	puts("输入电话号码");
	char phone[15];
	gets(phone);
	memcpy(curren->phone,phone,15*sizeof(char));
	cetfprint(choose,phone,1,id);
}
if(choose==3)
{
	puts("输入部门");
	char apartment[15];
	gets(apartment);
	memcpy(curren->apartment,apartment,15*sizeof(char));
	cetfprint(choose,apartment,1,id);
}
if(choose==4)
{
	puts("输入密码");
	char code[15];
	gets(code);
	memcpy(curren->code,code,15*sizeof(char));
	cetfprint(choose,code,1,id);
}
if(choose==5)
{
	puts("输入姓名");
	char name[15];
	gets(name);
	memcpy(curren->name,name,15*sizeof(char));
	cetfprint(choose,name,1,id);
}
puts("成功修改!\n");


}

void lowCorretNode(node head,char id[])
{
node curren = match(head,id);
printf("1.修改电话\n");
printf("2.修改部门\n");
printf("3.修改密码\n");
printf("4.修改姓名\n");
int choose;
scanf("%d",&choose);

char nothing[10];
gets(nothing);


if(choose==1)
{
	puts("输入电话号码");
	char phone[15];
	gets(phone);
	memcpy(curren->phone,phone,15*sizeof(char));
	cetfprint(choose,phone,1,id);
}
if(choose==2)
{
	puts("输入部门");
	char apartment[15];
	gets(apartment);
	memcpy(curren->apartment,apartment,15*sizeof(char));
	cetfprint(choose,apartment,1,id);
}
if(choose==3)
{
	puts("输入密码");
	char code[15];
	gets(code);
	memcpy(curren->code,code,15*sizeof(char));
	cetfprint(choose,code,1,id);
}
if(choose==4)
{
	puts("输入姓名");
	char name[15];
	gets(name);
	memcpy(curren->name,name,15*sizeof(char));
	cetfprint(choose,name,1,id);
}
puts("成功修改!\n");


}

void betterCorret(node head)
{
	char a[15] = {0};
	puts("输入待修改的成员学号");
	gets(a);

	node exist1 = match(head,a);
	if(exist1==NULL)
	printf("无该成员\n");
	else
	corretNode(head,a);




}

//查找成员信息
void inform(char a[],node list)
{

	node thisNode = match(list,a);
	if(thisNode)
	{
	printf("姓名：");
	puts(thisNode->name);
	printf("部门：");
	puts(thisNode->apartment);
	printf("电话：");
	puts(thisNode->phone);
	}
	else
	printf("无该成员");

}

void oinform(node head)
{
	printf("学号：");
	puts(head->id);
	printf("姓名：");
	puts(head->name);
	printf("部门：");
	puts(head->apartment);
	printf("电话：");
	puts(head->phone);
}
void betterGet(node head)
{
	puts("输入待查看人的学号");
	char a[15] = {0};
	gets(a);
	node q = match(head,a);

	if(q)
	{
	printf("姓名：%s\n",q->name);
	printf("学号：%s\n",q->id);
	printf("部门：%s\n",q->apartment);
	printf("电话: %s\n",q->phone);
	printf("密码：%s\n",q->code);
	if(q->position==1)
	printf("职位: %s部长",q->apartment);
	else
	printf("职位：%s成员\n",q->apartment);
	}


}



void Alook(node head)
{

while(head!=NULL)
{

	oinform(head);
	head = head->next;
}

}











