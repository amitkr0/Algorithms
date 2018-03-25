#include<iostream>
#include<cstdlib>
#include<cmath>
#include<windows.h>
using namespace std;
struct tree
{
	int data,height;
	tree *lc,*rc;
}*root;

int getheight(tree *p){       //height of any node..
	if(p==NULL)
		return 0;
	int x=getheight(p->lc);
	int y=getheight(p->rc);
	return (max(x,y)+1);
}
int gety() //to get y-coordinate
{ CONSOLE_SCREEN_BUFFER_INFO csbi;
    int y;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
     {   y = csbi.dwCursorPosition.Y;
     }
     return y;
}

 
void gotoxy(int x, int y)  // to place the cursor at the desired location
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}


void plottree(tree *rr,int h,int H,int mid,int Y)  // to plot the tree graphically
{
  if(rr==NULL)
    return;
    int x=mid,i;
    int y=Y+1+(H*(H+1))/2 - (h*(h+1))/2;
    gotoxy(x,y);
    cout<<rr->data;
    if(rr->rc!=NULL)
    {
        for(i=1;i<=(h-1);i++)
        {
            gotoxy(mid+i,y+i);
            cout<<"\\";
        }
        plottree(rr->rc,h-1,H,mid+(h),Y);
    }
    if(rr->lc!=NULL)
    {
        for(i=1;i<=(h-1);i++)
        {
            gotoxy(mid-i,y+i);
            printf("/");
        }
        plottree(rr->lc,h-1,H,mid-(h),Y);
    }
 
}

tree *nextsuc(tree *a)                     //return next inorder successor for swapping value with deleted node..
{
	tree *b=a;
	a=a->rc;
	while(a!=NULL){
		b=a;
		a=a->lc;
	}
	return b;
}



tree *parent(tree *a)      //to get parent node of any node..
{
	tree *p=root;
	tree *pq=p;
	while(p!=NULL){
		if(p->data==a->data){
			return pq;}  
		else if(p->data>a->data){
			pq=p;p=p->lc;}
		else if(p->data<a->data){
			pq=p;p=p->rc;}
	}
	return NULL;	
}

tree* search(int v)            //return node containing that value else return the node where new node can be inserted....
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

void llrot(tree *ptr){                     //left to left rotation..
	tree *par=parent(ptr);            
	tree *lptr=ptr->lc;
	ptr->lc=lptr->rc;
	lptr->rc=ptr;

	if(ptr==root){
		root=lptr;cout<<"\nroot";
	}
	else{
		if(ptr->data<=par->data)
			par->lc=lptr;
		else
			par->rc=lptr;
	}
	
	cout<<"llrot\n";
	return;
}


void rrrot(tree *ptr){             //right to right rotation..
	tree *par=parent(ptr);
	tree *rptr=ptr->rc;
	ptr->rc=rptr->lc;
	rptr->lc=ptr;
	
	if(ptr==root){
		root=rptr;cout<<"\nroot";
	}
	else{
		if(ptr->data<=par->data)
			par->lc=rptr;
		else
			par->rc=rptr;
	}
	
	cout<<"rrrot\n";
	return;
}

void lrrot(tree *ptr){        //left to right rotation..
	tree *lptr=ptr->lc;
	rrrot(lptr);             //rr rotation for left child..
	llrot(ptr);              //ll rotation for the node.
	
	cout<<"lrrot\n";
	return;
}

void rlrot(tree *ptr){             //right to left rotation..
	tree *rptr=ptr->rc;
	llrot(rptr);              //rr rotation for right child..
	rrrot(ptr);                  ////rr rotation for the node.
	
	cout<<"rlrot\n";
	return;
}


int balfac(tree *p){        //if root is not balanced return 1 otherwise return 0.
	tree *lp=p->lc;
	tree *rp=p->rc;
	int hl=getheight(lp);
	int hr=getheight(rp);
	int bf=abs(hl-hr);
	if(bf<=1)
		return 0;
	else
		return 1;
		
}

void chckcondn(tree *ptr){               //check balanced condition when any new node is inseted..if not then balanced it..
	tree *p;
	int i=0,val=ptr->data;
	while(ptr!=root)
	{
		ptr=parent(ptr);
		
		if(balfac(ptr)==1){
			cout<<"Unbalance";
			if(ptr->data<val){          //if inseted node is right to unbalanced node ..
				if(ptr->rc->data<val)
					rrrot(ptr);
				else
					rlrot(ptr);
			
			}
			else                           //if inseted node is left to unbalanced node ..
				if(ptr->lc->data<val)
					lrrot(ptr);
				else
					llrot(ptr);
		}
		
		
	}
	return ;
}

void delet(int v)
{
	if(root==NULL){cout<<"tree is empty \nno deletion\n";return;
	}
	if(root->data==v){              //check if root to be deleted..
		int nb=0;
		if(root->lc==NULL && root->rc==NULL){free(root);root=NULL;
		return;      //if only root is present in tree.
		}
		else if(root->lc==NULL && root->rc!=NULL){                      //if root have only right child...
			tree *k=root->rc;root->rc=NULL;
			free(root);root=k;nb=1;
		}
		else if(root->rc==NULL && root->lc!=NULL){                           //if root have only left child...
			tree *k1=root->lc;root->lc=NULL;
			free(root);root=k1;nb=1;
		}
		if(nb==1){
			chckcondn(root);
			cout<<"deletion successful\n";return;
		}
	}
	tree *p=search(v);                  //get the node
	if(p->data!=v){cout<<"ELement not found\n Deletion  UnSuccessful\n";return ;} //if node is not present
	tree *p1=parent(p);               //get the parent node 
	if(p->lc==NULL && p->rc==NULL){              //if deleted node is leaf node
		if(p1->lc==p)p1->lc=NULL;
		else
			p1->rc=NULL;
		free(p);
		chckcondn(p1);
		cout<<"Deletion Successful\n";
	}
	else if(p->lc==NULL){
		if(p1->lc==p)
			p1->lc=p->rc;
		else
			p1->rc=p->rc;
		free(p);
		chckcondn(p1);
		cout<<"Deletion Successful\n";
		}	
	else if(p->rc==NULL){
		if(p1->lc==p)
			p1->lc=p->lc;
		else
			p1->rc=p->lc;
		free(p);
		chckcondn(p1);
		cout<<"Deletion Successfulllllllllllll\n";
		}
	else{                   //if node has both child 
		tree *abc;
		abc=nextsuc(p);
		tree *p2=parent(abc);
		swap(p->data,abc->data);                     //swap data with its successor value.
		if(abc->rc!=NULL){                               //if successor has right child...then delete this node then make link with its right child..
			tree *aa=abc->rc;abc->rc=NULL;p2->rc=aa;
			free(abc);
			cout<<"DEletion succcccessfulll\n";
			chckcondn(p2);
			return;
		}
		if(p2->lc==abc)p2->lc=NULL;
		else
			p2->rc=NULL;
		free(abc);
		chckcondn(p2);
		cout<<"Deletion Suceeeeeeeesssssssssssssssssfulllllllll\n";}
		
return ;
}




void insert(int v)                //insert any node..
{
	tree *ab;tree *p;
	ab=(tree*)malloc(sizeof(tree));	
	ab->data=v;ab->lc=NULL;ab->rc=NULL;
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
		
	cout<<"Value Inserted\n";
	
	chckcondn(ab);
	return ;
}

void Inorder(tree* ptr){                  //INORDER.......
	if(ptr==NULL){
		cout<<"EMPTY\n";return ;
	}
	tree *pt=ptr;
	if(pt==NULL)return ;
	else{
		if(pt->lc!=NULL)
			Inorder(pt->lc);
		cout<<pt->data<<"\t";
		if(pt->rc!=NULL)
			Inorder(pt->rc);
	}
	return;
} 
void preorder(tree *ab)                //PREORDer..
{
	if(root==NULL){cout<<"empty\n";return;}
	if((ab)!=NULL){
		cout<<ab->data<<"\t";
		preorder(ab->lc);
		preorder(ab->rc);} 
	return;
}

int main(){
	root=NULL;
	int ch;
	cout<<"ENter ur choice \n";
	do{
		cout<<"1.Show 2.Insertion  3.To print tree 4.Deletion 5.Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"\t\tINORDER\n";
				Inorder(root);
				cout<<endl;
				cout<<"\t\tPREORDER\n";
				preorder(root);
				cout<<endl;
				break;
			case 2:
				int v1;
				cout<<"Enter the value to be inserted\n";
				cin>>v1;
				insert(v1);
				break;
			case 3:
				int ht;
				ht=getheight(root);
				plottree(root,ht,ht,ht*(ht+1)/2,gety());
				cout<<endl<<endl<<endl<<endl;
				break;
			case 4:
				int v3;cout<<"Enter the value TO be deleted\n";cin>>v3;
				cout<<"	DELETION \n";
				delet(v3);
				break;	
			case 5:
				ch=10;
				break;
			default:
				break;
		}
	}while(ch!=10);
	return 0;
}
