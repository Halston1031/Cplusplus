#include <stdio.h>
#include <stdlib.h>
typedef struct node *tree_pointer;
typedef struct node
{
    char data;
    tree_pointer left_child;
    tree_pointer right_child;
};

tree_pointer MakeBT(tree_pointer left_bt, char item, tree_pointer right_bt)
{
    tree_pointer temp;
    temp = (tree_pointer)malloc(sizeof(node));
    temp->data = item;
    temp->left_child = left_bt;
    temp->right_child = right_bt;
    return temp;
}

// 另行增加的...移除記憶體，不殺會浪費記憶體
tree_pointer del_tree(tree_pointer ptr)
{
    if (ptr == NULL) // 沒有樹，結束
        return NULL;
    del_tree(ptr->left_child);  // 殺左
    del_tree(ptr->right_child); // 殺右
    free(ptr);                  // 自殺
    return NULL;
}

void del(tree_pointer *ptr, char item)
{
    //第四項  修改程式使得刪除 tree 上的一個node with data =x
    /* delete a node with data = x from the tree  */
    tree_pointer tree, parent;
    tree_pointer lc, child;
    tree = *ptr;
    parent = NULL;
    while (tree != NULL)
    {
        if (tree->data == item) // 先查看左右手有幾個
        {
            child = NULL;                                                  // 移掉這個項目
            if ((tree->left_child == NULL) && (tree->right_child == NULL)) // 沒有左右手，自殺
            {
                if (*ptr == tree) // 自己就是根，把根移掉
                    *ptr = NULL;
                if (parent != NULL)
                {
                    if (parent->left_child == tree) // 爸爸的左手就是我
                        parent->left_child = NULL;
                    else //爸爸的右手是我
                        parent->right_child = NULL;
                }
                // 移動
                free(tree);
                return;
            }

            // 兒子看看要誰當老大，兩個只有一個有繼承
            if ((tree->left_child != NULL) && (tree->right_child == NULL))
            {
                child = tree->left_child;
            }
            else if ((tree->left_child == NULL) && (tree->right_child != NULL))
            {
                child = tree->right_child;
            }
            // 左右手只有一個，直接讓他們他就好
            if (child != NULL)
            {
                if (parent == NULL) // 最長者
                    *ptr = child;
                else
                {
                    if (parent->left_child == tree) // 爸爸的左手就是我
                        parent->left_child = child;
                    else //爸爸的右手是我
                        parent->right_child = child;
                }
                free(tree);
                return;
            }
            else // 兩個都有
            {
                // 左邊最大的
                child = tree->left_child;
                lc = tree->left_child;
                if (lc != NULL) // 有左邊
                {
                    while (lc->right_child != NULL)
                        lc = lc->right_child;
                    lc->right_child = tree->right_child; // 最小的右邊加入自己的右邊
                }
                if (parent != NULL) // 自己的爸爸接自己的兒子
                {
                    if (parent->left_child == tree) // 爸爸的左手就是我
                        parent->left_child = child;
                    else //爸爸的右手是我
                        parent->right_child = child;
                }
                else
                    *ptr = child;
                // 殺兒子
                free(tree);
            }
            return;
        }
        else if (item < tree->data)
        {
            parent = tree;
            tree = tree->left_child;
        }
        else
        {
            parent = tree;
            tree = tree->right_child;
        }
    }
}

// ...沒根時會當，所以改成傳入指標
void insert(tree_pointer *ptree, char item)
{ //第三項  修改程式使得當插入的值item存在時, 會顯示訊息, 但不會插入

    tree_pointer parent, temp, oldtree;
    tree_pointer tree;
    oldtree = tree = *ptree;
    parent = NULL; // 父親歸零
    while (tree)
    {
        if (item < tree->data)
        {
            parent = tree;
            tree = tree->left_child;
        }
        else
        {
            parent = tree;
            tree = tree->right_child;
        }
    }
    temp = (tree_pointer)malloc(sizeof(node));
    temp->data = item;
    temp->left_child = NULL;
    temp->right_child = NULL;
    if (parent != NULL) // 有爸爸時
    {
        if (item < parent->data)
            parent->left_child = temp;
        else
            parent->right_child = temp;
    }
    if ((*ptree) == NULL) // 當根為 null 時，自己就是樹根
        *ptree = temp;
}

void print_tree_inorder(tree_pointer ptr)
{
    if (ptr)
    {
        print_tree_inorder(ptr->left_child);
        printf("%c ", ptr->data);
        print_tree_inorder(ptr->right_child);
    }
}

//第一項(a) 完成tree postorder 和 tree preorder
void print_tree_postorder(tree_pointer ptr)
{
    if (ptr)
    {
        print_tree_postorder(ptr->left_child);
        print_tree_postorder(ptr->right_child);
        printf("%c ", ptr->data);
    }
}
//第一項(b) 完成tree postorder 和 tree preorder
void print_tree_preorder(tree_pointer ptr)
{
    if (ptr)
    {
        printf("%c ", ptr->data);
        print_tree_preorder(ptr->left_child);
        print_tree_preorder(ptr->right_child);
    }
}

// 另行增加的...取有幾個樹的節點
int get_tree_node_count(tree_pointer ptr)
{
    if (ptr == NULL) // 沒有就給0
        return 0;
    return 1                                        // 自己
           + get_tree_node_count(ptr->left_child)   //左
           + get_tree_node_count(ptr->right_child); //右
}
void print_tree_levelorder(tree_pointer ptr)
{ //第二項 完成tree level order
    //output every node's data by level order

    int c, n, p, i;
    tree_pointer t;
    tree_pointer *pptr;
    c = get_tree_node_count(ptr); // 取樹的數量
    if (c == 0)                   // 沒有東西，結束
    {
        printf("the tree no node \n");
        return;
    }
    pptr = (tree_pointer *)malloc(sizeof(tree_pointer) * c); // 建記憶體
    pptr[0] = ptr;                                           // 自己加入樹
    n = 1;                                                   // 目前有一個
    p = 0;
    while (p < n) // 取樹，FIFO
    {
        t = pptr[p]; // 取樹
        ++p;
        if (t->left_child) // 有左手，加入
        {
            pptr[n] = t->left_child;
            ++n;
        }
        if (t->right_child) // 有右手，加入
        {
            pptr[n] = t->right_child;
            ++n;
        }
    }
    for (i = 0; i < n; ++i) // 取完了，將其全部印出
        printf("%c ", pptr[i]->data);
    free(pptr); // 結束，釋放記憶體
}

int main(void)
{
    tree_pointer one, two, root;

    //Note that 當tree=NULL時, 此call insert會錯
    one = MakeBT(NULL, 'F', NULL);
    insert(&one, 'D');
    two = MakeBT(NULL, 'K', NULL);
    root = MakeBT(one, 'E', two);
    insert(&root, 'T');
    insert(&root, 'T');
    insert(&root, 'T');
    insert(&root, 'B');
    insert(&root, 'W');
    insert(&root, 'I');
    insert(&root, 'J');
    printf("Tree_Inorder:\n");
    print_tree_inorder(root);
    printf("\n");
    printf("Tree_Postorder:\n");
    print_tree_postorder(root);
    printf("\n");
    printf("Tree_Preorder:\n");
    print_tree_preorder(root);
    printf("\n");
    printf("Tree_levelorder:\n");
    print_tree_levelorder(root);
    printf("\n");
    printf("--------測試刪除-------\n");
    print_tree_inorder(root);
    printf("\n");
    printf("刪除Ｊ：\n");
    del(&root, 'J');
    print_tree_inorder(root);
    printf("\n");
    printf("刪除Ｅ：\n");
    del(&root, 'E');
    print_tree_inorder(root);
    printf("\n");
    printf("刪除Ｔ：\n");
    del(&root, 'T');
    print_tree_inorder(root);
    printf("\n");
    printf("刪除tree：\n");
    root = del_tree(root); // 殺樹，避免浪費記憶體
    print_tree_levelorder(root);
    system("pause");
    return 0;
}
