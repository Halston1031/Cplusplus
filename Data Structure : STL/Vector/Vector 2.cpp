//
//  main.cpp
//  Vector
//
//  Created by 曾億宜 on 2020/4/9.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
    <vector>
    std::vector
    template < class T, class Alloc = allocator<T> > class vector; // generic template
    
    ▨ Vector
        Vectors are sequence containers representing arrays that can change in size.
        Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets
        on regular
        pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled
        automatically by the container.
        Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new
        elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time,
        and thus, vectors do not reallocate each time an element is added to the container.
        Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater
        than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance between
        memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of
        individual elements at the end of the vector can be provided with amortized constant time complexity (see push_back).
        Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.
        Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient accessing its elements (just like arrays)
        and relatively efficient adding or removing elements from its end. For operations that involve inserting or removing elements at positions other than the
        end, they perform worse than the others, and have less consistent iterators and references than lists and forward_lists.

 */
#include <bits/stdc++.h>
#include <vector> //header
using namespace std;
typedef long long ll;

void print(int num)
{
 cout << num << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //1. 初始化
    cout << "1. 初始化" << '\n';
    vector<int> v;
    vector<int>::iterator it; //迭代器
    v.reserve(100); //設定vector最小的元素容納數量(100)
    v.assign(10, 2);//將vector中的10個值設置初始值為2
    cout << v.capacity() << endl; //返回vector“所能容納”的元素數量(在不重新分配記憶體的情況下）
    cout << v.size() << endl; //返回Vector實際含有的元素數量
    cout << endl;

    //2. 新增
    //注意：push_front()只適用於list和deque容器型別
    cout << "2. 新增" << '\n';
    for(int i = 0; i < 10; i++) v.push_back(i); //新增元素至vector的尾端，必要時會進行記憶體配置:0~9
    for_each(v.begin(), v.end(), print); //印出vector，需要#include <algorithm>
    cout << '\n';
    cout << v.size() << endl;
    cout << endl;

    //3. 插入及遍歷、逆遍歷
    cout << "3. 插入及遍歷、逆遍歷" << '\n';
    v.insert(v.begin() + 3, 99); //插入99至第四位
    v.insert(v.end() - 3, 99); //插入99至倒數第四位
    for_each(v.begin(), v.end(), print); //印出vector
    cout << endl;
    for_each(v.rbegin(), v.rend(), print);//逆序印出vector，在逆序迭代器上做++運算將指向容器中的前一個元素
    cout << endl;

    //一般遍歷寫法
    for(it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
    cout << '\n';
    cout << endl;

    //4. 刪除
    cout << "4. 刪除" << '\n';
    v.erase(v.begin() + 3); //刪除第四個數字：99
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.insert(v.begin() + 3, 99);//還原

    v.erase(v.begin(), v.begin() + 3); //注意刪除了"3個元素(前三個)“，而不是4個
    for_each(v.begin(), v.end(), print);
    cout << endl;

    //注意：pop_front()只適用於list和deque容器型別
    v.pop_back(); //刪除vector最尾端的元素
    for_each(v.begin(), v.end(), print);
    cout << '\n';
    cout << endl;

    //5. 查詢
    cout << "5. 查詢" << '\n';
    cout << v.front() << endl; //回傳vector第一個元素的值
    cout << v.back() << endl; //回傳vector最尾元素的值

    //危險的做法，但一般我們就像訪問陣列那樣操作就行
    for(int i = 15; i < 25; i++)
        cout << "Element " << i << " is " << v[i] << endl; //[] 操作符(operator)，若索引"超出範圍"，不會丟出exception
    cout << '\n';
    //安全的做法
    int i;
    try //使用try區塊來括住一個或多個可能會擲回例外狀況的語句
    {
        for (i = 15; i < 25; i++)
        cout << "Element " << i << " is " << v.at(i) << endl; //at() 存取會做陣列邊界檢查，如果存取越界將會拋出
    }
    catch (out_of_range err) //#include <stdexcept>
    {
        cout << "out_of_range at " << i << endl;
    }
    cout << endl;

    //6. 清空
    cout << "6. 清空" << '\n';
    v.clear();
    cout << v.size() << endl; //0
    for_each(v.begin(), v.end(), print); //已經clear，v.begin()==v.end()，不會有任何結果
    
    return 0;
}
