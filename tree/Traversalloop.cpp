#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
struct tree
{
	int data;	
	tree *lc,*rc;	
}*root;

stack<tree*> st;
stack<tree*> st1;

tree* search(int v)
{
	if(root==NULL){cout<<"tree is empty\n";
	return NULL;
	}
	tree *p=root;
	tree *pq=NULL;
	while(p!=NULL){
		if(p->data==v){
			return p;}  
		else if(p->data>v){
			pq=p;p=p->lc;}
		else if(p->data<v){
			pq=p;p=p->rc;}
	}
	return pq;
}

void insert(int v)
{
	tree *ab;tree *p;
	ab=(tree*)malloc(sizeof(tree));	
	ab->data=v;ab->lc=ab->rc=NULL;
	if(root==NULL){root=ab;return;}
	p=search(v);
	if(p->data==v){                   // for dupliclate items...
		if(p->lc==NULL)p->lc=ab;
		else
		{
			tree *q=p->lc;
			p->lc=ab;ab->lc=q;}
	}
	else if(p->data>v)	
		p->lc=ab;
	else 
		p->rc=ab;
	return ;
}


void Preorderloop(){
	if(root==NULL){
		cout<<"\t\tEmpty\n";
	}
	tree *ptr=root;
	while(1){
		if(ptr){
			st.push(ptr);                //push stack with root values..
			cout<<ptr->data<<"  ";         
			ptr=ptr->lc;                  //moves to left pointer.
		}
		else{
			if(st.empty())       //if stack is empty then break..
				break;
			ptr=st.top();st.pop();           //otherwise pop the nodes
			ptr=ptr->rc;                 //then movw to the right pointer
		}
	}
}

//same as the preorder loop .....just dfference of printing of data
void Inorderloop(){
	if(root==NULL){
		cout<<"\t\tEmpty\n";
	}
	tree *ptr=root;
	while(1){
		if(ptr){
			st.push(ptr);
			ptr=ptr->lc;
		}
		else{
			if(st.empty())
				break;
			ptr=st.top();st.pop();
			cout<<ptr->data<<"  ";
			ptr=ptr->rc;
		}
	}
}

void Post2stack(){                       //two stacks are required for traversal....
	if(root==NULL)
	{
		cout<<"\t\t Empty\n";
		return;
	}
	tree *ptr=root;
	st.push(ptr);
	while(!st.empty()){
		ptr=st.top();st.pop();
		st1.push(ptr);                      //push values in another stack after pop operation in 1st stack..
		if(ptr->lc)
			st.push(ptr->lc);             //push left child in 1st stack..
		if(ptr->rc)
			st.push(ptr->rc);             //push right child in 1st stack..
	}
	
	while(!st1.empty()){                 //items are present in stack in reverse order.
		ptr=st1.top();
		cout<<ptr->data<<"  ";
		st1.pop();
	}
	return ;
}
void Post1stack(){                       //Postorder traversal can be done using only one stack.......
	if(!root){
		cout<<"Empty\n";
		return ;
	}
	tree *ptr=root;
	do{
		if(ptr){
			if(ptr->rc)	
				st.push(ptr->rc);                   //first push right child then push root...
			st.push(ptr);
			ptr=ptr->lc;
		}
		else{
			ptr=st.top();st.pop();
			if(st.empty()){
				cout<<ptr->data<<" ";                 //if stack is empty then print its last value..
			}
			else if(ptr->rc==st.top()){               //if top of stack is right child of root then first right child is printed in postorder then root..so..
				st.pop();
				st.push(ptr);
				ptr=ptr->rc;
			}
			else{
				cout<<ptr->data<<"  ";                 //if it doesn't have any right child ,,print it. and make this node as null.
				ptr=NULL;
			}
		}
		
	}while(!st.empty());
	return ;
}
//for level order printing.
void padding ( char ch, int n )
{
  int i;
  cout<<endl;
  for ( i = 0; i < n; i++ )
    cout<<( ch );

}
void structure ( struct tree *root, int level )
{
  int i;
  if ( root == NULL ) {
    padding ( '\t', level );
    
    
  }
  else {
    structure(root->rc,level + 1 );
    padding ( '\t', level );
    cout<<( "%d\n", root->data );
    structure ( root->lc, level + 1 );
  }
}



int main(){
	root=NULL;
	cout<<"Enter the number of elements in tree\n";
	int n,val;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		insert(val);
	}
	int ch;	
	cout<<"Enter ur choice\n";
	cout<<"1.SHOW \n";
	do{
		
		cout<<"1.PREORDER 2.POSTORDER 3.INORDER and 4 exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\t\tPREORDER\n";
				Preorderloop();
				cout<<endl;
				break;
			case 2:
				cout<<"\t\tPOSTORDER\n";
				cout<<"Postorder using two stack\n";
				Post2stack();
				cout<<"\nPostorder using one stack\n";
				Post1stack();
				cout<<endl;
				break;
			case 3:
				cout<<"\t\tINORDER\n";
				Inorderloop();
				cout<<endl;
				break;
			case 4:
				break;
			default :
				structure(root,0);
				cout<<endl<<endl;
				break;
		}
	}while(ch!=4);
	return 0;
}
