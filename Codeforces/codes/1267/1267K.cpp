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
int fin;

lli fact(int n){
    lli ans = 1;
    FOR(i, n) ans*=i+1;
    return ans;
}

lli func(vi &cnt, int ty=0){
    lli ans = 1;
    vi pref(21, 0);
    pref[0]=cnt[0];
    FOR(i, 20) pref[i+1] = pref[i] + cnt[i+1];
    for(int i=2;i<=fin-ty;i++) ans*=(pref[i-1]-i+2);
    FOR(i, 21) ans/=fact(cnt[i]);
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    lli k;
    int t;
    cin>>t;
    while(t--){
        cin>>k;
        vi cnt(21, 0);
        for(int i=2;k;i++) cnt[k%i]++, k/=i, fin=i;
        lli ans = func(cnt);
        if(cnt[0]) cnt[0]--, ans-=func(cnt, 1);
        cout<<ans-1<<endl;
    }
}