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
    int n, ans = 0;
    string s;
    cin>>n>>s;
    vi check(n+1, -1), fact;
    for(int i=1;i<=n;i++) if(n%i==0) fact.pb(i);
    FORR(el, fact){
        int ok = 1;
        FOR(i, el){
            int te=0;
            for(int j=i;j<n;j+=el) if(s[j]=='1') te++;
            if(te & 1) ok=0;
            if(!ok) break;
        }
        check[el]=ok;
    }
    FOR(i, n) if(check[i+1]==1 || (check[i+1]==-1 && check[__gcd(n, i+1)])) ans++;
    cout<<ans<<endl;
}