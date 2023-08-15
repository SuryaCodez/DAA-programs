#include<iostream>
#include<ctime>
#define MAX 100
using namespace std;
bool visited[MAX];
int adj[MAX][MAX];
void dfs(int start, int n)
{
        int stack[MAX];
        int top=-1;
        int v;
        visited[start]=true;
        stack[++top]=start;
        while(top!=-1)
        {
                v=stack[top--];
                cout<<v<<"";
                for(int i=0;i<n;i++)
                {
                        if(adj[v][i]&&!visited[i])
                        {
                                visited[i]=true;
                                stack[++top]=i;
                        }
                }
        }
        cout<<endl;
}
int main()
{
        int start,n;
        cout<<"enter number of vertices\n";
        cin>>n;
        cout<<"enter the vertices\n";
        for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                        cin>>adj[i][j];
        cout<<"enter starting vertex\n";
        cin>>start;
        for(int i=0;i<n;i++)
                visited[i]=false;
        clock_t start_t=clock();
        dfs(start,n);
        clock_t end=clock();
        double time=double(end-start_t)/CLOCKS_PER_SEC;
        cout<<"time taken for dfs is\t"<<time*1000000<<"microseconds";
        return 0;
}
