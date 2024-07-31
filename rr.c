#include<stdio.h>
struct pcb{
	int pid,at,bt,ct,tat,wt,c,ind,but;
};
int i,j;
int f=-1,r=-1;
struct pcb q[10];
void enque(struct pcb p)
{
	if(f==-1 && r==-1)
	{
		f++;
		r++;
		q[r]=p;
	}
	else
	 q[++r]=p;
}
struct pcb del()
{
	struct pcb p;
	if(f==r)
	{
		p=q[f];
		f=r=-1;
	}
	else
	{
		p=q[f];
		f++;
	}
	return p;
}
void sort(struct pcb p[],int n)
{
	struct pcb temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
			else if((p[i].at==p[j].at)&&(p[i].bt>p[j].bt))
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		p[i].ind=i;
	}
}
void sort2(struct pcb p[],int n)
{
	struct pcb temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].pid>p[j].pid)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
void enque(struct pcb p);
struct pcb del();
void sort(struct pcb p[],int n);
void sort2(struct pcb p[],int n);

int main()
{
	int n;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	struct pcb p[n];
	printf("Enter process details:\n");
	for(i=0;i<n;i++)
	{
		p[i].pid=i+1;
		p[i].c=0;
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].but=p[i].bt;
	}
	int t;
	printf("Enter time interval:");
	scanf("%d",&t);
	sort(p,n);
	int k=0;
	int time=0;
	enque(p[0]);
	p[0].c=1;
	time=p[0].at;
	while(k<n)
	{
		struct pcb pro;
		pro=del();
		int ind=pro.ind;
		if(p[ind].but<=t)
		{
			p[ind].ct=time+p[ind].but;
			p[ind].tat=p[ind].ct-p[ind].at;
			p[ind].wt=p[ind].tat-p[ind].bt;
			p[ind].but=0;
			time=p[ind].ct;
			k++;
		}
		else
		{
			p[ind].but-=t;
			time+=t;
		}
		for(i=0;i<n;i++)
		{
			if(p[i].at<=time && p[i].c==0)
			{
				enque(p[i]);
				p[i].c=1;
			}
		}
		if(p[ind].but!=0)
		{
			enque(p[ind]);
			p[ind].c=1;
		}
	}
	sort2(p,n);
	printf("id\tat\tbt\tct\ttat\twt\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
		
	}
}
