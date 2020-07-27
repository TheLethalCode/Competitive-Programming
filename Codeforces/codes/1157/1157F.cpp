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
int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vi v(n);
    FOR(i, n) cin>>v[i];
    sort(all(v));
    int st=0, en=0;
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1]>1)continue;
        int j=i+1;
        while(j<n && v[j]-v[j-2]<=1) j++;
        if(en-st < j-i) st=i-1, en=j-1;
        i=j-1;
    }
    cout<<en-st+1<<endl;
    vi ans(en-st+1);
    for(int i=st;i<=en;i+=2){
        ans[i-st>>1]=v[i];
        if(i+1<=en) ans[en-st-(i-st>>1)] = v[i+1];
    }
    debugA(ans);

}