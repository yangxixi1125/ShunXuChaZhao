#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 4

struct chain
{
	char name[20];
	char city[20];
	char sex[10];
	char age[10];
	char job[10];
	struct chain *next;
};
//函数声明
struct chain *create(struct chain *Datas);   //生成链表函数
struct chain *SequelSeach(struct chain *head, char *name);     //顺序查找函数
void print_data(struct chain *point);
//数据初始化
struct chain Datas[NUM] =
{
	"Sun","weifang","male","24","student",NULL,
	"Tom","beijing","male","31","doctor",NULL,
	"marry","shanghai","female","19","techer",NULL,
	"willing","tianjing","female","21","worker",NULL,
};

void main(void)
{
	struct chain *head;
	struct chain *p;
	char name[30];
	head = create(Datas);
	printf("\n输入要查找的人名：");
	setbuf(stdin, NULL);
	scanf("%s", name);
	p = SequelSeach(head, name);
	print_data(p);
	return;
}

struct chain *create(struct chain *Datas)
{
	struct chain *head, *tail, *p;
	int i;
	head = tail = NULL;
	printf("\n生成链表\n");
	for (i = 0; i < NUM; i++)
	{
		p = (struct chain *)malloc(sizeof(struct chain));
		strcpy(p->name, Datas[i].name);
		strcpy(p->city, Datas[i].city);
		strcpy(p->sex, Datas[i].sex);
		strcpy(p->age, Datas[i].age);
		strcpy(p->job, Datas[i].job);
		p->next = NULL;
		if (head == NULL)
			head = tail = p;
		else
		{
			tail->next = p;
			tail = tail->next;
		}
		return head;
	}
}

struct chain *SequelSeach(struct chain *head, char *name)
{
	struct chain *temp;
	temp = head;
	for (temp = head; temp != NULL;)
	{
		if ((strcmp(temp->name, name)) == 0)
			break;
		else
			temp = temp->next;
	}
	if (temp == NULL)
		printf("\n没有\n");
	return temp;
}

void print_data(struct chain *point)
{
	if (point == NULL)
		return;
	printf("\n查找结果：\n");
	printf("\n姓名：\t\t%s\n",point->name);
	printf("\n城市：\t\t%s\n", point->city);
	printf("\n性别：\t\t%s\n", point->sex);
	printf("\n年龄：\t\t%s\n", point->age);
	printf("\n工作：\t\t%s\n", point->job);
	return;
}