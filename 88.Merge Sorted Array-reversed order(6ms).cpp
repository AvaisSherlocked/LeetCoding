//
//  Merge Sorted Array.cpp
//  Created by Ava on 2018/4/20.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int Index1=m-1,Index2=n-1,Total = m+n-1;
        while(Index1>=0 && Index2>=0){
            if(nums1[Index1] <= nums2[Index2])
                nums1[Total--] = nums2[Index2--];
            else
                nums1[Total--]=nums1[Index1--];
        }
        while(Index2>=0)
            nums1[Total--] = nums2[Index2--];
    }
};
