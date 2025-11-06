#include <iostream>
#include <chrono> //timer
#include <fstream>
#include "FlatHashMap.cpp"
#include "FlatTrie.cpp"
#include <thread>

using namespace std;
HashMap myHashMap; //Actual hashmap we are calling
Trie myTrie;
std::chrono::duration<double> hashMapSearchTime;
std::chrono::duration<double> trieSearchTime;

int trieSearchCount = 0;
int hashMapSearchCount = 0;

void LoadTrie(Trie& _Trie) {
    ifstream file("Data/rockyou.txt");
    string line;

    if (!file.is_open()) {
        cerr << "Error: could not open file." << endl;
    }

    while (getline(file, line)) {
        if (!line.empty()) _Trie.insert(line);
    }

    file.close();
    int size = _Trie.getSize();
    cout << "Loaded " << size << " passwords." << endl;

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

void StrengthCheck(string& userPassword, bool fullPassword = false) {
    string weakReason = "";
    string strength = "Strong";
    int startingIndex = 0;
    if (fullPassword) {
        startingIndex = -1;
    }

    bool inTrie = false;
        string substringPass = userPassword;
        for(int i = startingIndex; i < userPassword.length(); i++){
            substringPass = substringPass.substr(1);

            auto trieStart = std::chrono::high_resolution_clock::now();

            if (myTrie.search(substringPass)) {
                weakReason += "Contains the derivative " + myTrie.getPrevSearch() + " of a common password\n";
                strength = "Semi-Weak";
                auto trieEnd = std::chrono::high_resolution_clock::now();//stoping clock
                trieSearchTime += trieEnd - trieStart;
                trieSearchCount += 1;
                break;

            }
        }

    auto hashMapStart = std::chrono::high_resolution_clock::now(); //starting clock
    if (myHashMap.search(userPassword)) {
        auto hashMapEnd = std::chrono::high_resolution_clock::now();//stoping clock
        hashMapSearchTime += hashMapEnd - hashMapStart;
        hashMapSearchCount += 1;
        weakReason += "Password found in common dataset\n";
        strength = "Weak";
    } else if (userPassword.length() < 5) {
        strength = "Weak";
        weakReason += "Too short of a password\n";
    }else if (!inTrie){
        cout << "you have a strong password" << endl;
    }
    cout << "Password Strength: " << strength << endl;
    if (strength != "Strong") {
        cout << "Reason:\n" << weakReason << endl;
    }
}

void PrintMainMenu() {
    cout<< "\n\n\n=========================\n"
           "CipherSafe Menu\n"
           "=========================\n"
           "1. Check Password Strength\n"
           "2. Generate New Password\n"
           "3. Display Statistics\n"
           "4. Exit\n"
           "=========================\n"
           "Enter your choice:";

}

void HashMapSearchTime() {

}

int main(){

    //Populate the 2 data structures (trie and HashMap)
    std::cout << "Populating Data Structures..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now(); //starting clock
    LoadTrie(myTrie); //Load Trie Data Structure
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
        cout<<endl;
        if (menuSelection == "1") {
            cout << "Enter password: ";
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
                if (rand()%4 == 1) {
                    char randomUppercaseLetter = 'A' + (rand() % 26);
                    newPassword += randomUppercaseLetter;
                }else {
                    char randomLowercaseLetter = 'a' + (rand() % 26);
                    newPassword += randomLowercaseLetter;
                }
            }
            cout << "New Password: " << newPassword << endl;
        }else if (menuSelection == "3") {
            //Print Stats:
            /*
            Average Hashmap vs Average Trie Time difference
            HashMap vs Trie search time difference */
            cout << "Trie Population Time: " << triePopulationTime.count() << endl;
            cout << "Number of passwords in Trie: " << myTrie.getSize() << endl;
            cout << "HashMap Population Time: " << hashMapPopulationTime.count() << endl;
            cout << "Number of passwords in HashMap: " << myHashMap.getNumElements() << endl;
            cout<<endl;
            cout << "Hashmap Search Time: "<< hashMapSearchTime.count()/hashMapSearchCount << endl;
            cout << "Trie Search Time: " << trieSearchTime.count()/trieSearchCount << endl;
        }else if (menuSelection == "4") {
            cout << "Thank you for using CipherSafe";
            exit = true;    //exit program
        }else {
            cout << "Invalid input, please type only 1, 2, 3, or 4" << endl; //not a valid input
        }

        this_thread::sleep_for(std::chrono::seconds(4)); //delay the menu showing up for 4 seconds
    }
    return 0;
}


