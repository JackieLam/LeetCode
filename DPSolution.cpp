//
//  DPSolution.cpp
//  LeetCode
//
//  Created by Jackie Lin on 17/3/2019.
//  Copyright © 2019 Cho-Yeung Lam. All rights reserved.
//

#include "DPSolution.hpp"

DPSolution::DPSolution(){}
DPSolution::~DPSolution(){}

int DPSolution::LCS(const char *s1, const char *s2)
{
    size_t m = strlen(s1);
    size_t n = strlen(s2);
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) // bug: have to be i-1 and j-1
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[m][n];
}

int DPSolution::LCSubstring(string A, int n, string B, int m)
{
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    
    int ret = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ret = max(ret, dp[i][j]);
            }
    
    return ret;
} // 可以优化至O(N)或O(1)
