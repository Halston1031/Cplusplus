//
//  MergeSort.cpp
//  MergeSort
//
//  Created by 曾億宜 on 2020/11/6.
//  Copyright © 2020 曾億宜. All rights reserved.
//

// This is Cormen version...
/*
It operates as follows:
Divide: Divide the n-element sequence to be sorted into two subsequences of n=2 elements each.
Conquer: Sort the two subsequences recursively using merge sort.
Combine: Merge the two sorted subsequences to produce the sorted answer.
*/

#include <iostream>
#include <limits>
#include <vector>
using namespace std;
int infinite = numeric_limits<int>::max(); //Set the maximum value of int

void Merge(vector<int> &A, int p, int q, int r) //After the subroutine is sorted, merge the sorted array
{
    int n1 = q - p + 1; //Number of elements of left array (Include q).
    int n2 = r - q; //Number of elements of right array.
    int L[n1+1], R[n2+1]; //Declare L.R array

    for(int i = 0; i < n1; i++) //Assignment
        L[i] = A[p+i];
    for(int j = 0; j < n2; j++) //Assignment
        R[j] = A[q+j+1];
    L[n1] = infinite; //Insert the infinite value
    R[n2] = infinite; //Insert the infinite value
    int i = 0, j = 0; //Initialize left index and right index
    for(int k = p; k <= r; k++) //Vector traversal
    {
        if(L[i] <= R[j]) //The value in the left index is "less than / equal to" the value in the right index
        {
            A[k] = L[i]; //Put the value (left index) into the A vector
            i++; //Left index advances forward
        }
        else //The value in the left index is "more than" the value in the right index
        {
            A[k] = R[j]; //Put the value (right index) into the A vector
            j++; //Right index advances forward
        }
    }
}

void MergeSort(vector<int> &A, int p, int r)
{
    int q = 0;
    if(p < r) //position
    {
        q = ((p+r) / 2); //Find the middle position
        MergeSort(A,p,q); //Left subroutine sort
        MergeSort(A,q+1,r); //Right subroutine sort
        Merge(A,p,q,r); //Merge the sorted array
    }
}

void PrintArray(vector<int> &A) //Output vector
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(void)
{
    int n;
    cout << "n = ";
    cin >> n; //Input numbers of number
    int arr[n]; //Declare an array of length n
    for(int &i : arr) cin >> i; //Input value
    vector<int> A(arr, arr+sizeof(arr)/sizeof(int)); //Copy elements of array arr to vector A from index 0 to n-1 (inclusive)
    cout << "original:\n";
    PrintArray(A); //Output original array
    MergeSort(A, 0, n-1); //sorted
    cout << "sorted:\n";
    PrintArray(A); //Output sorted array
    return 0;
}
