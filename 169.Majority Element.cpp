//
//  169.cpp
//
//  Created by Ava on 2018/5/4.
//  Copyright © 2018年 Ava. All rights reserved.
//

//24 ms The most ordinary method, traverse --O(n^2)
 class Solution {
 public:
     int majorityElement(vector<int>& nums) {
         vector<int> val;
         vector<int> count;
         int h = nums.size()/2;
         for(int i=0;i<nums.size();i++){
             if(i==0){
                 val.push_back(nums[i]);
                 count.push_back(1);}
             else{
                 int j=0;
                 while(j<val.size()){
                     if(val[j]==nums[i]){
                         count[j]++;
                         if(count[j]>h) return nums[i];
                         break;
                     }
                     j++;
                 }

                 if(j==val.size())
                 {
                     val.push_back(nums[i]);
                     count.push_back(1);
                 }
             }
         }
         int max=0,index=0;
         for(int i=0;i<count.size();i++){
             if(count[i]>max){
                 max = count[i];
                 index = i;
             }
         }
         return val[index];
     }
 };

 //23 ms  it's said should be O(nlogn)
 class Solution {
 public:
     int majorityElement(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         return nums[nums.size()/2];
     }
 };

// O(n) since the majority is more than n/2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,val=nums[0];
        for(int i=1;i<nums.size();i++){
            if(val == nums[i]) count++;
            else if(count==0) val = nums[i];
            else count--;
        }
        return val;
    }
};
