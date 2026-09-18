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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* answer = nullptr;
        ListNode* traverse = head;
        
        while (traverse != nullptr) {
            ListNode* next = traverse->next;
            traverse->next = answer;

            answer = traverse;
            traverse = next;
        }

        return answer;
    }
};
