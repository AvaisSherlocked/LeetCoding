//
//  135.cpp
//  test3
//
//  Created by Ava on 2018/5/17.
//  Copyright © 2018年 Ava. All rights reserved.
//
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 
 e.g.1
 Input: [1,0,2]
 Output: 5
 Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 e.g.2
 Input: [1,2,2]
 Output: 4
 Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
 The third child gets 1 candy because it satisfies the above two conditions.
*/

//trully made me disgusted
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0) return 0;
        if(ratings.size()==1) return 1;
        vector<int> res(ratings.size(),0);
        int min=1,sum=0;
        
        // find the lowest one
        for(int i=0;i<ratings.size();i++){
            if(i==0 && ratings[i]<=ratings[i+1])
            { res[i]=1; sum += 1;}
            else if(i==ratings.size()-1 && ratings[i]<=ratings[i-1])
            { res[i]=1; sum += 1;}
            else if(ratings[i]<=ratings[i+1] && ratings[i]<=ratings[i-1])
            { res[i]=1; sum += 1;}
        }
        //rightward, begin at 1
        for(int i=1;i<ratings.size();i++){
            if(res[i] == 0 && ratings[i]>ratings[i-1]){
                if(i+1<ratings.size() && ratings[i]>ratings[i+1])
                    continue;   // very important--let go of the peak value
                res[i] = res[i-1]+1;
                sum += res[i];
            }
        }
        //leftward, begin at ratings.szie()-2
        for(int i=ratings.size()-2;i>=0;i--){
            if(res[i] == 0 && ratings[i]>=ratings[i+1]){
                if(i-1>=0 && ratings[i]>=ratings[i-1]){
                    if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1])
                        res[i] = max(res[i+1],res[i-1])+1;
                    else if(ratings[i] == ratings[i-1])
                        res[i] = res[i+1]+1;
                    else if(ratings[i] == ratings[i+1])
                        res[i] = res[i-1]+1;
                    // very important--get the max from two sides of the peak value
                    sum += res[i];
                    continue;
                }
                res[i] = res[i+1]+1;
                sum += res[i];
            }
        }
        
        return sum;
    }
};
