/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr_node = head;
        std::vector<ListNode*> linked;

        while (curr_node != nullptr) {
            linked.push_back(curr_node);

            curr_node = curr_node->next;
        }

        int target_pos = linked.size() - n;
        curr_node = linked[target_pos];

        if(target_pos - 1 >=0) {
            if (target_pos + 1 < linked.size()) {
                linked[target_pos - 1]->next = linked[target_pos + 1];
            }

            else {
                linked[target_pos - 1]->next = nullptr;
            }
        } 

        else {
            head = head->next;
        }

        delete linked[target_pos];

        return head;
    }
};
