//
//  InsertionSort.cpp
//  InsertionSort
//
//  Created by 曾億宜 on 2020/11/3.
//  Copyright © 2020 曾億宜. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, key, j;
    cout << "N = ";
    cin >> N; //Input N numbers
    vector<int> A(N); //Declare an vector of length n
    for(int &i : A) cin >> i; //Input value
    cout << "original:\n";
    for(int i : A) cout << i << " "; //Output Original vector
    for(int i = 0; i < N; i++) //Vector traversal
    {
        key = A[i]; //Insert A[i] into the sorted sequence A[1...i-1].
        j = i - 1; //Set j as the previous number
        while(j >= 0 && A[j] > key) //Keep comparing the previous number
        {
            A[j+1] = A[j]; //Adjust the big value backward
            j--; //j advances forward
        }
        A[j+1] = key; //Put into vector A
    }
    cout << '\n' << "sorted:\n";
    for(j = 0; j < N-1; j++) cout << A[j] << " "; //Output the value of vector A
    cout << A[N-1] << endl;
}
