#include <iostream>
#include <chrono> //timer
int main(){

    //Populate the 2 data structures (trie and HashMap)
    std::cout << "Populating Data Structures..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now(); //starting clock


    //Load Trie Data Structure


    auto end = std::chrono::high_resolution_clock::now();//stoping clock
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    //


    return 0;
}