#include<iostream>
#include<iomanip>
using namespace std;
int n,m;

void print_solTup(int elements[],int solTup[], int k)
{

	int i;
    
	cout<<std::left<<setw(20)<<"{";
	for(i=1;i<=k;i++)
	{
        
		cout<<std::left<<solTup[i];
        if(i!=k)
        cout<<std::left<<",";	
	}
	cout<<"} ";

    cout<<std::left<<setw(20)<<"[";
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
	
	solTup[k]=1;
	
	if(s+elements[k]==m)
	print_solTup(elements,solTup,k);
	else if((s+elements[k]+elements[k+1])<=m)
	sum_of_subsets(elements,solTup,s+elements[k],k+1,r-elements[k]);
	
	if((s+r-elements[k]>=m) && (s+elements[k+1]<=m))
	{
		solTup[k]=0;
		sum_of_subsets(elements,solTup,s,k+1,r-elements[k]);
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
	
	cout<<"ENTER TRAGET SUM: ";
	cin>>m;
    cout<<std::left<<setw(20)<<"TUPLE"<<std::left<<setw(20)<<"ELEMENTS: "<<endl;
	sum_of_subsets(elements,solTup,0,1,r);
	return 0;
}
