//
//  3Sum.cpp
//  Created by Ava on 2018/4/8.
//  Copyright © 2018年 Ava. All rights reserved.
/****** Summary *****/
//The simply traversal algorithm costs O(n3)?
// By sorting it first, skipping the duplicate one, and
// setting the third number k as nums.size()-1, narrow down from two sides
// the repeating searching is cut down.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol; // storing the solution
        vector<int> A(3,0);
        
        if(nums.size()<3)
            return sol;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;   //the second num
            int k=nums.size()-1;  //the third num
            int aim = -nums[i];
            while(j<k){  //careful about the judge condition
                int sum = nums[j]+nums[k];
                while(sum < aim && j+1<k) {  // keep j smaller than k
                    sum += nums[j+1]-nums[j];  // almost forget this step!
                    j++;
                }
                while(sum > aim && k-1>j){
                    sum += nums[k-1]-nums[k];
                    k--;
                }
                if(sum == aim){
                    A[0]=nums[i];
                    A[1]=nums[j];
                    A[2]=nums[k];
                    sol.push_back(A);  // add into the solution
                }
                while(j+1<k && nums[j+1]==nums[j]) j++;  //skip the duplicate
                j++; //continue to see if inside has right value too
            }
            while(i+1<nums.size()-2 && nums[i+1]==nums[i]) i++;  //skip the duplicate
        }
        return sol;
    }
};
