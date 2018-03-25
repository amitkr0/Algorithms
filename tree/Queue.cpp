#include<iostream>
#include<cstdlib>
using namespace std;
struct queue
{
	int data;
	queue *next;
};
void show(queue *s)
{
    if(s==NULL){
        cout<<"QUEUE EMPTY\n";
    }
    else{
    cout<<"QUEUE\n";
    while(s!=NULL){
        cout<<s->data<<"\t";
        s=s->next;}}cout<<"\n";
}
int main()
{
	int n,l,k;l=k=0;
	cout<<"Enter the maximum range of the queue:\t";
	cin>>n;
	queue *top,*rear,*ptr,*p,*q,*s;
	top=NULL;
	cout<<"Enter the elements in the queue\n";
	while(k==0 && l<n)
	{
		q=(queue*)malloc(sizeof(queue));
		cout<<"Enter the data:\t";cin>>q->data;
		q->next=NULL;
		if(top==NULL){
			top=q;
			top->next=NULL;
		}
		else{
			p=top;
			while(p->next!=NULL){
				p=p->next;
			}
			q=p->next;
		}
		rear=q;rear->next=NULL;
		l++;
		cout<<"Enter 0 to continue:\t";
		cin>>k;
	}
		int ch;
		do{
			cout<<"Enter your choice 1.Enqueue 2.Dequeue 3.EXit\t";
			cin>>ch;
			switch (ch){
				case 1:
					if(l==n)cout<<"Queue Full \n";
					else{
						q=(queue*)malloc(sizeof(queue));
						cout<<"enter the data:\t";
						cin>>q->data;q->next=NULL;
                        if(top==NULL)top=rear=q;
                        else{
						rear->next=q;
						rear=q;
					}l++;}
					show(top);
					break;
				case 2:
					if(top==NULL)cout<<"Queue Empty";
					else{
                        if(top==rear){
                            ptr=top;
                            free(ptr);
                            top=rear=NULL;
                        }
                        else{
						ptr=top;
						top=ptr->next;
						free(ptr);
					}
						l--;
					show(top);}
					break;
				case 3:
					break;
			}
		}while(ch!=3);
	return 0;
}
