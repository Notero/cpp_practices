#include <climits>

class Solution {
public:
    int reverse(int x) {
        int curr = 0;
        int digit = 0;

        while (x != 0){
            digit = x % 10;
            x /= 10;
            if(curr * 10 > INT_MAX || curr * 10 < INT_MIN) 
            {
                return 0;
            }
            curr = curr * 10 + digit;
        }
        return curr;
    }
};