//
// Created by Badi on 8/27/2024.
//

// Pointer knowledge and criteria:

// Standard elements
#include <iostream>

int main() {
    int a = 5;           // Declare an integer variable
    int* ptr = &a;       // Declare a pointer to int and initialize it with the address of 'a'

    std::cout << "Value of a: " << a << std::endl;         // Output: 5
    std::cout << "Address of a: " << &a << std::endl;      // Outputs the memory address of 'a'
    std::cout << "Value of ptr (address of a): " << ptr << std::endl;  // Outputs the memory address of 'a'
    std::cout << "Value pointed by ptr: " << *ptr << std::endl;  // Dereference the pointer to get the value of 'a'

    return 0;
}

// Null pointers

int* ptr = nullptr;  // Initialize a pointer with null

if (ptr == nullptr) {
std::cout << "Pointer is null." << std::endl;
}



