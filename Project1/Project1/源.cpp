#include<iostream>
#include<string>
using namespace std;

int fun(int n)
{
	if (n == 1)
		return 1;
	else return n * fun(n - 1);
}
int main()
{
;
	cout<<fun(20);

	return 0;
}