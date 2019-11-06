#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"
#include "log.h"


struct number      //��Ա�ṹ��
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

//����һ����Ա����,��������ͷ;
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

//�鿴��Ա����
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


//ƥ���Աѧ�ţ����س�Աָ��

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



//���ӳ�Ա
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
	fprintf(log,"һλ����Ա�����һ��ѧ��Ϊ%s�ĳ�Ա\n",id);
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


        puts("����ó�Ա��ѧ��");
        gets(id);
        puts("����ó�Ա������");
	gets(name);
	puts("����ó�Ա�Ĳ���");
        gets(apartment);
        puts("����ó�Ա������");
	gets(code);
	puts("����ó�Ա�ĵ绰");
        gets(phone);
        puts("����ó�Ա��ְλ");
	scanf("%d",&position);
        getchar();
        newAdd(list,position,name,phone,apartment,code,id);
        printf("�ɹ����\n");

}
void qBetterAdd(node list)
{

	char id[15] = {0};

        puts("����ó�Ա��ѧ��");
        gets(id);

        newAdd(list,"0","0","0","0","123456",id);
        printf("�ɹ����\n");

}


//ɾ����Ա
void deleteNode(node *head,char id[])
{
	int n=check(*head);
	node curren = *head;
	node pre = *head;
	node temptr;
        int curptr;


	for(int i=1;i<=n;i++)//������Ӧid��Ա�ڵڼ���node
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

	//�������
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
	puts("�����ɾ���ĳ�Աѧ��");
	gets(a);

        node exist = match(head,a);

        if(exist==NULL)
	printf("�޸ó�Ա");

	else{
	deleteNode(&head,a);
	FILE *log = fopen("log.txt","a");
	fputs(getTime(),log);
	fputs(":",log);
	fprintf(log,"һλ����Աɾ����һ��ѧ��Ϊ%s�ĳ�Ա\n",a);
	fclose(log);
        printf("�ɹ�ɾ��\n");
	printf("��ǰ��Ա����%d\n",check(head));
	}

}

//�޸ĳ�Ա����
void corretNode(node head,char id[])
{
node curren = match(head,id);
printf("1.�޸�ְλ\n");
printf("2.�޸ĵ绰\n");
printf("3.�޸Ĳ���\n");
printf("4.�޸�����\n");
printf("5.�޸�����\n");
int choose;
scanf("%d",&choose);

char nothing[10];
gets(nothing);

if(choose==1)
{
	puts("����1Ϊ����0Ϊ��Ա");
	int choosee;
	scanf("%d",&choosee);
	curren->position=choosee;
	cetfprint(choose,"1",choosee,id);
}
if(choose==2)
{
	puts("����绰����");
	char phone[15];
	gets(phone);
	memcpy(curren->phone,phone,15*sizeof(char));
	cetfprint(choose,phone,1,id);
}
if(choose==3)
{
	puts("���벿��");
	char apartment[15];
	gets(apartment);
	memcpy(curren->apartment,apartment,15*sizeof(char));
	cetfprint(choose,apartment,1,id);
}
if(choose==4)
{
	puts("��������");
	char code[15];
	gets(code);
	memcpy(curren->code,code,15*sizeof(char));
	cetfprint(choose,code,1,id);
}
if(choose==5)
{
	puts("��������");
	char name[15];
	gets(name);
	memcpy(curren->name,name,15*sizeof(char));
	cetfprint(choose,name,1,id);
}
puts("�ɹ��޸�!\n");


}

void lowCorretNode(node head,char id[])
{
node curren = match(head,id);
printf("1.�޸ĵ绰\n");
printf("2.�޸Ĳ���\n");
printf("3.�޸�����\n");
printf("4.�޸�����\n");
int choose;
scanf("%d",&choose);

char nothing[10];
gets(nothing);


if(choose==1)
{
	puts("����绰����");
	char phone[15];
	gets(phone);
	memcpy(curren->phone,phone,15*sizeof(char));
	cetfprint(choose,phone,1,id);
}
if(choose==2)
{
	puts("���벿��");
	char apartment[15];
	gets(apartment);
	memcpy(curren->apartment,apartment,15*sizeof(char));
	cetfprint(choose,apartment,1,id);
}
if(choose==3)
{
	puts("��������");
	char code[15];
	gets(code);
	memcpy(curren->code,code,15*sizeof(char));
	cetfprint(choose,code,1,id);
}
if(choose==4)
{
	puts("��������");
	char name[15];
	gets(name);
	memcpy(curren->name,name,15*sizeof(char));
	cetfprint(choose,name,1,id);
}
puts("�ɹ��޸�!\n");


}

void betterCorret(node head)
{
	char a[15] = {0};
	puts("������޸ĵĳ�Աѧ��");
	gets(a);

	node exist1 = match(head,a);
	if(exist1==NULL)
	printf("�޸ó�Ա\n");
	else
	corretNode(head,a);




}

//���ҳ�Ա��Ϣ
void inform(char a[],node list)
{

	node thisNode = match(list,a);
	if(thisNode)
	{
	printf("������");
	puts(thisNode->name);
	printf("���ţ�");
	puts(thisNode->apartment);
	printf("�绰��");
	puts(thisNode->phone);
	}
	else
	printf("�޸ó�Ա");

}

void oinform(node head)
{
	printf("ѧ�ţ�");
	puts(head->id);
	printf("������");
	puts(head->name);
	printf("���ţ�");
	puts(head->apartment);
	printf("�绰��");
	puts(head->phone);
}
void betterGet(node head)
{
	puts("������鿴�˵�ѧ��");
	char a[15] = {0};
	gets(a);
	node q = match(head,a);

	if(q)
	{
	printf("������%s\n",q->name);
	printf("ѧ�ţ�%s\n",q->id);
	printf("���ţ�%s\n",q->apartment);
	printf("�绰: %s\n",q->phone);
	printf("���룺%s\n",q->code);
	if(q->position==1)
	printf("ְλ: %s����",q->apartment);
	else
	printf("ְλ��%s��Ա\n",q->apartment);
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











