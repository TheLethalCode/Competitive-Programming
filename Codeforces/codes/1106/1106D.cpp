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
    int n,m;
    cin>>n>>m;
    vector< set<int> > v(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a-1].insert(b-1);
        v[b-1].insert(a-1);
    }
    priority_queue <int> pq;
    pq.push(0);
    int cnt=0;
    vi vis(n,0);
    vis[0]=1;
    vi ans;
    while(cnt<n)
    {
        int u=abs(pq.top());
        ans.pb(u);
        pq.pop();
        for(int a:v[u])
        {
            if(!vis[a])
            {
                pq.push(-a);
                vis[a]=1;
            }
        }
        cnt++;
    }
    for(int a:ans)
        cout<<a+1<<" ";
    cout<<endl;
}