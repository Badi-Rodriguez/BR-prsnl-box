//
// Created by Badi on 8/27/2024.
//

#include <cmath>
#include <cstdio>
#include <iostream>

using std::cout, std::endl;
template <typename T>
struct Node {
    T data;
    Node* next;
    explicit Node(const T& val): data(val),next(nullptr){};
};

template <typename T>
class List {
    Node<T>* head;
public:
    T front() {
        if(head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }
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
    void push_front(const T& e) {
        auto new_node = new Node<T>(e);
        auto old_head = head;
        head = new_node;
        new_node->next = old_head;
    }

    void push_back(const T& e) {
        if(head == nullptr) {
            head = new Node(e);
            return;
        }
        auto current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        auto new_node = new Node<T>(e);
        current->next = new_node;
    }

    void pop_front() {
        auto temp  = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        auto current = head;
        while (current->next->next!=nullptr) {
            current = current->next;
        }
        auto temp = current->next;
        current->next = nullptr;
        delete temp;
    }

    T& operator[](const int& i) {
        if (i < 0 || i >= size()) {
            throw std::out_of_range("Index out of bounds");
        }
        auto current = head;
        for(int k = 0; k<i;k++ ) {
            current = current->next;
        }
        return current->data;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int s=0;
        auto current = head;
        while(current!=nullptr) {
            s++;
            current = current->next;
        }
        return s;
    }

    void clear() {
        while(head!=nullptr) {
            pop_front();
        }
    }



    void print() {
        auto current = head;
        while(current!=nullptr) {
            printf("%i\n",current->data);
            current = current->next;
        }
    }

    void insert(const T& val, const int pos) {
        if(pos == 0) return push_front(val);
        int i =0;
        auto current = head;
        while( i++ < pos-1) current = current->next;
        auto* newNode = new Node<T>(val);
        auto next = current->next;
        current->next = newNode;
        newNode->next = next;
    }


    explicit List(Node<T>* head): head(head) {}

    List():head(nullptr){}
    ~List() {
        clear();
    }
};