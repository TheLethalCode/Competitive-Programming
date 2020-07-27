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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vi v(n), sm(n+1,-1), bi(n+1,-1), nsmi(n+1, 0), nbi(n+1, n-1);
    FOR(i,n){
        cin>>v[i];
        if(sm[v[i]]==-1)
            sm[v[i]]=i;
        bi[v[i]]=i;
    }
    int i=0, j=n-1;
    while(v[i]==v[0]) i++;
    while(v[j]==v[n-1])j--;
    nsmi[v[0]]=i, nbi[v[n-1]]=j;
    int ans = 0;
    FOR(i, n+1){
        if(sm[i]==-1) continue;
        ans = max3(ans, nbi[i]-sm[i], bi[i]-nsmi[i]);
    }
    cout<<ans<<endl;
}