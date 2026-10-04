class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k), nums(nums) {
    }
    
    int add(int val) {
        nums.push_back(val);

        std::sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];
    }

private:
    vector<int> nums;
    int k;
};
