//
//  main.cpp
//  Stack
//
//  Created by 曾億宜 on 2020/4/10.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
     <stack>
     std::stack
     template <class T, class Container = deque<T> > class stack;
 
        ▨ LIFO stack (Last In First Out)
            Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and
            extracted only from one end of the container.
            stacks are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying
            container, providing a specific set of member functions to access its elements. Elements are pushed/popped from the "back" of the specific container,
            which is known as the top of the stack.
            The underlying container may be any of the standard container class templates or some other specifically designed container class. The container shall
            support the following operations:
            empty
            size
            back
            push_back
            pop_back
            The standard container classes vector, deque and list fulfill these requirements. By default, if no container class is specified for a particular stack
            class instantiation, the standard container deque is used.
 */
/*
 轉載
 棧（statck）這種數據結構在計算機中是相當出名的。棧中的數據是先進後出的（First In Last Out, FILO）。
  棧只有一個出口，允許新增元素（只能在棧頂上增加）、移出元素（只能移出棧頂元素）、取得棧頂元素等操作。
  在STL中，棧是以別的容器作為底部結構，再將接口改變，使之符合棧的特性就可以了。因此實現非常的方便。
  下面就給出棧的函數列表和VS2008中棧的源代碼，
  可以看出，由於棧只是進一步封裝別的數據結構，並提供自己的接口，所以代碼非常簡潔，
  如果不指定容器，默認是用deque來作為其底層數據結構的
  在STL中棧一共就5個常用操作函數（top()、push()、pop()、 size()、empty() ）。

 //stack的定義
 template<class _Ty, class _Container = deque<_Ty> >
 class stack
 {   // LIFO queue implemented with a container
 public:
 typedef _Container container_type;
 typedef typename _Container::value_type value_type;
 typedef typename _Container::size_type size_type;
 typedef typename _Container::reference reference;
 typedef typename _Container::const_reference const_reference;

 stack() : c()
 {   // construct with empty container
 }

 explicit stack(const _Container& _Cont) : c(_Cont)
 {   // construct by copying specified container
 }

 bool empty() const
 {   // test if stack is empty
 return (c.empty());
 }

 size_type size() const
 {   // test length of stack
 return (c.size());
 }

 reference top()
 {   // return last element of mutable stack
 return (c.back());
 }

 const_reference top() const
 {   // return last element of nonmutable stack
 return (c.back());
 }

 void push(const value_type& _Val)
 {   // insert element at end
 c.push_back(_Val);
 }

 void pop()
 {   // erase last element
 c.pop_back();
 }

 const _Container& _Get_container() const
 {   // get reference to container
 return (c);
 }

 protected:
 _Container c;   // the underlying container
 };
 */
 
#include <bits/stdc++.h>
#include <stack> //header
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    stack<int> s; //棧 stack支持 empty() size() top() push() pop()
    stack<int, list<int>> a;
    stack<int, vector<int>>  b;

    for(int i = 0; i < 10; i++) //插入數據
    {
        a.emplace(i);
        b.push(i);
    }
    cout <<  a.size() << '\n' << b.size() << endl; //栈的大小
    while(!a.empty()) //取棧項數據並將數據彈出棧
    {
        cout << a.top() << " "; //打印棧頂元素
        a.pop(); //移除棧頂元素(出棧)
    }
    putchar('\n');

    while(!b.empty())
    {
        cout <<  b.top() << " ";
        b.pop();
    }
    putchar('\n');
}
