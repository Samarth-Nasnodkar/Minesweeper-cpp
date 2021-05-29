#include<iostream>
#include<chrono>
#include"Minesweeper.hpp"

int main(){
    Minesweeper ms;
    auto start = std::chrono::high_resolution_clock::now();
    ms.generate();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    ms.display();
    std::cout<<"Executed in "<<duration.count()<<" micros\n";
    return 0;
}
