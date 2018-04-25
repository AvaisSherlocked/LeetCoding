//
//  62.cpp
//
//  Created by Ava on 2018/4/25.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        // calculate the random sequence as select n-1 steps from m+n-2 steps
        long res=1,d=1;
        if(n>m){ int t=n;n=m;m=t;}  //if n>m, then swap them
        for(int i=1;i<n;i++){
            res = res*(m+n-1-i);
            d = d*(n-i);
        }
        // you can't do res=res*(m+n-1-i)/(n-i), because it may cause error when meet with "3/2=1"
        return res/d;
    }
};


// The iterate way also works, but exceed the time limit

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int count=0;
//         Count(m-1,n-1,0,0,count);
//         return count;
//     }
//     void Count(int m, int n, long i,long j, int & count){
//         if(i == m && j==n)  count++;
//         if(i<m) Count(m,n,i+1,j,count);
//         if(j<n) Count(m,n,i,j+1,count);
//     }
// };
