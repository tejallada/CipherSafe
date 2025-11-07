#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include <string>
#include "../src/FlatTrie.cpp"

TEST_CASE("Basic Tests", "[trie]") {
    Trie trie;

    SECTION("Empty") {

        REQUIRE(trie.getSize() == 0);

        REQUIRE(trie.search("hi") == false);
    }
    SECTION("Insert Once") {
        
        trie.insert("hi");

        REQUIRE(trie.search("hi") == true);
        REQUIRE(trie.search("h") == false);

    }

    SECTION("Insert Multiple") {
        trie.insert("hi");
        trie.insert("by");

        REQUIRE(trie.getSize() == 2);

        REQUIRE(trie.search("hi") == true);
        REQUIRE(trie.search("by") == true);

        REQUIRE(trie.search("b") == false);
    }

}