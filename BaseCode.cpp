//
// Created by nate on 3/26/2024.
//
// I'm here, too!!
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class token {       // The class token
public:             // Access specifier
    std::string IDENTIFIER = "IDENTIFIER"; //Main type of statment the token is (example Roll is identifier and so is nat)
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

std::vector<token> tokenizer(std::string code){   //This is where everything is converted to tokens
    std::vector<token> tokenlist;
    std::string tokenpiece = "starting the loop";
    while  (code.length() > 0) {
        tokenpiece = until_char(code, ' ');
        code.erase(0, 1);
        if (tokenpiece == "roll") {
            token returntoken;
            returntoken.IDENTIFIER = "MAIN";
            tokenlist.push_back(returntoken);

        } else if (tokenpiece == "initiative") {
            token returntoken;
            returntoken.OPERATOR = "START";
            tokenlist.push_back(returntoken);

        } else if (tokenpiece == "nat") {
            token returntoken;
            returntoken.IDENTIFIER = "VARIABLE";
            tokenlist.push_back(returntoken);

        } else if (tokenpiece == "kobold") {
            token returntoken;
            returntoken.OPERATOR = "INTEGER";
            tokenlist.push_back(returntoken);

        }
        else if (tokenpiece == "dragon") {
            token returntoken;
            returntoken.OPERATOR = "STRING";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "say") {
            token returntoken;
            returntoken.IDENTIFIER = "PRINT";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece[0] == '*') {
            tokenpiece = tokenpiece.erase(0,1);
            token returntoken;
            returntoken.VALUE = until_char(tokenpiece, '*' );
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "quest") {

        } else if (tokenpiece == "railroad") {

        } else {
        }
    }
    return tokenlist;
}

void parser(token tokenlist[] ) { // This is the final step where we turn the tokens in order
}

std::string lexer() { // This is the first step where we get the input from the file
    std::ifstream myfile ("MainDungeon.dandd");
    std::string codeinput = "";
    std::string finalstring ="";
    int countingthelines = 0;
    if ( myfile.is_open() ) { // always check whether the file is open
        while ( myfile ) { // loops until the end of the line
            std::getline(myfile, codeinput); // Grabs a full line of the file
            if (codeinput == "_^"){
                // Ignore the comment
            }
            else  { // Sends the line to tokenizer to be tokenized and save the result in the list called tokens
                finalstring.append(codeinput + " ");
            }
        }

    }
    return finalstring;


}


int main() {
    std::vector<token> tokenlist = tokenizer(lexer());
    std::cout << tokenlist[0].IDENTIFIER;
    return 0;
}
