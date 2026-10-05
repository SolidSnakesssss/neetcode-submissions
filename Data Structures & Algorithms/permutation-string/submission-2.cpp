class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int max_len = s1.size(), l = 0, r = max_len - 1;
        std::sort(s1.begin(), s1.end());

        while (r < s2.size()) {
            std::string perm(s2, l, max_len);
            std::sort(perm.begin(), perm.end());
            
            if (perm == s1) {
                return true;
            }

            l++;
            r++;
        }

        return false;
    }
};
