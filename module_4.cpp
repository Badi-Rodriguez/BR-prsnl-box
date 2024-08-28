//
// Created by Badi on 8/27/2024.
//

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* next;

    // Constructor to initialize a node with given data and nullify the next pointer
    Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // Destructor to clear the list
    ~LinkedList() {
        clear();
    }

    // Function to add a new element at the front of the list
    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to add a new element at the end of the list
    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to remove the first element of the list
    void pop_front() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to remove the last element of the list
    void pop_back() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // Function to print all elements in the list
    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to reverse the list
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Function to return the size of the list
    int size() const {
        int count = 0;
        Node<T>* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to check if the list is empty
    bool empty() const {
        return head == nullptr;
    }

    // Function to clear the entire list
    void clear() {
        while (head) {
            pop_front();
        }
    }

    // Function to get the element at a specific index (0-based)
    T& at(int index) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index out of bounds");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Function to insert an element at a specific index
    void insert(T val, int index) {
        if (index < 0 || index > size()) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            push_front(val);
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        Node<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to remove an element at a specific index
    void erase(int index) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            pop_front();
            return;
        }
        Node<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

// Test 1: Detect cycle

template<typename T>
bool hasCycle(Node<T>* head) {
    Node<T>* slow = head;
    Node<T>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }
    return false;
}

// Test 2: Find middle of a linked list

template<typename T>
Node<T>* findMiddle(Node<T>* head) {
    if (!head) return nullptr;

    Node<T>* slow = head;
    Node<T>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Move slow by one
        fast = fast->next->next; // Move fast by two
    }

    return slow;  // Slow will be at the middle
}

// Test 3: Merging of two sorted linked lists

template<typename T>
Node<T>* mergeTwoLists(Node<T>* l1, Node<T>* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Test 4: N-removal from end of a linked list

template<typename T>
void removeNthFromEnd(LinkedList<T>& list, int n) {
    int size = list.size();
    if (n > size) return; // N is greater than the size of the list

    int indexFromStart = size - n; // Convert to zero-based index from start

    list.erase(indexFromStart); // Use the erase function to remove the element
}





