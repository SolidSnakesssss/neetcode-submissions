class LinkedList {
public:
    struct Node {
        Node* next;
        int val;
        Node(Node* nextNode, int v) : next(nextNode), val(v) {}
    };

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    int get(int index) {
        if (index < 0 || index >= len)
            return -1;
        
        int i = 0;
        Node* temp = head;

        while (i < index) {
            temp = temp->next;
            i++;
        }
        
        return temp->val;
    }

    void insertHead(int val) {
        len++;
        
        Node* newHead = new Node(head, val);
        head = newHead;
        if (tail == NULL) {
            tail = head;
        }
    }
    
    void insertTail(int val) {
        len++;
        
        if (head == NULL) {
            head = new Node(NULL, val);
            tail = head;
            return;
        }

        Node* newTail = new Node(NULL, val);
        tail->next = newTail;
        tail = newTail;
    }

    bool remove(int index) {
        if (index < 0 || index >= len)
            return false;

        len--;
        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            if (len == 0) {
                tail = NULL;
            }
            delete toDelete;
            return true;
        }
       
        int i = 0;
        Node* prevNode = head;

        while (i < index - 1) {
            prevNode = prevNode->next;
            i++;
        }

        Node* currNode = prevNode->next;
        prevNode->next = currNode->next;
        if (currNode == tail) {
            tail = prevNode;
        }
        delete currNode;

        return true;
    }

    vector<int> getValues() {
        Node* read = head;
        std::vector<int> values;

        while (read != NULL) {
            values.push_back(read->val);
            read = read->next;
        }

        return values;
    }

    Node* head = NULL;
    Node* tail = NULL;
    int len = 0;
};