//
//  HashSolution.hpp
//  LeetCode
//
//  Created by Jackie Lin on 21/3/2019.
//  Copyright © 2019 Cho-Yeung Lam. All rights reserved.
//

#ifndef HashSolution_hpp
#define HashSolution_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class HashSolution {
public:
    HashSolution();
    ~HashSolution();
    
    vector<int> twoSum(vector<int>& nums, int target);
    bool isValidSudoku(vector<vector<char>>& board);
};

#endif /* HashSolution_hpp */
