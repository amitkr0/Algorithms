#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	node *next,*prev;
};
void show(node *pq){
	cout<<"             ********** LISTS **********\n";
	while(pq!=NULL){
		cout<<pq->data<<"\t";
		pq=pq->next;
	}
	cout<<"\n";
}
int main(){
	node *ptr,*start,*q,*p;
	start=NULL;
	int n,ch,tmp,l;
	l=1;
	cout<<"Enter the size of the list\n";
	cin>>n;
	cout<<"enter the elements in the list\n";
	for(int i=1;i<=n;i++){
		ptr=(node*)malloc(sizeof(node));
		cin>>ptr->data;
		ptr->prev=NULL;
		ptr->next=NULL;
		if(start==NULL){
			start=ptr;
			start->prev=NULL;
		}
		else{
			p=start;
			while(p->next!=NULL){
				p=p->next;
			}
			ptr->prev=p;
		p->next=ptr;}
	}
		ptr=start;
	do{
		cout<<"Enter ur choice ::::: \n 1.Show the list \n 2.Insertion \n 3.Deletion \n 4.Sorting \n 5.Searching. \n 6.Exit\n";
		cin>>ch;
		switch (ch){
			case 1 :
				show(start);
				break;
			case 2 :                
				int pos1;
				while(l>0){       
					cout<<"Enter ur choice for insertion ::\n 1.At Begining \n 2.At End \n 3.In Between \n 4.Exit\n";
					cin>>pos1;
				    if(pos1==4){
				    	break;
					}
					q=(node*)malloc(sizeof(node));
					cout<<"enter the element\n";
				    cin>>q->data;
					ptr=start;                           
				    q->next=NULL;
				    q->prev=NULL;
					switch (pos1){
						case 1:	
							start->prev=q;                                 //create new node make link with the start node them change header node..
							q->next=start;
							start=q;n++;show(start); 
							break;
						case 2:                                            //create new node make link with the last node .
							while(ptr->next!=NULL){
								ptr=ptr->next;
							}
							ptr->next=q;
							q->prev=ptr;n++;show(start);
							break;
						case 3:
							cout<<"Enter the position \n";
							int pos0;
							cin>>pos0;
							if(pos0>n || pos0==1){
						    	cout<<"Element cannot be inserted in given poition\n";
						    	break;}
							p=ptr;
							while(ptr->next!=NULL && l<pos0){
								p=ptr;ptr=ptr->next;
								l++;
							}if(pos0>n)
								break;
							p->next=q;q->next=ptr;
							q->prev=p;ptr->prev=q;n++;
							show(start);
							break;
						}
						}
						break;
			case 3 :                       //3 case for insertion
				int pos2;
				while(l>0){
					cout<<"Enter ur choice for deletion \n 1.From 1st position \n 2. From Last position \n 3.In between \n 4.Exit";
					cin>>pos2;
					if(pos2==4)
						break;
					ptr=start;l=1;
					switch (pos2){
						case 1 :                            // change header node..and delete the first node
							ptr=start;
							start=ptr->next;
							free(ptr);n--;
							show(start);
							break;
						case 2 :                         //delete the last node .
							ptr=start;
							while(ptr->next!=NULL){              
								q=ptr;
								ptr=ptr->next;
							}
							q->next=NULL;
							free(ptr);n--;
							show(start);
							break;
						case 3 :
							ptr=start;
							int pos3;
							cout<<"Enter the position\n";
							cin>>pos3;
							if(pos3>n && pos3==1)            //if position is invalid.
								break;
							while(l<pos3){
								q=ptr;
								ptr=ptr->next;l++;
							}
							q->next=ptr->next;
							ptr->next->prev=q;
							free(ptr);n--;
							show(start);
							break;
					}
					}
					break;
			case 4 :
				ptr=start;
				for(int i=1;i<=n;i++){
					p=ptr->next;
					for(int j=n;j>i;j--){        //bubble sort.
						if(ptr->data>p->data){
							tmp=ptr->data;
							ptr->data=p->data;
							p->data=tmp;}
							p=p->next;
					}
					ptr=ptr->next;
				}
				show(start);
				break;
			case 5 :
				int elem;
				cout<<"Enter the element to be searched\n";
				cin>>elem;
				ptr=start;l=1;
				while(ptr->data!=elem && ptr->next!=NULL){          
					l++;
					ptr=ptr->next;
				}
				if(ptr->data!=elem){
					cout<<"Given element is not found \n";
					break;
				}
				cout<<"Given element is found at position :"<<l<<"\n";
				break;
			case 6 :
				break;
			default :
				break;
					}
				}while(ch!=6);
			
	return 0;
}	
