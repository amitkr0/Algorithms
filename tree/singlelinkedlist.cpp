#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	node *next;
};
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
		ptr->next=NULL;
		if(start==NULL){
			start=ptr;
		}
		else{
			p=start;
			while(p->next!=NULL){
				p=p->next;
			}
		p->next=ptr;}
	}
	ptr=start;
	do{
		cout<<"Enter ur choice 1.Show the list 2.Insertion 3.Deletion 4.Sorting 5.Searching. 6.Exit\n";
		cin>>ch;
		switch (ch){
			case 1 :
				ptr=start;
				cout<<"             *****List*****\n";
				for(int i=1;i<=n;i++){
					cout<<ptr->data<<"\n";
					ptr=ptr->next;
				}
				break;
			case 2 :
				int pos1;
				cout<<"Enter the position where element is inserted\n";
				cin>>pos1;
				q=(node*)malloc(sizeof(node));
				cout<<"enter the element\n";
			    cin>>q->data;
				ptr=start;
			    q->next=NULL;
			    if(pos1>n+1 || pos1==0){
			    	cout<<"Element cannot be inserted in given poition\n";
			    	break;
				}else{
					if(pos1==1){
						q->next=start;
						start=q;
					}
					else if(pos1==n+1){
						while(ptr->next!=NULL){
							ptr=ptr->next;
						}
						ptr->next=q;
					}
					else{
						p=ptr;
						while(ptr->next!=NULL && l<pos1){
							p=ptr;ptr=ptr->next;
							l++;
						}
						p->next=q;q->next=ptr;
					}
					n++;
					break;
				}
			case 3 :
				int ele;
				cout<<"Enter the element to be deleted";
				cin>>ele;
				ptr=start;l=1;
				while(ptr->data!=ele && ptr->next!=NULL){
					l++;q=ptr;
					ptr=ptr->next;
				}
				if(l==1){
					start=ptr->next;
					free(ptr);
				}
				else if(l==n){
					if(ptr->data!=ele){
						cout<<"Element not found\n";
						break;
					}
					q->next=NULL;
					free(ptr);
				}
				else{
					q->next=ptr->next;
					free(ptr);
				}
				n--;
				break;
			case 4:
				ptr=start;
				for(int i=1;i<=n;i++){
					p=ptr->next;
					for(int j=n;j>i;j--){
						if(ptr->data>p->data){
							tmp=ptr->data;
							ptr->data=p->data;
							p->data=tmp;}
							p=p->next;
					}
					ptr=ptr->next;
				}
				ptr=start;
				cout<<" After sorting the list, List:::::::::::\n";
				for(int i=1;i<=n;i++){
					cout<<ptr->data<<"\n";
					ptr=ptr->next;
				}
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
