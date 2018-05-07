//
//  42.cpp
//
//  Created by Ava on 2018/5/8.
//  Copyright © 2018年 Ava. All rights reserved.
//
/*
 Question: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
    The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 */

//300 ms
class Solution {
public:
    int trap(vector<int>& height) {
        int One_stat=1,Total_stat=0;
        int s = height.size();
        while(One_stat>0){
            One_stat = 0;
            for(int i=0;i<s;i++){
                if(i-1>=0 && i+1<s && height[i]<height[i-1] && height[i]<height[i+1]){
                    int stat=0;
                    stat += min(height[i-1],height[i+1])-height[i];
                    height[i] += min(height[i-1],height[i+1])-height[i];
                    One_stat += stat;
                }
                else if(i-1>=0 && height[i]<height[i-1]){
                    int k=1;
                    int stat=0;
                    while(i+k<s && height[i+k]==height[i]) k++;
                    if(i+k==s) break;
                    if(height[i+k]>height[i]){
                        stat += min(height[i-1],height[i+k])-height[i];
                        for(int m=0;m<k;m++)
                            height[i+m] += min(height[i-1],height[i+k])-height[i];
                    }
                    One_stat += stat;
                }
            }
            Total_stat += One_stat;
        }
        return Total_stat;
    }
};

// 15ms
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int res=0;
        int leftM=0,rightM=0;
        while(left <= right){
            if(height[left]<=height[right]){
                if(height[left]>leftM) leftM = height[left];
                else res += leftM - height[left];
                left ++;
            }
            else{
                if(height[right]>rightM) rightM = height[right];
                else res += rightM - height[right];
                right --;
            }
        }
        return res;
    }
};
