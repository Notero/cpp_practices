#include <string>

class Solution {
public:
    std::string convert(const std::string& s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;

        std::string output;
        output.reserve(n);

        for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
            int bigStep   = 2 * (numRows - rowIndex - 1);
            int smallStep = 2 * rowIndex;
            bool isBigStep = true;

            int currTerm = rowIndex;              
            while (currTerm < n) {                
                output.push_back(s[currTerm]);

                int gap = isBigStep ? bigStep : smallStep;
                if (gap == 0)                    
                    gap = isBigStep ? smallStep : bigStep;

                currTerm += gap;                  
                isBigStep = !isBigStep;           
            }
        }
        return output;
    }
};