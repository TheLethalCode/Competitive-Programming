#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define nl cout<<"\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int n;
vector< vi > v;
int visited[10001]={0};
int parent[10001]={-1};
bool val=true;

void dfs(int x)
{
    visited[x]=1;
    for(auto &it:v[x])
    {
        if(visited[it] && parent[x]!=it)
        {
            val=false;
            return;
        }
        else if(visited[it])
            continue;
        parent[it]=x;
        dfs(it);
    }
}

int main()
{
    crap;
    int m;
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a-1].pb(b-1);
        v[b-1].pb(a-1);
    }
    dfs(0);
    for(int i=0;i<n;i++)
        if(!visited[i])
            val=false;
    if(val)
        cout<<"YES";
    else
        cout<<"NO";
    nl;
}