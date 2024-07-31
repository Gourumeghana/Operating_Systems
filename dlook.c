#include<stdio.h>
#include<limits.h>
int main()
{
	int n,i,j,v,t=0,h,in,d;
	printf("Enter no.of tracks:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter tracks:");
	for(i=0;i<n;i++){
	
	scanf("%d",&arr[i]);
}
 printf("Enter head position:");
   scanf("%d",&h);
   for(i=0;i<n;i++)
   {
   	for(j=i+1;j<n-1;j++)
   	{
   		if(arr[i]>arr[j])
   		{
   			int temp=arr[i];
   			arr[i]=arr[j];
   			arr[j]=temp;
		   }
	   }
   }
   for(i=0;i<n;i++)
   {
   	if(arr[i]>=h)
   	{
   		in=i;
   		break;
	   }
   }
  
   printf("Enter 1 for right and 0 for left:");
   scanf("%d",&v);
   if(v)
   {
   	for(i=in;i<n;i++)
   	{
   		d=abs(h-arr[i]);
   		t+=d;
   		h=arr[i];
	   }
	for(i=in-1;i>=0;i--)
	{
		d=abs(h-arr[i]);
		t+=d;
		h=arr[i];
	}
   }
   else
   {
   	for(i=in-1;i>=0;i--)
   	{
   		d=abs(h-arr[i]);
   		t+=d;
   		h=arr[i];
   		
	   }
	   for(i=in;i<n;i++)
	   {
	   	d=abs(h-arr[i]);
	   	t+=d;
	   	h=arr[i];
	   }
   }
   printf("total head movements:%d",t);
}
