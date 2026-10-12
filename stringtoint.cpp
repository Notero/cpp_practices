#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int curr = 0;
        bool isNeg = false;
        bool readFirst = false;
        bool signread = false;
        
        for (char c: s){
            
            if(c == ' ' && (readFirst || signread)) {break;}
            if(c == ' ') {continue;}
            if(c == '+' && readFirst == false) { 
                if(signread == true)
                {
                    break;
                } 
                signread = true;
                continue;
            }

            if(c == '-' && isNeg == false && readFirst == false)
            {
                if(signread == true)
                {
                    break;
                } 
                signread = true;
                isNeg = true;
                continue;
            }

            if('0' <= c && c <= '9')
            {
                int digit = (c - '0');
                readFirst = true;
                if(isNeg){
                    if(curr < (INT_MIN + digit) / 10) {return INT_MIN;}
                    curr = curr * 10 - digit;
                }else{
                    if(curr > (INT_MAX - digit) / 10) {return INT_MAX;}
                    curr = curr * 10 + digit;
                }
                
            }else{
                break;
            }
        }
        return curr;
    }
};