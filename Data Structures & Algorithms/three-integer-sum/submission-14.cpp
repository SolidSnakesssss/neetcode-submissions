class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> answer;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;

            if (i > 0) {
                if (nums[i] == nums[i - 1]) {
                    continue;
                }
            }

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (!sum) {
                    answer.push_back({nums[i], nums[left++], nums[right--]});

                    while (nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                }

                else if (sum > 0) {
                    right--;
                }

                else {
                    left++;
                }
            }
        }

        return answer;
    }
};
