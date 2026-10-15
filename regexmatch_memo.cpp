#include <string>
#include <iostream>
#include <vector>

class Solution {
    
    std::vector<std::vector<int>> memo;

public:
    bool isMatch(std::string s, std::string p) {
        memo.assign(s.size() + 1, std::vector<int>(p.size() + 1, -1));
        return match(s,p,0,0);
    }

    bool match(const std::string& s, const std::string& p, int si, int pi)
    {
        bool star = (p[pi + 1] == '*');

        if(memo[si][pi] != -1){
            return memo[si][pi];
        }

        //base case
        if (pi >= p.length()){
            return si >= s.length() && pi >= p.length();
        }

        //if exact match or anyone has a . with no starts ahead its a regular pass
        if ((s[si] == p[pi] || (p[pi] == '.' && s.length() != si)) && star == false) 
        {
            memo[si][pi] = match(s , p , si + 1, pi + 1);
            return memo[si][pi];
        }
        

        //check each path if not correct path try passing the star.
        if (star == true)
        {   
            //end of s case
            if (s.length() <= si) {
                memo[si][pi] = match(s,p,si,pi + 2);
                return memo[si][pi];
            }
            //no match case track back
            if(s[si] != p[pi] && p[pi] != '.') {
                memo[si][pi] = match(s,p,si, pi + 2);
                return memo[si][pi];
            }
            
            
            if (!match(s, p , si+1 ,pi))
            {

                memo[si][pi] = match(s,p, si, pi + 2);
                return memo[si][pi];
            }else {
                memo[si][pi] = 1;
                return true;
            };
        }
        memo[si][pi] = 0;
        return false;
    }
};