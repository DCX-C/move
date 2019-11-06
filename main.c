
#include "file.h"
#include <stdlib.h>






int main ()
{
//读取数据初始化
node list = allRead("data.txt");
saver(list);
list = allRead("temp.txt");
fopen("temp.txt","w");

char loadId[15] = {0};
char loadCode[15] = {0};

//界面
puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
puts("■■■■■■■■■■■■■■这里是智能硬件与互联网协会登录系统■■■■■■■■■■■■■■■");
printf("■■■■■■■■■■■■■■■■■当前共有%d名成员■■■■■■■■■■■■■■■■■■■■■\n",check(list));
printf("您必须输入您的学号和密码方可登录系统\n");

puts("现在请您输入您的学号");
gets(loadId);
puts("现在请您输入您的密码");
codeGet(loadCode,check(list),loadId);

node curId = match(list,loadId);
if(curId)
	;
else
puts("不存在该用户");
if(!searchId(loadCode,curId->code))
printf("密码出错");
else                            //成员操作
{
	if(curId->position==0)                 //部员操作
	{
	while(1)
	{
	puts(" ");
	puts("1.修改个人信息");
        puts("2.查看个人信息");
	puts("3.查看他人信息");
	puts("4.查看所有成员");
	puts("5.结束");
	int i;
        scanf("%d",&i);
        if(i==1)
	lowCorretNode(list,curId->id);

	else if(i==2)
	inform(loadId,list);


	else if (i==3)
	{
	puts("输入待查看人的学号");
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
	puts("操作有误");

	}
	savel(list);
        }                                     //部员操作结束

        else                                  //部长操作
	{
	while(1)
	{
	puts(" ");
	puts("1.增加一个成员");
	puts("2.快速添加成员");
	puts("3.删除一个成员");
	puts("4.修改成员信息");
	puts("5.查询成员信息");
        puts("6.查看所有成员");

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
	printf("输入有误\n");


	}
	savel(list);
	saver(list);
	fopen("temp.txt","w");
	}
	}                              //部长操作结束


}





return 0;
}
