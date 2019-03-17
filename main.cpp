//
//  main.cpp
//  LeetCode
//
//  Created by Jackie Lin on 12/6/2018.
//  Copyright © 2018 Cho-Yeung Lam. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "SortingSolution.h"
#include "StringSolution.h"
#include "BinaryTree.h"
#include "OtherSolution.h"
#include "LinkListSolution.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    char *pStr = const_cast<char *>("12345");
    string str = "12345";
    cout << sizeof(pStr) / sizeof(*pStr) << endl;
    cout << strlen(pStr) << endl;
    
    for (int i = 0; i < 5; i++)
        cout << str[i] << " ";
    cout << endl;
    
    SortingSolution sortSol;
    StringSolution stringSol;
    
    vector<int> v{3,5,1,7,2,8,0,9,4};
    sortSol.quick_sort(v);
    
    for (auto iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    
    vector<string> res;
    char pat = ' ';
    res = stringSol.split3("They are student", pat);
    for (auto iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << "-";
    cout << endl;
    
    
    char sentence[] = "they are student";
    stringSol.reverseSentence(sentence);
    for (int i = 0; i < strlen(sentence); i++)
        cout << sentence[i];
    cout << endl;
    
    return 0;
}
