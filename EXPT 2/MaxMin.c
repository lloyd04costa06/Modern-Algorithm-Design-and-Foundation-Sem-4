#include<stdio.h>
#define CN cnt++
int cnt=0;
int a[20];

void maxmin(int i, int j, int *max, int *min)
{
	int mid, max1, min1;	
	if(i==j){
		CN;
		*min=a[i];CN;
		*max=a[i];CN;
	}
	else if(i==j-1)
	{
		CN;
		if(a[i]<a[j])
		{
			CN;
			*max=a[j];*min=a[i];CN;
		}
		else
		{
			*max=a[i];*min=a[j];CN;
		}
	}
	else{
		mid=(i+j)/2;	CN;
	
		maxmin(i, mid, max, min);
		maxmin(mid+1, j, &max1, &min1);
		if(*max<max1)
		{
			CN;
			*max=max1;	CN;
		}
		
		if(*min>min1)
		{
			CN;
			*min=min1;	CN;
		}
				printf("%d,%d,%d\n,",mid,max,min);	
	}
}
int main()
{
	int n, max, min,i;
	printf("ENTER THE SIZE OF THE ARRAY: ");
	scanf("%d",&n);
	printf("ENTER THE ELEMENTS\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]: ",i+1);
		scanf("%d",&a[i]);
	}
	maxmin(0, n-1, &max, &min);
	printf("MAX= %d",max);
	printf("\nMIN= %d\n",min);
	printf("STEP COUNT= %d",cnt);
	return 0;
}
