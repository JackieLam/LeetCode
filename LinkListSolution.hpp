//
//  LinkListSolution.hpp
//  LeetCode
//
//  Created by Jackie Lin on 17/3/2019.
//  Copyright © 2019 Cho-Yeung Lam. All rights reserved.
//

#ifndef LinkListSolution_hpp
#define LinkListSolution_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkListSolution
{
public:
    LinkListSolution();
    ~LinkListSolution();
    ListNode* rotateRight(ListNode* head, int k);
    ListNode * ReverseList(ListNode* head);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    bool hasCycle(ListNode *head); // hash || fast&slow pointer
};


#endif /* LinkListSolution_hpp */
