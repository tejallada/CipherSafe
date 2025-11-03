#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <functional>
using namespace std;


class Node {
    public:
        string key;
        int value;

        Node(string key, int value) {
            this -> key = key;
            this -> value = value;
        }
};


class HashMap {
    private:
        int numElements;
        int tableSize;
        vector<list<Node> > table;
        hash<string> passwordHash;

        int hashingFunction(string& key) {
            return passwordHash(key) % tableSize;
        }

        void resizeInsertion(string& key, int value) {
            int index = hashingFunction(key);
            list<Node>& bucket = table[index];

            for(Node& node : bucket) {
                if(node.key == key) {
                    node.value = value;
                    return;
                }
            }
            bucket.emplace_back(key, value);
            numElements++;
        }

        void resizeTable() {
            int previousTableSize = tableSize;
            vector<list<Node> > previousTable = move(table);
            tableSize *= 2;
            numElements = 0;
            table.clear();
            table.resize(tableSize);

            for(int i = 0; i < previousTableSize; ++i) {
                for(Node& node : previousTable[i]) {
                    resizeInsertion(node.key, node.value);
                }
            }
        }

    public:
        HashMap(int startingSize = 5) {
            tableSize = startingSize;
            numElements = 0;
            table.resize(tableSize);
        }

        float getLoadFactor() {
            if(tableSize == 0) return 0.0f;
            else return (float)numElements / tableSize;
        }
};