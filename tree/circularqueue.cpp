#include<iostream>
#include<cstdlib>
using namespace std;
struct queue
{
	int data;
	queue *next;
}*top,*rear;
void show()
{
    queue *ptr;
    if(top==NULL){
        cout<<"QUEUE EMPTY\n";
        return;
    }
    ptr=top;
    cout<<"\n************QUEUE****************\n";
    do{
        cout<<ptr->data<<"\n";
        ptr=ptr->next;
}while(ptr!=top);
}
void enque(int value)                              //insert element at last ..
{
	queue *q=(queue*)malloc(sizeof(queue));
	if(!q){
		cout<<"QUEUE FULL\n";
		return;
	}
	else if(top==NULL){
		q->data=value;
		top=rear=q;
		rear->next=top;
	}
	else{
		q->data=value;
		q->next=top;
		rear->next=q;
		rear=q;
	}
}
void deque()                                    //delete element at the first.
{
	queue *q;
	q=top;
	if(top==NULL){
		cout<<"QUEUE EMPTY\n";
		return ;
	}
	else if(top==rear)
		top=rear=NULL;
	else
		{top=top->next;
		rear->next=top;}
	cout<<"Popped item is "<<q->data<<endl;
	free(q);
}

int main()
{
	int k;k=0;
	queue *q,*p;
	top=NULL;rear=NULL;
	cout<<"Input the values in queue\n";
	while(k==0)                       //insert element int he queue.
	{
		q=(queue*)malloc(sizeof(queue));
		cout<<"Enter the data:\t";cin>>q->data;
		q->next=NULL;
		if(top==NULL){
			top=q;
		}
		else{
			p=top;
			while(p->next!=NULL)
				p=p->next;
			
			p->next=q;
		}
		cout<<"Enter 0 to continue:\t";
		cin>>k;
	}
	q->next = top;
	rear=q;
	show();
	int ch;
	do{
		cout<<"Enter your choice 1.Enqueue 2.Dequeue 3.Show\t";
		cin>>ch;
		switch (ch){
			case 1:
				int v;
				cout<<"Enter the data\t:";
				cin>>v;
				enque(v);
				break;
			case 2 :
				deque();
				break;
			case 3:
				show();
				break;
			default :
				k=0;
		}
	}while(k!=0);
}

