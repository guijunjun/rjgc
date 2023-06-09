#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
#include<fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int Number, Type, MaxNum, printType, Bracket, PerNumber;//依次为生成算式的数量、算式运算类型、最大运算范围、输出类型、是否包含括号、算式中数字的最多个数
string suanshi[100];//产生的算式的集合
int NeedFloat; //是否需要小数点
void UserChoice()
{
	printf("欢迎使用小学四则运算自动生成程序\n");
	printf("请输入需要生成算式的数量：\n");
	scanf_s("%d", &Number);
	printf("请选择需要生成算式的运算类型：1 加法,2 减法,3 乘法,4 除法,5加减混合，6乘除混合，7加减乘除混合\n");
	scanf_s("%d", &Type);
	printf("请输入算式允许的最大范围(例如10、100、1000.....)：\n");
	scanf_s("%d", &MaxNum);
	printf("是否包含括号：1 包含，2 不包含\n");
	scanf_s("%d", &Bracket);
	printf("每个算式中最多包含数字的个数：\n");
	scanf_s("%d", &PerNumber);
	printf("是否包含小数：1 是，2否\n");
	scanf_s("%d", &NeedFloat);
	printf("请选择输出方式：1 输出到屏幕,2 输出到文件\n");
	scanf_s("%d", &printType);
}
float RandDigit()//随机产生数
{
	return rand() % MaxNum + 1;//不会产生0；
}
/*随机生成两位小数的浮点数*/
float RandFloat()
{
	return (rand() % (MaxNum * 100)) / 100.00;
}
/*随机生成每个算式中包含数的个数*/
int RandPerNumber()
{
	return rand() % PerNumber + 1;
}
/*随机产生两个随机数*/
int RandTwo()
{
	return rand() % 2;
}
/*当n=1时，返回+；当n=2时，返回-；当n=3时，返回*；当n=4时，返回/；
当n=5时，返回+或-；当n=6时，返回*或/；当n=7时，返回+、-、*或/。*/
char RandOperator()
{
	int n = Type;
	if (n == 1)
	{
		return '+';
	}
	if (n == 2)
	{
		return '-';
	}
	if (n == 3)
	{
		return '*';
	}
	if (n == 4)
	{
		return '/';
	}
	if (n == 5)
	{
		if (RandTwo() == 0)
		{
			return '+';
		}
		else
		{
			return '-';
		}
	}
	if (n == 6)
	{
		if (RandTwo() == 0)
		{
			return '*';
		}
		else
		{
			return '/';
		}
	}
	if (n == 7)
	{
		int temp = rand() % 4;
		if (temp == 1)
		{
			return '+';
		}
		else if (temp == 2)
		{
			return '-';
		}
		else if (temp == 3)
		{
			return '*';
		}
		else
		{
			return '/';
		}
	}
}
/*
itoa函数的用法：
itoa(i ,num ,10 );
i ---- 需要转换成字符串的数
num ---- 转换后保存字符串的变量
10 ---- 转换数字的基数（即进制）。10就是说按10进制转换数字。还可以是2，8，16等等你喜欢的进制类型
返回值：指向num这个字符串的指针
*/
/*
_gcvt_s函数的用法：
_gcvt_s(char* _Buffer, size_t _BufferCount, double _Value, int _DigitCount);
说明：显示正负号、小数点
_Digitcount：显示的位数，如1.25，显示两位是1.3（四舍五入），显示三位是1.25
_Value:需要转换成字符串的浮点数
*/
/*将数字转换为字符串*/
string int_string(float number)
{
	float temp = fabs(number);
	char str[200];
	if (NeedFloat == 1)
	{
		_gcvt_s(str, sizeof(str), temp, 7);//将浮点数转换为字符串，并保存正负号和小数点
	}
	else
	{
		_itoa_s(temp, str, 10);//将temp强制转换为整数然后转换为字符串
	}
	string str_ = str;
	return str_;
}
/*将两个string型变量合为一个*/
string combination(string str1, string str2, char k)
{
	string equation;
	equation = str1 + k + str2;
	return equation;
}
float Returnfloat()
{
	if (NeedFloat == 1)
	{
		return RandFloat();
	}
	else
	{
		return RandDigit();
	}
}
/*产生算式算法*/
void Produce()
{
	int itemp = 0;//记录已经产生的算式的个数
	float num1, num2;//随机产生的数
	char symbol;//接受返回的运算符
	string str_num1, str_num2;//随机产生的数的字符串形象式
	while (itemp < Number)
	{
		num1 = Returnfloat();
		num2 = Returnfloat();
		symbol = RandOperator();
		str_num1 = int_string(num1);
		str_num2 = int_string(num2);
		suanshi[itemp] = combination(str_num1, str_num2, symbol);//算式中的数为两个时；
		int count = RandPerNumber();//每个算式中包含数的个数；
		/*
		当算式中的数大于2个时
		*/
		if (count > 2)
		{
			for (count; count > 2; count--)
			{
				symbol = RandOperator();
				str_num1 = suanshi[itemp];
				if (Bracket == 1)//用户决定是否需要括号
				{
					if (RandTwo() == 0)//随机产生括号
					{
						str_num1 = '(' + str_num1 + ')';
					}
				}
				num2 = Returnfloat();
				str_num2 = int_string(num2);
				if (RandTwo() == 0)//随机将新产生的数放置于括号的前面
				{
					suanshi[itemp] = combination(str_num2, str_num1, symbol);
				}
				else
				{
					suanshi[itemp] = combination(str_num1, str_num2, symbol);
				}
			}
		}
		itemp++;
	}
}
/*将生成的算式打印*/
void Display()
{
	int i;
	if (printType == 1)
	{
		cout << "生成算式如下" << endl;
		for (i = 0; i < Number; i++)
		{
			cout << suanshi[i] << "=" << endl;
		}
	}
	else
	{
		ofstream fp;
		fp.open("生成算式.txt");
		fp << "生成算式如下：" << endl;
		for (i = 0; i < Number; i++)
		{
			fp << suanshi[i] << "=" << endl;
		}
		fp.close();
	}
}
int main()
{
	srand((int)time(NULL));  //设置时间种子 ，使得程序每次运行的结果都不同 
	UserChoice();
	Produce();
	Display();
	system("pause");
	return 0;
}