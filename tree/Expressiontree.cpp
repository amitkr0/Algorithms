#include<iostream>
#include<cstdlib>
#include<stack>
#include<cstring>
using namespace std;
struct tree{
    char data;
    tree *lc,*rc;   
}*root;

stack<tree*>st;


tree *getoperand(char ch){          //create a node with a single operand..
    tree *a=new tree;   
    a->lc=a->rc=NULL;
    a->data=ch;
    return a;
}

tree *getoperator(char ch){            //create a subtree or tree..with root as a operator .and chid is either operand or operator.but it has both childs..
    tree *a=new tree;
    a->data=ch;
    tree *b,*c;
    b=st.top();st.pop();               
    c=st.top();st.pop();
    a->lc=c;
    a->rc=b;
return a;
}

void inorder(tree *a){                //inorder traversal i.e.infix expression
    if(a==NULL)
        return;
    inorder(a->lc);
    cout<<a->data<<"  ";
    inorder(a->rc);
   return;
}


int main(){

	cout<<"Enter postfix expression   :		";
	string output;
	cin>>output;

    int i=0;
    char ch;
    while(i<output.length())
    {
        ch=output.at(i);
        if(isalnum(ch)){
            tree *q=getoperand(ch);               //create with a single opearnd.....
            st.push(q);
        }
        else if(ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='^'){
            tree *p=getoperator(ch);               //create node with operators...........
            st.push(p);
            }
        else{
            cout<<"INVALID \n";
            exit(0);
        }
	i++;
    }
    root=st.top();   
    inorder(root);
	cout<<endl;
    return 0;
}       
  
