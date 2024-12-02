//
// Created by Badi on 8/27/2024.
//

// Node and tree based implementation

#include <forward_list>
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;
    // So on and so forth
};

int module_1(){
    std::forward_list<int> fList_1;
    std::forward_list<int> fList_2;
    std::forward_list<int> fList_3;

    fList_1.assign({0, 1, 2, 3, 4});
    fList_2.assign({5, 6, 7, 8, 9});
    fList_3.assign(fList_1.begin(), fList_2.end());

    std::cout << "fList_1 contents: ";
    for (int& elem : fList_1){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "fList_2 contents: ";
    for (int& elem : fList_2){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "fList_3 contents: ";
    for (int& elem : fList_3){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}