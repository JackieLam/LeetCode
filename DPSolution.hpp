//
//  DPSolution.hpp
//  LeetCode
//
//  Created by Jackie Lin on 17/3/2019.
//  Copyright © 2019 Cho-Yeung Lam. All rights reserved.
//

#ifndef DPSolution_hpp
#define DPSolution_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class DPSolution {
public:
    DPSolution();
    ~DPSolution();
    int LCS(const char *s1, const char *s2);
    int LCSubstring(string A, int n, string B, int m);
};

#endif /* DPSolution_hpp */
