
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* createCircularLinkedList(int n) {
    Node* head = new Node();
    Node* curr = head;
    for (int i = 1; i <= n; i++) {
        curr->value = i;
        curr->next = new Node();
        curr = curr->next;
    }
    curr->next = head;
    return head;
}

void removeChildren(Node* head, int n, int k) {
    Node* curr = head;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            curr = curr->next;
        }
        Node* next = curr->next;
        curr->next = next->next;
        delete next;
        curr = curr->next;
    }
}

void printRemovalOrder(Node* head, int n) {
    Node* curr = head;
    for (int i = 0; i < n; i++) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;

    Node* head = createCircularLinkedList(n);
    removeChildren(head, n, k);
    printRemovalOrder(head, n);

    return 0;
}
