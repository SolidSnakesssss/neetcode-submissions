class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<string>> grouped;

        for (size_t i = 0; i < strs.size(); i++) {
            std::string word = strs[i];

            sort(word.begin(), word.end());

            grouped[word].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> answer;

        for (auto& it : grouped) {
            answer.push_back(it.second);
        }

        return answer;
    }
};
