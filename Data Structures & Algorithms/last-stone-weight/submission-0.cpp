class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> max_heap(stones.begin(), stones.end());

        while(max_heap.size() > 1) {
            int stone1 = max_heap.top();
            max_heap.pop();

            int stone2 = max_heap.top();
            max_heap.pop();

            int remain = stone1 - stone2;

            if (remain) {
                max_heap.push(remain);
            }
        }

        if (max_heap.empty()) {
            return 0;
        }

        return max_heap.top();
    }
};
