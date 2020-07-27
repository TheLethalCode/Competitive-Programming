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

int v[500005], sieve[10000001] = {0}, n;
vi fac[500005];

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    for(int i=2;i<1e7;i++) if(!sieve[i]) for(int j=2*i;j<=1e7;j+=i) sieve[j]=i;
    vi ans1(n,-1), ans2(n,-1);
    FOR(j, n) {
        int a, x;
        cin>>a; x=a;
        while(x>1){
            if(!sieve[x]) break;
            int y=sieve[x], tem=1;
            while(x%y==0) x/=y, tem*=y;
            if(tem<a) {
                ans1[j]=tem, ans2[j]=a/tem;
                break;
            }
        }
    }
    debugA(ans1);debugA(ans2);
}