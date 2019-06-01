#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <assert.h>

#if 0
//通讯录,动态开辟空间
enum menu{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,//0,增删改除
	SORT,//排序
	EMPTY,//清空
	SHOW,//显示
};
#define NAME_SIZE 30
#define SEX_SIZE 5
#define ADDR_SIZE 20
#define TEL_SIZE 12
#define MAX 3 //通讯录输入人数
//学生结构体
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
//主菜单
void menu(){
	printf("**********************************\n");
	printf("******  1、增加    2、删除  ******\n");
	printf("******  3、查找    4、修改  ******\n");
	printf("******  5、排序    6、保存  ******\n");
	printf("******  7、显示    0、退出  ******\n");
	printf("**********************************\n");

}
//初始化通讯录
void lnitMailList(MailList *ml){
	assert(ml != NULL);//断言指针不为空
	ml->capacity = MAX;
	ml->size = 0;
	ml->data = (Student*)malloc(sizeof(Student)*ml->capacity);
	memset(ml->data, 0, MAX*sizeof(Student));
}
//增加空间
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
//输入联系人
void AddMailListInfo(MailList *ml){
	assert(ml != NULL);
	if (ml->size >= ml->capacity && !IncCapacity(ml)){
		printf("通讯录已经满了，不能输入\n");
		return;
	}
	printf("请输入姓名，性别，年龄，住址，电话：\n");
	scanf("%s", ml->data[ml->size].name);
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);
	scanf("%s", ml->data[ml->size].add);
	scanf("%s", &ml->data[ml->size].tel);
	++ml->size;

}
//显示联系人
void Show(MailList *ml){
	int i;
	assert(ml != NULL);
	printf("%15s %5s %5s %10s %12s\n", "姓名", "性别", "年龄", "住址", "电话");
	for (i = 0; i < ml->size; i++){
		printf("%15s %5s %3d %10s %12s\n", ml->data[i].name, ml->data[i].sex, ml->data[i].age, ml->data[i].add, ml->data[i].tel);
	}
}
//联系人按照姓名排序
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
//寻找删除者的姓名
int FindName(MailList *ml, char *name){
	int i;
	for (i = 0; i < ml->size; i++){
		if (strcmp(ml->data[i].name, name)==0){
			return i;
		}
		return -1;
	}
}
//判断通讯录是否为空
int IsEmpty(MailList *ml){
	return ml->size == 0 ? 1 : 0;
}
//删除信息
void DelMailListInfo(MailList *ml){
	char name[NAME_SIZE];
	int i, n;
	assert(ml != NULL);
	if (IsEmpty(ml)){
		printf("通讯录为空\n");
		return;
	}
	printf("请输入需要删除的信息的姓名：\n");
	scanf("%s", name);
	n = FindName(ml, name);
	if (n == -1)
		return;
	//移动通讯录元素
	for (i = n; i < ml->size; i++){
		ml->data[i] = ml->data[i + 1];
	}
	ml->size--;
}
//功能实现
void Test(){
	MailList ml;
	int input;
	lnitMailList(&ml);
	/*menu();
	printf("请输入要实现的功能：\n");*/
	do{
		menu();
		printf("请输入要实现的功能：\n");
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
			printf("退出\n");
			break;
		default:
			printf("输入数据不存在，请重新输入\n");
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
	p = (int*)malloc(4);//防止内存泄漏
	*p = 6;
	printf("%d\n", *p);
	p = (int*)realloc(p, 6 * sizeof(int));
	system("pause");
	return 0;
}
#endif

#if 0
//通讯录
enum menu{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,//0,增删改除
	SORT,//排序
	EMPTY,//清空
	SHOW,//显示
};
#define NAME_SIZE 30
#define SEX_SIZE 5
#define ADDR_SIZE 20
#define TEL_SIZE 12
#define MAX 100 //通讯录输入人数
//学生结构体
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
//主菜单
void menu(){
	printf("**********************************\n");
	printf("******  1、增加    2、删除  ******\n");
	printf("******  3、查找    4、修改  ******\n");
	printf("******  5、排序    6、保存  ******\n");
	printf("******  7、显示    0、退出  ******\n");
	printf("**********************************\n");

}
//初始化通讯录
void lnitMailList(MailList *ml){
	assert(ml != NULL);//断言指针不为空
	ml->size = 0;
	memset(ml->data, 0, MAX*sizeof(Student));
}
//输入联系人
void AddMailListInfo(MailList *ml){
	assert(ml != NULL);
	if (ml->size >= MAX){
		printf("通讯录已经满了，不能输入\n");
		return;
	}
	printf("请输入姓名，性别，年龄，住址，电话：\n");
	scanf("%s", ml->data[ml->size].name);
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);
	scanf("%s", ml->data[ml->size].add);
	scanf("%s", &ml->data[ml->size].tel);
	++ml->size;

}
//显示联系人
void Show(MailList *ml){
	int i;
	assert(ml != NULL);
	printf("%15s %5s %5s %10s %12s\n", "姓名", "性别", "年龄", "住址", "电话");
	for (i = 0; i < ml->size; i++){
		printf("%15s %5s %3d %10s %12s\n", ml->data[i].name, ml->data[i].sex, ml->data[i].age, ml->data[i].add, ml->data[i].tel);
	}
}
//联系人按照姓名排序
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
//功能实现
void Test(){
	MailList ml;
	int input;
	lnitMailList(&ml);
	/*menu();
	printf("请输入要实现的功能：\n");*/
	do{
		menu();
		printf("请输入要实现的功能：\n");
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
			printf("退出\n");
			break;
		default:
			printf("输入数据不存在，请重新输入\n");
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
//文件
int main(){
	char c;
	FILE *fpr = fopen("C:\\Users\\hm\\Desktop\\作业1.txt", "r");//r文件只读
	FILE *fpw = fopen("C:\\Users\\hm\\Desktop\\作业2.txt", "w");
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