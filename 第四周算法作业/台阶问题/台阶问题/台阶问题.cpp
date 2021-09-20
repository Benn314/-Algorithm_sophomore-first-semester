#include <iostream>
using namespace std;

//递归方法
int f(int n)
{
	if (n < 1)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return (f(n - 1)+f(n - 2));
}

//递推方法
//int a = 1;
//int b = 2;
//int sum = 0;
//int test(int n)
//{
//	if (n < 1)
//		return 0;
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 2;
//
//	for (int i = 3; i < n + 1; i++)
//	{
//		sum = a + b;
//		a = b;
//		b = sum;
//	};
//	return sum;
//}


int main()
{
	int n;
	cout << "请输入要走的台阶数：";
	cin >> n;
	cout << "走" << n << "个台阶总共有 " << f(n) << " 种走法" << endl;
	//cout << "走" << n << "个台阶总共有 " << test(n) << " 种走法" << endl;

	return 0;
}
