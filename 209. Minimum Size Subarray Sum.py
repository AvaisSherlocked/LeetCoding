'''
questions:
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: [2,3,1,2,4,3], s = 7
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
'''
class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        #O(n)
        beg = total = 0
        min = len(nums)+1
        for end,n in enumerate(nums):    # remember the use of enumerate
            total += n
            while total>=s:             # no matter while or if, no '(,)'
                if end-beg < min:
                    min = end-beg+1
                total -= nums[beg]
                beg +=1
                
        return min if min<=len(nums) else 0.  # no ?:, but if else