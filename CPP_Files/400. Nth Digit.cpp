/* questions:
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9) return n;
        long m=n;
        int i=1;
        while(m>0){
            m -= i*9*pow(10,i-1);
            i++;
        }
        i--;
        m += i*9*pow(10,i-1);
        int res=0;
        if(m%i==0){
            res = (m/i)%10-1;
            if(res<0) res=9;
        }
        else if(m%i!=0){
            int r = m%i;  // the position in target number
            int d = m/i;  
            int t = pow(10,i-1)+d;  // locate the target number
            res = (int)(t/pow(10,i-r))%10;
        }
        return res;
    }
};