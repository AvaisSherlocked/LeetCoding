# LeetCoding
My solutions for leetcode with explanations

【148.Sort List】
```
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
    ListNode* sortList(ListNode* head) {
    
    }
};
```
Requirement: Sort a linked list in O(n log n) time using constant space complexity.
要求：将链表以O(1)的空间复杂度，O(nlogn)空间复杂度，进行排序。

Solution: 
1. Find the middle of list and to separate the list into two parts (Recursion).
2. Compare the two part of lists and merge them together, while use recursion, these two parts of lists should have been sorted.

解题思路：
1. 找到链表的中间位置，将其拆分为前后两部分。（递归）
2. 通过对比两部分的链表，将其按值的大小合并为一个链表。且在递归情况下，前后两个链表为已经排序的链表。

These two steps are implemented by two functions 这两个步骤分别通过两个函数实现
The first is sortList(ListNode* head), which is used to seperate the list in 'two' parts，acutually it's every node

首先是第一个函数：sortList(ListNode* head)
其目的是为list划分为前后"两"部分l1,l2,以递归的形式划分到每一个node
```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        
        // part 1: to sortList in binary tree order
        ListNode* slow = head;
        ListNode* fast = head->next; //it's important to set the faster in the next position, to avoid the single val list
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;   //fast is the latter part of list
        slow->next = nullptr;  //to cut down the latter part for head
        return MergeList(sortList(head),sortList(fast));
    }
```
The second function is MergeList(ListNode* l1, ListNode* l2), in order to merge two input lists according to the val.

第二个函数为MergeList(ListNode* l1, ListNode* l2)
其目的是为了将传入的两个list按数值大小顺序合并
```
// part 2: merge the input 2 lists
    ListNode* MergeList(ListNode* l1,ListNode* l2){
        ListNode* cur = new ListNode(0);
        ListNode* pcur = cur;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                cur->next =l1;
                l1 = l1->next ;
            }
            else{
                cur->next =l2;
                l2 = l2->next ;
            }
            cur= cur->next;
        }
        if(l1 != nullptr)
            cur->next = l1;
        if(l2 != nullptr)
            cur->next = l2;
        return pcur->next;
    }
```
Things to be learned 学到知识点：
1. Use fast (jump by 2) and slow (jump by 1) two pointers to find the middle of list.
2. Use recursion to merge nodes from only two to the whole half part of the list.


【100.Same Tree】
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    }
};
```
Although this is an easy problem, there are many matters needing attention.
It's about the "stop point": when to stop the recursion would be accurate and effciency too?
My habit of writting recursion is to write the body of recursion first, then add in judgement conditions.
For this problem, Tree, so the recursion is like below:
```
bool Left=true;
bool Right=true;
if(p->left || q->left) Left = Left = isSameTree(p->left,q->left);
if(p->right || q->right) Right = isSameTree(p->right,q->right);
return(Left && Right);
```
Now, consider the conditions below:
1. p's val differs from q's val;
2. p and q may both be nullptr;
3. one of p and q is nullptr;
```
if(p==nullptr && q==nullptr) return true;
if(!((p==nullptr && q==nullptr)||(p!=nullptr && q!=nullptr))) return false;
if(p->val != q->val) return false;
```
So the final solution is:
```
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(!((p==nullptr && q==nullptr)||(p!=nullptr && q!=nullptr))) return false;
        if(p->val != q->val) return false;
        bool Left = true;
        bool Right = true;
        if(p->left || q->left){  // incase that p only has left and q only has right
            Left = isSameTree(p->left,q->left);
        }
        if(p->right || q->right) {
            Right = isSameTree(p->right,q->right);
        }
        return(Left && Right);
    }
```

【35.Search In Insertion Position】
For sorted array, the dichotomy should be considered firstly.
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()||target<nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        
        int first=0,second=nums.size()-1;
        int mid = first+second >>1;
        while(first<=second){
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) first = mid+1;
            if(nums[mid]>target) second = mid-1;
            mid = first+second >>1; // cool~ bit operation, >>1 means move right 1 bit./ Euqals to divide by 2
        }
        return first;
    }
};
```
The bit operation '>> x ' means moving right x bits (x is constant).
