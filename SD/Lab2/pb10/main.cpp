#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
void insertEnd(node* &head, int data) {
    node* new_node= new node;
    new_node->data = data;
    new_node->next = nullptr;
    if (head == nullptr) {
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next=new_node;
}
void deletionEnd(node* &head) {
    if (head == nullptr) {
        return;
    }
    node* temp = head;
    node* temp1=head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    while (temp1->next != temp) {
        temp1 = temp1->next;
    }
    temp1->next=nullptr;
    delete temp;
}
void insertStart(node* &head, int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void deletionStart(node* &head) {
    node* temp = head;
    head = head->next;
    delete temp;
}
node* getElementByIndex(node* head, int position) {
    node* temp = head;
    int cnt=0;
    while (cnt!=position && temp!=nullptr) {
        temp=temp->next;
        cnt++;
    }
    if (cnt==position && temp!=nullptr) return temp;
    return nullptr;
}

void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << "\n";
}
int main() {
    node* head = nullptr;
    insertStart(head, 1);
    insertEnd(head, 2);
    insertEnd(head,3);
    insertStart(head,4);
    printList(head);
    cout<<endl;
    cout<<(getElementByIndex(head,3)->data);
    return 0;
}