#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> adj[100001];
vector<int> from[100001];

int parent[100001];

bool visited[100001],cycled[100001], finished[100001];



void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }

    v.erase(end, v.end());
}


int ans=0;
int  n,m;
void denoteCycle(int node)
{
    if(cycled[node]) return;
    cycled[node] = true;

    for(int i=0;i<from[node].size();i++)
    {
        denoteCycle(from[node][i]);
    }




}

void DFS(int node)
{
    if(visited[node]) return;

//cout << node <<endl;
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {

        int next = adj[node][i];

        if (!visited[next]) {
            parent[next] = node;
            DFS(next);
        }

        else if (finished[next] == false && !cycled[next]) {

            denoteCycle(node);
        }
    }
    finished[node] = true;
}

int main()

{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);



    int i;
    cin >> n >> m;

    for(i=0;i<=n;i++)
    {


        finished[i] = false;
        cycled[i] = false;
        visited[i] = false;
        parent[i] = i;

    }

    for(i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;



            adj[a].push_back(b);
            parent[b] = a;
            from[b].push_back(a);



    }
    for(i=1;i<=n;i++)
    {
        remove(adj[i]);
        remove(from[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i] ) DFS(i);
    }

    for(i=1;i<=n;i++)
    {
        if(!cycled[i]) ans++;
     //   else cout <<" "<< i << endl;
    }
    cout << ans<<endl;



    return 0 ;
}
