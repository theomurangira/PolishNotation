#ifndef _POLISH
#define _POLISH
#include<iostream>
#include<stack>
#include<string>
/*This function reads an input infix expression 
from the standard input*/

std::string readInfix();

/*This function takes an expression in infix notation
 and converts it in postfix notation (returned as a string)*/
std::string convertToPostfix(std::string infix);

/*This function takes a postfix expression and 
returns an integer representing the value of the expression*/

int evaluate(std::string postfix);

#endif