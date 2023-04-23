#include<iostream>
#include<iomanip>
#define CNT cntt++
using namespace std;
int n,m,cntt=0;

void whitespace(int x)
{
	for(int i=0;i<x;i++)
	cout<<" ";
}

void print_solTup(int elements[],int solTup[], int k)
{

	int i;
    
	cout<<"{";
	for(i=1;i<=k;i++)
	{
		cout<<solTup[i];CNT;
        if(i!=k)
        cout<<",";	
	}
	cout<<"} ";

	//i represents no. of spaces elements occupied on the screen
	whitespace(30-((i*2)+1));  //x2  No 0f elements,commas and brackets combined 
    cout<<"[";
	for(i=1;i<=k;i++)
	{
		if(solTup[i]==1)
        cout<<elements[i];
         if(i!=k&&solTup[i]==1)
        cout<<",";
	}
	cout<<"] ";
     
	cout<<endl;
}

void sum_of_subsets(int elements[],int solTup[],int s, int k, int r)
{
	if(k>n)
	return;
	
	solTup[k]=1;CNT;
	
	if(s+elements[k]==m)
	{CNT;print_solTup(elements,solTup,k);CNT;}
	else if((s+elements[k]+elements[k+1])<=m)
	{CNT;sum_of_subsets(elements,solTup,s+elements[k],k+1,r-elements[k]);CNT;}
	
	if((s+r-elements[k]>=m) && (s+elements[k+1]<=m))
	{
		CNT;
		solTup[k]=0;CNT;
		sum_of_subsets(elements,solTup,s,k+1,r-elements[k]);CNT;
	}
		
}
int main()
{
	int r=0,i;
	cout<<"ENTER THE SIZE OF THE SET"<<endl;
	cin>>n;
	
	int elements[n+1];
	int solTup[n+1];
	
	cout<<"ENTER ELEMENTS INTO YOUR ARRAY:\n";
	for(i=1;i<=n;i++)
	{
		cin>>elements[i];
		solTup[i]=0;
		r+=elements[i];
	}
	
	cout<<"ENTER TARGET SUM: ";
	cin>>m;cout<<endl;
	
	
    cout<<std::left<<setw(30)<<"TUPLE"<<std::left<<setw(30)<<"ELEMENTS: "<<endl;
	sum_of_subsets(elements,solTup,0,1,r);
	cout<<"\nSTEP COUNT: "<<cntt<<endl;
	return 0;
}
