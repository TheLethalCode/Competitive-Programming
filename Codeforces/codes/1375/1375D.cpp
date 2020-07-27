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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

int n;
int find_mex(vi &v){
    vi occ(n+3, 0);
    FORR(x, v) occ[x]=1;
    FOR(i, n+3) if(!occ[i]) return i;
}

bool is_sort(vi &v){
    for(int i=0;i<n-1;i++) if(v[i+1] < v[i]) return false;
    return true;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int cur = n;
        vi v(n), ans;
        FOR(i, n) cin>>v[i];
        while(cur>0 && v[cur-1]==cur) cur--;
        while(!is_sort(v)){
            int x = find_mex(v);
            if(x==cur) v[cur-1]=x, ans.pb(cur-1), cur--;
            else v[x]=x, ans.pb(x);
        }
        cout<<sz(ans)<<endl;
        FORR(x, ans) cout<<x+1<<" ";
        cout<<endl;
    }
}