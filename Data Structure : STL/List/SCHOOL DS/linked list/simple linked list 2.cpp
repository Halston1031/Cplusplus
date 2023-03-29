//
//  main.cpp
//  DS
//
//  Created by 曾億宜 on 2020/10/29.
//  Copyright © 2020 曾億宜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct list_node *list_pointer;
typedef struct list_node {
    int data;
    list_pointer link;
};

list_pointer create( )
{/* create a linked list with two nodes */
    list_pointer first; //把list_pointer指向first所代表的記憶體位置
    first = NULL;
    return first;
}

void insert(list_pointer *ptr, list_pointer node, int x)
{/* insert a new node with data = x into the list ptr after node */
    list_pointer temp;
    
    temp = (list_pointer)malloc(sizeof(list_node)); //要求一個list_node大的空間
    temp->data = x; //將x插入temp->data
    temp->link = NULL;  //temp->link設成NULL
    printf("add %d\n", x); //增加x訊息
    if(*ptr) //nonempty list
    {
        //進行相連
        temp->link = node->link;
        node->link = temp;
    }
    else//empty list
    {
        *ptr = temp; //*ptr指向temp
    }
}

void insertbyorder(list_pointer *ptr, int x)
{/* insert a new node with data = x into the list 使得資料由小到大排列 */
    list_pointer temp, current, trial;
    current = *ptr;
    trial = NULL;
    temp = (list_pointer)malloc(sizeof(list_node));
    temp->data = x;
    temp->link = NULL;
    if(*ptr)
    {
        while((current) && (current->data < x))
        {
            trial = current;
            current = current->link;
        }
        temp -> link = current;
        trial->link = temp;
    }
    else *ptr = temp;
}

void del(list_pointer *ptr,  int x)
{
    /* delete a node with data = x  */
    list_pointer current, trial;
    current = *ptr;
    trial = NULL;

    if(!*ptr)//empty list
    {
        printf("the linked list is empty.\n");
    }
    else //nonempty list
    {
        while ((current) && (current->data != x)) //find the target node
        {
            //移動trial
            trial = current;
            current = current->link;
            //移動current
        }
       
        if ((current) && (current->data) == x)//當current不是NULL且current->data=x
        {
            printf("delete %d\n", x);

            if (trial)//trial is not NULL
            {
                trial->link = current->link;
                //刪除current
            }
            else //trial is NULL
            *ptr = current->link;
            free(current);
            //歸還current所指的memory
        }
    }
}

void print_list(list_pointer ptr)
{
    printf("The list: ");
    for ( ; ptr; ptr = ptr->link)
    printf("->%3d ", ptr->data);
    printf("\n");
}


int main (void)
{
    list_pointer one = NULL;

    one = create();
    print_list (one);
    insert (&one, one, 10);
    print_list (one);

    insert (&one, one,20);
    print_list (one);

    insert (&one, one,30);
    print_list (one);

    insert (&one,  one,40);
    print_list (one);

    del (&one, 20);
    print_list (one);

    del (&one, 30);
    print_list (one);

    del (&one, 10);
    print_list (one);

    del (&one, 40);
    print_list (one);

    insertbyorder (&one, 10);
    print_list (one);

    insertbyorder (&one, 20);
    print_list (one);

    insertbyorder (&one, 30);
    print_list (one);

    insertbyorder (&one,  40);
    print_list (one);



    system("pause");

    return 0;
}
