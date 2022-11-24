#include<iostream>
using namespace std;

int color(int x,int v,int result[],int adj[])
{
    //available colors
    int avail[v];

    //making all color available
    for(int k=0;k<v;k++)
        avail[k]=1;
    for(int k=0;k<v;k++)
    {
        //making the assigned colours adjacent to the vertices as unavailable
        if(result[k]!=-1 && adj[k]==1)
        {
            avail[result[k]]=0;
        }
    }

    //assigning the color to that vertex
    for(int ind=0;ind<v;ind++)
    {
        if(avail[ind]==1)
        {
            result[x]=ind;
            return ind;
        }
    }
    return 0;

}

int main()
{
    //number of vertices
    int v;
    cout<<"Enter the number of vertices"<<endl;
    cin>>v;

    //adjacency matrix of VxV
    int adj[v][v];
    //visited matrix
    int visited[v];

    for(int i=0;i<v;i++)
    {
        //making all the vertices as not visited
        visited[i]=0;

        //getting the adj row for a vertex
        for(int j=0;j<v;cin>>adj[i][j++]);
    }

    //selecting our order as DFS
    int bfs[v],ind;//vertex pointer
    bfs[0]=0;
    visited[0]=-1;
    int temp=0;//loop variable
    int pointer=1;//pointer for queue
    while(temp<pointer)
    {
        ind=bfs[temp];
        for(int loops=0;loops<v;loops++)
        {
            if(adj[ind][loops]==1 && visited[loops]==0)
            {
                //cout<<"loops"<<loops<<endl;
                bfs[pointer++]=loops;
                visited[loops]=-1;
            }
        }
        temp++;
    }

    int fin_res[v];

    for(int ij=0;ij<v;ij++)
    {
        //cout<<"vertex:"<<bfs[ij]<<endl;
        int res=color(bfs[ij],v,visited,adj[bfs[ij]]);
        fin_res[bfs[ij]]=res;
    }

    for(int i=0;i<v;i++)
    {
        cout<<fin_res[i]<<endl;
    }



}