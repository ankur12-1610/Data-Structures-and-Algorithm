#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int nextpowerof2(int x)
{
	int temp=1;
	while(temp<x)
	{
		temp=temp*2;
	}
	return temp;
}
vector<vector<int>> padding(vector<vector<int>> A, int n)
{
	vector<vector<int>> ans(n,vector<int>(n));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<A[i].size();j++)
		{
			ans[i][j]=A[i][j];
		}
	}
	return ans;
}
vector<vector<int>> addMatrix(vector<vector<int>> A, vector<vector<int>>B, int n)
{
	vector<vector<int>> sum(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sum[i][j]=A[i][j]+B[i][j];
		}
	}
	return sum;
}
vector<vector<int>> subtractMatrix(vector<vector<int>> A, vector<vector<int>>B, int n)
{
	vector<vector<int>> diff(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			diff[i][j]=A[i][j]-B[i][j];
		}
	}
	return diff;
}

vector<vector<int>> Strassen(vector<vector<int>> A, vector<vector<int>> B, int n)
{
	vector<vector<int>> prod(n,vector<int>(n));
	if(n==1)
	{
		prod[0][0]=A[0][0]*B[0][0];
		return prod;
	}

	vector<vector<int>> a(n/2,vector<int>(n/2));
	vector<vector<int>> b(n/2,vector<int>(n/2));
	vector<vector<int>> c(n/2,vector<int>(n/2));
	vector<vector<int>> d(n/2,vector<int>(n/2));

	vector<vector<int>> e(n/2,vector<int>(n/2));
	vector<vector<int>> f(n/2,vector<int>(n/2));
	vector<vector<int>> g(n/2,vector<int>(n/2));
	vector<vector<int>> h(n/2,vector<int>(n/2));

	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			a[i][j]=A[i][j];
			b[i][j]=A[i][j+n/2];
			c[i][j]=A[i+n/2][j];
			d[i][j]=A[i+n/2][j+n/2];

			e[i][j]=B[i][j];
			f[i][j]=B[i][j+n/2];
			g[i][j]=B[i+n/2][j];
			h[i][j]=B[i+n/2][j+n/2];
		}
	}
	vector<vector<int>> p1(n/2,vector<int>(n/2));
	vector<vector<int>> p2(n/2,vector<int>(n/2));
	vector<vector<int>> p3(n/2,vector<int>(n/2));
	vector<vector<int>> p4(n/2,vector<int>(n/2));
	vector<vector<int>> p5(n/2,vector<int>(n/2));
	vector<vector<int>> p6(n/2,vector<int>(n/2));
	vector<vector<int>> p7(n/2,vector<int>(n/2));

	p1=Strassen(a,subtractMatrix(f,h,n/2),n/2);
	p2=Strassen(addMatrix(a,b,n/2),h,n/2);
	p3=Strassen(addMatrix(c,d,n/2),e,n/2);
	p4=Strassen(d,subtractMatrix(g,e,n/2),n/2);
	p5=Strassen(addMatrix(a,d,n/2),addMatrix(e,h,n/2),n/2);
	p6=Strassen(subtractMatrix(b,d,n/2),addMatrix(g,h,n/2),n/2);
	p7=Strassen(subtractMatrix(a,c,n/2),addMatrix(e,f,n/2),n/2);

	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			prod[i][j]=p5[i][j]+p4[i][j]-p2[i][j]+p6[i][j];
		}
		for(int j=n/2;j<n;j++)
		{
			prod[i][j]=p1[i][j-n/2]+p2[i][j-n/2];
		}
	}
	for(int i=n/2;i<n;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			prod[i][j]=p3[i-n/2][j]+p4[i-n/2][j];
		}
		for(int j=n/2;j<n;j++)
		{
			prod[i][j]=p1[i-n/2][j-n/2]+p5[i-n/2][j-n/2]-p3[i-n/2][j-n/2]-p7[i-n/2][j-n/2];
		}
	}
	return prod;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    auto start=chrono::high_resolution_clock::now();
    
    //code here
    
    int n1, m1;
    cin>>n1>>m1;
    vector<vector<int>> A(n1,vector<int>(m1));
    for(int i=0;i<n1;i++)
    {
    	for(int j=0;j<m1;j++)
    	{
    		cin>>A[i][j];
    	}
    }
    int n2, m2;
    cin>>n2>>m2;
    vector<vector<int>> B(n2,vector<int>(m2));
    for(int i=0;i<n2;i++)
    {
    	for(int j=0;j<m2;j++)
    	{
    		cin>>B[i][j];
    	}
    }
    if(m1!=n2)
    {
    	cout<<"Matrix Multiplication Not Possible!!"<<endl;
    	exit(0);
    }

    int temp=max(n1,max(n2,max(m1,m2)));
    int n=nextpowerof2(temp);
    A=padding(A,n);
    B=padding(B,n);
    vector<vector<int>> C(n,vector<int>(n));
    C=Strassen(A,B,n);

    for(int i=0;i<n1;i++)
    {
    	for(int j=0;j<m2;j++)
    	{
    		cout<<C[i][j]<<"\t ";
    	}
    	cout<<endl;
    }



    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr<<duration.count()/1000.0<<" ms\n";
}