//
//  11.cpp
//
//  Created by Ava on 2018/5/8.
//  Copyright © 2018年 Ava. All rights reserved.
//
//360 ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> pro(height.size(),0);
        for(int i=0;i<height.size();i++){
            if(height[i]==0) continue;
            int l=0;
            int r=height.size()-1;
            while(height[l]<height[i] && l<i) l++;
            while(height[r]<height[i] && r>i) r--;
            pro[i] = max(i-l,r-i)*height[i];
        }
        sort(pro.begin(),pro.end());
        return pro.back();
    }
};

// 22 ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int max = 0;
        while(l < r){
            int pro = min(height[l],height[r])*(r-l);
            if(pro > max)
                max = pro;
            if(height[l] > height[r])
                r--;
            else
                l++;
        }
        return max;
    }
};
