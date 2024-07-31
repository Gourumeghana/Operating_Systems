#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,resources;
    cin>>n>>resources;
    int allocated[n][resources],maximum[n][resources],need[n][resources],available[0][resources];
    for(int i=0;i<n;i++){
        for(int j=0;j<resources;j++){
            cin>>allocated[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<resources;j++){
            cin>>maximum[i][j];
        }
    }
    for(int j=0;j<resources;j++){
        cin>>available[0][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<resources;j++){
            need[i][j]=maximum[i][j]-allocated[i][j];
        }
    }
    int visited[n];
    int i=0,c=0;
    while(c!=n){
        int count=0;
        if(visited[i]!=1){
            for(int j=0;j<resources;j++){
            if(need[i][j]<=available[0][j]){
                count++;
            }
        }
        if(count==resources&&visited[i]!=1){
            cout<<i<<endl;
            visited[i]=1;
            for(int j=0;j<resources;j++){
                available[0][j]+=allocated[i][j];
            }
            c++;
        }
        }
        i++;
        if(i==n){
            i=0;
        }
    }
}