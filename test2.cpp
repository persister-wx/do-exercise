#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//使用构造函数
/*
class Tmp
{
public :
	Tmp()
	{
		n++;
		sum += n;
	}
	static void Reset()//初始化静态成员变量
	{
		n = 0;
		sum = 0;
	}
	static int GetSum()//返回最终和
	{
		return sum;
	}
private :
	static int n;
	static int sum;
};

int Tmp::n = 0;
int Tmp::sum = 0;

int Test(int n)
{
	Tmp::Reset();
	Tmp* ptr = new Tmp[n];//调用了n次构造函数
	delete[] ptr;
	ptr = NULL;
	return Tmp::GetSum();
}
*/

//使用逻辑运算符和递归算法
//
//int Sum_Solution(int n)
//{
//	int ans = n; 
//	ans && (ans += Sum_Solution(n - 1));
//	return ans;
//}

//使用函数指针
typedef unsigned int(*fun)(unsigned int);

unsigned int Sum_Teminator(unsigned int n)
{
	return 0;
}

unsigned int Sum_Solution(unsigned int n)
{
	static fun array[2] = { Sum_Teminator, Sum_Solution };
	return n + array[!!n](n - 1);//!!n--->得到一个bool值
}

int main()
{
	int sum = Sum_Solution(10);
	return 0;
}
