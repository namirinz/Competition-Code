#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    long long unsigned int memo[10000];

    long long unsigned int bottom_up(int n){
        memo[0] = 1;
        memo[1] = 1;
        for (int i=2;i<=n;i++){
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }

    long long unsigned int rec(int n){
        long long unsigned int ans = 0;
        if (n == 0 || n == 1){
            return 1;
        }

        if (memo[n]) return memo[n];

        ans += rec(n-1) + rec(n-2);
        return memo[n] = ans;
    }

    int climbStairs(int n){
        long long unsigned int ans = bottom_up(n);
        cout << "Answer " << ans;
        return ans;
    }
};
// @lc code=end

