//
// Created by Badi on 8/27/2024.
//

#include <cmath>
#include <cstdio>
#include <iostream>

// We are using std::cout and std::endl from the standard namespace for printing
using std::cout, std::endl;

// Node struct template for linked list
template <typename T>
struct Node {
    T data;          // Data of type T stored in the node
    Node* next;      // Pointer to the next node in the list

    // Constructor to initialize a node with a value and set the next pointer to nullptr
    explicit Node(const T& val): data(val),next(nullptr){};
};

// List class template implementing a singly linked list
template <typename T>
class List {
    Node<T>* head;  // Pointer to the first node (head) in the list

public:
    // Function to retrieve the first element (front) of the list
    // Throws an exception if the list is empty
    T front() {
        if(head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    // Function to retrieve the last element (back) of the list
    // Returns nullptr if the list is empty
    T back() {
        if(head == nullptr) {
            return nullptr;
        }
        auto current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }

    // Function to insert an element at the front of the list
    void push_front(const T& e) {
        auto new_node = new Node<T>(e); // Create a new node with the given data
        auto old_head = head;           // Save the old head
        head = new_node;                // Update the head to the new node
        new_node->next = old_head;      // Point the new node's next to the old head
    }

    // Function to insert an element at the end of the list
    void push_back(const T& e) {
        if(head == nullptr) {
            head = new Node(e);         // If the list is empty, create a new head
            return;
        }
        auto current = head;            // Start from the head
        while(current->next != nullptr) {
            current = current->next;    // Traverse to the last node
        }
        auto new_node = new Node<T>(e); // Create a new node
        current->next = new_node;       // Link the last node to the new node
    }

    // Function to remove the first element (front) from the list
    void pop_front() {
        auto temp  = head;              // Store the current head
        head = head->next;              // Update head to the next node
        delete temp;                    // Delete the old head
    }

    // Function to remove the last element (back) from the list
    void pop_back() {
        auto current = head;
        while (current->next->next != nullptr) {
            current = current->next;    // Traverse to the second last node
        }
        auto temp = current->next;      // Store the last node
        current->next = nullptr;        // Remove the link to the last node
        delete temp;                    // Delete the last node
    }

    // Overloaded subscript operator to access elements by index
    // Throws an exception if the index is out of bounds
    T& operator[](const int& i) {
        if (i < 0 || i >= size()) {
            throw std::out_of_range("Index out of bounds");
        }
        auto current = head;
        for(int k = 0; k < i; k++ ) {
            current = current->next;    // Traverse to the desired index
        }
        return current->data;           // Return the data at the index
    }

    // Function to check if the list is empty
    bool empty() {
        return head == nullptr;
    }

    // Function to return the size of the list (number of nodes)
    int size() {
        int s = 0;
        auto current = head;
        while(current != nullptr) {
            s++;                        // Increment the counter for each node
            current = current->next;    // Move to the next node
        }
        return s;
    }

    // Function to clear the list by deleting all nodes
    void clear() {
        while(head != nullptr) {
            pop_front();                // Continuously pop the front until the list is empty
        }
    }

    // Function to print all elements in the list
    void print() {
        auto current = head;
        while(current != nullptr) {
            printf("%i\n", current->data); // Print the data of each node
            current = current->next;       // Move to the next node
        }
    }

    // Function to insert an element at a specific position in the list
    void insert(const T& val, const int pos) {
        if(pos == 0) return push_front(val); // If inserting at the front, use push_front
        int i = 0;
        auto current = head;
        while(i++ < pos - 1) current = current->next; // Traverse to the position before the desired index
        auto* newNode = new Node<T>(val);             // Create a new node
        auto next = current->next;                    // Store the next node
        current->next = newNode;                      // Insert the new node
        newNode->next = next;                         // Link the new node to the next node
    }

    // Constructor to initialize the list with a given head node
    explicit List(Node<T>* head): head(head) {}

    // Default constructor to initialize an empty list
    List(): head(nullptr) {}

    // Destructor to clear the list when the object is destroyed
    ~List() {
        clear();
    }
};
