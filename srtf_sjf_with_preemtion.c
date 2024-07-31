#include<stdio.h>
struct pcb{
	int pid,at,bt,ct,tat,wt,c;
};
int find(struct pcb p[],int n,int t,int bt[])
{
	int ind=-1,min=9999,a=9999,i;
	for(i=0;i<n;i++)
	{
		if(p[i].at<=t && p[i].c==0)
		{
			if(bt[i]<min)
			{
				min=bt[i];
				ind = i;
				a=p[i].at;
			}
			else if(bt[i]==min && p[i].at<a)
			{
				min=bt[i];
				ind=i;
				a=p[i].at;
			}
		}
	}
	return ind;
}
int find(struct pcb p[],int n,int t,int bt[]);
int main()
{
	int n,i;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	struct pcb p[n];
	int bt[n];
	printf("Enter process details:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].c=0;
		p[i].pid=i+1;
	}
	for(i=0;i<n;i++)
	{
		bt[i]=p[i].bt;
	}
	int time=0,ind,k=0;
	while(k<n)
	{
		ind=find(p,n,time,bt);
		if(ind!=-1)
		{
			time++;
			bt[ind]=bt[ind]-1;
			if(bt[ind]==0)
			{
				p[ind].c=1;
				p[ind].ct=time;
				k++;
			}
		}
		else
		{
			time++;
		}
	}
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
	printf("pid\tat\tbt\tct\ttat\twt\t\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
}
