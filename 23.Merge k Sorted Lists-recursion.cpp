//
//  23.cpp
//
//  Created by Ava on 2018/4/16.
//  Copyright © 2018年 Ava. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // when lists is empty, return null----------------part 1
        int n=lists.size();
        if(n==0) return NULL;
        
        //erase all null listnodes-------------part 2
        //(because it's legal to contain null ListNodes)
        vector<ListNode*>::iterator iter=lists.begin();
        int i=0;
        while(!lists.empty()){
            iter = lists.begin();
            if(lists[i]==nullptr) {lists.erase(iter+i);if(i>0)i--;}
            else i++;
            if(i==lists.size()) break;
        }
        
        //find the minimum val in which position of lists --------part 3
        if(lists.empty()) return NULL;
        ListNode* pmin = lists[0];// initialize pmin
        int minI=0; // record the index
        
        for(int i=0;i<n;i++){
            if(lists[i] == NULL) continue; // incase of the null listnode
            if(pmin->val > lists[i]->val){
                pmin = lists[i];
                minI = i;
            }
        }
        
        // the revision of the lists, to cut out the pmin---------part4
        if(pmin == nullptr && n==1) return NULL;
        // revise the lists, pick out the pmin
        if(lists[minI]->next == NULL){  // if the lists[minI] has only one node, save this node and erase it
            iter += minI;
            lists.erase(iter);
        }
        else{ // save the node and let the next be the head in the minI position
            ListNode* pnew = pmin->next;
            lists[minI] = pnew;
        }
        
        // the recursion part -----------------part 5
        pmin->next = mergeKLists(lists);
        return pmin;
        
    }
};
