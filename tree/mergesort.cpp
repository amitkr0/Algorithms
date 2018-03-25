#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int a[],int l,int mid,int r){              //function for merging the elements of the array...
	int k=0,i=l,j=mid+1;
	int n=r-l+1;
	int c[n];                                         //create a new array
	while(i<=mid && j<=r){                           //insert the smaller value first i.e. ascending order..in the new array c[n];
		if(a[i]<=a[j]){
			c[k]=a[i];i++;}
		else{
			c[k]=a[j];j++;}
		k++;
	}
    while (i<=mid){                                      //rest elements are inserted.
        c[k]=a[i];
        k++;i++;
    }
    while (j<=r){                                         //rest elements are inserted.
        c[k]=a[j];
        k++;j++;
    }
	i=l;
	for(int m=0;m<k;m++){
		a[i]=c[m];i++;
		
	}
	
	return ;
}
	



void mergesort(int a[],int l,int r){        //function for diving the array...
	if(l>=r)
		return;
	int mid=(l+r)/2;
	mergesort(a,l,mid);                        
	mergesort(a,mid+1,r);
	merge(a,l,mid,r);
	return;
}

int main(){
	int n;
	cout<<"Enter the range of the array\n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"   ";
	}
	cout<<endl;
return 0;
}
