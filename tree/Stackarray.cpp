#include<iostream>
using namespace std;
void show(int *a,int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
int main()
{
	int n,i,f,l;
	f=i=l=0;
	cout<<"Enter the range of stack\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements in the stack\n";
	while(f!=1 && l<n)
	{
		cin>>a[i];
		l++;i++;
		cout<<"Enter 1 to exit otherwise input for stack elements\t";
		cin>>f;
	}
	cout<<"Elements in stack:\n";
	show(a,l);
	int ch;
	do
	{
		cout<<"\nenter 1.Push  2.Pop  3.Exit\n";
		cin>>ch;
		switch (ch)
		{
			case 1:
				if(l==n)
					cout<<"Not enough space\n";
				else
				{
					for(int i=l;i>0;i--)
					{
						a[i]=a[i-1];
					}
					cout<<"enter the data:\t";
					cin>>a[0];
					l++;show(a,l);
				}
				break;
			case 2:
				if(l==0)
					cout<<"Stack empty";
				else
				{
					for(int i=0;i<l;i++)
					{
						a[i]=a[i+1];
					}
					l--;
					cout<<"success\n";
					show(a,l);
				}
				break;
			case 3:
				break;
			}
		}while(ch!=3);
	return 0;
}
