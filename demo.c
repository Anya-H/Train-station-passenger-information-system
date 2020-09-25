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

//�����ÿ���Ϣ������
void getInput(struct Person *person)
{
	int a;
	printf("����������:");
    scanf("%s", person->name);
    printf("������֤����:");
    scanf("%s", person->num);
	printf("�������Ա�:");
    scanf("%s", person->sex);
    printf("����������:");
    scanf("%s", person->temperature);
	printf("���ٴ���������:");
    scanf("%d",&a);
    if(a>38)
		printf("�����쳣������ͣ����վ��\n");
    else 
		printf("����������\n");
}

//�����µ��ÿ���Ϣ
void addPerson(struct Person **contacts)
{
	struct Person *person;
    struct Person *temp;

	person =(struct Person *)malloc(sizeof(struct Person));
    if (person == NULL)
	{
		printf("�ڴ��ʧ��!\n");
        exit(1);
	}

    getInput(person);
    //�� person��ͷ�巨��ӵ��ڴ����
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

//��ӡ�ÿ���Ϣ
void printPerson(struct Person *person)
{
	printf("����:%s\n", person->name);
    printf("֤����:%s\n", person->num);
	printf("�Ա�:%s\n", person->sex);
    printf("����:%s\n", person->temperature);
}

//�����ÿ���Ϣ
struct Person *findPerson(struct Person *contacts)
{
	struct Person *current;
    char input[40];

    printf("����������:");
	scanf("%s", input);

	current = contacts;
    while (current != NULL && strcmp(current->name, input))
    {
		current=current->next;
	}
	
	return current;
}

//��ʾ����¼����ÿ���Ϣ
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

//�ͷŶ��ڴ�ռ�
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

//��ʾ������Ϣ
 void train()
 {
    
        printf("\n������Ϣ\n-------------------------\n");
        printf("\n--����--��ʼվ--��תվ--�յ�վ--\n");
		printf("\n  D001    ����    վ��A   ��ɽ   \n");
        printf("\n  D002    ����    վ��B   �麣   \n");
		printf("\n  D003    ����    վ��C   ����   \n");
		printf("\n  D004    ����    վ��D   ����   \n");		
		printf("\n  D005    ����    վ��E   ��ɽ   \n");
		printf("\n  D006    ����    վ��F   ����   \n");
   		printf("\n  D007    ����    վ��A   ��ɽ   \n");
        printf("\n  D008    �Ϻ�    վ��B   �麣   \n");
		printf("\n  D009    ����    վ��C   ����   \n");
		printf("\n  D010    �㽭    վ��D   ����   \n");		
		printf("\n  D011    ����    վ��E   ��ɽ   \n");
		printf("\n  D012    ����    վ��F   ����   \n");
		printf("\n-------------------------\n");
   
 }

//������
int main(void)
{
	int code;
	struct Person *contacts=NULL;
	struct Person *person;
	
	printf("|��ӭʹ�û�վ�ÿ��ۺ���Ϣ�������|\n");
	printf("|--------1:�����µ��ÿ���Ϣ--------|\n");
	printf("|--------2:���������ÿ���Ϣ--------|\n");
	printf("|--------3:��ʾ��ǰ�ÿ���Ϣ--------|\n");
	printf("|--------4:��ʾ��ǰ������Ϣ--------|\n");
    printf("|--------5:�˳�����----------------|\n");
   
	while (1)
	{
		printf("\n������ָ�����:");
		scanf("%d", &code);
		switch (code)
		{
		    case 1: addPerson(&contacts); break;
			case 2: person=findPerson(contacts);
				if (person == NULL)
				{
					printf("�Ҳ������ÿ���Ϣ��\n");
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
	releaseContacts(&contacts);//�˳�����
	
	return 0;
}
