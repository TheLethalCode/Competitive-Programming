#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int n;
    cin>>n;
    vector< vi > v(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    queue< int > q;
    q.push(0);
    vi p(n,-1);
    p[0]=0;
    int w;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto r: v[u])
        {
            if(p[r]!=-1)
                continue;
            p[r]=p[u]+1;
            w=r;
            q.push(r);
        }
    }
    for(int i=0;i<n;i++)
        p[i]=-1;
    p[w]=0;
    q.push(w);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto r: v[u])
        {
            if(p[r]!=-1)
                continue;
            p[r]=p[u]+1;
            w=p[r];
            q.push(r);
        }
    }
    cout<<w<<endl;
}