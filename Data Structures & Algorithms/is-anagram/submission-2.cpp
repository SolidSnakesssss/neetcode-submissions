class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        std::map<char, int> map1;
        std::map<char, int> map2;

        for (size_t i = 0; i < s.size(); i++) {
            char temp1 = s[i];
            char temp2 = t[i];
            
            if (map1.count(s[i]))
                map1[temp1] = map1.at(temp1) + 1;
            else 
                map1[temp1] = 0;
            
            if (map2.count(temp2))
                map2[temp2] = map2.at(temp2) + 1;
            else 
                map2[temp2] = 0;
        }

        return map1 == map2;
    }
};
