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

bool solve(int a, int b, vi v){
    int ch=0;
    FORR(x, v){
        if(x==a) ch=1;
        if(ch && x==b) return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    crap;
    map< char, pa > mp;
    mp['W'] = {0, 1}, mp['S'] = {0, -1}, mp['A'] = {-1, 0}, mp['D'] = {1, 0};
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int L = 0, R = 0, U = 0, D = 0;
        vi ad, ws;
        ad.pb(0), ws.pb(0);
        pa cur;
        FORR(c, s){
            cur.fi += mp[c].fi, cur.se += mp[c].se;
            L = max(L, -cur.fi), R = max(R, cur.fi);
            D = max(D, -cur.se), U = max(U, cur.se);
            ad.pb(cur.fi), ws.pb(cur.se);
        }
        lli ans = 1LL*(L+R+1)*(U+D+1), temp = ans;
        if((solve(R, -L, ad) || solve(-L, R, ad)) && L + R > 1) temp = min(temp, 1LL*(L+R)*(U+D+1));
        if((solve(U, -D, ws) || solve(-D, U, ws)) && U + D > 1) temp = min(temp, 1LL*(L+R+1)*(U+D));
        cout<<temp<<endl;
    }
}