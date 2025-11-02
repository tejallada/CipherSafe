#include <iostream>
#include <chrono> //timer
int main(){

    //Populate the 2 data structures (trie and HashMap)
    std::cout << "Populating Data Structures..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now(); //starting clock

    //temp placeholder
    for (int i = 0; i < 100000; i++) {
        int val = 0;
    }

    loadTrie();
    //Load Trie Data Structure


    auto end = std::chrono::high_resolution_clock::now();//stoping clock
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time to load Trie: " << duration.count() << " seconds" << std::endl;


    start = std::chrono::high_resolution_clock::now(); //starting clock


    //Load HashMap Data Structure


    end = std::chrono::high_resolution_clock::now();//stoping clock
    duration = end - start;
    std::cout << "Time to load HashMap: " << duration.count() << " seconds" << std::endl;






    return 0;
}

void loadTrie() {
    for ()
}
