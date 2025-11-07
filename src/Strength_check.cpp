#include <iostream>
#include <chrono> //timer
#include <fstream>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <functional>
#include <unordered_map>
#include "../src/FlatTrie.cpp"
#include "../src/FlatHashMap.cpp"


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