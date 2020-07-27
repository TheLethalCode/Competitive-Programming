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
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int n, q;
    lli tot=0;
    cin>>n;
    vi v(n+1), ext(n+1);
    FOR(i, n) cin>>v[i+1], tot+=v[i+1];
    cin>>q;
    set<pa> ed[n+1];
    while(q--){
        int a, b, c;
        cin>>a>>b>>c;
        auto it = ed[a].lower_bound(make_pair(b, 0));
        if(it!=ed[a].end() && it->fi==b){
            ext[it->se]--;
            if(ext[it->se] < v[it->se]) tot++;
            ed[a].erase(it);
        }
        if(c){
            ed[a].insert({b, c});
            ext[c]++;
            if(ext[c] <= v[c]) tot--;
        }
        cout<<tot<<endl;
    }
}