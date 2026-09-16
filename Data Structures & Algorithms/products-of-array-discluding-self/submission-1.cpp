class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero_count = 0;

        vector<int> answer(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];

            if (temp != 0) {
                product *= temp;
            }

            else {
                zero_count++;
            }
        }

        if (zero_count > 1) {
            return answer;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zero_count == 1) {
                if (nums[i] == 0) {
                    answer[i] = product;

                    break;
                }
            }

            else {
                answer[i] = product / nums[i];
            }
        }

        return answer;
    }
};
