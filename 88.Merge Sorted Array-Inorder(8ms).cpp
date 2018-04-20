//
//  88.cpp
//
//  Created by Ava on 2018/4/20.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int Index1=0,Index2=0;
        while(Index1<m && Index2<n){
            if(nums1[Index1] <= nums2[Index2]) Index1++;
            else {
                int LastPlace=m;
                while(LastPlace > Index1){
                    nums1[LastPlace]=nums1[LastPlace-1];
                    LastPlace--;
                }
                nums1[Index1] = nums2[Index2];
                Index1++; Index2++;
                m++;
            }
        }
        while(Index2<n){
            nums1[Index1] = nums2[Index2];
            Index1++; Index2++;
        }
        
    }
};
