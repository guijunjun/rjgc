
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;
/*

����ְ����š��������Ա����䣬ѧ�������ʡ�סַ���绰,���ղ���
*/
typedef struct cmp
{
	int n;
	char s[8][20];
	struct cmp* next;
}node;

void show();//�鿴 
void create();//��ʼ������ 
void add(node*h);//����Ա�� 
void shan(node* h);//ɾ��Ա�� 
void gai(node* h);//�޸�Ա������ 

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
	FILE* fp;//�����ļ�ָ��
	
		fp = fopen("1.txt", "r");

		fgetc(fp);
		if (feof(fp))//����ļ�Ϊ��
		{ system("cls");cout << "�����������ȳ�ʼ��\n"; fclose(fp); create(); return; }
		else
		{
			rewind(fp);
			node* h = new node, * p, * q;
			while (!feof(fp))//���ļ��������� 
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
			while (q)//��ʾ���� 
			{
				cout << q->n << ' ';
				for (int i = 0; i < 8; i++)
					cout << q->s[i] << " ";
				cout << endl;
				q = q->next;
			}
		
			cout << "1---����Ա��\n2---ɾ��Ա��\n3---�޸���Ϣ\n";
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
	
	cout << "��������|ְ�����|����|�Ա�|����|ѧ��|����|��ַ|�绰|���ղ���\nְ�����Ϊ0ʱ��������\n";
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
	cout << "��������|ְ�����|����|�Ա�|����|ѧ��|����|��ַ|�绰|���ղ���\n";
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
	cout << "����ɾ�����ݵ����\n";
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
	cout << "�����޸����ݵ����\n";
	int k;
	cin >> k;
	system("cls");
	cout << "������Ҫ�޸ĵ�����λ�ã�1��9��\n��������|ְ�����|����|�Ա�|����|ѧ��|����|��ַ|�绰|���ղ��� \n";
	int w;
	cin >> w;
	system("cls");
	cout << "��������\n";
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



