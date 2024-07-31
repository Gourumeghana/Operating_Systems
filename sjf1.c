#include<stdio.h>
#include<limits.h>
struct sj{
	int s,id,at,bt,c,w,t;
};
int main()
{
	struct sj p[10];
	int n,i;
	float tt=0,wt=0;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	int is_com[n];
	printf("Enter at and bt of processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&p[i].at,&p[i].bt);
		is_com[i]=0;
		p[i].id=i+1;
	}
	int com=0;
	int curr=0;
	printf("Ghantt chart:\n");
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
				if(p[i].bt==min)
				{
					if(p[i].at<p[in].at)
					{
						min=p[i].bt;
						in=i;
					}
				}
			}
	    }
		if(in!=-1)
		{
			p[in].s=curr;
			p[in].c=p[in].s+p[in].bt;
			p[in].t=p[in].c-p[in].at;
			p[in].w=p[in].t-p[in].bt;
			tt=tt+p[in].t;
			wt=wt+p[in].w;
			is_com[in]=1;
			com++;
			curr=p[in].c;
			printf(" p%d ",in+1);
		}
		else{
			curr++;
			printf("_");
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		
		printf("%d\t%d\t%d\n",p[i].c,p[i].t,p[i].w);
	}
	printf("Average of tat and wt:\n");
	printf("%f\t%f",tt/n,wt/n);
}
