class Solution {
public:
    bool isPalindrome(string s) {
        std::string new_string = "";

        for (char c : s) {
            if (isalnum(c)) {
                new_string += std::tolower(c);
            }
        }

        int first = 0, second = new_string.size() - 1;

        while (first <= second) {
            if (new_string[first++] != new_string[second--]) {
                return false;
            }
        }

        return true;
    }
};
