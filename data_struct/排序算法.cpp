#include <iostream>
#include <vector>
// #include <bits/stdc++.h>    //C++万能头文件
using namespace std;

// 冒泡排序：从小到大排
vector<int> BubbleSort(vector<int>& v)
{
    int N = v.size();
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
    return v;
}

// 快速排序：
void quickSort(vector<int>& arr, int l, int r){
    if(l >= r)
        return;
    int i = l, j = r;
    while(i < j){
        while(i < j && arr[j] >= arr[l])
            j--;    //从右向左找出第一个小于哨兵的数
        while(i < j && arr[i] <= arr[l])
            i++;    //从左向右找出第一个大于哨兵的数
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);   //交换哨兵
    quickSort(arr, l, i - 1);   //递归左子数组
    quickSort(arr, i + 1, r);   //递归右子数组
}


int main()
{
    vector<int> v = {1, 6, 32, 86, 91, 2, 5, 10, 7};
    cout << "冒泡排序前：" << endl;
    for (int num: v)
    {   
        cout << num << " ";
    }
    cout << endl;
    BubbleSort(v);
    cout << "冒泡排序后：" << endl;
    for (int num: v)
    {   
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}