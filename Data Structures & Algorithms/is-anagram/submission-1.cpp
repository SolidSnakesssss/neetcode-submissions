class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        std::map<char, int> set1;
        std::map<char, int> set2;

        for (size_t i = 0; i < s.size(); i++) {
            if (set1.count(s[i]))
                set1[s[i]] = set1.at(s[i]) + 1;
            else 
                set1[s[i]] = 0;
            
            if (set2.count(t[i]))
                set2[t[i]] = set2.at(t[i]) + 1;
            else 
                set2[t[i]] = 0;

            //people.insert({"Jenny", 22});
        }

        return set1 == set2;
    }
};
