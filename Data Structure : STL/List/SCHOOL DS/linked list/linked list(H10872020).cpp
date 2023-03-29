//
//  linked list(H10872020).cpp
//
//
//  Created by 曾億宜 on 2020/12/12.
//  Copyright © 2020 曾億宜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct polynode *polypointer;
typedef struct polynode
{
    int coef;
    int expon;
    polypointer link;
};

polypointer create()
{ /* create a linked list with two nodes */
    polypointer first;
    first = NULL;
    return first;
}

void insert(polypointer *ptr, int y, int x)
{ /* insert a new node with y^x into the list 使得資料由大到小排列 */

    polypointer temp, current, trial;

    current = *ptr; // 一開始是空的
    trial = NULL;

    temp = (polypointer)malloc(sizeof(polynode));
    temp->coef = y;
    temp->expon = x;
    temp->link = NULL;
    printf("add %dx^%d\n", y, x);

    if (*ptr)
    {
        //此題有錯, 當加入的順序不對時會當掉
        /*解決思路： 若第一個的指數比新加入的大 ((*ptr)->link > x ) 時
                ，下面的 while 為 false，trial 比較串列就不會執行，自然 trial ＝ NULL 。*/
        while ((current) && (current->expon > x))
        {
            trial = current;
            current = current->link;
        };

        temp->link = current;

        // 在 trial 為 NULL
        // 加入到 trial->link 一定會出錯
        // trial->link = temp;    ←＊＊當在這裡所以
        // 所以應該要改成先判斷 trial 是否為 NULL
        if (trial == NULL)
        {
            // 比第一個指數還要大，放在最前面
            // 更改根資料
            *ptr = temp;
        }
        else
        {
            trial->link = temp;
        }
    }
    else
    {
        *ptr = temp;
    }
}

void attach(float coefficient, int exponent, polypointer *ptr)
{ /* 建立一個新的節點包含coef = coefficient 且 expon = exponent，將它附加到ptr 所指向的節點。將ptr更新為指向此新節點。 */
    polypointer temp;
    temp = (polypointer)malloc(sizeof(polynode));
    temp->coef = coefficient;
    temp->expon = exponent;
    (*ptr)->link = temp;
    *ptr = temp;
}

polypointer padd(polypointer a, polypointer b)
{
    /* 傳回 a 與 b 相加後的多項式 */
    polypointer c, rear, temp;
    int sum;
    rear = (polypointer)malloc(sizeof(polynode));
    c = rear;
    while (a && b)
        switch ((a->expon > b->expon) - (a->expon < b->expon))
        {
        case -1:
            attach(b->coef, b->expon, &rear);
            b = b->link;
            break;
        case 0:
            sum = a->coef + b->coef;
            if (sum)
                attach(sum, a->expon, &rear);
            a = a->link;
            b = b->link;
            break;
        case 1:
            attach(a->coef, a->expon, &rear);
            a = a->link;
        }

    for (; a; a = a->link)
        attach(a->coef, a->expon, &rear);
    for (; b; b = b->link)
        attach(b->coef, b->expon, &rear);
    rear->link = NULL;
    temp = c;
    c = c->link;
    free(temp);
    return c;
}

polypointer pmul(polypointer a, polypointer b)
{
    /* 傳回a與b相乘後的多項式 */
    polypointer rear, temp;
    polypointer broot;
    /* 指標歸零 */
    rear = NULL;
    /* 記錄 B 的根 */
    broot = b;
    /* 建 A 迴圈 */
    while (a)
    {
        /* 把 B 拿回來，重新相乘 */
        b = broot;
        /* 建 B 迴圈 */
        while (b)
        {
            /* 暫存器歸零 */
            temp = NULL;
            /* 底數(x)相同，系數相乘，指數相加，直接用 insert 新增一個 */
            /* 計算結果放到暫存區 */
            insert(&temp, a->coef * b->coef, a->expon + b->expon);
            /* 暫存區加到串中，要先判斷根在不在 */
            if (rear == NULL) /* 沒根，直接放 */
                rear = temp;
            else // 有根， padd 加到串中
                rear = padd(rear, temp);
            /* 換到下一個 b */
            b = b->link;
        }
        /* 換到下一個a */
        a = a->link;
    }
    /* 結束 */
    return rear;
}

void del(polypointer *ptr, int x)
{
    /* delete a node 其指數為 x  */
    polypointer current, temp, exit;
    /* 上一個歸零 */
    exit = NULL;
    /* 從第一個開始 */
    current = *ptr;
    while (current)
    {
        /* 存放下一個 */
        temp = current->link;
        /* 指數相同，移掉 */
        if (current->expon == x)
        {
            /* 印移除文字 */
            printf("del %dx^%d\n", current->coef, current->expon);

            /* 若自己是指標頭，更新指標頭 */
            if (current == *ptr)
                *ptr = temp;
            /* 如果有上一個，將指標串到下一個中 */
            if (exit != NULL)
                exit->link = temp;
            /* 可以放心的移了 */
            free(current);
            /* 歸零 */
            current = NULL;
        }

        /* 存放目前的，當下一個用 */
        // 如果被歸零了，就不放
        if (current != NULL)
            exit = current;
        /* 放下一個 */
        current = temp;
    };
}

polypointer del_list(polypointer ptr)
{
    /* delete 全部，回傳NULL  */
    polypointer link;
    while (ptr)
    {
        // 先取下一個串
        link = ptr->link;
        // 移除目前串
        free(ptr);
        // 本地換下一個
        ptr = link;
    }
    /* 回傳 NULL */
    return NULL;
}

void print_list(polypointer ptr)
{
    printf("The list: ");
    for (; ptr; ptr = ptr->link)
        printf("-> %dx^%d ", ptr->coef, ptr->expon);
    printf("\n");
}

int main(void)
{
    polypointer one = NULL, two = NULL, three = NULL, four = NULL;

    one = create();

    insert(&one, 2, 9);
    insert(&one, 3, 14);
    insert(&one, 16, 5);
    insert(&one, -3, 7);
    print_list(one);

    insert(&two, -1, 8);
    insert(&two, -2, 5);
    insert(&two, -15, 3);
    print_list(two);

    three = padd(one, two);
    print_list(three);

    // 測試兩者相乘
    print_list(one);
    print_list(two);
    four = pmul(one, two);
    print_list(four);

    // 以下為測試程式碼
    // 測試─移除某項次
    print_list(one);
    del(&one, 14);
    del(&one, 7);
    print_list(one);

    // 有建立的要記得移
    one = del_list(one);
    two = del_list(two);
    three = del_list(three);
    four = del_list(four);
    //測試到此

    // 結束
    system("pause");
    return 0;
}
