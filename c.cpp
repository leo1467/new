#include <iostream>
#include <filesystem>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;
using namespace filesystem;

class Solution {
private:
    vector<char> sP = {'(', ')'};
    vector<char> mP = {'[', ']'};
    vector<char> bP = {'{', '}'};

public:
    bool isValid(string s) {
        size_t len = s.length();
        vector<char> stack;
        stack.reserve(len);
        char pop;
        for (size_t i = 0; i < len; i++) {
            if (s[i] != sP[1] && s[i] != mP[1] && s[i] != bP[1]) {
                stack.push_back(s[i]);
            } else {
                if (stack.size() == 0) {
                    return false;
                } else {
                    pop = stack.back();
                    stack.pop_back();
                    switch (pop) {
                        case '(': {
                            if (s[i] != sP[1])
                                return false;
                            break;
                        }
                        case '[': {
                            if (s[i] != mP[1])
                                return false;
                            break;
                        }
                        case '{': {
                            if (s[i] != bP[1])
                                return false;
                            break;
                        }
                    }
                }
            }

        }
        if (stack.size() != 0) 
            return false;
        
        return true;
    }
};

int main(void) {
    Solution s;
    cout << s.isValid("()") << endl;
}