//
//  main.cpp
//  Multimap
//
//  Created by 曾億宜 on 2020/4/10.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
     <map>
     std::multimap
     template < class Key,                                     // multimap::key_type
                class T,                                       // multimap::mapped_type
                class Compare = less<Key>,                     // multimap::key_compare
                class Alloc = allocator<pair<const Key,T> >    // multimap::allocator_type
                > class multimap;
    
        ▨ Multiple-key map
            Multimaps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order, and
            where multiple elements can have equivalent keys.
            In a multimap, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to
            this key. The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:
                                                                typedef pair<const Key, T> value_type;
            Internally, the elements in a multimap are always sorted by its key following a specific strict weak ordering criterion indicated by its internal
            comparison object (of type Compare).
            multimap containers are generally slower than unordered_multimap containers to access individual elements by their key, but they allow the direct
            iteration on subsets based on their order.
            Multimaps are typically implemented as binary search trees.

 */
/*
 *
 ********************************************
 * multimap多重映照容器的基礎說明：
 ********************************************
 *
 * multimap多重映照容器:容器的數據結構採用紅黑樹進行管理
 * multimap的所有元素都是pair:第一元素為鍵值(key),不能修改;第二元素為實值(value),可被修改
 *
 * multimap特性以及用法與map完全相同，唯一的差別在於:
 * 允許重複鍵值的元素插入容器(使用了RB-Tree的insert_equal函數)
 * 因此:
 * 鍵值key與元素value的映照關係是多對多的關係
 * 沒有定義[]操作運算
 *
 * Sorted Associative Container Pair Associative Container Unique Associative Container
 *
 * 使用multimap必須使用宏語句#include <map>
 *
 **************************************************************************************
 *
 * 創建multimap對象:
 * 1.multimap<char,int,greater<char> > a; //元素鍵值類型為char,映照數據類型為int,鍵值的比較函數對象為greater<char>
 * 2.multimap(const key_compare& comp) //指定一個比較函數對象comp來創建map對象
 * 3.multimap(const multisetr&); //multimap<int,char*> b(a); //此時使用默認的鍵值比較函數less<int>  * 4.multimap(first,last);
 * 5.multimap(first,last,const key_compare& comp);
 *
 * //Example:
 * pair<const int ,char> p1(1,'a');
 * pair<const int ,char> p2(2,'b');
 * pair<const int ,char> p3(3,'c');
 * pair<const int ,char> p4(4,'d');
 * pair<const int ,char> pairArray[]={p1,p2,p3,p4};
 * multimap<const int,char> m4(pairArray,pairArray+5);
 * multimap<const int,char> m3(m4);
 * multimap<const int,char,greater<const int> > m5(pairArray,pairArray+5,greater<const int>());
 *
 **************************************************************************************
 *
 * 元素的插入
 * //typedef pair<const key,T> value_type;
 * pair<iterator,bool> insert(const value_type& v);
 * iterator insert(iterator pos,const value_type& v);
 * void insert(first,last);
 *
 **************************************************************************************
 *
 * 元素的刪除
 * void erase(iterator pos);
 * size_type erase(const key_type& k); //刪除等於鍵值k的元素
 * void erase(first,last); //刪除[first,last)區間的元素
 * void clear();
 *
 **************************************************************************************
 *
 * 訪問與搜索
 *
 * iterator begin();iterator end(); //企圖通過迭代器改變元素是不被允許的
 * reverse_iterator rbegin();reverse_iterator rend();
 *
 * iterator find(const key_type& k) const;
 * pair<iterator,iterator> equal_range(const key_type& k) const;//返回的pair對象，
 * //first為lower_bound(k);大於等於k的第一個元素位置
 * //second為upper_bound();大於k的第一個元素位置
 *
 * 其它常用函數
 * bool empty() const;
 * size_type size() const;
 * size_type count(const key_type& k) const;   //返回键值等于k的元素个数
 * void swap();
 *
 * iterator lower_bound();iterator upper_bound();pair<iterator,iterator> equal_range();//上界、下届、确定区间
 *
 *
 *
 */
 
#include <map>
#include <string>
#include <iostream>
using namespace std;
// 基本操作與set類型,牢記map中所有元素都是pair
// 對於自定義類,初學者會覺得比較函數如何構造很麻煩,這個可以參照前面的書寫示例
// 但若設置鍵值為int或char類型，無須構造比較函數
 
struct student{
 char* name;
 int age;
 char* country;
 char* Departments;
};
 
int main()
{
    student s[] = {
    {"Elizabeth",23,"France","Accounting"},
    {"Catherine",19,"USA","Physics"},
    {"Evan",16,"Switzerland","Economic"},
    {"Vivian",18,"Canada","Diplomacy"},
    {"Shawn",19,"Finland","music"},
    {"Halston",20,"Netherlands","Computer Science"}
    };
    // insert some values:
    multimap<int,student> a;
    a.insert(pair<int,student>(4,s[0]));
    a.insert(pair<int,student>(2,s[1]));
    a.insert(pair<int,student>(3,s[2]));
    a.insert(pair<int,student>(4,s[3])); //鍵值key與p1相同
    a.insert(pair<int,student>(5,s[4]));
    a.insert(pair<int,student>(6,s[5]));
    
    multimap<int,student>::iterator it = a.find(4);
    pair <multimap<int,student>::iterator, multimap<int,student>::iterator> ret;
    cout << "學校人數："<< a.size() << endl;
    cout << "學校key值為" << it->first << "的學生有：" << a.count(4) << "名" << '\n';
    cout << "刪除key值大於" << it->first << "的同學......" << endl;
    a.erase(it, a.end()); //刪除key值為4以後的
    cout << "現在學校總人數為：" << a.size() << " \n" << "人員如下: " << endl;
    for(it = a.begin(); it != a.end(); it++)
    {
        cout << "The name: " <<  it->second.name << "     " << "Age: " << it->second.age << "     " << "Country: " << it->second.country << "      " << "Departments: " << it->second.Departments << endl;
    }
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    multimap<string,int> m_map;
    string s("USA"),s1("TAIWAN");
    m_map.insert(make_pair(s,50));
    m_map.insert(make_pair(s,55));
    m_map.insert(make_pair(s,60));
    m_map.insert(make_pair(s1,30));
    m_map.insert(make_pair(s1,20));
    m_map.insert(make_pair(s1,10));
    
    //在multimap中，同一個鍵關聯的元素必然相鄰存放-----------------------------依序將key對應的多個value輸出
    //方式1：使用find和count函數。 count函數求出某個鍵出現的次數，find函數返回一個迭代器，指向第一個擁有正在查找的鍵的實例
    int k;
    multimap<string,int>::iterator m;
    m = m_map.find(s);
    for(k = 0; k != m_map.count(s); k++, m++)
        cout << m->first << "--" << m->second << endl;
    //方式2：使用lower_bound(key)和upper_bound(key)，lower_bound(key)返回一個迭代器，指向鍵不小於k的第一個元素，upper_bound(key)返回一個迭代器，指向鍵大於k的第一個元素
    multimap<string,int>::iterator beg, end;
    beg = m_map.lower_bound(s1);
    end = m_map.upper_bound(s1);
    for(m = beg; m != end; m++)
        cout << m->first << "--" << m->second << endl;
    //方式3:使用equat_range(key)，返回一個迭代器的pair對象，first成員等價於lower_bound(key)，second成員等價於upper_bound(key)
    beg = m_map.equal_range(s).first;
    end = m_map.equal_range(s).second;
    for(m = beg; m != end; m++)
        cout << m->first << "--" << m->second << endl;
    return 0;
}
*/
