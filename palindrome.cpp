#include <string>
#include <unordered_map>
#include <deque>
#include <array>
#include <algorithm>

class Solution {

    int selection = -1;
    int curr_long = 0;
    std::string possiblePalindromeString;
    std::vector<std::pair<int,int>> pairs;
    std::unordered_map<char, std::deque<int>> umap;

public:

    std::string longestPalindrome(std::string s) {
        possiblePalindromeString = s;
        std::string val(1, s[0]);
        if (possiblePalindromeString.length() == 1){
            return s;
        }
        createMap();
        fillPairs();
        if (pairs.empty()){
            return val;
        }
        int index = 0;
        for (std::pair<int,int> value : pairs){
            auto [small, big] = std::minmax(value.first, value.second);
            if (isPalindrome(small,big)){
                if (curr_long <= big - small){
                    curr_long = big - small;
                    selection = index;
                }
            }
            index++;
        }

        if (selection == -1){
            return val;
        }

        auto [first,second] = std::minmax(pairs[selection].first, pairs[selection].second);
        return possiblePalindromeString.substr(first, second - first + 1); 
    }

    void fillPairs(){
        for(const auto& [key, value] : umap){
            auto& d = value;
            if (d.size() == 1) { continue; }
        for (size_t i = 0; i < d.size(); ++i){
            for (size_t j = i + 1; j < d.size(); ++j){
                    pairs.push_back({d[i], d[j]});
                }
            }
        }
    }

    void createMap(){
        for (int x = 0;x < possiblePalindromeString.length(); x++){
            umap[possiblePalindromeString[x]].push_back(x);
        }
    }


    bool isPalindrome(int begin, int end) {
    if (begin >= end){
        return true;
    }
    
    return possiblePalindromeString[begin] == possiblePalindromeString[end] && isPalindrome(begin + 1, end - 1);
    }
};