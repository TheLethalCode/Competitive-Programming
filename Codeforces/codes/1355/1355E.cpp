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
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
lli n, A, B, M;

lli calc(int i, lli H, vli &pref){
    lli x = H*i - pref[i], y = pref[n]-pref[i] - H*(n-i);
    lli z = min(x, y);
    x-=z, y-=z;
    return A*x+B*y+M*z;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>A>>B>>M;
    vli v(n), pref(n+1);
    FOR(i, n) cin>>v[i];
    sort(all(v)); 
    FOR(i, n) pref[i+1]=pref[i]+v[i];

    if(M>=A+B){
        int i=0;
        while(i<n && A*i <= B*(n-i)) i++;
        lli x = v[i-1]*i - pref[i], y = pref[n]-pref[i] - v[i-1]*(n-i);
        cout<<A*x+B*y<<endl;
        return 0;
    } 
    
    lli ans = 1e18;
    FOR(i, n) ans = min(ans, calc(i+1, v[i], pref));
    
    lli ch = pref[n]/n;
    int i = lower_bound(all(v), ch) - v.begin();
    i+=(v[i]==ch), ans=min(ans, calc(i, ch, pref));
    
    i = lower_bound(all(v), ch+1) - v.begin(), i+=(v[i]==ch+1);
    ans = min(ans, calc(i, ch+1, pref));
    
    cout<<ans<<endl;
}