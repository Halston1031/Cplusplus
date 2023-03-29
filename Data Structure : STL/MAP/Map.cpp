//
//  main.cpp
//  MAP
//
//  Created by 曾億宜 on 2020/4/8.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
▣ class template
    <map>
    std::map
    template < class Key,                                     // map::key_type
               class T,                                       // map::mapped_type
               class Compare = less<Key>,                     // map::key_compare
               class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
               > class map;
 
    ▨ Map
        Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
        In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this
        key. The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:
                                                                typedef pair<const Key, T> value_type;
        Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison
        object (of type Compare).
        map containers are generally slower than unordered_map containers to access individual elements by their key, but they allow the direct iteration on
        subsets based on their order.
        The mapped values in a map can be accessed directly by their corresponding key using the bracket operator ((operator[]).
        Maps are typically implemented as binary search trees.
*/

#include <bits/stdc++.h>
#include <map> //header
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map <int , string> mp; //map <變數型, 變數型> 名稱; （1對1）
    mp[1] = "Monday"; //Key對映value(Key一定不同)，key排序後輸出
    mp[2] = "Tuseday";
    mp[3] = "Wednesday";
    mp[4] = "Thursday";
    mp[5] = "Friday";
    
    cout << mp[1] << endl; //Key1對映其value:Monday
    
    mp.insert(pair<int, string>(6, "Saturday")); //插入
    mp.insert(pair<int, string>(7, "Sunday"));
    
    map <int , string> :: iterator it; //迭代器
    
    for(it = mp.begin(); it != mp.end(); it++) //迭代器輸出map
        cout << it -> first << " " << it -> second << endl;
    
    cout << "Map Size: " << mp.size() << '\n' << endl; //map長度
    
    it = mp.find(5); //用迭代器尋找
    cout << "Find: " << it -> second << '\n' << endl;
    
    mp.erase(5); //迭代器找到後，刪除
    for(it = mp.begin(); it != mp.end(); it++) //刪除後結果
    cout << it -> first << " " << it -> second << endl;
    
    mp.clear(); //清空map
    cout << '\n' << "Map Size (After Clear): " << mp.size() << endl;
    cout << '\n' << "Is empty = " << mp.empty() << endl; //判斷是否為空，是返回1，不是返回0
}

 /*
#include <bits/stdc++.h>
#include <map> //header
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map <string , string> mp;
    mp["apple"] = "蘋果";
    mp["banana"] = "香蕉";
    mp["kiwi"] = "奇異果";
    mp["orange"] = "橘子";
    mp["strawberry"] = "草莓";
    mp.insert(pair<string, string>("peach", "桃子"));
    mp.insert(pair<string, string>("watermelon", "西瓜"));
    map <string , string> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++) //key排序後輸出
        cout << it -> first << " " << it -> second << endl;
}
*/
