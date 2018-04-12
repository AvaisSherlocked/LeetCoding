//
//  22.cpp

//  Created by Ava on 2018/4/12.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
    vector<string> sol;
public:
    vector<string> generateParenthesis(int n) {
        int L=n; // the number of Left parenthesis needing to be add in
        int R=0; // when add one left parenthesis, one right parenthesis needs to be count in
        string s="";
        GP(s,L,R);
        return sol;
    }
    void GP(string s, int L,int R){
        if(L==0 && R==0){
            sol.push_back(s);
            return;
        }
        if(L>0) GP(s+'(',L-1,R+1); // it's very important that --L, not L--
        if(R>0) GP(s+')',L,R-1);
    }
    
};
