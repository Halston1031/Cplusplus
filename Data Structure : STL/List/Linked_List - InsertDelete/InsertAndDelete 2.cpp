//
//  main.cpp
// Linked list: Insert and Delete a node at nth position
//
//  Created by 曾億宜 on 2021/8/12.
//  Copyright © 2021 曾億宜. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
void Insert(int data, int n)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int n){
    struct Node* temp1 = head;
    if (n == 1){
        head = (*temp1).next; //head now points to second node.
        free(temp1);
        return;
    }
    for(int i = 0; i < n-2; i++)
        temp1 = temp1->next;
    // temp1 points to (n-1)th Node
    struct Node* temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    free(temp2); //delete temp2
}
int main()
{
    head = NULL; //empty list
    Insert(2, 1); //List: 2
    Insert(3, 2); //List: 2, 3
    Insert(4, 1); //List: 4, 2, 3
    Insert(5, 2); //List: 4, 5, 2, 3
    Print();
    int n = 0;
    cout << "Enter a position" << endl;
    cin >> n;
    Delete(n);
    Print();
}
