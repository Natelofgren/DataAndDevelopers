//
// Created by nate on 3/26/2024.
//
// I'm here, too!!
#include <iostream>
#include <string>
#include <fstream>

//The code below is helpful function that isn't actually running stuff based of the code
// the function below takes a string and sends back the string until the first space
std::string until_space(std::string const& s)
{
    std::string::size_type pos = s.find(' ');
    if (pos != std::string::npos)
    {
        return s.substr(0, pos);
    }
    else
    {
        return s;
    }
}
// Functions below are for running the virtual code
void create_function_or_class(std::string value) { // This is used for rolling initiative or for creating a class
    if (value == "initative") {
        std::cout << "Yall need to roll initative";
    }
    if (value == "class") {
        std::cout << "Yall need to make a class";
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
            else if (codeinput.find("roll") == 0) { // If roll is the first part of the line
                codeinput.erase(0,5); //removes roll (we already read it)
                create_function_or_class(until_space(codeinput));
            }
            else {  std::cout << codeinput; // << countingthelines; // pipe stream's content to standard output
            }
        }
    }
    return 0;
}
