#include<stdio.h>
#define MAX 10
#define CN count++
int count=0;

void merge(int arr[],int temp[],int K, int h1, int L, int h2)
{	
	int ThirdArrCOUNTER=K;CN;
	while(l1<=h1&&l2<=h2)
	{
		CN;
		if(arr[k]<=arr[L])
			{
				temp[ThirdArrCOUNTER]=arr[K];
				K++;
				ThirdArrCOUNTER++
			}
		else
			{
				temp[ThirdArrCOUNTER]=arr[L];
				L++;
				ThirdArrCOUNTER++;
			}
	}
	
	
	
	
	while(K<=h1)
	{
		temp[ThirdArrCOUNTER]=arr[K];
		ThirdArrCOUNTER++;
		k++;
	}

	while(L<=h2)
	{
		temp[ThirdArrCOUNTER]=arr[L];
		ThirdArrCOUNTER++;
		L++;
	}
	
	
	
}

void copy(int arr[],int temp[],int low, int high)
{
	int i;
	for(i=0;i<=high;i++)
	{
		arr[i]=temp[i];
		
	}
}


void MergeSort(int arr[],int low, int high)
{

	if(low<high)
	{
		CN;
		int mid=(low+high)/2,temp[MAX];CN;
		MergeSort(arr,low,mid);CN;
		MergeSort(arr,mid+1,high);CN;
		merge(arr,temp,low,mid, mid+1, high);CN;
		copy(arr,temp,low,high);CN;
	}

}


int main()
{

	int i,n,arr[MAX];
	printf("ENTER THE SIZE OF YOUR ARRAY: ");
	scanf("%d",&n);

	printf("ENTER ELEMENT INTO YOUR ARRAY: \n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);

	MergeSort(arr,0,n-1);

	printf("THE ARRAY AFTER SORTING: \n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	  printf("\nSTEP COUNT: %d\n",count);

}
