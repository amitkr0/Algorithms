#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int data,row,col;
	node *next,*down;
}*start;

void insert(){              //Insertion func with arguments range of matrix  i.e. row and column of sparse matrix...
	int val,r,c;
	cout<<"Data   : ";         cin>>val;
	cout<<"Row    : ";         cin>>r; 
	cout<<"Column : ";         cin>>c;
	if(r>start->row || c>start->col){
		cout<<"Position ::: Out of range\n";
		return;
	}
	else if(r==0 || c==0){
		cout<<"INVALID row column\n";
		return;
	}
	node *a,*b,*aprev,*bprev;
	a=start->down;
	b=start->next;
	while(a->row<r){
		a=a->down;
		//cout<<"1\n";
	}
	aprev=a;
	node *p=a;
	a=a->next;
	int j=1;
	while(a!=p && j<c){
		aprev=a;
		a=a->next;j++;
		//cout<<"2\n";
	}         
	if(j==c && a->col==c){                                    //a node points to the node before ptr node(new node)..
		a->data=val;
		//cout<<"3\n";
		return;
	}
	while(b->col<c){
		b=b->next;//cout<<"4\n";
	}
	bprev=b;
	p=b;
	j=1;
	b=b->down;
	while(b!=p && j<r){
		bprev=b;
		b=b->down;j++;cout<<"5\n";
	}                                        //b node points to the node upside to the ptr node(new node)..
	node *ptr=new node;
	ptr->data=val;
	aprev->next=ptr;ptr->next=a;
	bprev->down=ptr;ptr->down=b;
	ptr->row=r;ptr->col=c;
	return;
}

void search(int v){                              //search function..
	int flag=0;
	node *q=start->down;
	node *a=q;
	node *b=q;
	while(q!=start && flag==0){                 //check whether a pointer reaches at start or not   or  check flag condition......
		b=q;a=q->next;
		while(a!=b){                              //goes to each point in a row.......
			//cout<<"Infinit2nd\n";
			if(a->data==v){
				flag=1;break;
			}                  
			a=a->next;
		}
		//cout<<"infin 1st\n";
		q=q->down;
	}
	
	if(flag==0)
		cout<<"Element Not Found\n";
	else
		cout<<"Element found \nRow :: "<<a->row<<"        Column :: "<<a->col<<endl<<endl;
	return ;
}


int main(){
	int r,c;
	cout<<"Enter the range of the sparse matrix::\n";
	cout<<"row  ::    ";               cin>>r;
	cout<<"column :: ";            cin>>c;
	node *a,*b;
	start=new node;
	if(!start)
		exit(0);
	start->row=r;start->col=c;
	start->down=start;start->next=start;
	start->data=0;
	
	b=start;
	//create row links....  for 0th column.
	for(int i=0;i<r;i++){
		a=new node;
		if(!a)
			exit(0);
		a->data=0;a->row=i+1;a->col=0;
		b->down=a;
		a->down=start;a->next=a;
		b=a;
	}
	b=start;
	node *w;
	//create column links........for 0th row.....
	for(int i=0;i<c;i++){
		w=new node;
		if(!w)
			exit(0);
		w->data=0;w->col=i+1;w->row=0;
		b->next=w;
		w->next=start;w->down=w;
		b=w;
	}
	
	//fill some values in sparse matrix..
	int n,k;
	cout<<"Enter the number of values to be inserted in sparse matrix\t\t";
	cin>>n;
	cout<<"Enter the data and row and column to insert a value\n";
	for(int i=0;i<n;i++)
	{
		cout<<"*********Details of element************\n";
		insert();
	}
	cout<<"Enter ur choice \n";
	int ch;
	do{
		cout<<"1.Searching  2.Insertion 3 Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				int v1;
				cout<<"Enter value to search\t\t";
				cin>>v1;
				search(v1);
				break;
			case 2:
				insert();
				break;
			default:
				break;
			}
		}while(ch!=3);
	return 0;
}
