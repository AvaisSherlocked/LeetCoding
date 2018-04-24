//
//  51.cpp
//
//  Created by Ava on 2018/4/25.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> V(n,0);
        int curRow = 0;
        solve(res, V, curRow, n);
        return res;
    }
    void solve(vector<vector<string>> &res, vector<int> &V, int curRow, int n){
        for(int i=0;i<n;i++){ // the first loop in row
            V[curRow] = i;
            bool nocrash = true;
            for(int j=0;j<curRow;j++){ //check with former positions
                if(V[j] == i || abs(V[j]-V[curRow]) == abs(j-curRow))  //remember the positive, negative situation
                { nocrash = false; break;}
            }
            
            if(curRow == n-1 && nocrash){
                vector<string> v (n,string(n,'.'));
                for(int i=0;i<n;i++){
                    v[i][V[i]]='Q';
                }
                res.push_back(v);
            }
            
            else if(nocrash == true)
                solve(res,V,curRow+1,n);
        }
    }
};
