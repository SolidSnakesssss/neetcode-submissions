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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* traverse = head;

        while (l1 != nullptr || l2 != nullptr) {    
            bool canMakeNode = true;
            
            if (l1 == nullptr) {
                traverse->val = l2->val;

                l2 = l2->next;

                if (l2 == nullptr) {
                    canMakeNode = false;
                }
            }
            
            else if (l2 == nullptr) {
                traverse->val = l1->val;

                l1 = l1->next;

                if (l1 == nullptr) {
                    canMakeNode = false;
                }
            }

            else {
                traverse->val = l1->val + l2->val;

                l1 = l1->next;
                l2 = l2->next;

                if (l1 == nullptr && l2 == nullptr) {
                    canMakeNode = false;
                }
            }

            if (canMakeNode) {                
                ListNode* prev = traverse;
                ListNode* temp = new ListNode();
                traverse = temp;
                prev->next = traverse;
            }
        }

        traverse = head;
        size_t carry_over = 0;

        while (traverse != nullptr) {
            if (carry_over) {
                traverse->val += carry_over;
                carry_over = 0;
            }

            if (traverse->val >= 10) {
                carry_over = traverse->val / 10;
                traverse->val %= 10;
            }

            if (traverse->next == nullptr && carry_over) {
                ListNode* temp = new ListNode(carry_over);
                traverse->next = temp;
                break;
            }

            traverse = traverse->next;
        }

        return head;
    }
};
