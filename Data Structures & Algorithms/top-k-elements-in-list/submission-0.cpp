class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> sol;

        for(int i : nums) {
            sol[i]++;
        }

        std::vector<std::pair<int, int>> pairs;

        for(auto& it: sol) {
            pairs.push_back({it.second, it.first});
        }

        sort(pairs.begin(), pairs.end());

        std::vector<int> solution;

        int stop = 0;
        int iter = pairs.size() - 1;

        while (true) {
            solution.push_back(pairs[iter--].second);

            if(++stop >= k)
                break;
        }

        return solution;
    }
};
