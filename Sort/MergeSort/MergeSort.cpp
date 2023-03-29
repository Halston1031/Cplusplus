//
//  MergeSort.cpp
//  MergeSort
//
//  Created by 曾億宜 on 2020/11/3.
//  Copyright © 2020 曾億宜. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int infinite = numeric_limits<int>::max(); //設定int型的極大值

void Merge(vector<int> &Array, int front, int mid, int end) //子程式排序完，合併出排序後的陣列
{
    vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1), RightSub(Array.begin()+mid+1, Array.begin()+end+1); //宣告R.L子程式向量
    LeftSub.insert(LeftSub.end(), infinite); //在左子程式最尾端插入極大值
    RightSub.insert(RightSub.end(), infinite); //在右子程式最尾端插入極大值
    int idxLeft = 0, idxRight = 0; //宣告左.右索引初始值為0
    for (int i = front; i <= end; i++) //從到尾遍歷
    {
        if (LeftSub[idxLeft] <= RightSub[idxRight]) //左索引內的數值"小於(等於)"右索引內的數值,則放入左索引內的數值
        {
            Array[i] = LeftSub[idxLeft]; //將左索引內的數值放置於Array陣列
            idxLeft++; //左索引向前遞進
        }
        else //左索引內的數值"大於"右索引內的數值,則放入右索引內的數值
        {
            Array[i] = RightSub[idxRight]; //將右索引內的數值放置於Array陣列
            idxRight++; //右索引向前遞進
        }
    }
}

void MergeSort(vector<int> &array, int front, int end)
{
    if (front < end) //位置
    {
        int mid = (front + end) / 2; //找到位在中間的位置
        MergeSort(array, front, mid); //左子程式排序
        MergeSort(array, mid+1, end); //右子程式排序
        Merge(array, front, mid, end); //子程式排序完，合併出排序後的陣列
    }
}

void PrintArray(vector<int> &array) //印出向量array內的數值
{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}

int main(void)
{
    int n; //宣告n,表示要讀取的數字個數
    cout << "n = ";
    cin >> n; //讀取數字個數
    int arr[n]; //宣告變數名稱為arr，且長度為n的陣列
    
    for(int i = 0; i < n; i++) //讀取輸入的數值
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    vector<int> array(arr, arr+sizeof(arr)/sizeof(int)); //將陣列arr的元素複製到向量array從索引0到n-1(包括)
    /*
        sizeof(arr)陣列所占的內存byte的總數，sizeof(int)每個int型數據所佔的內存
        sizeof(arr)/sizeof(int)就是array陣列的長度
    */
    cout << "original:\n";
    PrintArray(array); //印出向量array內的數值(原始)
    MergeSort(array, 0, n-1); //對array陣列進行排序
    cout << "sorted:\n";
    PrintArray(array); //印出向量array內的數值(已排序完)
    return 0;
}
