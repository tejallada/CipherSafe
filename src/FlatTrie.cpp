#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <functional>
#include <unordered_map>
using namespace std;


class NodeTrie {
    public:
        bool isEnd;
        //switched to unordered map for special characters
        unordered_map<char, NodeTrie*> children;

        NodeTrie() {
            isEnd = false;
        }
        ~NodeTrie() {
            for (auto &each : children) {
                delete each.second;
            }
            children.clear();
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
                if (node->children.count(lc) == false) {
                    node->children[lc] = new NodeTrie();
                }
                node = node->children[lc];

            }
            if (node->isEnd == false) {
                node->isEnd = true;

                numElements++;
            }
        }

        bool search(const string& password) {
            NodeTrie* node = root;

            for (char lc : password) {
                if (node->children.count(lc) == false)  {
                    return false;
                }
                node = node->children[lc];
            }
            return node->isEnd;
        }

        int getSize() const {
            return numElements;
        }

};