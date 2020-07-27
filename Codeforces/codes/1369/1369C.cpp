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

#define perc %

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, k;
        lli ans = 0;
        cin>>n>>k;
        vli v(n), w(k);
        FOR(i, n) cin>>v[i];
        sort(all(v));
        FOR(i, k) cin>>w[i];
        sort(all(w));
        FORR(x, w) {
            if(x==1) ans += v.back();
            ans+=v.back(), v.pop_back();
        }
        int inc = 0;
        for(int i=k-1;i>=0 && w[i]>1;i--){
            ans += v[inc];
            inc += w[i]-1;
        }
        cout<<ans<<endl;
    }
}