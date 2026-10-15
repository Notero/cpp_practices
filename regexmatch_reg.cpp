#include <string>
#include <iostream>

class Solution {
    bool star = false;

public:
    bool isMatch(std::string s, std::string p) {
        return match(s,p,0,0);
    }

    bool match(const std::string& s, const std::string& p, int si, int pi)
    {
        //base case
        if (pi >= p.length()){
            return si >= s.length() && pi >= p.length();
        }

        //star dotstar scanner
        if (p[pi + 1] == '*'){
            star = true;
        }

        //if exact match or anyone has a . with no starts ahead its a regular pass
        if ((s[si] == p[pi] || (p[pi] == '.' && s.length() != si)) && star == false) 
        {
            return match(s , p , si + 1, pi + 1);
        }
        

        //check each path if not correct path try passing the star.
        if (star == true)
        {   
            //end of s case
            if (s.length() <= si) {
                star = false;
                return match(s,p,si,pi + 2);
            }
            //no match case track back
            if(s[si] != p[pi] && p[pi] != '.') {
                star = false;
                return match(s,p,si, pi + 2);
            }
            
            
            if (!match(s, p , si+1 ,pi))
            {
                star = false;
                return match(s,p, si, pi + 2);
            }else return true;
        }

        return false;
    }
};