#questions:
'''
Given two strings s and t , write a function to determine if t is an anagram of s.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false
'''

class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # sol1: dict
        A,B = {},{}
        for item in s:
            A[item] = A.get(item,0)+1
        for item in t:
            B[item] = B.get(item,0)+1
        return A==B
        
        # sol2: array
        A,B = [0]*26,[0]*26
        for item in s:
            A[ord(item)-ord('a')] +=1
        for item in t:
            B[ord(item)-ord('a')] +=1
        return A==B
        
        # sol3: string
        return sorted(s)==sorted(t)