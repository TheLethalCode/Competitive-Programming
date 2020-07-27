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

int main(int argc, char **argv)
{
    crap;
    int n, x, a, prev, prev1=0;
    lli ans = 0;
    cin>>n>>x;
    prev = x+1;
    vi first(x+2, n), last(x+2, -1), next(x+2), bef(x+2);
    FOR(i, n) {
        cin>>a;
        if(first[a]==n) first[a]=i;
        last[a]=i;
    }
    for(int i=x;i>=0;i--) {
        if(first[i]!=n) prev=i;
        next[i]=prev;
    }
    for(int i=0;i<=x;i++) {
        if(first[i]!=n) prev1=i;
        bef[i]=prev1;
    }
    
    int pl = next[0], l = next[pl+1], pr = bef[x], r = bef[pr-1];
    while(l < x){
        if(last[pl] > first[l]) break;
        pl=l, l=next[l+1];
    }
    while(r > 1){
        if(last[r] > first[pr]) break;
        pr = r, r=bef[r-1];
    }
    
    for(int i=1, j=max(r, i); i<=l; i++){
        j = max(j, i);
        while(j <= x && first[next[j+1]] < last[bef[i-1]]) j++;
        ans += x+1-j;
    }
    cout<<ans<<endl;
}