#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <assert.h>

#if 0
//ͨѶ¼,��̬���ٿռ�
enum menu{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,//0,��ɾ�ĳ�
	SORT,//����
	EMPTY,//���
	SHOW,//��ʾ
};
#define NAME_SIZE 30
#define SEX_SIZE 5
#define ADDR_SIZE 20
#define TEL_SIZE 12
#define MAX 3 //ͨѶ¼��������
//ѧ���ṹ��
typedef struct student{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	short int age;
	char add[ADDR_SIZE];
	char tel[TEL_SIZE];
}Student;

typedef struct MailList{
	//Student data[MAX];//Student *data;
	Student *data;
	int capacity;
	int size;
}MailList;
//���˵�
void menu(){
	printf("**********************************\n");
	printf("******  1������    2��ɾ��  ******\n");
	printf("******  3������    4���޸�  ******\n");
	printf("******  5������    6������  ******\n");
	printf("******  7����ʾ    0���˳�  ******\n");
	printf("**********************************\n");

}
//��ʼ��ͨѶ¼
void lnitMailList(MailList *ml){
	assert(ml != NULL);//����ָ�벻Ϊ��
	ml->capacity = MAX;
	ml->size = 0;
	ml->data = (Student*)malloc(sizeof(Student)*ml->capacity);
	memset(ml->data, 0, MAX*sizeof(Student));
}
//���ӿռ�
bool IncCapacity(MailList *ml){
	Student *temp = NULL;
	assert(ml != NULL);
	ml->capacity = ml->capacity + MAX;
	temp = (Student*)realloc(ml->data, sizeof(Student)*ml->capacity);
	if (temp != NULL){
		ml->data = temp;
		return 1;
	}
	else
		return 0;
}
//������ϵ��
void AddMailListInfo(MailList *ml){
	assert(ml != NULL);
	if (ml->size >= ml->capacity && !IncCapacity(ml)){
		printf("ͨѶ¼�Ѿ����ˣ���������\n");
		return;
	}
	printf("�������������Ա����䣬סַ���绰��\n");
	scanf("%s", ml->data[ml->size].name);
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);
	scanf("%s", ml->data[ml->size].add);
	scanf("%s", &ml->data[ml->size].tel);
	++ml->size;

}
//��ʾ��ϵ��
void Show(MailList *ml){
	int i;
	assert(ml != NULL);
	printf("%15s %5s %5s %10s %12s\n", "����", "�Ա�", "����", "סַ", "�绰");
	for (i = 0; i < ml->size; i++){
		printf("%15s %5s %3d %10s %12s\n", ml->data[i].name, ml->data[i].sex, ml->data[i].age, ml->data[i].add, ml->data[i].tel);
	}
}
//��ϵ�˰�����������
void Sort(MailList *ml){
	int i, j;
	Student temp;
	assert(ml != NULL);
	for (i = 0; i < ml->size; i++){
		for (j = 0; j < ml->size - 1 - i; j++){
			if (strcmp(ml->data[j].name, ml->data[j + 1].name)>0){
				temp = ml->data[j];
				ml->data[j] = ml->data[j + 1];
				ml->data[j + 1] = temp;
			}
		}
	}
}
//Ѱ��ɾ���ߵ�����
int FindName(MailList *ml, char *name){
	int i;
	for (i = 0; i < ml->size; i++){
		if (strcmp(ml->data[i].name, name)==0){
			return i;
		}
		return -1;
	}
}
//�ж�ͨѶ¼�Ƿ�Ϊ��
int IsEmpty(MailList *ml){
	return ml->size == 0 ? 1 : 0;
}
//ɾ����Ϣ
void DelMailListInfo(MailList *ml){
	char name[NAME_SIZE];
	int i, n;
	assert(ml != NULL);
	if (IsEmpty(ml)){
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("��������Ҫɾ������Ϣ��������\n");
	scanf("%s", name);
	n = FindName(ml, name);
	if (n == -1)
		return;
	//�ƶ�ͨѶ¼Ԫ��
	for (i = n; i < ml->size; i++){
		ml->data[i] = ml->data[i + 1];
	}
	ml->size--;
}
//����ʵ��
void Test(){
	MailList ml;
	int input;
	lnitMailList(&ml);
	/*menu();
	printf("������Ҫʵ�ֵĹ��ܣ�\n");*/
	do{
		menu();
		printf("������Ҫʵ�ֵĹ��ܣ�\n");
		scanf("%d", &input);
		switch (input){
		case 1://ADD
			AddMailListInfo(&ml);
			break;
		case 2://DEL
			DelMailListInfo(&ml);
			break;
		case 3://MODIFY
			//ModifyMailListInfo(&ml);
			break;
		case 4://SEARCH
			//SearchMailListInfo(&ml);
			break;
		case 5://SORT
			Sort(&ml);
			break;
		case 6:
			break;
		case 7:
			Show(&ml);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�������ݲ����ڣ�����������\n");
			break;
		}
	} while (input);
}

int main(){
	Test();
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	int *p = NULL;
	p = (int*)malloc(4);//��ֹ�ڴ�й©
	*p = 6;
	printf("%d\n", *p);
	p = (int*)realloc(p, 6 * sizeof(int));
	system("pause");
	return 0;
}
#endif

#if 0
//ͨѶ¼
enum menu{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,//0,��ɾ�ĳ�
	SORT,//����
	EMPTY,//���
	SHOW,//��ʾ
};
#define NAME_SIZE 30
#define SEX_SIZE 5
#define ADDR_SIZE 20
#define TEL_SIZE 12
#define MAX 100 //ͨѶ¼��������
//ѧ���ṹ��
typedef struct student{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	short int age;
	char add[ADDR_SIZE];
	char tel[TEL_SIZE];
}Student;

typedef struct MailList{
	Student data[MAX];//Student *data;
	int capacity;
	int size;
}MailList;
//���˵�
void menu(){
	printf("**********************************\n");
	printf("******  1������    2��ɾ��  ******\n");
	printf("******  3������    4���޸�  ******\n");
	printf("******  5������    6������  ******\n");
	printf("******  7����ʾ    0���˳�  ******\n");
	printf("**********************************\n");

}
//��ʼ��ͨѶ¼
void lnitMailList(MailList *ml){
	assert(ml != NULL);//����ָ�벻Ϊ��
	ml->size = 0;
	memset(ml->data, 0, MAX*sizeof(Student));
}
//������ϵ��
void AddMailListInfo(MailList *ml){
	assert(ml != NULL);
	if (ml->size >= MAX){
		printf("ͨѶ¼�Ѿ����ˣ���������\n");
		return;
	}
	printf("�������������Ա����䣬סַ���绰��\n");
	scanf("%s", ml->data[ml->size].name);
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);
	scanf("%s", ml->data[ml->size].add);
	scanf("%s", &ml->data[ml->size].tel);
	++ml->size;

}
//��ʾ��ϵ��
void Show(MailList *ml){
	int i;
	assert(ml != NULL);
	printf("%15s %5s %5s %10s %12s\n", "����", "�Ա�", "����", "סַ", "�绰");
	for (i = 0; i < ml->size; i++){
		printf("%15s %5s %3d %10s %12s\n", ml->data[i].name, ml->data[i].sex, ml->data[i].age, ml->data[i].add, ml->data[i].tel);
	}
}
//��ϵ�˰�����������
void Sort(MailList *ml){
	int i, j;
	Student temp;
	assert(ml != NULL);
	for (i = 0; i < ml->size; i++){
		for (j = 0; j < ml->size - 1 - i; j++){
			if (strcmp(ml->data[j].name, ml->data[j + 1].name)>0){
				temp = ml->data[j];
				ml->data[j] = ml->data[j + 1];
				ml->data[j + 1] = temp;
			}
		}
	}
}
//����ʵ��
void Test(){
	MailList ml;
	int input;
	lnitMailList(&ml);
	/*menu();
	printf("������Ҫʵ�ֵĹ��ܣ�\n");*/
	do{
		menu();
		printf("������Ҫʵ�ֵĹ��ܣ�\n");
		scanf("%d", &input);
		switch (input){
		case 1://ADD
			AddMailListInfo(&ml);
			break;
		case 2://DEL
			//DelMailListInfo(&ml);
			break;
		case 3://MODIFY
			//ModifyMailListInfo(&ml);
			break;
		case 4://SEARCH
			//SearchMailListInfo(&ml);
			break;
		case 5://SORT
			Sort(&ml);
			break;
		case 6:
			break;
		case 7:
			Show(&ml);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�������ݲ����ڣ�����������\n");
			break;
		}
	} while (input);
}

int main(){
	Test();
	system("pause");
	return 0;
}
#endif

#if 1
//�ļ�
int main(){
	char c;
	FILE *fpr = fopen("C:\\Users\\hm\\Desktop\\��ҵ1.txt", "r");//r�ļ�ֻ��
	FILE *fpw = fopen("C:\\Users\\hm\\Desktop\\��ҵ2.txt", "w");
	while ((c = fgetc(fpr)) != EOF){
		fputc(c, fpw);
	}
	fclose(fpr);
	fclose(fpw);
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	system("pause");
	return 0;
}
#endif