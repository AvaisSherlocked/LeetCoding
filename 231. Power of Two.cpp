/*
questions:
Given an integer, write a function to determine if it is a power of two:
Example 1:
Input: 1
Output: true
Example 2:
Input: 16
Output: true
Example 3:
Input: 218
Output: false
*/
// divide
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n == n/2*2 && n!=0) return isPowerOfTwo(n/2);
        else return false;
    }
};

// bit
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
    }
};
