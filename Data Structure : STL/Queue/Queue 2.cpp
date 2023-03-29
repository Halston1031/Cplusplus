//
//  main.cpp
//  Queue
//
//  Created by 曾億宜 on 2020/4/10.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
     <queue>
     std::queue
     template <class T, class Container = deque<T> > class queue;
 
     ▨ FIFO queue
        queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), where elements are inserted into one end
        of the container and extracted from the other.
        queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container,
        providing a specific set of member functions to access its elements. Elements are pushed into the "back" of the specific container and popped from its
        "front".
        The underlying container may be one of the standard container class template or some other specifically designed container class. This underlying container
        shall support at least the following operations:
        empty
        size
        front
        back
        push_back
        pop_front
        The standard container classes deque and list fulfill these requirements. By default, if no container class is specified for a particular queue class
        instantiation, the standard container deque is used.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    queue<string> q;
    cout << q.empty() << endl; //列隊是否為空，若空返回true(1)
    q.push("Hello World!");
    q.push("MY COUNTRY");
    q.push("USA");
    q.emplace ("TAIWAN");
    cout << q.size() << endl;
    cout << q.back() << endl;
    cout << '\n';
    while(!q.empty()) //印出
    {
        cout << q.front() << '\n';
        q.pop(); //最靠前位置的元素拿掉
    }
}
