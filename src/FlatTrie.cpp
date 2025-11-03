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
};