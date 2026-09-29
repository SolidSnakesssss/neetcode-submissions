class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int curr = 1, best = 1;

        if (!nums.size()) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 == nums[i - 1] || nums[i] + 1 == nums[i - 1]) {
                curr++;
            }

            else if (nums[i] == nums[i - 1]) {
                continue;
            }

            else {
                best = std::max(best, curr);

                curr = 1;
            }
        }

        return std::max(best, curr);
    }
};
