#include<iostream>
using namespace std;
void enque(struct pcb p);
void sort(struct pcb [],int n);
void sort2(struct pcb [],int n);

struct pcb 
{
    int pid,at,bt,burst,ct,tat,wt,c,ind;
};

struct pcb que[100];
int f=-1;
int r=-1;

void sort(struct pcb p[],int n)
{
    struct pcb temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
            if(p[i].at==p[j].at)
            {
            	if(p[j].bt<p[i].bt)
            	{
            		temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
				}
			}
        }
    }
    for(int i=0;i<n;i++)
    {
       p[i].ind=i;
    }
}

void sort2(struct pcb p[],int n)
{
     struct pcb temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
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
void enque(struct pcb p)
{
    if(f==-1 && r==-1)
    {
        f=r=0;
        que[r]=p;
    }
    else{
    r++;
    que[r]=p;
    }
}
struct pcb deque()
{
    struct pcb p;
    if(f==r)
    {
        p=que[r];
        f=r=-1;
    }
    else
    {
        p=que[f];
        f++;
    }
    return p;
}
int main()
{
    int n;
    cout<<"Enter no.of processes : ";
    cin>>n;
    struct pcb p[n];
    int time;
    cout<<"Enter process details \n";
    for(int i=0;i<n;i++)
    {
        cin>>p[i].at>>p[i].bt;
        p[i].pid=i+1;
        p[i].burst=p[i].bt;
        p[i].c=0;
    }
    cout<<"Enter time interval : ";
    cin>>time;
    int t=0;
    int k=0;
    sort(p,n);
    enque(p[0]);
    p[0].c=1;
    t=p[0].at;
    while(k<n)
    {
        struct pcb process;
        process=deque();
        int ind=process.ind;
        if(p[ind].burst<=time)
        {
            t=t+p[ind].burst;
            p[ind].ct=t;
            p[ind].burst=0;
            p[ind].tat=p[ind].ct-p[ind].at;
            p[ind].wt=p[ind].tat-p[ind].bt;
            k++;
        }
        else
        {
            p[ind].burst-=time;
            t+=time;
        }
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=t && p[i].c==0)
            {
                enque(p[i]);
                p[i].c=1;
            }
        }
        if(p[ind].burst!=0)
        {
            enque(p[ind]);
            p[ind].c=1;
        }
    }
    sort2(p,n);
    for(int i=0;i<n;i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\n";
    }
}
