//
//  main.cpp
//  Pair
//
//  Created by 曾億宜 on 2020/4/10.
//  Copyright © 2020 曾億宜. All rights reserved.
//
/*
 ▣ class template
     <utility>
     std::pair
     template <class T1, class T2> struct pair;
 
        ▨ Pair of values
            This class couples together a pair of values, which may be of different types (T1 and T2). The individual values can be accessed through its public members
            first and second.
            Pairs are a particular case of tuple.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    //1. 初始
    cout << "1. 初始" << endl;
    pair<string, int> p;
    p.first = "Chinese";
    p.second = 5;
    cout << p.first << " " << p.second << endl;
    cout << endl;
    
    //2.增加元素
    cout << "2. 增加元素" << endl;
    p = make_pair("Mathematics",55);
    cout << p.first << " " << p.second << endl;
    
    //多個形式相同的pair
    typedef pair<string,int> pa;
    pa a("English",555);
    pa b;
    b = make_pair("Art",5);
    cout << a.first << " " << a.second << endl;
    cout << b.first << " " << b.second << endl;
    
    //作為map的鍵值對來進行插入
    map<string,int> mp;
    mp.insert(make_pair("Science",5)); //排序後才插入
    mp.insert(pair<string,int>("Music",10));
    for(map<string, int>::iterator it = mp.begin();it != mp.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    
    //3. 取值
    cout << "3. 取值" << endl;
    cout << "pair-b contains: ";
    cout << get<0>(b) << " and " << get<1>(b) << '\n'; //b = ("Art",5);
    cout << endl;

    //4. 交換
    cout << "4. 交換" << endl;
    swap (a,b); //原始：a = ("English",555)，b = ("Art",5)
    cout << "pair-a contains: " << a.first << " and " << a.second << '\n'; //pair-a和pair-b交換，a = ("Art",5)
    cout << "pair-b contains: " << b.first << " and " << b.second << '\n'; //pair-b和pair-a交換，b = ("English",555)
    cout << endl;

}


