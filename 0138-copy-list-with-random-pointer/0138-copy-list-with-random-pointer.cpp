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
private:
    void insertCopyInbetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);

            copy->next = nextElement;
            temp->next = copy;

            temp = nextElement;
        }
    }

    void insertRandomPtr(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copy = temp->next;
            if (temp->random != NULL) {
                copy->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }

    Node* saparateList(Node* head) {
        Node* temp = head;
        Node* ans = head->next;
        while (temp != NULL) {
            Node* copy = temp->next;
            temp->next = copy->next;
            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }
            temp = temp->next;
        }
        return ans;
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == NULL){
            return NULL;
        }

        insertCopyInbetween(head);
        insertRandomPtr(head);
        return saparateList(head);
    }
};