#include<stdio.h>
#include<limits.h>
struct ps{
	int at,bt,pt,c,t,w,id,s;		
};
int main()
{
	int n,i;
	struct ps p[10];
	printf("Enter no.of processes:");
	scanf("%d",&n);
	int is_com[n];
	printf("Enter at,bt and priority:");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pt);
		p[i].id=i+1;
		is_com[i]=0;
	}
	int curr=0;
	int com=0;
	float tt=0,wt=0;
	while(com!=n)
	{
		int in=-1;
		int min=INT_MAX;
		for(i=0;i<n;i++){
		
		if(p[i].at<=curr && is_com[i]==0)
		{
			if(p[i].pt<min)
			{
				min=p[i].pt;
				in=i;
			}
			if(p[i].pt==min)
			 if(p[i].at<p[in].at){
			 
			{
				min=p[i].pt;
				in =i;
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
		tt+=p[in].t;
		wt+=p[in].w;
		is_com[in]=1;
		com++;
		curr=p[in].c;
	}
	else
	{
		curr++;
	}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",p[i].c,p[i].t,p[i].w);
	}
	printf("Averages of tat and wt:");
	printf("%f\t%f",tt/n,wt/n);
	
}
