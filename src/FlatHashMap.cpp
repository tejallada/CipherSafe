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

        void resizeTable() {
            
        }
};