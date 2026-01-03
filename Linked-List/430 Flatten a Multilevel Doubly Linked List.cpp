/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        dfs(head);
        return head;
    }

private:
    Node* dfs(Node* node) {
        Node* curr = node;
        Node* last = nullptr;

        while (curr) {
            Node* next = curr->next;
            if (curr->child) {
                Node* childTail = dfs(curr->child);
                curr->next = curr->child;
                curr->child->prev = curr;

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                curr->child = nullptr;
                last = childTail;
            } else {
                last = curr;
            }

            curr = next;
        }
        return last;
    }
};
