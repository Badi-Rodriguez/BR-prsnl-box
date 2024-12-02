// Pregunta 3

#include <iostream>
#include <vector>
using namespace std;

#define ALPHABET_SIZE 26

// Node of the Trie
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    // Helper function for searching with one character difference
    bool searchWithModification(TrieNode* node, const string& word, int index, bool modified) {
        if (index == word.length()) {
            return modified && node->isEndOfWord;
        }

        int originalIndex = word[index] - 'a';
        // Try without modifying current character
        if (node->children[originalIndex] != nullptr) {
            if (searchWithModification(node->children[originalIndex], word, index + 1, modified)) {
                return true;
            }
        }

        // Try modifying current character (only if no previous modification)
        if (!modified) {
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (i != originalIndex && node->children[i] != nullptr) {
                    if (searchWithModification(node->children[i], word, index + 1, true)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search if there exists a word with exactly one character modified
    bool searchWithModification(const string& word) {
        return searchWithModification(root, word, 0, false);
    }
};

class MagicDictionary {
private:
    Trie trie;

public:
    MagicDictionary() {
    }

    // Build dictionary by inserting all words into the Trie
    void buildDict(vector<string> dictionary) {
        for (const string& word : dictionary) {
            trie.insert(word);
        }
    }

    // Search for a word that differs by exactly one character
    bool search(string searchWord) {
        return trie.searchWithModification(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */