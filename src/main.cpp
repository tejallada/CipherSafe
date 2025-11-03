#include <iostream>
#include <chrono> //timer
#include <fstream>
#include "FlatHashMap.cpp"
#include "FlatTrie.cpp"

using namespace std;
HashMap myHashMap; //Actual hashmap we are calling
vector<string> passwords; //filler for Trie

void LoadTrie() {
    ifstream file("Data/rockyou.txt");
    string line;

    if (!file.is_open()) {
        cerr << "Error: could not open file." << endl;
    }

    while (getline(file, line)) {
        passwords.push_back(line);
    }

    file.close();

    cout << "Loaded " << passwords.size() << " passwords." << endl;

}

void LoadHashMap(HashMap& dict) {
    ifstream file("Data/rockyou.txt");
    string line;
    if (!file.is_open()) {
        cerr << "Error: could not open file." << endl;
    }
    while (getline(file, line)) {
        if (!line.empty()) dict.Insert(line, 1);
    }
    file.close();
    cout << "Loaded " << dict.getNumElements() << " passwords." << endl;
}

void StrengthCheck(string& userPassword) {
    string weakReason = "";
    string strength = "Strong";
    if (myHashMap.search(userPassword)) {

        //check the trie after this

        cout << "Password found." << endl;
    } else if (userPassword.length() < 5) {
        strength = "Weak";
        weakReason += "Too short of a password\n";
    }else {
        cout << "you have a strong password" << endl;
    }
    cout << "Password Strength: " << strength << endl;
    cout << "Reason:\n" << weakReason << endl;
}

void PrintMainMenu() {
    cout<< "=========================\n"
           "CipherSafe Menu\n"
           "=========================\n"
           "1. Check Password Strength\n"
           "2. Generate New Password\n"
           "3. Display Statistics\n"
           "4. Exit\n"
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
    LoadHashMap(myHashMap); //Load HashMap Data Structure
    end = std::chrono::high_resolution_clock::now();//stoping clock
    duration = end - start;
    std::cout << "Time to load HashMap: " << duration.count() << " seconds" << std::endl;

    bool exit = false;

    //Program is running
    while(!exit) {
        PrintMainMenu();
        string menuSelection;
        cin >> menuSelection;
        if (menuSelection == "1") {
            cout << "Checking Password Strength" << endl;
        }else if (menuSelection == "2") {
            cout << "Enter password: " << endl;
            string usrPass;
            cin >> usrPass;
            StrengthCheck(usrPass); //check the strength of the password and explain why
        }else if (menuSelection == "3") {
            //ask for password length
            //generate password
        }else if (menuSelection == "4") {
            cout << "Thank you for using CipherSafe";
            exit = true;    //exit program
        }else {
            cout << "Invalid input, please type only 1, 2, 3, or 4" << endl; //not a valid input
        }


    }
    return 0;
}


