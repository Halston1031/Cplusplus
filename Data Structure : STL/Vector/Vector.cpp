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
                vector<int> v[10] // 宣告10個vector，每一個都可以存int
                vector<int> v = {a, b, c,...} // 直接宣告動態陣列的值
                vector<vector<int> > 2D // 二維陣列宣告 ->(注意：">>" 之間要有空格)
                v.reserve(n); // 設定vector最小的元素容納數量(n)
                v.assign(n, 2) // 將vector中的n個值設置初始值為2
                v.capacity() // 返回vector"所能容納"的元素數量(在不重新分配記憶體的情況下）-> 只會長大不會縮小(2的倍數)
                v.size() // 返回vector"實際含有"的元素數量
                v.max_size() // 返回最大的可以儲存的元素
                v.resize()  // 改變vector目前持有的元素個數 -> 既修改capacity大小，也修改size大小
                v.shrink_to_fit // 要求vector退回不需要的內存空間
                v.reserve() // 只修改capacity大小，不修改size大小
                v.empty() // 如果vector內部為空，則傳回 true
                v.insert(v.begin() + n, m); // 插入 m 至第n位 (往 前 跳n格)
                v.insert(v.end() - n, m); // 插入 m 至倒數第n位 (往 後/回 跳n格)
                v.insert(v.end(), n, m); // 從末尾下一位置插入 n 個值為 m 的元素
                v.emplace() // 將元素放置在vector的指定位置
                v.emplace_back() // 將元素放置在vector末端 -> 只是將參數移動到向量，因此元素保持相同類型
                v.push_back(n) // 新增元素 n 至vector的末端，必要時會進行記憶體配置:0~9(少依賴)-> 在將其push到vector之前創建要插入的對象的副本，因此它會相應地修改類型
                v.pop_back() // 刪除末尾元素
                v.erase(v.begin() + n); // 刪除第 n+1 個數字
                v.erase(a, b); // 刪除a ~ b區間的數字
                v.begin() // 回傳一個iterator，它指向vector第一個元素
                v.end() // 回傳一個iterator，它指向vector最尾端元素的下一個位置（注意：它不是最末元素）
                v.back() // 回傳vector最尾元素的值
                v.rbegin() // 回傳一個反向iterator，它指向vector最尾端元素的
                v.rend() // 回傳一個iterator，它指向vector的第一個元素
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
    v.reserve(5); // 設定vector最小的元素容納數量(5)
    v.assign(11, 2); // 將vector中的11個值設置初始值為2
    for_each(v.begin(), v.end(), print); // 印出vector，需要#include <algorithm> 
    cout << "\nCapacity of vector: " << v.capacity() << endl; // 返回vector"所能容納"的元素數量(在不重新分配記憶體的情況下）
    cout << "Size of vector: " << v.size() << endl; // 返回vector實際含有的元素數量
    v.resize(13, 70); // 改變vector的元素個數為13
    cout << "Capacity of vector(after resize()): " << v.capacity() << '\n'; // capacity 2倍數擴增
    for_each(v.begin(), v.end(), print); 
    v.shrink_to_fit();
    cout << "\nCapacity of vector(shrink_to_fit()): " << v.capacity() << '\n';
    cout << endl;


    // 2. 新增
    // 注意：push_front()只適用於list和deque容器型別
    cout << "2. 新增" << '\n';
    for(int i = 0; i < 10; i++) v.push_back(i); // 新增元素至vector的尾端，必要時會進行記憶體配置:0~9
    for_each(v.begin(), v.end(), print); // -> 2 2 2 2 2 2 2 2 2 2 2 70 70 0 1 2 3 4 5 6 7 8 9 
    cout << '\n';

    /*
    auto y = v.emplace(v.begin()+1, 100); // 0 100 1 2 3 4 5 6 7 8 9
    v.emplace(y, 200); // 0 200 100 1 2 3 4 5 6 7 8 9
    v.emplace(v.end(), 300); // 0 200 100 1 2 3 4 5 6 7 8 9 300
    v.emplace_back(70); // 0 200 100 1 2 3 4 5 6 7 8 9 300 70
    cout << "Vector contains(emplace): ";
    for (auto& x: v)
        cout << ' ' << x;
    cout << '\n';
    */

    auto last_iterator = prev(end(v)); // 使用 prev() 獲取容器中最後一個元素的迭代器
    int last_element = *last_iterator;
    cout << "Using prev() to find the last element: " << last_element << endl; 
    cout << "Using back() to find the last element: " << v.back() << endl;
    cout << "The size of vector: " << v.size() << endl;
    cout << endl;


    // 3. 插入及遍歷、逆遍歷
    cout << "3. 插入及遍歷、逆遍歷" << '\n';
    v.insert(v.begin() + 3, 99); // 插入99至第四位(往前跳3格)
    v.insert(v.end() - 3, 99); // 插入99至倒數第四位(往後跳3格)
    for_each(v.begin(), v.end(), print); // 印出vector
    cout << endl;

    // 一般遍歷寫法
    vector<int>::iterator it; // 迭代器
    for(it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << '\n';

    for_each(v.rbegin(), v.rend(), print); // 逆序印出vector，在逆序迭代器上做++運算將指向容器中的前一個元素
    cout << '\n';
    cout << endl;


    // 4. 刪除
    cout << "4. 刪除" << '\n';
    v.erase(v.begin() + 3); // 刪除第四個數字：99
    for_each(v.begin(), v.end(), print);
    cout << endl;

    v.erase(v.begin(), v.begin() + 3); // 注意:刪除了"3個元素(前三個)“，而不是4個
    for_each(v.begin(), v.end(), print);
    cout << endl;

    // 注意:pop_front()只適用於list和deque容器型別
    v.pop_back(); // 刪除vector最尾端的元素
    for_each(v.begin(), v.end(), print);
    cout << '\n';
    cout << endl;


    // 5. 查詢
    cout << "5. 查詢" << '\n';
    cout << "Front: " << v.front() << endl; // 回傳vector第一個元素的值
    cout << "Back: " << v.back() << endl; // 回傳vector最尾元素的值

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


    // 6. 交換
    cout << "6. 交換" << '\n';
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


    // 7. 迭代器的位置更動
    cout << "\n7. 迭代器的位置更動" << '\n';
    cout << "Original: ";
    for_each(v.begin(), v.end(), print);

    // 使用 advance(), 可以向前.向後移
    // 向前
    auto itt = v.begin(); // 指向第一個元素的迭代器
    cout << "\niterator before moving forward: " << *itt << '\n';
    advance(itt, 10); // 需要 #include <iterator>. 向前10步 -> 0
    cout << "iterator after moving forward(10): " << *itt << '\n';
    
    // 向後(危險做法)
    auto ite = v.end(); // 指向尾後元素的迭代器
    cout << "\niterator before moving afterward: " << *ite << '\n'; // *ite 為 9的原因請看下方註解
    advance(ite, -4); // 需要 #include <iterator>. 向後(往回)4步
    cout << "iterator after moving afterward(-4): " << *ite << '\n';
    /*
        執行 auto ite = v.end()時，iterator 被分配為指向緊跟在vector的最後一個元素之後的 內存位置 ，這 不是vector的有效元素
        嘗試訪問 end() 迭代器指向的元素（即 dereferencing the end() iterator: 將指標所指向的空間內容值傳回去）是未定義的行為，可能會導致意外結果        
        但是，在您的特定情況下，向量的最後一個元素之後的內存位置似乎恰好包含值 9，這就是iterator計算結果為 9 的原因
        務必注意，此行為無法保證，並且可能會因各種因素而異，例如 C++ 標準庫或編譯器的實現 

        因此，最好 Avoid dereferencing the end() iterator。意味著
        --> "不應使用 end() 迭代器直接訪問容器的最後一個元素", 而是將其用作 "檢查迭代器在迭代期間是否已到達容器末尾" 
        例如，在遍歷容器的循環中，通常會將當前迭代器與 end() 迭代器進行比較，以確定循環何時終止。
        在 C++ 中，end() 迭代器指向容器最後一個元素之後的一個。 它用作容器結束的指示器，並且經常在循環中使用以遍歷容器的元素。 
        ---> 總而言之，重要的是將 end() 迭代器"視為容器末尾的標記"，而不是嘗試 訪問 end() 迭代器指向的元素
    */
    // 向後(較佳做法)
    auto iter = v.end(); // 指向尾後元素的迭代器
    while (iter != v.begin()) 
    {
        advance(iter, -1); // 將迭代器向後(往回)移動 1 個位置
        cout << *iter << " "; 
    }
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
    for (auto row : vv) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    
    // 9. 清空
    cout << "\n9. 清空" << '\n';
    v.clear();
    cout << v.size() << endl; // 0
    for_each(v.begin(), v.end(), print); // 已經clear，v.begin()==v.end()，不會有任何結果
    cout << endl;


    // 10. 新知識
    // 1. get_allocator()
    cout << "\n10-1. get_allocator()" << '\n';
    vector<int> vec;
    int * p;

    // 使用vector的分配器為5個元素分配一個空間數組
    p = vec.get_allocator().allocate(5);

    // 在數組上構造數值
    for (int i = 0; i < 5; i++) 
        vec.get_allocator().construct(&p[i],i); //p[0] = 0, p[1] = 1....
    cout << "The allocated array contains:";
    for (int i = 0; i < 5; i++) 
        cout << ' ' << p[i];
    cout << '\n';

    // 銷毀和釋放
    for (int i = 0; i < 5; i++) 
        vec.get_allocator().destroy(&p[i]); // 銷毀數值
    vec.get_allocator().deallocate(p,5); //釋放內存

    // 2. data() -- 返回一個直接指向內存中存儲vector元素位置的指針
    cout << "\n10-2. data()" << '\n';
    vector<int> myvector (5); // 5個int空間
    int* t = myvector.data();
    *t = 10; // myvector[0]
    ++t; // 向前遞進
    *t = 20; // myvector[1]
    t[2] = 100; // t 增加 2，因此它現在指向第四個元素: myvector[3]
    cout << "Myvector contains:";
    for (unsigned i = 0; i < myvector.size(); ++i)
        cout << ' ' << myvector[i];
    cout << '\n';

    return 0;
}
/*
溫馨小教室 ~ ~ ~:
1. for(auto element : MyArray)可以很方便的遍歷元素
	for(auto a:b)中b為一個容器，效果是利用a "遍歷並獲得" b容器中的每一個值，但是a "無法影響" 到b容器中的元素。(以值訪問）
	for(auto& a:b)中加了引用符號(&)，可以對容器中的內容"進行賦值"，即可通過 "對a賦值" 來做到容器b的內容填充。（以引用訪問）
2. for_each:
        template <typename InputIt, typename UnaryFunction>
        UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f);
    -> first 和 last 表示應用函數的元素範圍。 first 代表範圍的開始，last 代表結束（最後一個元素之後的一個）。f 是應用於範圍內每個元素的函數對象。 該函數必須接受範圍內元素類型的單個參數。
*/
