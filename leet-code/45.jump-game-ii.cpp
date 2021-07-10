#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start

class Solution {
public:
    int memo[10005];

    int rec(vector<int>& arr, int i, int n){
        if (i == n-1){
            return 0;
        }
        if (arr[i] == 0){
            return 999999;
        }
        if (memo[i]) return memo[i];
        int ans = 999999;
        for (int j=1;j <= arr[i] && i+j < n; j++){
                //cout << i << ' ' << j << ' ' << ans << endl;
                ans = min(ans, rec(arr, i+j, n)+1);
                memo[i] = ans;
        }

        return memo[i];
    }

    int jump(vector<int>& nums) {
        
        int ans_ = rec(nums, 0, nums.size());
        return ans_;
    }
};
// @lc code=end

