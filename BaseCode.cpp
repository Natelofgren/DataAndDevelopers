//
// Created by nate on 3/26/2024.
//
// I'm here, too!!
#include <iostream>
#include <string>
#include <fstream>

class token {       // The class token
public:             // Access specifier
    std::string IDENTIFIER = "IDENTIFIER"; //Main type of statment the token is
    std::string OPERATOR = "OPERATOR";
    std::string EOC = "ENDOFCOMMAND"; //The last part of the line
    std::string EQUALS = "EQUALS";
    std::string VALUE = "VALUE";  // Information the user inputs
};
// tstd::stringhe function below takes a string and sends back the string until the first space
std::string until_char(std::string const& s, char thing)
{
    std::string::size_type pos = s.find(thing);
    if (pos != std::string::npos)
    {
        return s.substr(0, pos);
    }
    else
    {
        return s;
    }
}

token tokenizer(std::string line){   //This is where everything is converted to tokens
    token returntoken;
    if (until_char(line, ' ' ) == "roll"){
        returntoken.IDENTIFIER = "MAIN";
        line = line.erase(0, 5);
        if (until_char(line, ' ') == "initiative") {
            returntoken.OPERATOR = "START";
            line = line.erase(0, 11);
            returntoken.EOC =  line;
        }
    }
    else if (until_char(line, ' ') == "nat") {
        returntoken.IDENTIFIER = "VARIABLE";
        line = line.erase(0, 4);
        if (until_char(line, ' ') == "kobold") {
            returntoken.OPERATOR = "INTEGER";
            line = line.erase(0, 7);
            returntoken.VALUE = until_char(line, ' ');
            line = line.erase(0, line.find(' '));
            returntoken.EQUALS = until_char(line, line.back());
            returntoken.EOC = line.back();
        }
        if (until_char(line, ' ') == "dragon") {
            returntoken.OPERATOR = "STRING";
            line = line.erase(0, 7);
            returntoken.VALUE = until_char(line, ' ');
            line = line.erase(0, (line.find(' ') + 1));
            returntoken.EQUALS = until_char(line, '*');
            returntoken.EOC = line.back();
        }
    }

    else if (until_char(line, ' ' ) == "say") {
        returntoken.IDENTIFIER = "PRINT";
        line = line.erase(0, 5);
        returntoken.VALUE = until_char(line, '*');
        returntoken.EOC = line.back();
    }
    else if (until_char(line, ' ') == "quest") {

    }
    else if (until_char(line, ' ') == "railroad") {

    }
    else {
    }
    return returntoken;
}

void parser(token tokenlist[] ) { // This is the final step where we turn the tokens in order
    std::cout << (tokenlist[5].EOC);
}

void lexer() { // This is the first step where we get the input from the file
    std::ifstream myfile ("MainDungeon.dandd");
    std::string codeinput = "";
    int countingthelines = 0;
    token tokenlist[255];
    if ( myfile.is_open() ) { // always check whether the file is open
        while ( myfile ) { // loops until the end of the line
            std::getline(myfile, codeinput); // Grabs a full line of the file
            if (codeinput == "_^"){
                // Ignore the comment
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
