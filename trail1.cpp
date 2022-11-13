#include<iostream>
#include<vector>
using namespace std;

void colour(int v,int i,int result[],int adj[])
{
    int avail[v];
    for(int k=0;k<v;k++)
        avail[k]=1;
    for(int k=0;k<v;k++)
    {
        //making the assigned colours adjacent to the vertices as unavailable
        if(result[k]!=-1 && adj[k]==1)
            avail[result[k]]=0;
    }

    for(int ind=0;ind<v;ind++)
    {
        if(avail[ind]==1)
        {
            result[i]=ind;
            break;
        }
    }
}


int main()
{
    int v;
    cout<<"Enter the No of vertices\n";
    cin>>v;
    int adj[v][v];
    int result[v];
    //getting adjacency matrix
    for(int i=0;i<v;i++)
    {
        //assigning no colours to the vertices
        result[i]=-1;
        for (int  j = 0; j < v; j++)
        {
            //getting inputs for the adjcancy matrix
            cin>>adj[i][j];
        }
        
    }
    for(int i=0;i<v;i++)
    {
        colour(v,i,result,adj[i]);
        cout<<result[i]<<endl;
    }
    return 0;
}