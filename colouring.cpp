#include<iostream>
using namespace std;
class Graph
{
   
    public:
        Graph(int v)
        {
            int adj[v][v];
            //={{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,0},{1,0,0,0,1},{0,1,0,1,0}};
            cout<<"Enter the adjcancy matrix : \n";
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    cin>>adj[i][j];
                }
            }

            int col[v]={0};

            for(int i=0;i<v;i++)
            {
                if(col[i]==0)
                {
                    for(int j=0;j<v;j++)
                    {
                        if(adj[i][j]==1 && col[j]==col[i])
                            col[i]++;
                    }
                    col[i]++;
                }
            }
            
            for(int i=0;i<v;i++)
            {
                cout<<col[i]<<endl;
            }
        }
};

int main()
{
    int n;
    cin>>n;
    Graph g(n);
    return 0;
}
