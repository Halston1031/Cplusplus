//
//  main.cpp
//  Divide-and-conquer algorithm(分治算法)
//
//  Created by 曾億宜 on 2020/7/29.
//  Copyright © 2020 曾億宜. All rights reserved.
//
//Leetcode 162 Find Peak Element
/*A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.
Follow up: Your solution should be in logarithmic complexity.
*/

/*
//Linear Scan
 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    for(int &i : v) cin >> i;
    for(int i = 1; i < v.size(); i++)
        if(v[i] < v[i-1])
            return i-1;
    return v.size()-1;
}
*/

/*
//Literative Binary Search
 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int left = 0;
    int right = v.size() - 1;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(v[mid] < v[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }
   return right;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int Healper(int, int, int);
int findPeakElement(const vector<int>)
{
    return Healper(num, 0, num.size()-1);
}
int Healper(const vector<int> &num, int low, int high)
{
    if(low == high)
        return low;
    else
    {
        int mid1 = (low + high) / 2;
        int mid2 = mid1 + 1;
        if(num[mid1] > num[mid2])
            return Healper(num, low, mid1);
        else
            return Healper(num, mid2, high);
    }
}
int main()
{
    vector<int> v;
    for(int &num : v) cin >> num;
    findPeakElement(v);
}
*/
