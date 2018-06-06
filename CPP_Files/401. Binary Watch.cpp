/* questions:
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

*/

/* bit operation*/ // used bitset<10> x.count
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(bitset<10>((i<<6)+j).count() == num){  // (i<<6+j) leave 6 bits for minute, this count() shows how many '1' in tenth number
                    string tmp = to_string(i);
                    if(j<10) tmp += ":0"+to_string(j);
                    else tmp += ":"+to_string(j);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
/* backtracking way*/
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> AH={1,2,4,8};
        vector<int> AM={1,2,4,8,16,32};
        vector<string> res;
        
        int i=0;
        while(i<4 && num-i>=0){
            vector<int> H,M;
            Hour(i,H,AH,0,0,0);
            Minute(num-i,M,AM,0,0,0);
            for(int j=0;j<H.size();j++){
                for(int k=0;k<M.size();k++){
                    string tmp = to_string(H[j]);
                    if(M[k]<10)
                        tmp +=":0"+to_string(M[k]);
                    else
                        tmp +=":"+to_string(M[k]);
                    res.push_back(tmp);
                }
            }
            i++;
        }
        return res;
    }
    void Hour(int n,vector<int>& h,vector<int> AH,int sum,int j,int c){
        //c starts from 1, j starts from 0
        if(c==n){
            if(sum<12)h.push_back(sum);
            return;
        }
        for(int i=j;i<4;i++){
            sum += AH[i];
            Hour(n,h,AH,sum,j+1,c+1);
            sum -= AH[i];
            j++;
        }
        return;
    }
    void Minute(int n,vector<int>& m,vector<int> AM,int sum,int j,int c){
        //c starts from 1, j starts from 0
        if(c==n){
            if(sum<60)m.push_back(sum);
            return;
        }
        for(int i=j;i<6;i++){
            sum += AM[i];
            Minute(n,m,AM,sum,j+1,c+1);
            sum -= AM[i];
            j++;
        }
        return;
    }
};
