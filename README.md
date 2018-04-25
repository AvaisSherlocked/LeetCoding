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

【215. Kth Largest Element in an Array】
```
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
```
Use quick sort or min heap sort would be efficiency.
Here are some conclusions for things needing attention:
1. Don't forget the juding conditions: "while(i<j)" and also "nums[j]>=val && i<j"
the && i<j is easy to be forgotten.
2. Don't forget to run the while loop for j first(if you choose the left first num as the base num). Because the right part is less than left part, so if i goes first, it may stop at a num smaller than the base number, and swap. e.g. [2,3,3,3,1,1,1]
3. The recursion part, the two index should be [left,i-1] and [i+1,right].

【51.N-QUEENS】

Questions:
```
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
```
Examples:
```
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
```
Solution:
```
class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> V(n,0);
        int curRow = 0;
        solve(res, V, curRow, n);
        return res;
    }
    void solve(vector<vector<string>> &res, vector<int> &V, int curRow, int n){
        for(int i=0;i<n;i++){ // the first loop in row
            V[curRow] = i;
            bool nocrash = true;
            for(int j=0;j<curRow;j++){ //check with former positions
                if(V[j] == i || abs(V[j]-V[curRow]) == abs(j-curRow))  //remember the positive, negative situation
                { nocrash = false; break;}
            }
            
            if(curRow == n-1 && nocrash){
                vector<string> v (n,string(n,'.'));
                for(int i=0;i<n;i++){
                    v[i][V[i]]='Q';
                }
                res.push_back(v);
            }
            
            else if(nocrash == true)
                solve(res,V,curRow+1,n);
        }
    }
};
```
The whole solution is doing following things:

1. For every row in board, judge when set its one col as Q, if there are any crash existing before this row.
2. To make it more clear and efficient, use vector<int>V, to store the j-th n-th col in row. e.g. V[Row] = j.
3. After judging rows one by one, when row comes to n, one solution is reached and push back into vector<vector<string>> res.

Explainations in detail:
 in the main function, input the  parameters for void function "solve". curRow means current row, starts from 0.
```
 vector<vector<string>> solveNQueens(int n)
```
solve() function has three parts:
1. check each row before current row if the position has crash, in order to find the right sequence.
```
for(int i=0;i<n;i++){ // the first loop in row
            V[curRow] = i;
            bool nocrash = true;
            for(int j=0;j<curRow;j++){ //check with former positions
                if(V[j] == i || abs(V[j]-V[curRow]) == abs(j-curRow))  //remember the positive, negative situation
                { nocrash = false; break;}
            }
 ···
 ```
 2. when curRow comes to end, one solution is found and is pushed back. Learn to use "vector<string> v(n,string(n,'.'))" this method of initialization.
 ```
 if(curRow == n-1 && nocrash){
                vector<string> v (n,string(n,'.'));
                for(int i=0;i<n;i++){
                    v[i][V[i]]='Q';
                }
                res.push_back(v);
            }
```
3. To judge next row.
```
 else if(nocrash == true)
       solve(res,V,curRow+1,n);
```

【69.sqrt(x)】

`questions:`
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
e.g.
```
Input: 4
Output: 2
Input: 8
Output: 2
```
My solution:
```
class Solution {
public:
    int mySqrt(int x) {
        long s=x/10;
        while(s*s > x)
            s = s/10;
        if(s*s == x) return s;
        else{
            long l=s;
            long r=s*10;
            if(r==0) r=10;
            s=(s+r)/2;
            while(!(s*s<=x && (s+1)*(s+1)>=x)){
                if(s*s < x){
                    l = s;
                    s = (l+r)/2;
                }
                else if(s*s > x){
                    r = s;
                    s = (l+r)/2;
                }
            }
            if((s+1)*(s+1)==x) return s+1;
            return s;
        }
    }
};
```
First use /10 then use middle value to approaching the target value.
However, it's slower and looks more complicated than following codes:
```
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        long a = x;
        while(r * r > a) {
            r = (r + a / r) / 2;
        }
        return r;
    }
};
```
【70.climbing stairs】

questions:
```
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```
At first I plan to see the rules between n stairs and n-1 stairs. However, when I list out the first 5 items of 1,2,3,4,5 stairs, I found the total sum of distinct ways are of Fibonacci sequence. So just calculate the n-th Fibonacci value can get the problem solved.
There are two ways to solve this:
`Accumulation`
```
class Solution {
public:
    int climbStairs(int n) {
        long sum =0;
        if(n==1) return 1;
        if(n==2) return 2;
        long f=1;
        long s=2;
        for(int i=3;i<=n;i++){
            sum =f+s;
            f = s;
            s = sum;
        }
        return sum;
    }
};
```
`formular`
```
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        double sum = (pow((1+sqrt(5))/2,n+1)-pow((1-sqrt(5))/2,n+1))/sqrt(5);
        return (int)sum;
    }
};
```
the second 'formular' way is faster than the first way: O(1) vs O(n). 
