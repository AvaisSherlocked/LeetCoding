/*questions:
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        string r=ransomNote;
        sort(r.begin(),r.end());
        string m=magazine;
        sort(m.begin(),m.end());
        if(r.size()>m.size()) return false;
        if(r.size()==0) return true;
        int j=0;
        for(int i=0;i<m.size();i++){
            if(m[i]==r[j]){
                if(j==r.size()-1)
                    return true;
                j++;
            }
        }
        return false;
    }
};