#include<stdio.h>
#include<limits.h>
int main()
{
	int n,i,h;
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
		t=t+abs(h-arr[i]);
		h=arr[i];
	}
	printf("Total head movements:%d",t);
}
