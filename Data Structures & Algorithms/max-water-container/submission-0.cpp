class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer = 0, left = 0, right = heights.size() - 1;

        while (left < right) {
            answer = std::max(answer, std::min(heights[left], heights[right]) * (right - left));

            if (heights[left] < heights[right]) {
                left++;
            }

            else {
                right--;
            }
        }

        return answer;
    }
};
