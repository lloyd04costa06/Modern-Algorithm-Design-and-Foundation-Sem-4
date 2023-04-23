#include<stdio.h>
#define CN count++
#define MAX 10
int count=0;

void swap(int arr[],int i, int j)
{
   int temp= arr[i];CN;
   arr[i]=arr[j];CN;
   arr[j]=temp;CN;
}

int partition(int arr[], int i, int j)
{
    int piv=i; CN;
    i=i+1;CN;
    do{
        CN;
        while(arr[i]<=arr[piv])
        {CN;i++;CN;}

        while(arr[j]>arr[piv])
        {CN;j--;CN;}

        if(i<j)
        {CN;swap(arr,i,j);CN;}
        

    }while(i<j);

    swap(arr,piv,j);CN;
    
    CN;return j;

}

void QuickSort(int arr[], int low, int high)
{
    int p;
    if(low<high)
    {
        CN;
        p=partition(arr,low,high);CN;
        QuickSort(arr,low,p-1);CN;
        QuickSort(arr,p+1,high);CN;
    }

}

int main()
{
    int arr[MAX], i,n;
    printf("ENTER THE VALUE OF N: ");
    scanf("%d",&n);

    printf("ENTER THE ELEMENTS INTO YOUR ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("A[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    QuickSort(arr,0,n-1);
    printf("ARRAY AFTER SORTING: \n");
     for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
   
    printf("\nSTEP COUNT: %d\n",count);
    

}