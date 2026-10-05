class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> brackets {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        std::stack<char> expected;

        for (char c : s) {
            if (brackets[c]) {
                expected.push(brackets[c]);
                continue;
            }

            if (expected.empty()) {
                return false;
            }

            if (c != expected.top()) {
                return false;
            }

            expected.pop();
        }

        if (!expected.empty()) {
            return false;
        }

        return true;
    }
};
