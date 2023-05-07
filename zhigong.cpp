
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;
/*

包括职工编号、姓名、性别，年龄，学历，工资、住址、电话,保险补贴
*/
typedef struct cmp
{
	int n;
	char s[8][20];
	struct cmp* next;
}node;

void show();//查看 
void create();//初始化数据 
void add(node*h);//增加员工 
void shan(node* h);//删除员工 
void gai(node* h);//修改员工数据 

int main()
{
	
	    while(1)
		{
		show();
		}
		
}
void show()
{
	int m = 0;
	FILE* fp;//创建文件指针
	
		fp = fopen("1.txt", "r");

		fgetc(fp);
		if (feof(fp))//如果文件为空
		{ system("cls");cout << "暂无数据请先初始化\n"; fclose(fp); create(); return; }
		else
		{
			rewind(fp);
			node* h = new node, * p, * q;
			while (!feof(fp))//从文件读入数据 
			{
				p = new node;
				p->next = NULL;
				fscanf(fp, "%d ", &p->n);
				for (int i = 0; i < 8; i++)
					fscanf(fp, "%s ", p->s[i]);
				p->next = NULL;
				if (!m) { h = p; q = h; m = 1; }
				else q->next = p;
				q = p;
				if (feof(fp))break;
			}
			q = h;
			while (q)//显示数据 
			{
				cout << q->n << ' ';
				for (int i = 0; i < 8; i++)
					cout << q->s[i] << " ";
				cout << endl;
				q = q->next;
			}
		
			cout << "1---增加员工\n2---删除员工\n3---修改信息\n";
			int x;
			cin >> x;
			
			if (x == 1)add(h);
			if (x == 2)shan(h);
			if (x == 3)gai(h);
		}
	
	
	fclose(fp);
	return;
}
void create()
{
	
	cout << "依次输入|职工编号|姓名|性别|年龄|学历|工资|地址|电话|保险补贴\n职工编号为0时结束输入\n";
	int n = 0;
	node* h, * q, * p;
	while (1)
	{
		p = new node;
		p->next = NULL;
		cin >> p->n;
		if (p->n == 0)break;
		for (int i = 0; i < 8; i++)
			cin >> p->s[i];
		//if (p->n == 0)break;
		if (!n) { h = p; q = h; n = 1; }
		else q->next = p;
		q = p;
	}
	FILE* fp;
	fp = fopen("1.txt", "w");
	


	while (h)
	{
		fprintf(fp, "%d ", h->n);
		for (int i = 0; i < 8; i++)
			fprintf(fp, "%s ", h->s[i]);
		h = h->next;
	}
	fclose(fp);
}
void add(node* h)
{
	node* p = new node;
	system("cls");
	cout << "依次输入|职工编号|姓名|性别|年龄|学历|工资|地址|电话|保险补贴\n";
	cin >> p->n;
	for (int i = 0; i < 8; i++)
		cin >> p->s[i];
	p->next = NULL;
	node* q = h;
	while (q->next)
		q = q->next;
	q->next = p;
	FILE* fp;
	fp = fopen("1.txt", "w");
	
	while (h)
	{
		fprintf(fp, "%d ", h->n);
		for (int i = 0; i < 8; i++)
			fprintf(fp, "%s ", h->s[i]);
		h = h->next;
	}
	fclose(fp);
}
void shan(node* h)
{
	system("cls");
	cout << "输入删除数据的序号\n";
	int k;
	cin >> k;
	node* p, * q;
	p = h;
	if (p->n == k)h = h->next;
	else
		for (p = h, q = h->next;; p = p->next, q = q->next)
			if (q->n == k)
			{
				p->next = q->next;
				break;
			}
	FILE* fp;
	fp = fopen("1.txt", "w");
	
	while (h)
	{
		fprintf(fp, "%d ", h->n);
		for (int i = 0; i < 8; i++)
			fprintf(fp, "%s ", h->s[i]);
		h = h->next;
	}
	fclose(fp);
}
void gai(node* h)
{
	system("cls");
	cout << "输入修改数据的序号\n";
	int k;
	cin >> k;
	system("cls");
	cout << "输入需要修改的数据位置（1到9）\n依次输入|职工编号|姓名|性别|年龄|学历|工资|地址|电话|保险补贴 \n";
	int w;
	cin >> w;
	system("cls");
	cout << "输入数据\n";
	int o;
	char a[20];
	if (w == 1)cin >> o;
	else cin >> a;
	node* p, * q;
	p = h;
	if (p->n == k)
	{
		if (w == 1)p->n = o;
		else strcpy(p->s[w - 2], a);
	}
	else
		while (p)
		{
			if (p->n == k)
			{
				if (w == 1)p->n = o;
				else strcpy(p->s[w - 2], a);
			}
			p = p->next;
		}
	FILE* fp;
	fp = fopen("1.txt", "w");
	while (h)
	{
		fprintf(fp, "%d ", h->n);
		for (int i = 0; i < 8; i++)
			fprintf(fp, "%s ", h->s[i]);
		h = h->next;
	}
	fclose(fp);
}



