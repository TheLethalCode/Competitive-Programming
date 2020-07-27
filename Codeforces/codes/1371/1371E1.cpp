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
    int n, p;
    cin>>n>>p;
    vi v(n), fin;
    FOR(i, n) cin>>v[i];
    sort(all(v));
    FOR(i, 2000){
        int x = i+1, ok=1;
        lli ans = 1;
        vi pos(n, 0);
        FOR(i, n) {
            if(v[i] > x+n-1){
                ok=0;
                break;
            }
            pos[max(0, v[i]-x)]++;
        }
        if(!ok) continue;
        FOR(i, n-1) pos[i+1]+=pos[i];
        FOR(i, n) ans = (ans * (pos[i]-i))%p;
        if(ans) fin.pb(x);
    }
    cout<<sz(fin)<<endl;
    FORR(x, fin) cout<<x<<" ";
    cout<<endl;
}