#include <iostream>
#include <chrono> //timer
#include <fstream>
using namespace std;

void LoadTrie() {
    ifstream file("Data/rockyou.txt");
    vector<string> passwords;
    string line;

    if (!file.is_open()) {
        cerr << "Error: could not open file." << endl;
    }

    while (getline(file, line)) {
        passwords.push_back(line);
    }

    file.close();

    cout << "Loaded " << passwords.size() << " passwords." << endl;
    cout << "First password: " << passwords[0] << endl;

}

void LoadHashMap() {
    ifstream file("Data/rockyou.txt");
    vector<string> passwords;
    string line;

    if (!file.is_open()) {
        cerr << "Error: could not open file." << endl;
    }

    while (getline(file, line)) {
        passwords.push_back(line);
    }

    file.close();

    cout << "Loaded " << passwords.size() << " passwords." << endl;
    cout << "First password: " << passwords[0] << endl;
}

void PrintMainMenu() {
    cout<< "=========================\n"
           "CipherSafe Menu\n"
           "=========================\n"
           "1. Check Password Strength\n"
           "2. Generate New Password\n"
           "4. Display Statistics\n"
           "6. Exit\n"
           "=========================\n"
           "Enter your choice:";

}

int main(){

    //Populate the 2 data structures (trie and HashMap)
    std::cout << "Populating Data Structures..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now(); //starting clock
    LoadTrie(); //Load Trie Data Structure
    auto end = std::chrono::high_resolution_clock::now();//stoping clock
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time to load Trie: " << duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); //starting clock
    LoadHashMap(); //Load HashMap Data Structure
    end = std::chrono::high_resolution_clock::now();//stoping clock
    duration = end - start;
    std::cout << "Time to load HashMap: " << duration.count() << " seconds" << std::endl;

    bool exit = false;

    while(!exit) {
        PrintMainMenu();
        exit = true;
    }




    return 0;
}


