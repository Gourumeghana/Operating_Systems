#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter the number of process: ");
	scanf("%d",&n);
	int m,size[n];
	printf("enter the sizes of process: \n");
	for(i=1;i<=n;i++)
	{
		printf("process-%d size: ",i);
		scanf("%d",&size[i]);
	}
	printf("enter the number of blocks in memory: ");
	scanf("%d",&m);
	int block[m],visit[m];
	printf("Enter the sizes of each blocks: \n");
	for(i=1;i<=m;i++)
	{
		printf("size of block-%d  ",i);
		scanf("%d",&block[i]);
		visit[i]=-1;
	}
	int a[n];
	int k=1,count=0;
	while(k<=n){
		int min=999,flag=0;
		for(i=1;i<=m;i++)
		{
			if(block[i]<min && block[i]>=size[k] && visit[i]==-1)
			{
				min=block[i];
				flag=i;
			}
		}
		if(flag!=0)
		{
			visit[flag]=k;
			block[flag]=block[flag]-size[k];
			k++;
		}
		else
		{
			a[count]=k;
			count++;
			printf("process-%d is can not insert into memory\n",k);
			k++;
		}
	}
	printf("the process allocated are: \n");
	for(i=1;i<=m;i++)
	{
		if(visit[i]!=-1)
		{
			printf("block-%d:  p%d\n",i,visit[i]);
		}
	}
	int sum=0;
	
	for(i=1;i<=m;i++)
	{
		if(visit[i]!=-1)
		{
			sum=sum+block[i];
		}
	}
	printf("internal fragment of memory: %d\n",sum);
	int sum1=0;
	  if(count!=0){
	  
	 for(i=1;i<=m;i++)
	 {
	 	if(visit[i]==-1)
	 	{
	 		sum1+=block[i];
		 }
	 }
}

		printf("external fragment: %d",sum1);
	
	
}
