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
    lli n, k;
    cin>>n>>k;
    if(n<k*(k+1)/2){
        cout<<"NO"<<endl;
        return 0;
    }
    lli a = (n-k*(k+1)/2)/k, rem = n-k*(k+1)/2-k*a;
    vi ans(k);
    FOR(i, k) ans[i]=i+1+a;
    if(rem!=k-1 || a || k==1) ans[k-1]+=rem;
    else if(k>3) ans[k-1]+=rem-1, ans[k-2]+=1;
    else{
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    FOR(i, k) cout<<ans[i]<<" ";
    cout<<endl;
}