#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
char isOperand(char);
char pop();                                     //check if it is operand or not
void push(char);                               
int getprior(char);                           //check the priority of the operators
struct node
{
    float data;
    node *next;
}*top;
int main()
{
    top=NULL;
    int i=0;
    string s,out;
    out="";
    cout<<"Enter the infix expression:\n";
    cin>>s;
    char item;
    do
    {
        item=s.at(i);
        i++;
        if('x'==isOperand(item))
           {
             out += item;              //if operand then add it with output expression...
           }

        else if(item =='+' || item =='-' || item =='*' || item == '/' || item =='%' || item =='^')
          { char it=pop();
            while(getprior(it)>=getprior(item) && top!=NULL&& it!='('){           //if priority of coming operator is greater than priority of stack operator then
                    out += it;                                                    // add it with output expression..otherwise push in the stack..
                    it=pop();
            }
            push(it);
            push(item);
			}
        else if( item=='(')              //if '(' comes then push it in the stack
      {
          push(item);
      }

        else if(item==')')       //if ')' comes then pop elements of the stack until '(' not comes in the stack
          {
			 char ite;
            ite=pop();
            while(ite!='('){
                    out += ite;
                    ite=pop();
                  }}
        else{                //if other than these operators are present in the expression the given expression is invalid expression

            i=s.length()+5;
            cout<<"GIVEN STRING IS NOT A EXPRESSION\n";
            exit(0);}

    }while(i<s.length());              //if any extra elements present in the infix expression then add it in the postfix expression
    if(top!=NULL){
        while(top!=NULL){
            char y;
            y=pop();
            out += y;
        }
    }
    cout<<"Output expression in postfix order:\n";
    cout<<out;
    return 0;
}
void push(char y)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
        return;
    p->data=y;
    p->next=top;
    top=p;
}
char pop()
{
    if(top==NULL)
        return ' ';
    char ch;
    ch=top->data;
    node *q=top;
    top=top->next;
    free(q);
    return ch;
}
int getprior(char item)
{
    if(item == '+' || item=='-')
        return 1;
    else if(item == '*'|| item== '/' || item=='%')
        return 2;
    else if(item == '^')
        return 3;
    else
        return -1;
}
char isOperand(char it)
{
    if(isalnum(it))
        return 'x';
    return ' ';
}
