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
                ▨ Summery:   如果不指定容器，默認是用deque來作為其底層數據結構的
                    #include <stack> // 引入標頭檔
                    top() -> 返回對stack的頂元素(最後插入棧中的元素)
                    push() -> 插入數據
                    emplace() -> 插入數據
                    pop() -> 移除stack 的頂元素(出棧), 被移除的元素是最新插入棧中的元素(stack::top)
                    size() -> stack的大小
                    empty() -> 返回stack是否為空. 0為true，否則為false
                    swap() -> 交換
 */
 
#include <bits/stdc++.h>
#include <stack> //header
using namespace std;

void print_stack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // constructing stacks
    deque<int> mydeque (3,100); // 100 100 100
    vector<int> myvector (2,200); // 200 200

    stack<int> first; // 空的stack. first 是使用 deque<int> (雙端佇列: double-ended queue)實現. 適合用在stack兩端頻繁插入和移除(可使用於沒有任何特定的性能或內存要求時)
    stack<int> second(mydeque);  // stack 初始化為 mydeque

    // 下方仍是1D, 而非2D喔~~
    stack<int, vector<int> > third;  // 空的stack(使用vector實現stack中存int元素). vector 可使得隨機訪問操作變得高效(但是vector具有固定容量，當超出容量時可能需要調整大小，可能會導致性能下降)
    stack<int, list<int> > fourth; // 空的stack(使用linked list實現stack中存int元素), 將元素存在 doubly-linked list ( <-> )中，而linked list中的每個節點都存儲一個整數值. 適合用在stack中間頻繁插入和移除元素時(支持任意位置高效插入和刪除)，但隨機訪問比vector或deque慢
    stack<int,vector<int> > fifth (myvector);
    /*
    first & second 的元素"不一定"存儲在連續的內存位置. 默認情況下，雙端隊列實現為一系列固定大小的內存塊，這些內存塊根據需要分配以存儲元素。每個塊相對於序列中的其他塊"可能不連續"，因此不能保證堆棧的元素存儲在連續的內存位置中
    third & fifth (vector) 將元素存儲在"連續的內存位置"中
    fourth 將元素存儲在"具有下一個指針(Next pointer)的節點(node)"中. 列表中的每個節點都存儲一個值和兩個指針——一個指向前一個節點，另一個指向下一個節點。 這意味著節點可以分散在整個內存中，它們不需要存儲在連續的內存位置
    */

    for(int i = 0; i < 10; i++) // emplace(), push() -> 插入數據
    {
        //fourth.emplace(i);
        third.push(i);
    }
    cout << "\nsize of first: " << first.size() << '\n'; // size() -> stack的大小. 0
    cout << "size of second: " << second.size() << '\n'; // 100 100 100 -> 3
    cout << "size of third: " << third.size() << '\n'; // 9 8 7 6 5 4 3 2 1 0 -> 10
    // 取stack中元素後將元素pop()出stack
    while(!third.empty())  // empty() -> 返回stack是否為空. 0為true，否則為false
    {
        cout << third.top() << " "; // top() -> 返回對stack的頂元素(最後插入棧中的元素)
        third.pop(); // pop() -> 移除stack 的頂元素(出棧), 被移除的元素是最新插入棧中的元素(stack::top)
    }
    putchar('\n');
    cout << "size of fourth: " << fourth.size() << '\n';
    /* while(!fourth.empty()) 
    {
        cout << fourth.top() << " "; 
        fourth.pop(); 
    }
    putchar('\n');*/
    cout << "\nsize of fifth: " << fifth.size() << '\n'; // 200 200 -> 2

    stack<int> mystack;
    mystack.push(10);
    mystack.push(20);
    mystack.top() -= 5;
    cout << "Mystack.top() is now " << mystack.top() << '\n';

    // swap() -> 交換
    stack<int> foo, bar;
    foo.push (10); 
    foo.push(20); 
    foo.push(30);
    bar.push (111); 
    bar.push(222);
    foo.swap(bar);
    cout << "size of foo: " << foo.size() << '\n';
    print_stack(foo);
    cout << "\nsize of bar: " << bar.size() << '\n';
    print_stack(bar);
}
