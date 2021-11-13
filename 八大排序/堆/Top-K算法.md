# Top-K算法

#### Top-k.cpp

```c++
/*
题目：堆排序的用法：
	  1、利用堆排序从n个数字中取出top-k个最大的数字
	  2、主要使用最小堆，维护k个大小的最小堆
*/
/*思路：1、维护k个最小堆，如果某个新进来的数字大于最小堆的根节点，那么将根节点换为新进来的数字，然后在对最小堆进行调整。
2、在找出k个大的数字后，对k个大的数字进行一次堆排序，因为我们做的是最小堆，所以堆排序后得到的序列就是升序的序列
Ps：堆排序的平均时间复杂度都为O（n*logn），它比快排好的地方是，快排在最坏的情况下（数组已有序）时间复杂度为O(n ^ 2)*/

#include<iostream>
#include<vector>
using namespace std;

void min_heapify(vector<int> &arr, int start, int end) {
	//i这里指向的是左子树
	int i = start * 2 + 1;
	while (i <= end) {
		//先找左右子树中最小的
		if (i + 1 <= end && arr[i] > arr[i + 1]) {
			//如果左子树大于右子树，则i指向右子树
			i++;
		}
		if (arr[start] > arr[i]) {
			swap(arr[start], arr[i]);
			start = i;
			i = 2 * start + 1;
		}
		else {
			break;
		}
	}
}

void heapSort(vector<int> &arr, int start, int end) {
	//堆排序是从第一个非叶节点开始从下往上更新，直到更新到根节点为止
	for (int i = (end - 1) / 2; i >= 0; i--) {
		min_heapify(arr, i, end);
	}
	/* 下面进行堆排序，进行堆排序的时候，因为上面已经调整过一遍堆了，
	这次只是替换了堆顶元素，所以只需要对堆顶元素进行一次调整即可。*/
	for (int i = end; i - 1 >= 0; i--) {
		swap(arr[i], arr[0]);
		min_heapify(arr, 0, i - 1);
	}
}

```

#### Main.cpp

```c++
int main() {
	//堆排序维护k个大小的最小堆
	int k;
	int length;	//length为数组长度 
	cout << "请输入数组长度：";
	cin >> length;
	cout << "Top-k的值为：";
	cin >> k;
	cout << "依次输入数组，然后找出top-" << k << "个值" << endl;
	vector<int> arr(k, 0);
	for (int i = 0; i < length; i++) {
		if (i >= k) {	//i在前k个以后 
			int temp;
			cin >> temp;	//相当于只保留了小k堆，因为根节点是最小的，所以如果有比最小的值大的话，直接代替掉就好了，然后重							   新排序
			if (temp > arr[0]) {	//当然如果小k堆要求全部元素Top，就相当于下面else语句了嘛，求堆排序咯
				arr[0] = temp;		//输入的值如果不比a[0]大，直接不要，就是a[]的第k位后，不比a[0]（最小值）大的就不要，									   就相当于存放在temp的内存中不进行任何操作
                
				min_heapify(arr, 0, k - 1);	//维护前k个小堆 
			}
		}
		else {
			int temp;
			cin >> temp;
			arr[i] = temp;
			if (i == k - 1) {	//第k位 
				//这里先建堆
				for (int j = (k - 1 - 1) / 2; j >= 0; j--) {	//((k-1)-1)/2是求最后一个父节点 ,end是k-1啦~
					min_heapify(arr, j, k - 1);	//先对小k堆进行排序
				}
			}
		}
	}
	//对堆进行最小堆排序
	heapSort(arr, 0, k - 1);	//如果没有排序的话，输出就是按最小堆顺序排的，而不是从Top-1到Top-k（也就是降序）
								//此时的堆是已建好的，还没拿来从下往上砍进行排序，所以要来个heapsort
	//for (int i = 0; i < arr.size(); i++) {
	//	cout << arr[i];
	//	if (i < arr.size() - 1) {
	//		cout << " ";
	//	}
	//}
	cout << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << "Top-" << i + 1 << " = " << arr[i] << endl;
	}
	cout << endl << endl;;
	system("pause");
	return 0;
}
```



#### Debug_running_diagram



<div align=center>
<img src="https://user-images.githubusercontent.com/70643377/141604548-5d014f60-d3ea-48c6-82a5-a8391ab8970f.png" width="80%" height="80%">
</div>
