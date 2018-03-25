#include<iostream>
using namespace std;

int partition(int a[],int l,int r){
	int loc=l;
	while(l<r){                                     //check if right to pivot is greater than pivot or not
		while(a[loc]<=a[r] && loc<r){
			r--;
		}
		if(a[loc]>a[r]){                          //if not swap the value
			swap(a[loc],a[r]);
			loc=r;l++;
		}
		while(a[loc]>=a[l] && loc>l){               //check if left to pivot is less than pivot or not
			l++;
		}
		if(a[l]>a[loc]){                           //if not swap the value
			swap(a[loc],a[l]);
			loc=l;r--;
		}
	}
	return loc;
}
/*

int partition(int a[],int l,int r){                //HOARE PARTITION...........
	int loc=l,m=l;
	l--;r++;
	do{
		do{
			r--;
		}while(a[loc]<=a[r] && l<r);
		
		do{
			l++;
		}while(a[loc]>=a[l] && l<r);
		
		swap(a[l],a[r]);
		
	}while(l<r);
	
	loc=l;
	swap(a[m],a[loc]);
	
	return loc;
}
*/
void quicksort(int x[],int l,int r){
	int p;
	if(l<r){
		p=partition(x,l,r);                //divide the array according to its pivot location
		quicksort(x,l,p-1);               //recursiively call itself
		quicksort(x,p+1,r);
	}
	return;
}




int main()
{
	int n;
	cout<<"ENter the range of the array\n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	quicksort(a,0,n-1);

	for(int i=0;i<n;i++)cout<<a[i]<<"  ";
		
	return 0;
}
