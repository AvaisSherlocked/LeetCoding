//
//  215.cpp
//
//  Created by Ava on 2018/4/20.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSort(nums,0,nums.size()-1,nums.size()-k);  // the quicksort is min first, so it's nums.size()-k
    }
    
    int QuickSort(vector<int>& nums, int left, int right, int k){
        int val = nums[left];  //i:begin, j:end
        if(left == right) return val;
        int i = left;
        int j = right;
        while(i<j){
            // it's very very important to let j go first. And also don't forget the '&& i<j'
            while(nums[j]>=val && i<j) j--;
            while(nums[i]<=val && i<j) i++;
            if(i>=j) break;
            int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
        }
        nums[left] = nums[j];
        nums [j] = val;
        if(k == i) return nums[i];
        else if(k < i) return QuickSort(nums,left,i-1,k); // i-1
        else return QuickSort(nums,i+1,right,k); //i+1
        
    }
};
