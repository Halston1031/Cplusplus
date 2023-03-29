//
//  main.cpp
//  Linked_List - Reverse Iterative method
//
//  Created by 曾億宜 on 2021/8/12.
//  Copyright © 2021 曾億宜. All rights reserved.
//
/*
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
struct Node* Reverse(struct Node* head){
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev =current;
        current = next;
    }
    head = prev;
    return head;
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
    head = Reverse(head);
    Print(head);
}
*/
#include<bits/stdc++.h>
 
using namespace std;
 
struct node {
    int data;
    struct node *next;
};
 
// To create a demo we have to construct a linked list and this
// function is to push the elements to the list.
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}
 
// Function to reverse the list
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}
 
// To check our program
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
 
// Driver function
int main() {
    struct node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 8);
    push(&head, 0);
    push(&head, 4);
    push(&head, 10);
    cout << "Linked List Before Reversing" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "Linked List After Reversing"<<endl;
    printnodes(head);
    cout << endl;
    return 0;
}
