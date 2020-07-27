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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %

int main(int argc, char **argv)
{
    crap;
    int n, m, fin=2*mod;
    pa in;
    cin>>n>>m;
    vi f(n, 0), hap[n+1];
    vpal cost(1<<9, {2*mod, -1}), cost1(1<<9, {2*mod, -1});
    vector< pair<lli, pa> > ans(1<<9, {2*mod, {-1, -1}});
    FOR(i, n){
        int x, a;
        cin>>x;
        FOR(j, x){
            cin>>a;
            f[i] |= 1<<a-1;
        } 
    }
    FOR(i, m){
        int x, a, c, temp=0;
        cin>>c>>x;
        FOR(j, x){
            cin>>a;
            temp |= 1<<a-1;
        }
        if(cost[temp].fi>c) cost[temp].fi=c, cost[temp].se=i+1;
        else if(cost1[temp].fi>c) cost1[temp].fi=c, cost1[temp].se=i+1;
    }
    FOR(i, 1<<9){
        int cnt=0;
        FOR(j, n) if((f[j]&i)==f[j]) cnt++;
        hap[cnt].pb(i);
    }
    
    FOR(i, 1<<9) FOR(j, i+1) {
        if(i==j){
            if(ans[i|j].fi>cost[i].fi+cost1[j].fi){
                ans[i|j].fi=cost[i].fi+cost1[j].fi;
                ans[i|j].se={cost[i].se, cost1[j].se};
            }
        }
        else if(ans[i|j].fi>cost[i].fi+cost[j].fi){
            ans[i|j].fi=cost[i].fi+cost[j].fi;
            ans[i|j].se={cost[i].se, cost[j].se}; 
        }
    }
    
    for(int i=n, ok=1;i>=0 && ok;i--){
        FORR(x, hap[i]) {
            if(fin > ans[x].fi) 
                in=ans[x].se, fin=ans[x].fi, ok=0;
        }
    }
    cout<<in.fi<<" "<<in.se<<endl;
}