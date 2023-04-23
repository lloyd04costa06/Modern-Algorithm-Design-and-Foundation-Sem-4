#include<stdio.h>
#define MAX 10
#define CN count++
int count=0;
int Bsearch(int arr[],int low, int high,int key)
{
    int mid;
    while(low<high)
    {
    	CN;
        mid=(low+high)/2;CN;

        if(key==arr[mid])
        {
        	CN;CN;     return mid;
        }
       
        else if(key<arr[mid])
        {
        	CN;CN;high=mid-1;
        }   
        else
        {
        	CN; low=mid+1;
        }
           
    }
    CN;return -1;
}

int main()
{

    int arr[MAX],n,i,key;
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS INTO YOUR ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&arr[i]);

    }

    printf("ENTER THE SEARCH KEY: ");
    scanf("%d",&key);

    
    int x=Bsearch(arr,0,n,key);
    
    CN;
    if(x==-1)
    printf("ELEMENT NOT FOUND IN ARRAY\n");
    else
    printf("ELEMENT FOUND AT %d LOCATION\n",x);
    
        printf("\nSTEP COUNT=%d\n",count);



}
