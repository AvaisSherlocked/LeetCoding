/*
questions:
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/
/*. sol1: use map */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> MS;
        unordered_map<char,int> MT;
        for(int i=0;i<26;i++){
            MS['a'+i] = i;
            MT['a'+i] = i;
        }
        for(int i=0;i<s.length();i++){
            MS[s[i]]++;
            MT[t[i]]++;
        }
        return (MS == MT);
    }
};
/* sol2.use array to count */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> Count(26,0);

        for(int i=0;i<s.length();i++)
            Count[s[i]-'a']++;
        for(int i=0;i<s.length();i++)
            Count[t[i]-'a']--;
        for(int i=0;i<26;i++)
            if(Count[i]!=0) return false;
        return true;
    }
};