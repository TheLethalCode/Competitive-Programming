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
    int n, m;
    cin>>n>>m;
    vector< vi > ed(n+1);
    FOR(i, m){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    set<int> left;
    vi vis(n+1, -1);
    FOR(i, n) 
        left.insert(i+1), sort(all(ed[i+1]));
    int cnt = 0;

    FOR(i, n){
        if(vis[i+1] != -1) 
            continue;

        queue<int> cur;
        cur.push(i+1), vis[i+1]=cnt, left.erase(i+1);
        while(!cur.empty()){
            int u = cur.front();
            cur.pop();
            vi temp;
            for(int el : left)
                if(!binary_search(all(ed[u]), el))
                    temp.pb(el), cur.push(el);
                
            for(int el : temp)
                left.erase(el), vis[el]=cnt;
        }
        cnt++;
    }
    cout<<cnt-1<<endl;
}