//
//  BubbleSort.cpp
//  Bubble Sort
//
//  Created by 曾億宜 on 2020/11/10.
//  Copyright © 2020 曾億宜. All rights reserved.
//
// This is Cormen version...
#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n; j > i; j--) //Goes downto i+1
        {
            if(arr[j] < arr[j-1]) //Swap
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void PrintArray(vector<int> &arr)
{
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main(void)
{
    int n = 0;
    cout << "n = ";
    cin >> n; //Input numbers of number
    int v[n]; //Declare an array of length n
    for(int &i : v) cin >> i; //Input value
    vector<int> arr(v, v+sizeof(v)/sizeof(int)); //Copy elements of array arr to vector A from index 0 to n-1 (inclusive)
    cout << "original:\n";
    PrintArray(arr); //Output original array
    BubbleSort(arr, n); //sorted
    cout << "sorted:\n";
    PrintArray(arr); //Output sorted array
    return 0;
}
