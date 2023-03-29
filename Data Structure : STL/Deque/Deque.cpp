//
//  main.cpp
//  Deque
//
//  Created by 曾億宜 on 2020/4/9.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
     <deque>
     std::deque
     template < class T, class Alloc = allocator<T> > class deque;
 
    ▨ Double ended queue
        deque (usually pronounced like "deck") is an irregular acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that
        can be expanded or contracted on both ends (either its front or its back).
        Specific libraries may implement deques in different ways, generally as some form of dynamic array. But in any case, they allow for the individual elements
        to be accessed directly through random access iterators, with storage handled automatically by expanding and contracting the container as needed.
        Therefore, they provide a functionality similar to vectors, but with efficient insertion and deletion of elements also at the beginning of the sequence,
        and not only at its end. But, unlike vectors, deques are not guaranteed to store all its elements in contiguous storage locations: accessing elements in a
        deque by offsetting a pointer to another element causes undefined behavior.
        Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both work in quite different ways: While
        vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage,
        with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform
        sequential interface (through iterators). Therefore, deques are a little more complex internally than vectors, but this allows them to grow more
        efficiently under certain circumstances, especially with very long sequences, where reallocations become more expensive.
        For operations that involve frequent insertion or removals of elements at positions other than the beginning or the end, deques perform worse and have less
        consistent iterators and references than lists and forward lists.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    deque<string> Deq;
     
    Deq.assign(4,string("Smile"));
    Deq.push_back("last_string");
    Deq.push_front("first_string");
    copy(Deq.begin(),Deq.end(),
        ostream_iterator<string>(cout," "));
    cout << endl;
    cout << endl;
    
    for(int i = 0; i < Deq.size();++i)
        cout << "Deq[" << i << "] : " << Deq[i] << endl; //返回索引i所指的數據，如果i越界，直接崩潰
    cout << endl;

    for(int i = 0;i < Deq.size();++i)
        cout << "Deq.at(" << i << ") : " << Deq.at(i) << endl; //返回索引i所指的数据,如果i越界，抛出out_of_range异常
    cout << endl;
    
    
    Deq.pop_front(); //消失頭元素
    Deq.pop_back(); //消失尾元素
    copy(Deq.begin(),Deq.end(),
        ostream_iterator<string>(cout," "));
    cout << endl;
    cout << endl;
    
    for(int i = 1;i < Deq.size();++i)
        Deq[i] = "pre" + Deq[i];
    copy(Deq.begin(),Deq.end(),
        ostream_iterator<string>(cout," "));
    cout << endl;
    cout << endl;
    
    Deq.resize(6,"resized string"); //重新指定容器的長度為num(6),若容器變長，则以elem(resized string)填充新位置。如果容器變短，則末尾超出容器長度的元素被刪除。
    copy(Deq.begin(),Deq.end(),
        ostream_iterator<string>(cout," "));
    cout << endl;
}

