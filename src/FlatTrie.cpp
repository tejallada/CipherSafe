#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <functional>
using namespace std;


class NodeTrie {
    public:
        bool isEnd;

        NodeTrie* children[26];

        NodeTrie() {
            isEnd = false;

            for (int i = 0; i<26; i++) {
                children[i] = nullptr;
            }
        }
        ~NodeTrie() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
                children[i] = nullptr;

            }
        }
    
};

class Trie {
    private: 
        NodeTrie* root;
        int numElements;

    public:

        Trie() {
            root = new NodeTrie();
            numElements = 0;

        }
        
        ~Trie() {
            delete root;
        }

        void insert(const string& password) {
            
            NodeTrie* node = root;

            for (char lc : password) {
                lc = tolower(lc);

                if (node->children[lc-'a'] == nullptr) {
                    node->children[lc-'a'] = new NodeTrie();

                }
                node = node->children[lc-'a'];

            }
            if (node->isEnd == false) {
                node->isEnd = true;

                numElements++;
            }
        }
};