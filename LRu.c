#include<stdio.h>

int findLru(int time[],int n)
{
	int i,mini=time[0],pos=0;
	for(i=1;i<n;++i)
	{
		if(time[i]<mini)
		{
			mini=time[i];
			pos=i;
		}
	}
	return pos;
}

int main()
{
	int nf,np,i,j,flag1,flag2,count=0,time[30],fault=0;
	int pos;
	printf("Enter number of frames:");
	scanf("%d",&nf);
	printf("\n");
	printf("Enter number of pages:");
	scanf("%d",&np);
	int frames[nf],pages[np];
	printf("Enter pages:");
	for(i=0;i<np;i++)
	{
		scanf("%d",&pages[i]);
	}
	for(i=0;i<nf;i++)
	{
		frames[i]=-1;
	}
	for(i=0;i<np;i++)
	{
	//	printf("%d Frames:",pages[i]);
		flag1=flag2=0;
		
		for(j=0;j<nf;j++)
		{
			if(frames[j]==pages[i])
			{
				count++;
				time[j]=count;
				flag1=flag2=1;
				break;
			}
		}
		if(flag1==0)
		{
		for(j=0;j<nf;j++)
		{
			if(frames[j]==-1)
			{
				count++;
				fault++;
				frames[j]=pages[i];
				time[j]=count;
				flag2=1;
				break;	
			}	
		}
		
     	}
     	
     	if(flag2==0)
     	{
     		
     	pos=findLru(time,nf);
		 count++;
		  fault++;
		 time[pos]=count;
		 frames[pos]=pages[i];
	 }
		 
		 for(j=0;j<nf;j++)
		 {
		 	printf(" %d ",frames[j]);
		 }
		 printf("\n");
		 
}
		 int hit=np-fault;
		 printf("hits number is %d :",hit);
		 printf("\n fault number %d :",fault);
}
