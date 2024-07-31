#include<stdio.h>
#include<limits.h>
int main()
{
	int n,i,j,h;
	printf("Enter no.of tracks:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter track values:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter head position:");
	scanf("%d",&h);
	int t=0;
	for(i=0;i<n;i++)
	{
		int min=INT_MAX,in=0;
		for(j=0;j<n;j++)
		{
			int d=abs(h-arr[j]);
			if(d<min)
			{
				min=d;
				in=j;
			}
		}
		t+=min;
		h=arr[in];
		arr[in]=INT_MAX;
	}
	printf("Total head movements:%d",t);
}
