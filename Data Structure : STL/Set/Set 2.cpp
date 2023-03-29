//
//  main.cpp
//  Set
//
//  Created by 曾億宜 on 2020/4/10.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
    <set>
    std::set
    template < class T,                        // set::key_type/value_type
            class Compare = less<T>,        // set::key_compare/value_compare
            class Alloc = allocator<T>      // set::allocator_type
            > class set;
 
        ▨ Set
        Sets are containers that store unique elements following a specific order.
        In a set, the value of an element also identifies it (the value is itself the key, of type T), and each value must be unique. The value of the elements in a set
        cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.
        Internally, the elements in a set are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type
        Compare).
        set containers are generally slower than unordered_set containers to access individual elements by their key, but they allow the direct iteration on subsets
        based
        on their order.
        Sets are typically implemented as binary search trees.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    set<int> s;
    //1. 插入元素
    s.insert(5); //第一次插入5，可以插入
    s.insert(1);
    s.insert(6);
    s.insert(3);
    s.insert(8);
    s.emplace(7);
    s.emplace(9);
    s.emplace(5); //第二次插入5，重複元素，不會插入
    s.emplace(2);
    pair<set<int>::iterator,bool> pr;
    pr = s.insert(7);
    cout << "1. 插入元素（正向輸出）" << endl;
    set<int>::iterator it; //定義前向迭代器
    for(it = s.begin(); it != s.end(); it++) //正序遍歷集合中的所有元素
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;

    
    //2. 反向輸出
    cout << "2. 反向輸出" << endl;
    set<int>::reverse_iterator rit; //定義反向迭代器
    for(rit = s.rbegin(); rit != s.rend(); rit++) //反向遍歷集合中的所有元素
    {
        cout << *rit << " ";
    }
    cout << endl;
    cout << endl;

    //3. 計次
    cout << "3. 計次" << endl;
    cout << "1出現次數： " << s.count(1) << endl;
    cout << endl;
    
    //4. 刪除
    cout << "4. 刪除" << endl;
    s.erase(s.begin()); //刪除第一個元素
    s.erase(3); //刪除3
    it = s.find (8);
    s.erase (it, s.end()); //刪除8以後的元素
    for(it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //5. 查詢
    cout << "5. 查詢" << endl;
    if((it = s.find(2)) != s.end())
    {
        cout << *it << endl;
    }
    cout << endl;
    
    //6. lower_bound/lower_bound
    cout << "6. lower_bound/upper_bound" << endl;
    cout << "lower_bound: " << *s.lower_bound(3) << endl; //返回一個迭代器，指向鍵值>= key的第一個元素。
    cout << "upper_bound: " << *s.upper_bound(5) << endl; //返回一個迭代器，指向鍵值> key的第一個元素。
    cout << endl;

    //7. 清除集合
    cout << "7. 清除集合" << endl;
    s.clear();
    if(s.empty())
    {
        cout << s.size() << endl;
    }
    cout << endl;
}
/*
// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
using namespace std;
int main ()
{
  int myints[] = {10,20,30,30,20,10,10,20};
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
  vector<int>::iterator low, up;
  low = lower_bound (v.begin(), v.end(), 20); //         ^
  up = upper_bound (v.begin(), v.end(), 20); //                   ^
  cout << "lower_bound at position " << (low - v.begin()) << '\n';
  cout << "upper_bound at position " << (up - v.begin()) << '\n';
}
*/
