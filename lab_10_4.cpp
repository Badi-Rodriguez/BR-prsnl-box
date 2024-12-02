// Pregunta 4

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class CustomHashMap {
private:
    static const int SIZE = 1000;
    vector<pair<string, int>> map[SIZE];

    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % SIZE;
        }
        return hash;
    }

public:
    void put(const string& key) {
        int hashValue = hashFunction(key);
        for (auto& pair : map[hashValue]) {
            if (pair.first == key) {
                pair.second++;
                return;
            }
        }
        map[hashValue].push_back({key, 1});
    }

    vector<pair<string, int>> getAll() {
        vector<pair<string, int>> result;
        for (int i = 0; i < SIZE; ++i) {
            for (auto& pair : map[i]) {
                result.push_back(pair);
            }
        }
        return result;
    }
};

class MinHeap {
private:
    vector<pair<int, string>> heap;

    void heapifyUp(int idx) {
        while (idx > 0 && compare(heap[idx], heap[(idx - 1) / 2])) {
            swap(heap[idx], heap[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void heapifyDown(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < heap.size() && compare(heap[left], heap[smallest])) {
            smallest = left;
        }
        if (right < heap.size() && compare(heap[right], heap[smallest])) {
            smallest = right;
        }
        if (smallest != idx) {
            swap(heap[idx], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    bool compare(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }

public:
    void push(pair<int, string> newPair) {
        heap.push_back(newPair);
        heapifyUp(heap.size() - 1);
    }

    pair<int, string> pop() {
        if (heap.empty()) return {0, ""};
        pair<int, string> minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }

    int size() {
        return heap.size();
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        CustomHashMap freqMap;

        for (const string& word : words) {
            freqMap.put(word);
        }

        vector<pair<string, int>> freqList = freqMap.getAll();
        MinHeap minHeap;

        for (auto& entry : freqList) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> result;
        while (minHeap.size() > 0) {
            result.push_back(minHeap.pop().second);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
