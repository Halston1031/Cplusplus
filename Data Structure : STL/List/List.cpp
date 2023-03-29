//
//  main.cpp
//  List
//
//  Created by 曾億宜 on 2020/4/9.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
    <list>
    std::list
    template < class T, class Alloc = allocator<T> > class list;
 
    ▨ List
        Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.
        List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage
        locations. The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.
        They are very similar to forward_list: The main difference being that forward_list objects are single-linked lists, and thus they can only be iterated
        forwards, in exchange for being somewhat smaller and more efficient.
        Compared to other base standard sequence containers (array, vector and deque), lists perform generally better in inserting, extracting and moving elements
        in any position within the container for which an iterator has already been obtained, and therefore also in algorithms that make intensive use of these,
        like sorting algorithms.
        The main drawback of lists and forward_lists compared to these other sequence containers is that they lack direct access to the elements by their position;
        For example, to access the sixth element in a list, one has to iterate from a known position (like the beginning or the end) to that position, which takes
        linear time in the distance between these. They also consume some extra memory to keep the linking information associated to each element (which may be an
        important factor for large lists of small-sized elements).
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(int num)
{
    cout << num << " ";
}
    
bool IsOdd(int i)
{
  return ((i & 1) == 1);
}
   
int main()
{
    //1. 初始化
    cout << "1. 初始化" << endl;
    list<int> lit;
    list<int>::iterator it;
   
    lit.assign(10, 2);//將10個值為2的元素賦到list中
    for_each(lit.begin(), lit.end(), print);
    cout << '\n';
    cout << lit.size() << endl; //返回list實際含有的元素數量
    cout << endl;
    
    //2. 新增
    cout << "2. 新增" << endl;
    lit.push_front(666); //插入至list前端
    for(int i = 0; i < 10; i++) lit.push_back(i); //插入至list後端
    for_each(lit.begin(), lit.end(), print); //需要#include <algorithm>
    cout << endl;
    cout << lit.size() << endl;
    cout << endl;
   
    //3. 插入及遍歷、逆遍歷和倒轉
    cout << "3. 插入及遍歷、逆遍歷和倒轉" << endl;
    lit.insert(lit.begin() , 99); //不能+和-了
    lit.insert(lit.end() , 99);

    for_each(lit.begin(), lit.end(), print);
    cout << endl;
    for_each(lit.rbegin(), lit.rend(), print);//逆序list，在逆序迭代器上做++運算將指向容器中的前一個元素
    cout << endl;

    //一般遍歷寫法
    for(it = lit.begin(); it != lit.end(); ++it)
    cout << *it << " ";
    cout << endl;
   
    lit.reverse();
    for_each(lit.begin(), lit.end(), print);
    cout << endl;
    for_each(lit.rbegin(), lit.rend(), print);
    cout << endl;
    cout << endl;

    //4. 排序
    cout << "4. 排序" << endl;
    lit.sort();//為連結串列排序，預設是“升序”
    for_each(lit.begin(), lit.end(), print);
    cout << endl;
    cout << endl;
   
    //5. 刪除
    cout << "5. 刪除" << endl;
    lit.erase(lit.begin()); //刪除第一個字元：99
    for_each(lit.begin(), lit.end(), print);
    cout << endl;
    lit.insert(lit.begin() , 99);//還原
    for_each(lit.begin(), lit.end(), print);
    cout << '\n';

    lit.unique();  //刪掉連結串列中所有重複的元素
    for_each(lit.begin(), lit.end(), print);
    cout << endl;

    
    lit.remove(2); //去掉所有含2的元素
    for_each(lit.begin(), lit.end(), print);
    cout << endl;

    
    lit.remove_if(IsOdd); //刪掉所有奇數
    for_each(lit.begin(), lit.end(), print);
    cout << endl;

    lit.pop_front(); //去掉頭元素
    lit.pop_back();  //去掉尾元素
    for_each(lit.begin(), lit.end(), print);
    cout << endl;
    cout << endl;

    //6. 查詢
    cout << "6. 查詢" << endl;
    cout << lit.front() << endl; //第一個元素的值
    cout << lit.back() << endl;  //最後一個元素的值
    cout << endl;

    //7. 清空
    cout << "7. 清空" << endl;
    lit.clear();
    cout << lit.size() << endl;//0
    for_each(lit.begin(), lit.end(), print); //已經clear，v.begin()==v.end()，不會有任何結果。

    return 0;
 }

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode
{
private:
    int data;
    ListNode *next;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    // int size;                // size是用來記錄Linked list的長度, 非必要
    ListNode *first;            // list的第一個node
public:
    LinkedList():first(0){};
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
};


void LinkedList::PrintList(){

    if (first == 0) {                      // 如果first node指向NULL, 表示list沒有資料
        cout << "List is empty.\n";
        return;
    }

    ListNode *current = first;             // 用pointer *current在list中移動
    while (current != 0) {                 // Traversal
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


void LinkedList::Push_front(int x){

    ListNode *newNode = new ListNode(x);   // 配置新的記憶體
    newNode->next = first;                 // 先把first接在newNode後面
    first = newNode;                       // 再把first指向newNode所指向的記憶體位置
}


void LinkedList::Push_back(int x){

    ListNode *newNode = new ListNode(x);   // 配置新的記憶體
    if (first == 0)
    {                      // 若list沒有node, 令newNode為first
        first = newNode;
        return;
    }

    ListNode *current = first;
    while (current->next != 0)             // Traversal
    {
        current = current->next;
    }
    current->next = newNode;               // 將newNode接在list的尾巴
}


void LinkedList::Delete(int x)
{
    ListNode *current = first,
             *previous = 0;
    while (current != 0 && current->data != x) {  // Traversal
        previous = current;                       // 如果current指向NULL
        current = current->next;                  // 或是current->data == x
    }                                             // 即結束while loop

    if (current == 0) // list沒有要刪的node, 或是list為empty
    {
        std::cout << "There is no " << x << " in list.\n";
        // return;
    }
    else if (current == first)          // 要刪除的node剛好在list的開頭
    {
        first = current->next;          // 把first移到下一個node
        delete current;                 // 如果list只有一個node, 那麼first就會指向NULL
        current = 0;                    // 當指標被delete後, 將其指向NULL, 可以避免不必要bug
    }
    else                                   // 其餘情況, list中有欲刪除的node,
    {
        previous->next = current->next; // 而且node不為first, 此時previous不為NULL
        delete current;
        current = 0;
    }
}


void LinkedList::Clear()
{
    while (first != 0) // Traversal
    {
        ListNode *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}


void LinkedList::Reverse()
{
    if (first == 0 || first->next == 0)// list is empty or list has only one node
    {
        return;
    }

    ListNode *previous = 0,
             *current = first,
             *preceding = first->next;
    while (preceding != 0)
    {
        current->next = previous;      // 把current->next轉向
        previous = current;            // previous往後挪
        current = preceding;           // current往後挪
        preceding = preceding->next;   // preceding往後挪
    }                                  // preceding更新成NULL即跳出while loop

    current->next = previous;          // 此時current位於最後一個node, 將current->next轉向
    first = current;                   // 更新first為current
}


int main() {

    LinkedList list;     // 建立LinkedList的object
    list.PrintList();    // 目前list是空的
    list.Delete(4);      // list是空的, 沒有4
    list.Push_back(5);   // list: 5
    list.Push_back(3);   // list: 5 3
    list.Push_front(9);  // list: 9 5 3
    list.PrintList();    // 印出:  9 5 3
    list.Push_back(4);   // list: 9 5 3 4
    list.Delete(9);      // list: 5 3 4
    list.PrintList();    // 印出:  5 3 4
    list.Push_front(8);  // list: 8 5 3 4
    list.PrintList();    // 印出:  8 5 3 4
    list.Reverse();      // list: 4 3 5 8
    list.PrintList();    // 印出:  4 3 5 8
    list.Clear();        // 清空list
    list.PrintList();    // 印出: List is empty.
    return 0;
}
*/
