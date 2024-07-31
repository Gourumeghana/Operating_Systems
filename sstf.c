//sstf
#include<stdio.h>
#include<Math.h>
int n,s,end,a[30],h,head,b[30],c[30],k,ans,v[30];

void check2()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(v[i]==0)
		{
			b[i]=abs(h-a[i]);
			printf("%d",b[i]);
			
		}
		printf("\n");
	}
}

void check()
{
	int i,mini;
	while(k<n)
	{
		mini=1000;
		for(i=0;i<n;i++)
		{
		
		if(mini>=b[i] && v[i]==0)
		{
			mini=b[i];
			c[k]=i;
		}
	}
	v[c[k]]=1;
	h=a[c[k]];
	k++;
	check2();	
	}
	
	printf("sequence is %d",head);
	for(i=0;i<n;i++)
	{
		ans=ans+abs(head-a[c[i]]);
		head=a[c[i]];
	}
	
	printf("heading moments:");
	printf("%d",ans);
}
int main()
{
	printf("Enter number of tracks:");
	scanf("%d",&n);
	printf("Enter starting positin:");
	scanf("%d",&s);
	printf("Enter ending position:");
	scanf("%d",&end);
	int i=0;
	while(i<n)
	{
		printf("Enter track %d ",i+1);
		scanf("%d",&a[i]);
		if(a[i]>s && a[i]<end)
			i++;		
	}
	
	printf("Enter head track:");
	scanf("%d",&h);
	head=h;
	for(i=0;i<n;i++)
	{
		v[i]=0;
	}
	check2();
	check();

}
