
#include <stdio.h>
int adj[10][10] = {{0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 1, 0, 0, 1, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0}};
int result[10] = {-1, -1, -1, -1, -1,-1,-1,-1,-1,-1};
int visited[10];
int q[10];
int f = -1;
int r = -1;
int isempty()
{
    if ((f == -1) || (f > r))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    if (r == 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int enque(int val)
{
    if (isfull() != 1)
    {
        r++;
        q[r] = val;
    }
    else
    {
        // printf("Queue is full\n");
    }
    if (isempty())
    {
        f++;
    }
}
int deque()
{
    if (!isempty())
    {
        int del_el = q[f];
        f++;
        return del_el;
    }
    else
    {
        printf("Queue is empty\n");
    }
}
void color(int u)
{
    while (!isempty())
    {
        u = deque();
        visited[u] = 1;
        int i;
        int colour = 0;
        for (i = 0; i < 10; i++)
        {
            if (adj[u][i] == 1 && result[i] != -1)
            {
                if(result[i] == colour){
                    colour++;
                }
            }
            if (adj[u][i] == 1 && visited[i] != 1)
            {
                enque(i);
            }
        }
        result[u] = colour;
    }
}

int main()
{
    enque(0);
    color(0);
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}
