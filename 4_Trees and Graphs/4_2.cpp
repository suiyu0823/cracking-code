#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 100;
bool g[maxn][maxn];
bool visited[maxn];

int n;
queue<int>q;

void init()
{
    memset(g, false, sizeof(g));
    memset(visited, false, sizeof(visited));
}

bool isRoute(int src, int dest)
{
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        if(t == dest) return true;
        for (int i = 0; i < n; i++)
        {
            if(g[t][i] && !visited[i] )
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

int main()
{

    freopen("4_2.txt", "r", stdin);
    
    init();
    int m, u, v;
    cin>>n>>m;
   // cout << n << m << endl;
    for(int i=0; i<m; ++i){
        cin>>u>>v;
       // cout << u << " " << v << endl;
        g[u][v] = true;
    }
    cout<<isRoute(0, 4)<<endl;
    fclose(stdin);
    return 0;
}