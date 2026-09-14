class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        size_t len = nums.size();
        
        for (size_t i = 0; i < len; i++) {
            for (size_t j = i + 1; j < len; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }
};