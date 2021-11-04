~~~c++
#include <iostream>

using namespace std;


//先写一个最常规的顺序查找

void Sequential_Search(int *array, int length, int e)

{

for(int i=0;i<length;i++){

   if (e == array[i]) {

	cout << "找到元素了，在第【 " << i + 1 << " 】位" << endl;

	return;

   }

}

cout << "找不到元素！" << endl;

}

int main()

{

	int array[8] = { 2,0,0,5,2,0,3,7 };
	int e;
	cout << "请输入您要查找的元素：";
	cin >> e;
	Sequential_Search(array, 8, e);

}

//复杂度分析：
//含一个for循环，规模为n，时间复杂度为O(n), 空间复杂度为O(1)
~~~

