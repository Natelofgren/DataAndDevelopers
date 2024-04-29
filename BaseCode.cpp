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
    int RIGHT = 123456;
    int LEFT = 123456;
};
// the function below takes a string and sends back the string until the first space
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
        int remove = tokenpiece.length() + 1;
        if (remove == 0) {
            remove = 1;
        }
        code = code.erase(0, remove);
        //std::cout <<code;
        //std::cout << "/\\";
        if (tokenpiece == "roll") { //tokenizes word for object or function
            token returntoken;
            returntoken.IDENTIFIER = "MAIN";
            tokenlist.push_back(returntoken);

        } else if (tokenpiece == "initiative") { //tokenizes the word main function that starts the code
            token returntoken;
            returntoken.OPERATOR = "START";
            tokenlist.push_back(returntoken);

        } else if (tokenpiece == "nat") {//tokenizes the word for the start of a variable
            token returntoken;
            returntoken.IDENTIFIER = "VARIABLE";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "kobold") {
            token returntoken;
            returntoken.OPERATOR = "INTEGER";
            tokenlist.push_back(returntoken);
        }
        else if (tokenpiece == "dragon") {//tokenizes the word that defines a string
            token returntoken;
            returntoken.OPERATOR = "STRING";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "goblin") {//tokenizes the word that defines a 
                token returntoken;
                returntoken.OPERATOR = "BOOLEAN";
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
        } else if (isdigit(tokenpiece[0])) {
            token returntoken;
            returntoken.VALUE = tokenpiece;
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "chest") {
            token returntoken;
            returntoken.VALUE = "TRUE";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "mimic") {
            token returntoken;
            returntoken.VALUE = "FALSE";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "?") {
            token returntoken;
            returntoken.EOC = "END";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "<>") {
            token returntoken;
            returntoken.EOC = "OPENBRACKET";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "><") {
            token returntoken;
            returntoken.EOC = "CLOSEDBRACKET";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "//") {
            token returntoken;
            returntoken.EOC = "OPENIF";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "\\\\") {
            token returntoken;
            returntoken.EOC = "CLOSEDIF";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "&") {
            token returntoken;
            returntoken.OPERATOR = "PLUS";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "–") {
            token returntoken;
            returntoken.OPERATOR = "MINUS";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "·") {
            token returntoken;
            returntoken.OPERATOR = "MULTIPLY";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "÷") {
            token returntoken;
            returntoken.OPERATOR = "DIVIDE";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "is") {
            token returntoken;
            returntoken.OPERATOR = "IFEQUALS";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "quest") {
            token returntoken;
            returntoken.IDENTIFIER = "IF";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "sidequest") {
            token returntoken;
            returntoken.IDENTIFIER = "IFELSE";
            tokenlist.push_back(returntoken);
        } else if (tokenpiece == "railroad") {
            token returntoken;
            returntoken.IDENTIFIER = "ELSE";
            tokenlist.push_back(returntoken);
        } else {
        }
    }
    return tokenlist;
}

// This is the second to last step where we turn the tokens in order

std::vector<token> parser(std::vector<token>  tokenlist) {
    int lastoperator = 0;
    bool firstvalue = 0;

    for (int i = 0; i < tokenlist.size(); i++ ){ //loops through all the items in the token list
        if (firstvalue == 0 && tokenlist[i].VALUE != "VALUE" ){
            tokenlist[i].LEFT = i;
            firstvalue = i;
            //std::cout << "assigned a left value ";

        } else if (tokenlist[i].OPERATOR != "OPERATOR") {
            if (lastoperator == 0){
                lastoperator = firstvalue;
            }
            tokenlist[i].LEFT = (lastoperator);
            lastoperator = i;
            //std::cout << "assigned a left value ";
            if (tokenlist[i + 1].VALUE != "VALUE") {
                tokenlist[i].RIGHT = i + 1;
                //std::cout << "assigned a right value ";
            }
        }
        for (int i = 0; i < tokenlist.size(); i++ ) { //loops
            if (tokenlist[i].IDENTIFIER != "IDENTIFIER") {
                tokenlist[i].LEFT = lastoperator;
                if (tokenlist[tokenlist.size() - 1].EOC != "EOC") {
                    tokenlist[i].RIGHT = tokenlist.size() - 1;
                }
            }
        }
    }
    return tokenlist;
}
void treeinator(std::vector<token>  tokenlist) {
    std::string rightnumber = "";
    for (int i = tokenlist.size() - 1; i >= 0; i-- ){
        std::string spaces = "";
        //loops through all the items in the token list building a tree
        for (int l = 0; l < tokenlist.size(); l++  ) {
            spaces.append("_");
        }
        if (tokenlist[i].LEFT != 123456) {
            if (tokenlist[i].IDENTIFIER != "IDENTIFIER"){
                std::cout << ("\n/" + spaces);
                std::cout << tokenlist[i].IDENTIFIER;
                if (tokenlist[i].RIGHT != 123456) {
                    rightnumber.append("/\\" + tokenlist[tokenlist[i].RIGHT].EOC);
                }
            }
            }
        }
    for (int i = tokenlist.size() - 1; i >= 0; i-- ){
        std::string spaces = "";
        //loops through all the items in the token list building a tree
        for (int l = i; l >= 0; l--  ) {
            spaces.append("_");
        }
         if (tokenlist[i].LEFT != 123456) {
             std::cout << ("\n/" + spaces);
             if (tokenlist[i].VALUE != "VALUE") {
                 std::cout << tokenlist[i].VALUE;
                 std::cout << (rightnumber);
                 if (rightnumber != "") {
                     rightnumber = "";
                 }
             } else if (tokenlist[i].OPERATOR != "OPERATOR") {
                 std::cout << tokenlist[i].OPERATOR;
                 std::cout << (rightnumber);
                 if (rightnumber != "") {
                     rightnumber = "";
                 }
                 if (tokenlist[i].RIGHT != 123456) {
                     rightnumber.append("/\\" + tokenlist[tokenlist[i].RIGHT].VALUE);
                 }
            }
         }
    }


}




std::string lexer() { // This is the first step where we get the input from the file
    std::ifstream myfile ("MainDungeon.dandd");
    std::string codeinput = "";
    std::string finalstring ="";
    std::string lastcodeinput ="";
    if ( myfile.is_open() ) { // always check whether the file is open
        while ( myfile ) { // loops until the end of the line
            std::getline(myfile, codeinput); // Grabs a full line of the file
            if (codeinput == "_^"){
                // Ignore the comment
            }
            if (codeinput == lastcodeinput) {
                //Ignore if the last line is the same as this line
            }
            else  { // Sends the line to tokenizer to be tokenized and save the result in the list called tokens
                lastcodeinput = codeinput;
                finalstring.append(codeinput + " ");

            }
        }

    }
    //std::cout <<"\n" + finalstring + "\n";
    return finalstring;
}
void printidentifier(token  giventoken) {
    if (giventoken.VALUE != "VALUE"){
        std::cout << giventoken.VALUE;
    }

}
int domath(token operate, token left, token right){
    int returnnumber;

    int leftnumber =stoi(left.VALUE);
    int rightnumber =stoi(right.VALUE);
    if (operate.OPERATOR == "PLUS") {
        returnnumber =  (leftnumber +  rightnumber);
    }
    if (operate.OPERATOR == "DIVIDE") {
        returnnumber =  (leftnumber / rightnumber);
    }
    if (operate.OPERATOR == "MULTIPLY") {
        returnnumber =  (leftnumber *  rightnumber);
    }
    if (operate.OPERATOR == "MINUS") {
        returnnumber =  (leftnumber -  rightnumber);
    }
    return returnnumber;
}

void interpreter(std::vector<token>  tokenlist) { //Actually executes the code
    std::string rightnumber = "";
    for (int i = 0; i < tokenlist.size(); i++ ){
        std::string spaces = "";
        if (tokenlist[i].LEFT != 123456) {
            if (tokenlist[i].OPERATOR != "OPERATOR"){
                tokenlist[i].VALUE = std::to_string(domath(tokenlist[i], tokenlist[tokenlist[i].LEFT], tokenlist[tokenlist[i].RIGHT]));
            }
        }
    }
    for (int i = 0; i < tokenlist.size(); i++ ){
        std::string spaces = "";
        if (tokenlist[i].LEFT != 123456) {
            if (tokenlist[i].IDENTIFIER != "IDENTIFIER"){
                if (tokenlist[i].IDENTIFIER == "PRINT") {
                    printidentifier(tokenlist[tokenlist[i].LEFT]);
                }
            }
        }
    }

}


int main() {
    std::vector<token> tokenlist = tokenizer(lexer());
    //std::cout << tokenlist.size();
    //treeinator(parser(tokenlist));
    tokenlist = parser(tokenlist);
    interpreter(tokenlist);
    return 0;
}
