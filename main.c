
#include "file.h"
#include <stdlib.h>






int main ()
{
//��ȡ���ݳ�ʼ��
node list = allRead("data.txt");
saver(list);
list = allRead("temp.txt");
fopen("temp.txt","w");

char loadId[15] = {0};
char loadCode[15] = {0};

//����
puts("��������������������������������������������������������������������������������������������");
puts("��������������������������������������Ӳ���뻥����Э���¼ϵͳ������������������������������");
printf("������������������������������������ǰ����%d����Ա������������������������������������������\n",check(list));
printf("��������������ѧ�ź����뷽�ɵ�¼ϵͳ\n");

puts("����������������ѧ��");
gets(loadId);
puts("��������������������");
codeGet(loadCode,check(list),loadId);

node curId = match(list,loadId);
if(curId)
	;
else
puts("�����ڸ��û�");
if(!searchId(loadCode,curId->code))
printf("�������");
else                            //��Ա����
{
	if(curId->position==0)                 //��Ա����
	{
	while(1)
	{
	puts(" ");
	puts("1.�޸ĸ�����Ϣ");
        puts("2.�鿴������Ϣ");
	puts("3.�鿴������Ϣ");
	puts("4.�鿴���г�Ա");
	puts("5.����");
	int i;
        scanf("%d",&i);
        if(i==1)
	lowCorretNode(list,curId->id);

	else if(i==2)
	inform(loadId,list);


	else if (i==3)
	{
	puts("������鿴�˵�ѧ��");
	char personId[15] = {0};
	gets(personId);
	gets(personId);
	inform(personId,list);
	}
	else if(i == 4)
	Alook(list);

	else if(i == 5)
	{
        break;
	}

	else
	puts("��������");

	}
	savel(list);
        }                                     //��Ա��������

        else                                  //��������
	{
	while(1)
	{
	puts(" ");
	puts("1.����һ����Ա");
	puts("2.������ӳ�Ա");
	puts("3.ɾ��һ����Ա");
	puts("4.�޸ĳ�Ա��Ϣ");
	puts("5.��ѯ��Ա��Ϣ");
        puts("6.�鿴���г�Ա");

	int i;
        scanf("%d",&i);
        getchar();
	switch(i)
	{
        case 1:
	betterAdd(list);
	break;

	case 2:
	qBetterAdd(list);
	break;

	case 3:
	betterDelete(list);
	break;

	case 4:
	betterCorret(list);
	break;

	case 5:
	betterGet(list);
	break;

	case 6:
	Alook(list);
        break;

	default:
	printf("��������\n");


	}
	savel(list);
	saver(list);
	fopen("temp.txt","w");
	}
	}                              //������������


}





return 0;
}
