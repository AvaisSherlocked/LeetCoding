//
//  52.cpp
//
//  Created by Ava on 2018/4/25.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int totalNQueens(int n) {
        int sol=0;
        vector<int> V(n,0);
        solve(sol,V,0,n);
        return sol;
    }
    void solve(int &sol, vector<int> &V, int curRow, int n){
        for(int i=0;i<n;i++){ // the first loop in row
            V[curRow] = i;
            bool nocrash = true;
            for(int j=0;j<curRow;j++){ //check with former positions
                if(V[j] == i || abs(V[j]-V[curRow]) == abs(j-curRow))  //remember the positive, negative situation
                { nocrash = false; break;}
            }
            
            if(curRow == n-1 && nocrash){
                sol++;
            }
            
            else if(nocrash == true)
                solve(sol,V,curRow+1,n);
        }
    }
};
