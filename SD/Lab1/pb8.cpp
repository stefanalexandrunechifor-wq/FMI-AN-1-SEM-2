#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
void insertEnd(node* &head, int data) {
    node* new_node= new node();
    new_node->data = data;
    new_node->next = nullptr;
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
void insert(node* head, int data, int position) {
    int cnt=1;
    node* temp=head;
    node* new_node= new node;
    new_node->data=data;
    while (cnt!=position-1) {
        cnt++;
        temp = temp->next;
    }
    node* temp1 = temp;
    temp1 = temp1->next;
    temp->next=new_node;
    new_node->next=temp1;
}
void deletion(node* head, int position) {
    int cnt=1;
    node* temp=head;
    while (cnt!=position-1) {
        cnt++;
        temp = temp->next;
    }
    node* temp1 = temp;
    temp1 = temp1->next;
    node* temp2 = temp1->next;
    temp->next=temp2;
    delete temp1;
}
node* getElementByValue(node* head, int data) {
    node* temp = head;
    while (temp->data!=data) {
        temp=temp->next;
    }
    if (temp->data==data) return temp;
    return nullptr;
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
void find_cycle(node* head,int &lungime, node* &primul) {
    int v[100];
    int cnt=0;
    node* temp=head;
    while (v[cnt] !=1) {
        v[cnt]=1;
        temp = temp->next;
        cnt++;
    }
    int cnt1=1;
    while (v[cnt] !=2) {
        v[cnt]=2;
        temp = temp->next;
        cnt++;
        cnt1++;
    }
    primul=temp;
    lungime=cnt1;
}
int main() {
    node* head = nullptr;
    insertStart(head, 1);
    insertEnd(head, 2);
    insertEnd(head,3);
    insertStart(head,4);
    insert(head,8,2);
    printList(head);
    cout<<endl;
    cout<<(getElementByIndex(head,3)->data);
    return 0;
}
