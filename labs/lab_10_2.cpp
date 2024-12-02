// Pregunta 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ALPHABET_SIZE 26

// TrieNode representing each character in a word
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    vector<string> suggestions; // Top 3 lexicographically smallest products

    TrieNode() {
        fill(begin(children), end(children), nullptr); // Initialize children as nullptr
    }
};

class Trie {
private:
    TrieNode* root;

    // Insert a product into the Trie and maintain top 3 lexicographically smallest suggestions at each node
    void insertWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];

            // Maintain top 3 lexicographically smallest suggestions
            if (node->suggestions.size() < 3) {
                node->suggestions.push_back(word);
            } else if (word < node->suggestions[2]) {
                node->suggestions[2] = word;
            }
            sort(node->suggestions.begin(), node->suggestions.end());
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Build the Trie from the list of products
    void buildTrie(const vector<string>& products) {
        for (const string& product : products) {
            insertWord(product);
        }
    }

    // Retrieve suggestions for the given prefix
    vector<string> getSuggestionsForPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index]) return {}; // No suggestions if prefix not found
            node = node->children[index];
        }
        return node->suggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;

        // Sort products and build the Trie
        sort(products.begin(), products.end());
        trie.buildTrie(products);

        // Get suggestions for each prefix of searchWord
        vector<vector<string>> result;
        string prefix;
        for (char ch : searchWord) {
            prefix += ch;
            result.push_back(trie.getSuggestionsForPrefix(prefix));
        }

        return result;
    }
};
