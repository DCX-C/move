#include <stdio.h>
#include "list"



void savel(node head)
{
	FILE *fp = fopen("text.txt","w");
	fclose(fp);
	fp = fopen("text.txt","a");
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
void saver(node head)
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
	FILE *fp = fopen("temp.txt","w");
	fclose(fp);

}
