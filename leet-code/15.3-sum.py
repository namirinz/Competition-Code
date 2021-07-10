#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = set()
        def rec(arr, i):
            if len(arr) == 3 and sum(arr) == 0:

                ans.add(tuple(sorted(arr)))
            elif i < 0:
                return
            elif len(arr) < 3:
                arr.append(nums[i])
                rec(arr, i-1)
                arr.pop()
                rec(arr, i-1)
    
        rec(list([]), len(nums)-1)
        output = [list(tuple_item) for tuple_item in list(ans)]
        print(output) 
        return output

            
# @lc code=end

