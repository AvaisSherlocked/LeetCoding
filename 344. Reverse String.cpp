/* questions:
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
/* sol1-- for loop */
class Solution {
public:
    string reverseString(string s) {
        string res;
        for(int i=s.length()-1;i>=0;i--)
            res +=s[i];
        return res;
    }
};

/* sol2 -- stack*/
class Solution {
public:
    string reverseString(string s) {
        string res;
        stack<char> st;
        for(auto item:s) st.push(item);
        while(!st.empty()){ res += st.top(); st.pop();}
        return res;
    }
};