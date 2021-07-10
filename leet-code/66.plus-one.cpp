#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int arr_length = digits.size();
        int num_add;
        bool more_plus = true;
        vector<int> ans_arr;

        for (int i=arr_length-1; i>=0; i--){
            num_add = digits[i];
            num_add += more_plus;
            
            if (num_add >= 10){
                num_add = num_add % 10;
                more_plus = true;
            }else {
                more_plus = false;
            }

            ans_arr.push_back(num_add);
        }

        if (more_plus){
            ans_arr.push_back(1);
        }

        reverse(ans_arr.begin(), ans_arr.end());
        return ans_arr;
    }
};
// @lc code=end

