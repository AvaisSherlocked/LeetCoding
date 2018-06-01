/* questions:
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> count;
        count.push_back(make_pair(1,nums[0]));
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) count[j].first++;
            else {
                count.push_back(make_pair(1,nums[i]));
                j++;
            }
        }
        sort(count.begin(),count.end());
        for(int i=0;i<k;i++)
            res.push_back(count[count.size()-1-i].second);
        return res;
    }
};