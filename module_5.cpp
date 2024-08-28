//
// Created by Badi on 8/27/2024.
//

// Sorting methods

// 1.- Bubble Sort

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to perform Bubble Sort
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swapping elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swapping elements
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Function to perform Insertion Sort
void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int sort_tests() {
    // Generate a vector of 10000 random integers
    vector<int> arr;
    srand(time(nullptr)); // Seed for random number generation
    for (int i = 0; i < 10000; ++i) {
        arr.push_back(rand() % 10000 + 1); // Generate random numbers between 1 and 10000
    }

    // Sort the vector using each algorithm and measure time
    clock_t start_time, end_time;

    start_time = clock();
    bubble_sort(arr);
    end_time = clock();
    double bubble_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    selection_sort(arr);
    end_time = clock();
    double selection_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    insertion_sort(arr);
    end_time = clock();
    double insertion_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the time taken by each sorting algorithm
    cout << "Bubble Sort time: " << bubble_sort_time << endl;
    cout << "Selection Sort time: " << selection_sort_time << endl;
    cout << "Insertion Sort time: " << insertion_sort_time << endl;

    return 0;
}

