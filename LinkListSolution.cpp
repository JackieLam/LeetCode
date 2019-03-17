//
//  LinkListSolution.cpp
//  LeetCode
//
//  Created by Jackie Lin on 17/3/2019.
//  Copyright © 2019 Cho-Yeung Lam. All rights reserved.
//

#include "LinkListSolution.hpp"

LinkListSolution::LinkListSolution()
{
}

LinkListSolution::~LinkListSolution()
{
}

ListNode* LinkListSolution::rotateRight(ListNode* head, int k)
{
    if (head == NULL) return NULL;
    ListNode *node = head;
    int len = 1;
    while (node->next != NULL) {
        len++;
        node = node->next;
    }
    node->next = head;
    
    node = head;
    for (int i = 1; i < len-k%len; i++)
        node = node->next;
    
    head = node->next;
    node->next = NULL;
    
    return head;
}

ListNode * LinkListSolution::ReverseList(ListNode* head)
{
    if (head == NULL) return NULL;
    ListNode *pre = NULL;
    ListNode *cur = head;
    ListNode *nxt = cur->next;
    cur->next = pre;
    
    while (nxt != NULL) {
        pre = cur;
        cur = nxt;
        nxt = nxt->next;
        cur->next = pre;
    }
    
    return cur;
}

ListNode* LinkListSolution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (!l1) return l2;
    if (!l2) return l1;
    if (!l1 && !l2) return NULL;
    
    ListNode *head = nullptr;
    if (l1->val <= l2->val) head = l1;
    else head = l2;
    
    ListNode *node = new ListNode(-1);
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            node->next = l1;
            l1 = l1->next;
        }
        else {
            node->next = l2;
            l2 = l2->next;
        }
        
        node = node->next;
        node->next = NULL;
    }
    while (l1) {
        node->next = l1;
        l1 = l1->next;
        node = node->next;
    }
    while (l2) {
        node->next = l2;
        l2 = l2->next;
        node = node->next;
    }
    
    return head;
}

bool LinkListSolution::hasCycle(ListNode *head) {
    unordered_set<ListNode *> us;
    while (head != NULL) {
        if (us.find(head) == us.end())
            us.insert(head);
        else
            return true;
        head = head->next;
    }
    
    return false;
}
