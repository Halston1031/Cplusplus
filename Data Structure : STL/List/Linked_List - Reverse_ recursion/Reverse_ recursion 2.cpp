//
//  main.cpp
//  Linked_List - Reverse_recursion
//
//  Created by 曾億宜 on 2021/8/12.
//  Copyright © 2021 曾億宜. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
 
    Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        // Recursive call
        Node* rest = reverse(head->next);
        head->next->next = head;
        
        head->next = NULL;
 
        return rest;
    }
 
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
 
int main()
{
    LinkedList ll;
    ll.push(320);
    ll.push(34);
    ll.push(315);
    ll.push(385);
    
    cout << "Linked List Before Reversing\n";
    ll.print();
 
    ll.head = ll.reverse(ll.head);
 
    cout << "\nLinked List After Reversing \n";
    ll.print();
    cout << endl;
    return 0;
}
