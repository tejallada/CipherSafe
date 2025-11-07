#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include <string>
#include "../src/Strength_check.cpp"
#include "../src/FlatTrie.cpp"
#include "../src/FlatHashMap.cpp"


Trie trie;
HashMap hashMap;

TEST_CASE("Test weak", "[strngth]") {
    
    trie.insert("pass1234");
    hashMap.Insert("pass1234", 1);
    
    SECTION("Common password test") {
        std::string password = "pass1234";
        StrengthCheck(password, false);
    }

    SECTION("Short password test") {
        std::string password = "abc";
        StrengthCheck(password, false);
    }
}

TEST_CASE("Test strong", "[strngth]") {
    SECTION("long password") {
        std::string password = "THisisaLongPass123!!";
        StrengthCheck(password, false);
    }
    SECTION("special character password") [
        std::string password = "P@ss@$1234";
        StrengthCheck(password, false);
    ]
}