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

lli n, k;

lli func(lli x){
    if(x > n) return 0;
    lli temp = 2*x, i=1, cnt=1;
    while(temp + (1LL<<i) - 1 <= n){
        temp*=2, cnt+=1LL<<i, i++;
    }
    if(temp > n) return cnt;
    else cnt += (n&((1LL<<i)-1))+1; 
    return cnt;
}

lli can(lli ans){
    return func(ans) + (ans&1?0:func(ans+1)) >= k;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>k;
    lli ans = 0;
    for(int i=60;i>=1;i--){
        if(can(ans+(1LL<<i)))
            ans+=1LL<<i;
    }
    if(can(ans+1)) ans++;
    cout<<ans<<endl;
}