//
// Created by nate on 3/26/2024.
//
// I'm here, too!!
#include <iostream>
#include <string>
#include <fstream>
void functionName(std::string value) {
    if (value == "initative") {
        
    }
    if (value == "class") {

    }
}
int main() {

    std::ifstream myfile ("MainDungeon.dandd");
    std::string codeinput = "";
    int countingthelines = 0;
    if ( myfile.is_open() ) { // always check whether the file is open
        while ( myfile ) { // loops until the end of the line
            std::getline(myfile, codeinput); // Grabs a full line of the file
            countingthelines++;
            if (codeinput == "_^") {
                std::cout << "Comment (so ignore)" ;
            }
            if (codeinput.find("roll") == 0) { // If roll is the first part of the line
                std::cout << "Comment (so ignore)" ;
            }
            else {  std::cout << codeinput; // << countingthelines; // pipe stream's content to standard output
            }
        }
    }
    return 0;
}
