#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector< vi > ed(n+1);
        FOR(i, n-1){
            int a, b;
            cin>>a>>b;
            ed[a].pb(b), ed[b].pb(a);
        }
        if(n==1 || ed[x].size()==1){
            cout<<"Ayush"<<endl;
            continue;
        }
        vi vis(n+1, -1);
        vis[x]=0;
        int cnt=1;
        FOR(i, n){
            if(vis[i+1]!=-1) continue;
            queue<int> q;
            q.push(i+1);
            vis[i+1]=cnt;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v: ed[u]){
                    if(vis[v] == -1){
                        vis[v]=cnt, q.push(v);
                    }
                }
            }
            cnt++;
        }
        int o = 0;
        vi st(cnt, 0);
        FOR(i, n) st[vis[i+1]]++;
        FOR(i, cnt-1) if(st[i+1]&1) o++;
        if(o&1) cout<<"Ayush";
        else cout<<"Ashish";
        cout<<endl; 
    }
}