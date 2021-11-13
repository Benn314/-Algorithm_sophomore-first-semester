# 基于基数排序的查找



### 问题描述

------

```c++
在O(n)的时间复杂度下求得无序序列数据排序后的第K位
```



#### radixSort_Find_pos.cpp

```c++
#include <iostream>
using namespace std;

//打印输出
int printer(char array[],int n) {
	for(int i=0; i<n; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl<<"\n";
	return 0;
}


//int len = sizeof(arr)/sizeof(arr[0])

//写一个求数组最大值，求该最大值的位数
int Maxbit(char array[],int length) {
	//求最大值
	int Max=array[0];
	int bit=0;

	for(int i=0; i<length; i++) {
		if(Max<array[i]) {
			Max=array[i];
		}
	}

	while(Max>0) {
		Max /= 10;
		bit++;
	}

	return bit;
}


void radix_Sort(char array[],int length) {
	int base=1; //用来求基数进行排序
	int bit=Maxbit(array,length);
	char *tmp =new char[length];	//用new一般用tmp来接收啦~

	while(bit>0) {
		int count[10];//0号桶~~9号桶 ，每次循环都做一次清零操作，让下一位基数可以进行排序
		for(int i=0; i<10; i++) {
			count[i]=0;
		}

		//把数组元素按基数大小放入相应桶里
		for(int i=0; i<length; i++) {
			int k;	//k代表桶的下标
			k=(array[i]/base)%10;
			count[k]++;		//记录每个桶里有多少个元素
		}


		for(int i=0; i<10; i++) {
			count[i]=count[i-1]+count[i];	//当前的桶加上之前桶的总和
		}									//将tmp中的位置依次分配给每个桶

		//再把桶里的元素，按基数排序后从0号桶到9号桶输出
		for(int j=length-1; j>=0; j--) {	//将所有桶中记录依次收集到tmp中
			int k=(array[j]/base)%10;
			tmp[count[k]-1]=array[j];
			count[k]--;
		}

		//将临时数组tmp再赋值到array进行排序后的打印输出
		for(int i=0; i<length; i++) {
			array[i]=tmp[i];
		}

		bit--;	//循环最大位数次
		base *= 10;	//取个十百...位数
	}
	delete []tmp;
	//delete []count;
}


```

#### Main.cpp

```c++
int main() {
	char array[8] = {'2','0','0','5','2','0','3','7'};
	cout<<"排序前数组：";
	printer(array,8);
	cout<<"排序后数组：";
	radix_Sort(array,8);
	printer(array,8);

	cout<<endl<<endl;
	int k;
	cout<<"请输入第k位数：" ;
	cin>>k;
	cout<<"第k位数为："<<array[k-1]<<endl;

	return 0;

}

```



#### Debug_running_diagram

![image-20211112201955939](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20211112201955939.png)

