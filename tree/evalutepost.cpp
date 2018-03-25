#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
char isOperand(char);
float pop();                                     //done............
void push(float);                               //done...................
struct node
{
    float data;
    node *next;
}*top;
int main()
{
    top=NULL;
    int i=0;
    string s;
    cout<<"Enter the postfix expression:\n";
    cin>>s;
    char item;
    do
    {
        item=s.at(i);
        i++;
        if('x'==isOperand(item))
           {
           	 item=(float)item-(float)'0';
             push(item);
           }

        else if(item =='+' || item =='-' || item =='*' || item == '/' || item =='%' || item =='^')
          { float it=pop();
          	float ite=pop();
          	float re;
          	if(ite==0.123f){
          		cout<<"Invalid postfix expression\n";
          		exit(0);
			  }
        	switch(item)              //for evaluating pop the first two elements then evaluate it according to operands position
        	{
        		case '+':
        			re=ite+it;                    
        			break;
        		case '-':
        			re=ite-it;
        			break;
        		case '*':
        			re=ite*it;
        			break;
				case '/':
					re=ite/it;
					break;
				case '%':
					re=(int)ite % (int)it;
					break;
				}
        	push(re);
			}
		else{
			cout<<"Invalid expression"<<endl;
		}
		}while(i<s.length());
		float res=pop();
		cout<<"Answer is ::\t"<<res;
		return 0;
}
char isOperand(char it)         // check if it is operand or not.
{
    if(isalnum(it))
        return 'x';
    return ' ';
}

void push(float y)                 //push in the stack
{
    node *p;
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
        return;
    p->data=y;
    p->next=top;
    top=p;
}
float pop()                  //pop operation
{
    if(top==NULL)
        return 0.123f;
    float ch;
    ch=top->data;
    node *q=top;
    top=top->next;
    free(q);
    return ch;
}
