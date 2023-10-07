#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void swap(int*a,int*b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[], int l, int r)
{
	// Taking the last element as the pivot
	int pivot=a[r];
	
	int pos=l-1;
	for(int i=l;i<r;i++)
	{
		if(a[i]<=pivot)
		{
			pos++;
			swap(&a[pos],&a[i]);
		}
	}
	swap(&a[pos+1],&a[r]);
	return pos+1;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    auto start=chrono::high_resolution_clock::now();
    
    //code here

    // Taking Input
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }


    // Creating a stack
    int stack[n];
    int top=-1;

    stack[++top]=0;
    stack[++top]=n-1;

    // While stack is not empty
    while(top>=0)
    {
    	int r=stack[top--];
    	int l=stack[top--];

    	// Setting pivot element at its correct position in the sorted array
    	int temp=partition(a,l,r);

    	// Taking the elements on the left in the stack
    	if(temp-1>l)
    	{
    		stack[++top]=l;
    		stack[++top]=temp-1;
    	}

    	// Taking the elements on the right in the stack
    	if(temp+1<r)
    	{
    		stack[++top]=temp+1;
    		stack[++top]=r;
    	}
    }

    // Printing the sorted array
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
    }


    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr<<duration.count()/1000.0<<" ms\n";
}