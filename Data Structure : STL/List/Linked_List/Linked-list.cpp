//
//  main.cpp
//  Linked-List
//
//  Created by 曾億宜 on 2021/7/9.
//  Copyright © 2021 曾億宜. All rights reserved.
//Linked List: Inserting a node at begining

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void Insert(Node** pointerToHead, int x)
{
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x; //(*temp).data = x;
    temp->next = NULL;
    if (*pointerToHead != NULL)
        temp->next = *pointerToHead;
    *pointerToHead = temp;
 }
void Print(Node* head)
{
    cout << "List is: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}
int main(int argc, const char *argv[])
{
    Node* head = NULL; //empty list
    cout << "How many numbers?" << endl;
    int n, i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter the number" << endl;
        cin >> x;
        Insert(&head,x);
        Print(head);
    }
    return 0;
}
