#include<iostream>
#include<stdlib.h>
using namespace std;

void colour(int v,int result[],int *adj)
{
    int avail[v];
    for(int i=0;i<v;i++)
    {
        result[i]=-1;
        avail[i]=1;
    }
    result[0]=0;
    for(int i=0;i<v;i++)
    {
        for(int l=0;l<v;l++)
        {
            avail[l]=1;
        }
        for(int k=0;k<v;k++)
        {
            if(*(adj+(i*v)+k)==1)
            {
                if(result[k]!=-1)
                {  
                    avail[result[k]]=0;
                }
            }
        }
        for(int j=0;j<v;j++)
        {
            if(*(adj+(v*i)+j)==1)
            {
                if(result[i]==-1)
                {
                    for(int k=0;k<v;k++)
                    {
                        if(avail[k]==1)
                        {
                            result[i]=k;
                            break;
                        }
                    }
                }
            }                
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<result[i]<<endl;
    }
}


int main()
{
    int v;
    cin>>v;
    int* adj=(int *)malloc(sizeof(int)*v*v);
    cout<<"Enter the adjcancy matrix : \n";

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>*(adj+(v*i)+j);
        }
    }
    int visited[v] ; //array to checkif it is visited
    int result[v];
    colour(v,result,adj);
    return 0;
}