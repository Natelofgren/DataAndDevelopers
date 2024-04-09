//
// Created by nate on 3/26/2024.
//
// I'm here, too!!
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream myfile ("MainDungeon.dandd");


    std::string codeinput = "";

    if ( myfile.is_open() ) { // always check whether the file is open
        myfile >> codeinput; // pipe file's content into stream
        std::cout << codeinput; // pipe stream's content to standard output
    }

    int x = 1;
    std::cout << "Hello, World!" << std::endl;
    printf("Hello \t, %d %d World \n", x,x);
    return 0;
}
