#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sort(int disks[],int n);
int main()
{
    int n;
    cout<<"Enter no.of disks: ";
    cin>>n;
    int disks[n];
    cout<<"Enter disks \n";
    for(int i=0;i<n;i++)
       cin>>disks[i];
    int head,dir,t,ans,total=0;
    cout<<"Enter head: ";
    cin>>head;
    cout<<"Enter track: ";
    cin>>t;
    cout<<"Enter 1. right and 2. left: ";
    cin>>dir;
    sort(disks,n);
    if(dir==1)
    {
        int i=0;
        while(disks[i]<head)
        {
            ans=disks[i];
            i++;
        }
        total+=abs(head-(t-1))+abs((t-1)-0)+abs(0-ans);
    }
    else if(dir==2)
    {
        int i=n-1;
        while(disks[i]>head)
        {
            ans=disks[i];
            i--;
        }
        total+=abs(head-0)+abs(0-(t-1))+abs((t-1)-ans);
    }
    cout<<"The total value is : "<<total<<endl;
}
void sort(int disks[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int temp;
        for(int j=i+1;j<n;j++)
        {
           if(disks[i]>disks[j])
           {
                temp=disks[i];
                disks[i]=disks[j];
                disks[j]=temp;
           }
        }
    }
}