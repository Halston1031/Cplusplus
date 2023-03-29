//
//  main.cpp
//  Vector
//
//  Created by 曾億宜 on 2020/4/9.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
    <vector>
    std::vector
    template < class T, class Alloc = allocator<T> > class vector; // generic template
    
    ▨ Vector
        Vectors are sequence containers representing arrays that can change in size.
        Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets
        on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled
        automatically by the container.
        Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new
        elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time,
        and thus, vectors do not reallocate each time an element is added to the container.
        Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater
        than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance between
        memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of
        individual elements at the end of the vector can be provided with amortized constant time complexity (see push_back).
        Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.
        Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient accessing its elements (just like arrays)
        and relatively efficient adding or removing elements from its end. For operations that involve inserting or removing elements at positions other than the
        end, they perform worse than the others, and have less consistent iterators and references than lists and forward_lists.

        STL將通用容器分為了三類:    1. 順序性容器: vector、list、deque
                                2. 關聯式容器: map、multimap、set、multiset
                                3. 容器適配器: stack、queue、priority_queue

            ▨ summary:
                #include <vector> // 引入標頭檔
                vector<int> v // 默認初始化，空
                vector<int> v1(v) // 使用 v 初始化 v1
                vector<int> v(n) // 宣告1個vector，裡面有 n 個int空間
                vector<int> v[10]  // 宣告10個vector，每一個都可以存int。
                vector<vector<int> > 2D // 二維陣列宣告 ->(注意：">>" 之間要有空格)
                v.reserve(n); // 設定vector最小的元素容納數量(n)
                v.assign(n, 2) // 將vector中的n個值設置初始值為2
                v.capacity() // 返回vector"所能容納"的元素數量(在不重新分配記憶體的情況下）-> 只會長大不會縮小
                v.size() // 返回vector"實際含有"的元素數量
                v.max_size() // 返回最大的可以儲存的元素
                v.resize()  // 改變vector目前持有的元素個數 -> 既修改capacity大小，也修改size大小
                v.reserve()  // 只修改capacity大小，不修改size大小
                v.empty() // 如果vector內部為空，則傳回 true
                v.insert(v.begin() + n, m); // 插入 m 至第四位 (往前跳n格)
                v.insert(v.end() - n, m); // 插入 m 至倒數第四位 (往後跳n格)
                v.insert(v.end(), n, m); // 從末尾下一位置插入 n 個值為 m 的元素
                v.erase(v.begin() + n); // 刪除第 n+1 個數字
                v.begin() // 回傳一個iterator，它指向vector第一個元素
                v.end() // 回傳一個iterator，它指向vector最尾端元素的下一個位置（注意：它不是最末元素）
                v.rbegin() // 回傳一個反向iterator，它指向vector最尾端元素的
                v.rend() // 回傳一個iterator，它指向vector的第一個元素
                v.push_back(n) // 新增元素 n 至vector的末端，必要時會進行記憶體配置:0~9(少依賴)
                v.pop_back() // 刪除末尾元素
                v.front() // 回傳vector第一個元素的值
                v.back() // 回傳vector最末元素的值
                v.at(i) // at() 存取會做陣列邊界檢查，如果存取越界將會拋出. 可合併try, catch 防呆 -> #include <stdexcept>
                v.find(v.begin(), v.end(), n) // 在vector中找n ( [first, last) )
                v.clear(); // 清空所有元素
                v1.swap(v2); // v1和v2交換
 */
#include <bits/stdc++.h>
#include <vector> //header
using namespace std;
typedef long long ll;

void print(int num)
{
    cout << num << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // 1. 初始化
    cout << "1. 初始化" << '\n'; 
    vector<int> v; //默認初始化，空
    v.reserve(100); // 設定vector最小的元素容納數量(100)
    v.assign(10, 2); // 將vector中的10個值設置初始值為2
    cout << v.capacity() << endl; // 返回vector“所能容納”的元素數量(在不重新分配記憶體的情況下）
    cout << v.size() << endl; // 返回Vector實際含有的元素數量
    cout << endl;

    //2. 新增
    // 注意：push_front()只適用於list和deque容器型別
    cout << "2. 新增" << '\n';
    for(int i = 0; i < 10; i++) v.push_back(i); // 新增元素至vector的尾端，必要時會進行記憶體配置:0~9
    for_each(v.begin(), v.end(), print); // 印出vector，需要#include <algorithm>
    cout << '\n';
    cout << v.size() << endl;
    cout << endl;

    // 3. 插入及遍歷、逆遍歷
    cout << "3. 插入及遍歷、逆遍歷" << '\n';
    v.insert(v.begin() + 3, 99); // //插入99至第四位(往前跳3格)
    v.insert(v.end() - 3, 99); // 插入99至倒數第四位(往後跳3格)
    for_each(v.begin(), v.end(), print); // 印出vector
    cout << endl;

    // 一般遍歷寫法(兩種寫法)
    vector<int>::iterator it; // 迭代器
    for(it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
    cout << '\n';

    vector<int>::iterator iterator = v.begin();
    for(; iterator != v.end(); iterator++)
    {
        cout << *iterator << " ";
    }
    cout << '\n';

    for_each(v.rbegin(), v.rend(), print); // 逆序印出vector，在逆序迭代器上做++運算將指向容器中的前一個元素
    cout << endl;
    cout << endl;


    // 4. 刪除
    cout << "4. 刪除" << '\n';
    v.erase(v.begin() + 3); // 刪除第四個數字：99
    for_each(v.begin(), v.end(), print);
    cout << endl;
    v.insert(v.begin() + 3, 99);// 還原

    v.erase(v.begin(), v.begin() + 3); // 注意刪除了"3個元素(前三個)“，而不是4個
    for_each(v.begin(), v.end(), print);
    cout << endl;

    // 注意：pop_front()只適用於list和deque容器型別
    v.pop_back(); // 刪除vector最尾端的元素
    for_each(v.begin(), v.end(), print);
    cout << '\n';
    cout << endl;

    // 5. 查詢
    cout << "5. 查詢" << '\n';
    cout << v.front() << endl; // 回傳vector第一個元素的值
    cout << v.back() << endl; // 回傳vector最尾元素的值

    // 危險的做法，但一般我們就像訪問陣列那樣操作就行
    for(int i = 15; i < 25; i++)
        cout << "Element " << i << " is " << v[i] << endl; // [] 操作符(operator)，若索引"超出範圍"，不會丟出exception
    cout << '\n';
    //安全的做法
    int i;
    try // 使用try區塊來括住一個或多個可能會擲回例外狀況的語句
    {
        for (i = 15; i < 25; i++)
        cout << "Element " << i << " is " << v.at(i) << endl; // at() 存取會做陣列邊界檢查，如果存取越界將會拋出
    }
    catch (out_of_range err) // #include <stdexcept>
    {
        cout << "out_of_range at " << i << endl;
    }
    cout << endl;

    // 6. 清空
    cout << "6. 清空" << '\n';
    v.clear();
    cout << v.size() << endl; // 0
    for_each(v.begin(), v.end(), print); // 已經clear，v.begin()==v.end()，不會有任何結果
    cout << endl;

    // 7. 交換
    cout << "7. 交換" << '\n';
    vector<int> v1(3, 1); // vs1有3個元素, 元素值皆為1
    vector<int> v2(5, 2); // vs2有5個元素, 元素值皆為2
    cout << "Original: ";
    for_each(v1.begin(), v1.end(), print); 
    for_each(v2.begin(), v2.end(), print); 
    cout << "\nAfter: ";
    v1.swap(v2); // 交換後,v1中5個元素，v2則存3個元素
    for_each(v1.begin(), v1.end(), print); 
    for_each(v2.begin(), v2.end(), print);
    cout << endl;


    // 8. 二維陣列
    cout << "\n8. 二維陣列" << '\n';
    int n, m;
    cout << "Input n, m(vv[n][m]): ";
    cin >> n >> m;
    vector<vector<int> > vv(n, vector<int>(m, 0)); // 2D vector with size n x m

    cout << "Input inside numbers(Quantity: n*m): ";
    for (auto& row : vv) {
        for (auto& element : row) {
            cin >> element;
        }
    }

    // 印出
    for (auto& row : vv) {
        for (auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    return 0;
}
/*
溫馨小教室 ~ ~ ~:
1. for(auto element : MyArray)可以很方便的遍歷元素
	for(auto a:b)中b為一個容器，效果是利用a "遍歷並獲得" b容器中的每一個值，但是a "無法影響" 到b容器中的元素。(以值訪問）
	for(auto &a:b)中加了引用符號(&)，可以對容器中的內容"進行賦值"，即可通過 "對a賦值" 來做到容器b的內容填充。（以引用訪問）
2. for_each:
        template <typename InputIt, typename UnaryFunction>
        UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f);
    -> first 和 last 表示應用函數的元素範圍。 first 代表範圍的開始，last 代表結束（最後一個元素之後的一個）。f 是應用於範圍內每個元素的函數對象。 該函數必須接受範圍內元素類型的單個參數。
*/
