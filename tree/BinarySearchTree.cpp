#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
struct tree
{
	int data;	
	tree *lc,*rc;	
}*root;

//for graphically tree..
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
int heightof(tree *root){                     //return height of any node..
	if(!root)
		return 0;
	return(max(heightof(root->lc),heightof(root->rc))+1);
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




//for insertion and deletion ,searching method..
tree* search(int v)                //if value is present then return that node otherwise return node where node with value v is inseted..
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

tree *getParent(tree *a)             //return parent of any node..if not return Null..
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
//for deletion process.
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

void swap(int *qq,int *qw){
	int da=*qq;*qq=*qw;*qw=da;
return;
}


void insert(int v)
{
	tree *ab;tree *p;
	ab=(tree*)malloc(sizeof(tree));	
	ab->data=v;ab->lc=ab->rc=NULL;
	if(root==NULL){root=ab;return;}
	p=search(v);                       //get the node where node with value v can be inserted..
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

//for traversal  ..

void delet(int v)
{
	if(root==NULL){cout<<"tree is empty \nno deletion\n";return;
	}
	if(root->data==v){              //check if root to be deleted..
		int nb=0;
		if(root->lc==NULL && root->rc==NULL){free(root);root=NULL;nb=1;       //if only root is present in tree.
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
			cout<<"deletion successful\n";return;
		}
	}
	tree *p=search(v);                  //get the node
	if(p->data!=v){cout<<"ELement not found\n Deletion  UnSuccessful\n";return ;} //if node is not present
	tree *p1=getParent(p);               //get the parent node 
	if(p->lc==NULL && p->rc==NULL){              //if deleted node is leaf node
		if(p1->lc==p)p1->lc=NULL;
		else
			p1->rc=NULL;
		free(p);
		cout<<"Deletion Successful\n";
	}
	else if(p->lc==NULL){
		if(p1->lc==p)
			p1->lc=p->rc;
		else
			p1->rc=p->rc;
		free(p);
		cout<<"Deletion Successful\n";
		}	
	else if(p->rc==NULL){
		if(p1->lc==p)
			p1->lc=p->lc;
		else
			p1->rc=p->lc;
		free(p);
		cout<<"Deletion Successfulllllllllllll\n";
		}
	else{                   //if node has both child 
		tree *abc;
		abc=nextsuc(p);
		tree *p2=getParent(abc);
		swap(&(p->data),&(abc->data));                     //swap data with its successor value.
		if(abc->rc!=NULL){                               //if successor has right child...then delete this node then make link with its right child..
			tree *aa=abc->rc;abc->rc=NULL;p2->rc=aa;
			free(abc);
			cout<<"DEletion succcccessfulll\n";
			return;
		}
		if(p2->lc==abc)p2->lc=NULL;
		else
			p2->rc=NULL;
		free(abc);
		cout<<"Deletion Suceeeeeeeesssssssssssssssssfulllllllll\n";}
		
return ;
}

void preorder(tree *ab)   //PREORDER...
{
	if(root==NULL){cout<<"empty\n";return;}
	if((ab)!=NULL){
		cout<<ab->data<<"\t";
		preorder(ab->lc);
		preorder(ab->rc);} 
	return;
}

//POSTORDER traversal.
void postorder(tree *ab)
{
	if(root==NULL){cout<<"empty\n";return;}
	if(ab!=NULL){
		postorder(ab->lc);
		postorder(ab->rc);
		cout<<ab->data<<"\t";}
	return;
}

//INORDER traversal.
void inorder(tree *ab)
{
	if(root==NULL){cout<<"empty\n";return;}
	if(ab!=NULL){
		inorder(ab->lc);
		cout<<ab->data<<"\t";
		inorder(ab->rc);}
	return;
}



int main(){
	root=NULL;
	int ch;	
	cout<<"Enter ur choice\n";
	do{
		cout<<"1.SHOW 2.SEARCHING 3.INSERTION 4.DELETION  5. Tree Structure and 6.Exit\t\t";
		cin>>ch;
		switch(ch){
			case 1:
				int ch1;
				cout<<"1.PREORDER 2.POSTORDER 3.INORDER and else to exit\n";cin>>ch1;
				switch(ch1)
				{
					case 1:
						cout<<"\t\tPREORDER\n";
						preorder(root);
						cout<<endl;
						break;
					case 2:
						cout<<"\t\tPOSTORDER\n";
						postorder(root);
						cout<<endl;
						break;
					case 3:
						cout<<"\t\tINORDER\n";
						inorder(root);
						cout<<endl;
						break;
					default :
						break;}
				break;
			case 2:
				int v1;
				cout<<"Enter the element to be searched\n";cin>>v1;
				tree *b;
				b=search(v1);
				if(b==NULL || b->data!=v1)cout<<"Data not found \n";
				else
					cout<<"Data is present in the node\n";
				break;
			case 3:
				int v2;	
				cout<<"Enter the data to be inserted \n";cin>>v2;
				insert(v2);
				break;
			case 4:
				int v3;cout<<"Enter the value TO be deleted\n";cin>>v3;
				cout<<"	DELETION \n";
				delet(v3);
				break;
			case 5:
				int ht;
				ht=heightof(root);
				plottree(root,ht,ht,ht*(ht+1)/2,gety());
				cout<<endl<<endl<<endl<<endl;
				break;
			case 6:
				break;
			default:
				ch=10;
				break;
			}
		}while(ch!=6);
	return 0;
}
