//
//  205.cpp
//  test3
//
//  Created by Ava on 2018/5/20.
//  Copyright © 2018年 Ava. All rights reserved.
//
/*
 Given two strings s and t, determine if they are isomorphic.
 Two strings are isomorphic if the characters in s can be replaced to get t.
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 e.g.1
 Input: s = "egg", t = "add"
 Output: true
 e.g.2
 Input: s = "foo", t = "bar"
 Output: false
 e.g.3
 Input: s = "paper", t = "title"
 Output: true
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        pair<map<char,char>,map<char,char>> PM;
        
        for(int i=0;i<s.length();i++){
            if(PM.first.find(s[i]) == PM.first.end())
                PM.first[s[i]] = t[i];
            else if(PM.first[s[i]] != t[i])
                return false;
            if(PM.second.find(t[i]) == PM.second.end())
                PM.second[t[i]] = s[i];
            else if(PM.second[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
