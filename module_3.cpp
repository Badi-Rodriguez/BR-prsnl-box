//
// Created by Badi on 8/27/2024.
//

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    prev->next = temp->next;
    delete temp;
}

int module_3() {
    Node* head = nullptr;

    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);

    traverse(head);  // Output: 5 10 20

    deleteNode(head, 10);
    traverse(head);  // Output: 5 20

    return 0;
}
