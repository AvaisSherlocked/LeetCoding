//
//  73.cpp
//
//  Created by Ava on 2018/4/27.
//  Copyright © 2018年 Ava. All rights reserved.
//

//66ms
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        vector<int> x,y;  // to record the zero elements
//        int m=matrix.size();
//        int n=matrix[0].size();
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                if(matrix[i][j]==0){
//                    x.push_back(i);
//                    y.push_back(j);
//                }
//            }
//        }
//        /////set each col and row to be zero
//        for(int j=0;j<n;j++){
//            for(int i=0;i<x.size();i++)
//                matrix[x[i]][j]=0;
//        }
//        for(int i=0;i<m;i++){
//            for(int j=0;j<y.size();j++)
//                matrix[i][y[j]]=0;
//        }
//    }
//};


// 55 ms  --- use set to replace recording vector

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> x,y;  // to record the zero elements
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        /////set each col and row to be zero
        for(int j=0;j<n;j++){
            for(auto i=x.begin();i!=x.end();i++)
                matrix[*i][j]=0;
        }
        for(int i=0;i<m;i++){
            for(auto j=y.begin();j!=y.end());j++)
                matrix[i][*j]=0;
        }
    }
};
