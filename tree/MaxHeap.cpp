#include<iostream>
using namespace std;
int a[10000];

void insert(int n,int v){                     
	
	int par=n/2,j=n;
	a[n]=v;                //insert at last index....
	
	while(a[j]>a[par] && par>0){        //check if value at parent is greater or not....
		swap(a[j],a[par]);
		j=par;par=j/2;
	}
}

void delet(int n){               
	swap(a[1],a[n]);               //swap value of first with last index
	int i=1,k;
	int ch=2*i+1;
	while(ch<n){              //then check condition for max heap.
		if(a[ch]>a[ch-1])k=ch;
		else
			k=ch-1;
		if(a[i]<a[k])
			swap(a[i],a[k]);
		i=k;
		ch=2*i+1;
	}
	cout<<"Element with maximum value(i.e. root) is deleted\n";
	return ;
}

int main(){
	a[0]=0;
	int n=0,ch;
	cout<<"Enter ur choice\n";
	do{
		cout<<"1.Show 2.Insertion 3.Deletion 4 Exit \t::\t";
		cin>>ch;
		switch(ch){
			case 1:
				if(n==0)
					cout<<"Empty\n";
				for(int i=1;i<=n;i++){
					cout<<a[i]<<"    ";
				}
				cout<<endl;
				break;
			case 2:
				int v,z;
				cout<<"Enter the no of elements to be inserted\n";
				cin>>z;
				for(int i=0;i<z;i++){
					cin>>v;
					n++;
					insert(n,v);
					}
				break;
			case 3:
				if(n==0){
					cout<<"Empty Deletion Unsuccessful\n";
				}
				else{
					delet(n);
					n--;
				}
				break;
			default:
				break;
		}
	}while(ch!=4);
	return 0;
}
