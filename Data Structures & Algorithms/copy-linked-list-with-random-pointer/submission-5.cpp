/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        
        std::unordered_map<Node*, Node*> deep_map;

        Node* traverse = head->next;

        Node* new_head = new Node(*head);
        Node* prev = new_head;

        // [Old Head, New Head] pair
        deep_map[head] = new_head;
         
        // Create the random node
        if(new_head->random != nullptr) {
            if (deep_map.find(new_head->random) == deep_map.end()) {
                Node* new_rand = new Node(*new_head->random);
                deep_map[new_head->random] = new_rand;
                new_head->random = new_rand;
            }

            else {
                new_head->random = new_head;
            }
        }

        if (new_head->next == nullptr) {
            return new_head;
        }

        while (traverse != nullptr) {
            Node* temp;

            if (deep_map.find(traverse) == deep_map.end()) {
                temp = new Node(*traverse);

                deep_map[traverse] = temp;
            }

            else {
                temp = deep_map[traverse];
            }

            prev->next = temp;
            prev = temp;

            if (temp->random != nullptr) {
                if (deep_map.find(temp->random) == deep_map.end()) {
                    Node* temp_rand = new Node(*temp->random);

                    deep_map[temp->random] = temp_rand;

                    temp->random = temp_rand;
                }

                else {
                    temp->random = deep_map[temp->random];
                }
            }

            traverse = traverse -> next;
        }

        return new_head;
    }
};
