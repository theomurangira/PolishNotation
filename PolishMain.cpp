#include "Polish.h"

int main()
{
    std::string infix=readInfix();
    std::string postfix= convertToPostfix(infix);
    std::cout<<infix <<"----->"<<postfix<<"\n";
    std::cout<<"result ="<<evaluate(postfix)<<"\n";
}