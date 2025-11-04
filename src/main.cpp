#include <iostream>
#include <chrono> //timer
#include <fstream>
#include "FlatHashMap.cpp"
#include "FlatTrie.cpp"
#include <cstdlib>

using namespace std;
HashMap myHashMap; //Actual hashmap we are calling
Trie myTrie;
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
    bool inTrie = false;
        string substringPass = userPassword;
        for(int i = 0; i < userPassword.length(); i++){
            substringPass = substringPass.substr(1);
            cout << "Substring pass: " << substringPass << endl;
            if (myTrie.search(substringPass)) {
                weakReason = weakReason + "Contains the derivitive of a common password";
                strength = "Semi-Weak";

            }
        }

    if (myHashMap.search(userPassword)) {
        weakReason += "Password found in common dataset";
        strength = "Weak";
        cout << "Password found." << endl;
    } else if (userPassword.length() < 5) {
        strength = "Weak";
        weakReason += "Too short of a password\n";
    }else if (!inTrie){
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
    std::chrono::duration<double> triePopulationTime = end - start;
    std::cout << "Time to load Trie: " << triePopulationTime.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); //starting clock
    LoadHashMap(myHashMap); //Load HashMap Data Structure
    end = std::chrono::high_resolution_clock::now();//stoping clock
    std::chrono::duration<double> hashMapPopulationTime = end - start;
    std::cout << "Time to load HashMap: " << hashMapPopulationTime.count() << " seconds" << std::endl;

    bool exit = false;

    //Program is running
    while(!exit) {
        PrintMainMenu();
        string menuSelection;
        cin >> menuSelection;
        if (menuSelection == "1") {
            cout << "Enter password: " << endl;
            string usrPass;
            cin >> usrPass;
            cout << "Checking Password Strength..." << endl;
            StrengthCheck(usrPass); //check the strength of the password and explain why
        }else if (menuSelection == "2") {
            int passLength;
            cout << "Enter Password Length: " << endl;
            cin >> passLength;
            cout << "Generating Password..." << endl;
            string newPassword;
            for (int i = 0; i < passLength; i++) {
                if (rand()%2 == 1) {
                    char randomLowercaseLetter = 'a' + (rand() % 26);
                    newPassword += randomLowercaseLetter;
                }else {
                    char randomUppercaseLetter = 'A' + (rand() % 26);
                    newPassword += randomUppercaseLetter;
                }
                cout << "New Password: " << newPassword << endl;
            }
        }else if (menuSelection == "3") {
            //Print Stats:
            /*
             Average Hasmap vs average Trie Time difference
            HashMap vs Trie search time difference
            triePopulationTime.count()
            hashMapPopulationTime.count()
            */
        }else if (menuSelection == "4") {
            cout << "Thank you for using CipherSafe";
            exit = true;    //exit program
        }else {
            cout << "Invalid input, please type only 1, 2, 3, or 4" << endl; //not a valid input
        }


    }
    return 0;
}


