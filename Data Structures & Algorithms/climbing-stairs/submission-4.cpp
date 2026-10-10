class Solution {
public:
    int climbStairs(int n) {
        int one_step = 1, two_step = 1;

        for (int i = 1; i < n; i++) {
            int hold = one_step;
            one_step = one_step + two_step;
            two_step = hold;
        }

        return one_step;
    }
};
