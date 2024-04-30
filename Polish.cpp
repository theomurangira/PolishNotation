#include "Polish.h"

std::string readInfix()
{   std::string infix;
    std::cout<<"enter an infix expression\n";
    std::getline(std::cin,infix);
    std::cout<<"read "<<infix<<"\n";
    return infix;
}

std::string convertToPostfix(std::string infix)
{
    /* Simplifying assumptions: 
    (1) Operands are integers from 1 to 9
    (2) Operators supported are + - * and /
    (3) Supported brackets are () [] and {}
    */
   
   std::string postfix;
   std::stack<char> s;
   char c;
   for(size_t i=0;i<infix.size();++i)
   {
     c=infix[i];
     if(c=='(' || c=='[' || c=='{')
     {
      s.push(c);
     }
     else if (c>='1' && c<='9' )
     {
       postfix +=c;
     }
     else if (c==']' || c==')'|| c=='}'){
        switch(c)
        {
            case ']':
                while(s.top()!='['){
                     postfix +=s.top();
                     s.pop();
                }
                s.pop();
                break;
            case ')':
                while(s.top()!='('){
                    postfix +=s.top();
                    s.pop();
                }
                s.pop();
                break;
            case '}':
                while(s.top()!='{'){
                    postfix +=s.top();
                    s.pop();
    
                }
                s.pop();
                break;
        }
     }
     else if(c=='+' || c=='-')
     { if( s.empty())  s.push(c);
       else {
        while(s.top()=='-' || s.top()=='+'|| s.top()=='*' ||s.top()=='/')
        {
            postfix +=s.top();
            s.pop();
        }
        s.push(c);
       }
     }
     else if (c=='*' ||c=='/')
     {
        if(s.empty()) s.push(c);
        else{
        while(s.top()=='*' || s.top()=='/')
        {
            postfix +=s.top();
            s.pop();
        }
        s.push(c);
        }
     }
   }
while(!s.empty())
{
    postfix +=s.top();
    s.pop();
}
 return postfix;
}

int evaluate(std::string postfix)
{
    std::stack<int> s;
    int result=0;
    for(size_t i=0; i<postfix.size();++i)
    {
        char c=postfix[i];
        int op1=0;
        int op2=0;
        if( std::isdigit(c))
          s.push(c-'\0');
        else if (c=='+'|| c=='-' ||c=='*' ||c=='/')
          {
            op2=s.top();
            s.pop();
            op1=s.top();
            s.pop();
            switch(c)
            {
                case '+':
                  result=op1+op2;
                  break;
                case '-':
                  result=op1-op2;
                  break;
                case '*':
                  result=op1*op2;
                  break;
                case '/':
                result =op1/op2;
                break;

            }
            s.push(result);

          }
    }
    result =s.top();
    return result;
}