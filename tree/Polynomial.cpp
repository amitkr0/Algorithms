#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int power,coeff;
	node *next;
}*atop,*btop;

void show(node *p)                                                               //Show for  expression........
{
    while(p->next!=NULL){
        cout<<p->coeff<<"a"<<p->power<<" + ";
        p=p->next;
    }cout<<p->coeff<<"a"<<p->power;
    cout<<endl;
}

void simplify(node *q)                                //Removing terms having same power with adding its coeff and deleting the node.....
{
    node *a,*c,*d;
    while(q)
    {
        a=q->next;c=q;
        while(a)
        {
            if(q->power==a->power){
                q->coeff=q->coeff+a->coeff;
                if(a->next==NULL)
                	c->next=NULL;
				else
                	c->next=a->next;
				d=a;
                a=a->next;
                free(d);
                }
      		else{
                    c=a;a=a->next;
                }
        }
        q=q->next;
    }
    
}

void add(node*a,node*b)                  //merging then call simplify func...
{
	node *sumtop;
	sumtop =a;
	while(a->next!=NULL)a=a->next;
	a->next=b;
	simplify(sumtop);
	show(sumtop);
}
void subtract(node *a,node *b){               //merging with negative coefficient..
	node *p;
	node *q=b;
	node *difftop;
	difftop=a;
	while(a->next)a=a->next;
	a->next=b;
	while(b){                             
		b->coeff=-(b->coeff);                 //merge after changing the sign
		b=b->next;
	}
	simplify(difftop);
	show(difftop);
	while(q){                               //two times negative ...i.e. gaining its initial sign
		q->coeff=-(q->coeff);
		q=q->next;
	}
	cout<<"aaa";
	return;
}


node *createxp(){
	node *ptr=NULL,*p=NULL,*top=NULL;
	int k=0;
    cout<<"Enter the coefficient and degree and k==1 to exit\n";
	while(k!=1){                                                                            //input for expression
            int d,c;
            cout<<"degree : ";cin>>d;
            cout<<"coefficient : ";cin>>c;
            ptr=(node*)malloc(sizeof(node));
            ptr->next=NULL;
            if(ptr==NULL)
                exit(0);
            ptr->coeff=c;
            ptr->power=d;
            if(top==NULL)
            	top=ptr;
            else
            {
                p=top;
                while(p->next!=NULL)
                    p=p->next;
                p->next=ptr;
            }
            cout<<"k =  ";
            cin>>k;
        }
    return top;
}

void multiply(node *a,node *b){
	node *abctop=NULL,*ptr,*q;
	while(a){                    //go to each node of list and multiply every term..
		while(b){
			ptr=(node*)malloc(sizeof(node));;
			ptr->power=a->power+b->power;
			ptr->coeff=a->coeff*b->coeff;
			ptr->next=NULL;
			if(!abctop)
				abctop=ptr;
			else{
				q=abctop;
				while(q->next){
					q=q->next;
				}
				q->next=ptr;
			}
			b=b->next;
		}
		a=a->next;
	}
	simplify(abctop);
	cout<<"After Multiplying these two equations, we get\n";
	show(abctop);
	cout<<endl;
	return ;
	
}

int main(){
	
	node *ptr,*start,*q,*p;
	int n;
	atop=NULL;btop=NULL;
	cout<<"ENter the values for 1st expression\n";
	atop=createxp();
	cout<<"\t\texpression\n";
	show(atop);
	simplify(atop);
	cout<<"ENter the values for 2nd expression\n";
	btop=createxp();
	cout<<"\t\texpression\n";
	show(btop);
	simplify(btop);
	cout<<" After adding terms having same power    1st expression\n";
	show(atop);
	cout<<" After adding terms having same power   2nd expression\n";
	show(btop);
	int ch;
	cout<<"Enter ur choice\n";
	do{
		cout<<"1.Addition 2.Subtraction 3.Multiplication else Exit\t\t\t";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"After adding both equations\n";
				add(atop,btop);
				break;
			case 2:
				cout<<"After subtraction, equation\n";
				subtract(atop,btop);
				break;
			case 3:
				multiply(atop,btop);
				break;
			default:
				break;
				
		}
		
	}while(ch<4);
	return 0;
}
