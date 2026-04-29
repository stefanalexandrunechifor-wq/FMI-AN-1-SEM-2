#include <iostream>

using namespace std;
struct node {
    int data;
    node* next;
};
void insert(node* &head, int data) {
    node* new_node = new node;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void deletion(node* &head) {
    if (head == nullptr) {
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}
node* gasire(node* head, int poz) {
    node* temp = head;
    int cnt = 0;
    while (temp != nullptr && cnt != poz) {
        temp = temp->next;
        cnt++;
    }
    return temp;
}
int main() {
    node* head = nullptr;
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        while (head != nullptr && v[head->data] >= v[i]) {
            deletion(head);
        }
        if (head == nullptr) {
            cout << 0 << " ";
        } else {
            cout << head->data + 1 << " ";
        }
        insert(head, i);
    }

    return 0;
}
