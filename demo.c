#include <stdio.h>             
#include <string.h>             
#include <stdlib.h>

struct Person
{
	char name [40];
    char num [20];
	char sex[10];
    char temperature[10];
    struct Person *next;
};

void getInput(struct Person *person);
void printPerson(struct Person *person);
void addPerson(struct Person **contacts);
struct Person *findPerson(struct Person *contacts);
void displayContacts(struct Person *contacts);
void releaseContacts(struct Person **contacts);

//输入旅客信息的内容
void getInput(struct Person *person)
{
	int a;
	printf("请输入姓名:");
    scanf("%s", person->name);
    printf("请输入证件号:");
    scanf("%s", person->num);
	printf("请输入性别:");
    scanf("%s", person->sex);
    printf("请输入体温:");
    scanf("%s", person->temperature);
	printf("请再次输入体温:");
    scanf("%d",&a);
    if(a>38)
		printf("体温异常，请暂停出入站！\n");
    else 
		printf("体温正常！\n");
}

//插入新的旅客信息
void addPerson(struct Person **contacts)
{
	struct Person *person;
    struct Person *temp;

	person =(struct Person *)malloc(sizeof(struct Person));
    if (person == NULL)
	{
		printf("内存分失败!\n");
        exit(1);
	}

    getInput(person);
    //将 person用头插法添加到内存池中
    if (*contacts !=NULL)
	{
		temp=*contacts;
        *contacts=person;
        person->next=temp;
	}
	else
	{
		*contacts=person;
        person->next=NULL;
	}
}

//打印旅客信息
void printPerson(struct Person *person)
{
	printf("姓名:%s\n", person->name);
    printf("证件号:%s\n", person->num);
	printf("性别:%s\n", person->sex);
    printf("体温:%s\n", person->temperature);
}

//查找旅客信息
struct Person *findPerson(struct Person *contacts)
{
	struct Person *current;
    char input[40];

    printf("请输入姓名:");
	scanf("%s", input);

	current = contacts;
    while (current != NULL && strcmp(current->name, input))
    {
		current=current->next;
	}
	
	return current;
}

//显示所有录入的旅客信息
void displayContacts(struct Person *contacts)
{
	struct Person *current;
	
	current=contacts;
	while (current !=NULL)
	{
		printPerson(current);
        current=current->next;
	}
}

//释放堆内存空间
void releaseContacts(struct Person **contacts)
{
	struct Person *temp;
    
	while (*contacts != NULL)
	{
		temp =*contacts;
		*contacts =(*contacts)->next;
		free(temp);
	}
}

//显示车次信息
 void train()
 {
    
        printf("\n车次信息\n-------------------------\n");
        printf("\n--车次--起始站--中转站--终点站--\n");
		printf("\n  D001    广州    站点A   中山   \n");
        printf("\n  D002    广州    站点B   珠海   \n");
		printf("\n  D003    广州    站点C   深圳   \n");
		printf("\n  D004    广州    站点D   厦门   \n");		
		printf("\n  D005    广州    站点E   佛山   \n");
		printf("\n  D006    广州    站点F   江门   \n");
   		printf("\n  D007    北京    站点A   中山   \n");
        printf("\n  D008    上海    站点B   珠海   \n");
		printf("\n  D009    北京    站点C   深圳   \n");
		printf("\n  D010    浙江    站点D   厦门   \n");		
		printf("\n  D011    北京    站点E   佛山   \n");
		printf("\n  D012    北京    站点F   江门   \n");
		printf("\n-------------------------\n");
   
 }

//主函数
int main(void)
{
	int code;
	struct Person *contacts=NULL;
	struct Person *person;
	
	printf("|欢迎使用火车站旅客综合信息管理程序|\n");
	printf("|--------1:插入新的旅客信息--------|\n");
	printf("|--------2:查找已有旅客信息--------|\n");
	printf("|--------3:显示当前旅客信息--------|\n");
	printf("|--------4:显示当前车次信息--------|\n");
    printf("|--------5:退出程序----------------|\n");
   
	while (1)
	{
		printf("\n请输入指令代码:");
		scanf("%d", &code);
		switch (code)
		{
		    case 1: addPerson(&contacts); break;
			case 2: person=findPerson(contacts);
				if (person == NULL)
				{
					printf("找不到该旅客信息！\n");
				}
				else
				{
					printPerson (person );
				}
				break;
			
			case 3: displayContacts(contacts); break;
			case 4: train(); break;
			case 5: goto END;
		}
	}
END:
	releaseContacts(&contacts);//退出函数
	
	return 0;
}
