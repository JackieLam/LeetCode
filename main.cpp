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
#include <algorithm>
#include "SortingSolution.h"
#include "StringSolution.h"
#include "BinaryTree.h"
#include "OtherSolution.h"
#include "LinkListSolution.hpp"
using namespace std;

string strSort(string s) {
    int counter[26] = {0};
    for (char c : s) {
        counter[c - 'a']++;
    }
    string t;
    for (int c = 0; c < 26; c++) {
        t += string(counter[c], c + 'a');
    }
    return t;
}


string minWindow(string s, string t)
{ // LeetCode: 76
    //S = "ADOBECODEBANC", T = "ABC"
    
    int ans[] = {0,0,INT_MAX}; // beg, end, length
    int l = 0;
    int r = 0;
    int required = 0;
    int formed = 0;
    int m = s.length();
    int n = t.length();
    if (m < n)
        return "";
    unordered_map<char, int> dictT;
    unordered_map<char, int> windowsCount;
    
    // init
    for (int i = 0; i < t.length(); ++i) {
        windowsCount[t[i]] = 0;
        if (dictT.find(t[i]) == dictT.end())
            dictT[t[i]] = 1;
        else
            dictT[t[i]]++;
    }
    required = dictT.size();
    
    while (r < m) {
        if (dictT.find(s[r]) != dictT.end()) {
            windowsCount[s[r]]++;
            if (windowsCount[s[r]] == dictT[s[r]])
                formed++;
        }
        
        if (formed == required) {
            if (r - l + 1 < ans[2]) {// done
                cout << l << " " << r << " " << r - l + 1 << endl;
                ans[0] = l, ans[1] = r, ans[2] = r - l + 1;
            }
            
            while (l < r) { // bug: while outside of if
                if (dictT.find(s[l]) != dictT.end()) {
                    windowsCount[s[l]]--;
                    if (windowsCount[s[l]] == (dictT[s[l]] - 1)) { // fix
                        formed--;
                        //                        l++; // bug: didn't have this line
                        cout << "break " << l << " " << r << " " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
                        break;
                    }
                }
                l++;
            }
            
            if (r - l + 1 < ans[2]) { // bug: if was in the while loop, wrong pos
                ans[0] = l, ans[1] = r, ans[2] = r - l + 1;
            }
            l++;
        }
        
        r++;
    }
    
    if (ans[2] == INT_MAX)
        return "";
    return s.substr(ans[0], ans[2]);
}

void NSum(vector<int> &A, int N, int target, vector<int> sol, vector<vector<int>> &res)
{ // Bug: not passed: LeetCode 18
    if (N > A.size() || N < 2)
        return;
    
    if (N == 2) {
        unordered_map<int, int> um;
        for (int i = 0; i < A.size(); ++i) {
            if (um.find(target - A[i]) == um.end())
                um.insert({ A[i], target - A[i] });
            else {
                sol.push_back(target - A[i]);
                sol.push_back(A[i]);
                res.push_back(sol);
                return;
            }
        }
        return;
    }
    else {
        for (int i = 0; i < A.size(); i++) { // length
            if (i > 0 && A[i] == A[i - 1])
                continue;
            vector<int> Asub;
            for (int j = i + 1; j < A.size(); j++)
                Asub.push_back(A[j]);
            sol.push_back(A[i]);
            NSum(Asub, N - 1, target - A[i], sol, res);
            sol.pop_back();
        }
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> sol;
    NSum(nums, 4, target, sol, res);
    
    return res;
}

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};



int maxPoints(vector<Point>& points)
{
    unordered_map<double, int> um; // count same points on a line
    int self = 1;
    int n = points.size();
    int res = 0;
    
    if (n <= 2)
        return n;
    
    // INT_MAX for vertical line
    for (int i = 0; i < n; i++) {
        int local = 0;
        for (int j = i; j < n; j++) {
            if (i == j)
                continue;
            
            double k = 0;
            if (points[j].x == points[i].x && points[j].y == points[i].y) {
                self++;
            }
            else {
                k = (points[j].x == points[i].x) ? INT_MAX :
                (double)((double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x));
                cout << "k :: " << k << endl;
                if (um.find(k) == um.end())
                    um[k] = 1;
                else
                    um[k] += 1;
                local = max(local, um[k]);
            }
        }
        cout << "i :: " << i << " " << local << endl;
        res = max(res, local + self);
        
        self = 1;
        um.clear();
    }
    
    return res;
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if (n == 0) return 0;
    if (triangle[0].size() == 0) return 0;
    
    vector<int> dp(n, 0);
    
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (; j < i; j++) {
            if (j == 0)
                dp[j] = dp[j] + triangle[i][j];
            else
                dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            cout << dp[j] << " ";
        }
        dp[j] = dp[j-1] + triangle[i][j];
        cout << dp[j] << endl;
    }
    
    return *std::max_element(dp.begin(),dp.end());
}

int main(int argc, const char * argv[])
{
    vector<vector<int>>v = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout << minimumTotal(v);

    return 0;
}
