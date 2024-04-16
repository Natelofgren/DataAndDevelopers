//
// Created by nate on 3/26/2024.
//
// I'm here, too!!
#include <iostream>
#include <string>
#include <fstream>

enum token
{
    IDENTIFIER = 1,
    OPERATOR = 2,
    EOC = 3,
    EQUALS = 4,
    NUMBER = 5
};

// tstd::stringhe function below takes a string and sends back the string until the first space
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


void tokenizer(std::string line){   //This is where everything is converted to tokens
    if (until_space(line) == "roll"){
    }
    else if (until_space(line) == "nat") {

    }
    else if (until_space(line) == "dungeon") {

    }
    else if (until_space(line) == "say") {

    }
    else if (until_space(line) == "quest") {

    }
    else if (until_space(line) == "railroad") {

    }
    else {

    }
}

void lexer() { // This is the first step where we get the input from the file
    std::ifstream myfile ("MainDungeon.dandd");
    std::string codeinput = "";
    int countingthelines = 0;
    if ( myfile.is_open() ) { // always check whether the file is open
        while ( myfile ) { // loops until the end of the line
            std::getline(myfile, codeinput); // Grabs a full line of the file
            countingthelines++;
            if (codeinput == "_^") {
            }
            else  { // Sends the line to tokenizer to be tokenized!
                tokenizer(codeinput);
            }
        }

    }
}

void parser() { // This is the first step where we get the input from the file
}

int main() {
    lexer();
    return 0;
}
