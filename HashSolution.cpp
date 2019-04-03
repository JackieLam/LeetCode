//
//  HashSolution.cpp
//  LeetCode
//
//  Created by Jackie Lin on 21/3/2019.
//  Copyright © 2019 Cho-Yeung Lam. All rights reserved.
//

#include "HashSolution.hpp"

vector<int> HashSolution::twoSum(vector<int>& nums, int target)
{
    vector<int> res;
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
        um.insert({target-nums[i], nums[i]});
    }
    
    for (int i = 0; i < nums.size(); i++) {
        auto iter = um.find(nums[i]);
        if (iter != um.end()) {
            res.push_back(iter->second);
            res.push_back(i);
        }
    }
    
    return res;
}
