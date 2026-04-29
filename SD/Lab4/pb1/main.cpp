#include<iostream>
#include<vector>
#include<algorithm>
struct Node {
    int value;
    Node *left, *right;
    Node(int val) : value(val),left(nullptr),right(nullptr) {}
};
class BST {
    Node* root = nullptr;
    Node* insert(const std::vector<int>& values, int start, int end) {
        if (start>end) return nullptr;
        int mid=start+(end-start)/2;
        Node* node = new Node(values[mid]);
        node->left = insert(values,start,mid-1);
        node->right = insert(values,mid+1,end);
        return node;
    }

public:
    void construct(std::vector<int>& values) {
        if (values.empty()) return;
        std::sort(values.begin(),values.end());
        root = insert(values,0,values.size()-1);
    }
    bool exists(Node* node,int elem) {
        if (node == nullptr) return false;
        if (elem==node->value) return true;
        else if (elem<node->value) {
            return exists(node->left,elem);
        }
        else if (elem>node->value) {
            return exists(node->right,elem);
        }
    }
    int predecesor(Node* node, int elem) {
        if (node == nullptr) return -1;
        if (elem < node->value) {
            return predecesor(node->left, elem);
        }
        else if (elem > node->value) {
            return predecesor(node->right, elem);
        }
        else {
            if (node->left != nullptr) {
                Node* temp = node->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                return temp->value;
            }
            else {
                Node* temp = root;
                Node* candidat = nullptr;
                while (temp != nullptr && temp->value != elem) {
                    if (elem > temp->value) {
                        candidat = temp;
                        temp = temp->right;
                    } else {
                        temp = temp->left;
                    }
                }

                if (candidat != nullptr) {
                    return candidat->value;
                } else {
                    return -1;
                }
            }
        }
    }
    int succesor(Node* node, int elem) {
        if (node == nullptr) return -1;
        if (elem < node->value) {
            return predecesor(node->left, elem);
        }
        else if (elem > node->value) {
            return predecesor(node->right, elem);
        }
        else {
            if (node->right != nullptr) {
                Node* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                return temp->value;
            }
            else {
                Node* temp = root;
                Node* candidat = nullptr;
                while (temp != nullptr && temp->value != elem) {
                    if (elem > temp->value) {
                        candidat = temp;
                        temp = temp->left;
                    } else {
                        temp = temp->right;
                    }
                }

                if (candidat != nullptr) {
                    return candidat->value;
                } else {
                    return -1;
                }
            }
        }
    }
    Node* erase(Node* node, int elem) {
        if (node == nullptr) return nullptr;
        if (elem < node->value) {
            node->left = erase(node->left, elem);
        }
        else if (elem > node->value) {
            node->right = erase(node->right, elem);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = node->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                node->value = temp->value;
                node->left = erase(node->left, temp->value);
            }
        }

        return node;
    }
};
int main() {
    return 0;
}