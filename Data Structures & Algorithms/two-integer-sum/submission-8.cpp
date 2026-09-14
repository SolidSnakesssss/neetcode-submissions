class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];

            int num2 = target - num1;

            auto it = find(nums.begin() + i + 1, nums.end(), num2);

            if (it != nums.end()){
                return {i, static_cast<int>(distance(nums.begin(), it))};
            }
        }
    }
};
