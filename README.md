# LeetCoding
My solutions for leetcode with explanations

【148.Sort List】

questions  
`Sort a linked list in O(n log n) time using constant space complexity.`  
e.g.1  
Input: 4->2->1->3  
Output: 1->2->3->4  

e.g.2  
Input: -1->5->3->4->0  
Output: -1->0->3->4->5  

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
```C++
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
```C++
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
```C++
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
```C++
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
```C++
if(p==nullptr && q==nullptr) return true;
if(!((p==nullptr && q==nullptr)||(p!=nullptr && q!=nullptr))) return false;
if(p->val != q->val) return false;
```
So the final solution is:
```C++
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
```C++
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
```C++
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
```C++
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
```C++
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
```C++
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
```C++
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
```C++
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
This `r = (r + a / r) / 2` can work out is because it shrink according to the r you use. Suppose r^2 > a, then r > a/r must be true. Use the middle value of r and a/r would approach the right value step by step.
【70.climbing stairs】

questions:
```C++
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
```C++
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
```C++
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

【46. Permutations】--Conclusion according to backtracking
`question`
```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```
This problem can be solved by both iteratively and backtracking.

`Iteratively:`
`Choose the element one by one. Insert it to each available position.`
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int s=nums.size();
        vector<vector<int>> res;
        if(s==0) return res;
        res.push_back(vector<int>(1,nums[0]));
        for(int i=1;i<s;i++){
            Insertion(res,nums[i]);
        }
        return res;
    }
    void Insertion(vector<vector<int>> &res,int m){
        vector<vector<int>> res2;
        for(int i=0;i<res.size();i++){
            vector<int> item = res[i];
            item.push_back(m); // add in one more element
            res2.push_back(item);
            for(int j=item.size()-1;j>0;j--){ // the insert position is moving forward one by one 
                item[j] = item[j-1];
                item[j-1]=m;
                res2.push_back(item);
            }
        }
        res = res2;
    }
};
```
Time Complexity: O(n^2)
Space Complexity: O(n^2)

`recursively`
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums,0);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &nums, int pos){
        if(pos==nums.size()) {res.push_back(nums);return;}
        for(int i=pos;i<nums.size();i++){
            swap(nums[pos],nums[i]);
            helper(res,nums,pos+1);  // pos+1, very important!
            swap(nums[pos],nums[i]);
        }
    }
};
```
Solution：swap one elements till the end.
However, if the permute contains duplicate elements, the iterative method is difficult to implement.

【47.Permutations II】
==
`Question:`
```
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```
Solution: Choose one element from the permutation, and each time the choice should skip duplicate elements. 
`e.g.
[1,1,2,2]

level1:       1 - [1,2,2],                      2 - [1,1,2]

level2: 11-[2,2],     12-[1,2],          21-[1,2],      22-[1,1]

level3: 112-[2],  121-[2],122-[1],   211-[2],212-[1],   221-[1]

level4: 1122,        1212,1221,        2112, 2121,       2211
`

`Codes:`
```C++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        Allswap(res,nums,0);
        return res;
    }
    
    void Allswap(vector<vector<int>> &res,vector<int> nums,int i){
        if(i==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(i!=j && nums[i]==nums[j]) continue;   // skip the duplicate
            swap(nums[i],nums[j]);
            Allswap(res,nums,i+1);
            
        }
    }
};
```
Attention: 
1. sort first
2. skip the duplicates before swap

【190.Reverse bits】
=
`Reverse bits of a given 32 bits unsigned integer`
```
e.g.
Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.
```
`solution`
Problem of bit operation, things need to be known previously:
1. 32 bits unsigned integer can use 16 bits system to represent.
2. in C++ there is no way to define 2 bits system integer but can represent 8-bits, 10-bits and 16-bits.
3. know the meaning of '>>' and '<<' and '|' operation signs.
This problem is solved by binary swapping.
```C++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
```
The first line swap the former 16-bits and latter 16-bits. And each line of the next go on swapping the former half and latter half of the smaller period.(result of the upper line).

【198.House Robbing】
=
```
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint
stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob 
tonight without alerting the police.
```
```
e.g.1
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
```
```
e.g.2
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
```
`Solution`
This is a DP problem and the constrains are:
1. the adjacent elements can't be added together
2. Maximize the sum
We can't consider it from backward since each choice of now would affect the choice afterwards. So we consider it as how to choose the former sum to get the best choice. 
Considering that to maximize the sum, it's definitely right to add as more legal elements as possible. So in the e.g.`a b c d` we get three situations, when choose 'a' we have 'c','d' left to be chosen and if we choose 'b', we can only choose'c'. With the purpose that the current choice should be the best, we use the form of `n = max(x,y)`to achieve this. In addition, the choice can be divided by the odd and even number to implement the traverse.
```C++
class Solution {
public:
    int rob(vector<int>& nums) {
        int no=0,ne=0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0)
                no = max(no+nums[i],ne);
            else
                ne = max(ne+nums[i],no);
        }
        return max(no,ne);
    }
};
```
`time complexity: O(n)`

`space complexity: O(n)`
