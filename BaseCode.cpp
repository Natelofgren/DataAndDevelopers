//
// Created by nate on 3/26/2024.
//
// I'm here, too!!
#include <iostream>
#include <string>
#include <fstream>

class token {       // The class token
public:             // Access specifier
    std::string IDENTIFIER = "IDENTIFIER";
    std::string OPERATOR = "OPERATOR";
    std::string EOC = "ENDOFCOMMAND";
    std::string EQUALS = "EQUALS";
    std::string VALUE = "VALUE";  // Attribute (string variable)
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

std::string until_astrix(std::string const& s) {
    std::string::size_type pos = s.find('*');
    if (pos != std::string::npos) {
        return s.substr(0, pos);
    }
    else {
        return s;
    }
}
token tokenizer(std::string line){   //This is where everything is converted to tokens
    token returntoken;

    if (until_space(line) == "roll"){
    }
    else if (until_space(line) == "nat") {

    }
    else if (until_space(line) == "dungeon") {

    }
    else if (until_space(line) == "say") {
        returntoken.IDENTIFIER = "say";
        line = line.erase(0, 5);
        returntoken.VALUE = until_astrix(line);
        returntoken.EOC = line.back();
    }
    else if (until_space(line) == "quest") {

    }
    else if (until_space(line) == "railroad") {

    }
    else {
    }
    return returntoken;
}

void parser(token tokenlist[] ) { // This is the final step where we turn the tokens in order
    std::cout << (tokenlist[0].EOC);
}

void lexer() { // This is the first step where we get the input from the file
    std::ifstream myfile ("MainDungeon.dandd");
    std::string codeinput = "";
    int countingthelines = 0;
    token tokenlist[255];
    if ( myfile.is_open() ) { // always check whether the file is open
        while ( myfile ) { // loops until the end of the line
            std::getline(myfile, codeinput); // Grabs a full line of the file
            if (codeinput == "_^") {
            }
            else  { // Sends the line to tokenizer to be tokenized and save the result in the list called tokens
                tokenlist[countingthelines] = (tokenizer(codeinput));
                countingthelines++;
            }
        }

    }
    parser(tokenlist);



}


int main() {
    lexer();
    return 0;
}
