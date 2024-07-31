#include<stdio.h>
#include<limits.h>
struct sr{
	int at,bt,c,w,t,id;
};
int main()
{
	int n,i;
	struct sr p[10];
	printf("Enter no.of processes:");
	scanf("%d",&n);
	int is_com[n];
	int brust[n];
	printf("Enter at and bt processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].id=i+1;
		is_com[i]=0;
		brust[i]=p[i].bt;
		
	}
	int com=0;
	int curr=0;
	int tt=0;
	int wt=0;
	while(com!=n)
	{
		int in=-1;
		int min=INT_MAX;
		for(i=0;i<n;i++)
		{
			if(p[i].at<=curr && is_com[i]==0)
			{
				if(p[i].bt<min)
				{
					min=p[i].bt;
					in=i;
				}
				if(p[i].bt==min && p[i].at<p[in].at)
				{
					min=p[i].bt;
					in=i;
				}
			}
		}
		if(in!=-1)
		{
			p[in].bt-=1;
			curr++;
			if(p[in].bt==0)
			{
				
				p[in].c=curr;
				p[in].t=p[in].c-p[in].at;
				p[in].w=p[in].t-brust[in];
				tt=tt+p[in].t;
				wt=wt+p[in].w;
				is_com[in]=1;
			
				com++;
			}
	}
			else{
				curr++;
			}
		
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",p[i].id,p[i].c,p[i].t,p[i].w);
	}
	printf("Averages of tat and wt:");
	printf("%d\t%d",tt/n,wt/n);
}
