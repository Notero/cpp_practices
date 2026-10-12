#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){return false;}
        int digitCount = 0;
        int c = x;
        while(c > 0){
            c /= 10;
            digitCount++;
        }
        int half = digitCount / 2;
        int num = 1;
        for (int i = 0; i < half; i++)
        {
            num *= 10;
        }
        int rightHalf = x % num;
        int leftHalf = x / num;
        if (digitCount % 2 != 0){
            leftHalf /= 10;
        }
        leftHalf = reverse(leftHalf);

        return leftHalf == rightHalf;

    }

    int reverse(int x) {
        int curr = 0;
        while (x != 0){
            if(curr > INT_MAX / 10 || curr < INT_MIN / 10) {return 0;}
            curr = (curr * 10) + (x % 10);
            x /= 10;
        }
        return curr;
    }
};