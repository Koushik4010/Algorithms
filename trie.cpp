#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node structure
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;  // Indicates if the node represents the end of a word

    TrieNode() : isEndOfWord(false) {}
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    // Check if any word in the Trie starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c]) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

    // Delete a word from the Trie
    bool deleteWord(const string& word) {
        return deleteHelper(root, word, 0);
    }

private:
    // Helper function to delete a word recursively
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        // If last character of the word is reached
        if (depth == word.size()) {
            // This node is no longer end of the word
            if (node->isEndOfWord) {
                node->isEndOfWord = false;

                // If the node has no children, it can be deleted
                return node->children.empty();
            }
            return false;
        }

        char c = word[depth];
        if (deleteHelper(node->children[c], word, depth + 1)) {
            delete node->children[c];
            node->children.erase(c);

            // Check if current node is now redundant
            return node->children.empty() && !node->isEndOfWord;
        }
        return false;
    }
};

// Test the Trie implementation
int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");

    cout << "Search 'apple': " << trie.search("apple") << endl;    // Returns true
    cout << "Search 'app': " << trie.search("app") << endl;        // Returns true
    cout << "Prefix 'app': " << trie.startsWith("app") << endl;    // Returns true

    trie.deleteWord("apple");
    cout << "Search 'apple' after deletion: " << trie.search("apple") << endl; // Returns false

    return 0;
}
