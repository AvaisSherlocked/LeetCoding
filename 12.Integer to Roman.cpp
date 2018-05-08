//
//  12.cpp
//
//  Created by Ava on 2018/5/8.
//  Copyright © 2018年 Ava. All rights reserved.
//

// smart idea
class Solution {
public:
    string intToRoman(int num) {
        vector<string> I={"","I","II","III","IV","V","VI","VII","VIII","IX","X"};
        vector<string> X={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"};
        vector<string> C={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"};
        vector<string> M={"","M","MM","MMM"};
        return M[num/1000] + C[num%1000/100] + X[num%100/10] + I[num%10];
    }
};
// stupid idea
class Solution {
public:
    string intToRoman(int num) {
        string res;
        if(num/1000 > 0){
            int i=num/1000;
            num -= 1000*i;
            while(i>0){
                res += "M";
                i--;
            }
        }
        if(num/100 > 0){
            int i=num/100;
            num -= 100*i;
            if(i==5)
                res += "D";
            else if(i==4)
                res += "CD";
            else if(i==9)
                res += "CM";
            else if(i<4)
                while(i>0){
                    res += "C";
                    i--;
                }
            else{
                res +="D";
                while(i-5 >0){
                    res +="C";
                    i--;
                }
            }
        }
        if(num/10 > 0){
            int i=num/10;
            num -= i*10;
            if(i==5)
                res += "L";
            else if(i==4)
                res += "XL";
            else if(i==9)
                res += "XC";
            else if(i<4)
                while(i>0){
                    res += "X";
                    i--;
                }
            else{
                res +="L";
                while(i-5 >0){
                    res +="X";
                    i--;
                }
            }
        }
        if(num > 0){
            int i=num;
            if(i==5)
                res += "V";
            else if(i==4)
                res += "IV";
            else if(i==9)
                res += "IX";
            else if(i<4)
                while(i>0){
                    res += "I";
                    i--;
                }
            else{
                res +="V";
                while(i-5 >0){
                    res +="I";
                    i--;
                }
            }
        }
        return res;
    }
};
