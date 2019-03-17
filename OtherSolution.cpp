//
//  OtherSolution.cpp
//  LeetCode
//
//  Created by Jackie Lin on 16/3/2019.
//  Copyright © 2019 Cho-Yeung Lam. All rights reserved.
//

#include "OtherSolution.h"

bool OtherSolution::binarySearchMatrix(const vector<vector<int>> &mat, int t)
{
    int m = (int)mat.size();
    if (m == 0) return false;
    int d = (int)mat[0].size();
    if (d == 0) return false;
    
    int lo = 0;
    int hi = m * d - 1;
    int mid = (lo + hi) / 2;
    
    while (lo < hi) {
        if (mat[mid / d][mid % d] == t) return true;
        else if (mat[mid / d][mid % d] > t) {
            hi = mid;
            mid = (lo + hi) / 2;
        }
        else {
            lo = mid;
            mid = (lo + hi) / 2;
        }
    }
    
    return false;
};
