/*questions:
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/
//sol1
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==0) return false;
        if(num==1) return true;
        int tmp = num;
        if(num>0 && !(num &(num-1))){
            while(tmp>4) tmp = tmp>>2;
            if(tmp == 4) return true;
            else return false;
        }
        else return false;
    }
};

/* sol2*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && !(num&(num-1)) && (num-1)%3==0;
    }
};