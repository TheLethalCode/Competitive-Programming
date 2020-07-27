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

vli ar(18, 0), po(19, 1);

lli solve(int u, int i, int j, int sum){
    if(u + 9*j > sum) return 1e18;
    lli var = u + ar[j];
    sum -= u + 9*j;
    var += min(sum, 9-!!i)*po[j+1], sum=max(0, sum-9+!!i);
    int cnt = sum/9, rem = sum-9*cnt;
    if(cnt + j + 2 + !!rem >= 18) return 1e18;
    FOR(k, cnt) var += 9*po[k+j+2];
    if(rem) var += rem*po[cnt+j+2];
    return var;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    lli w = 90;
    FOR(i, 17) ar[i+1] = ar[i]+w, w*=10;
    FOR(i, 18) po[i+1] = po[i]*10;

    while(t--){
        int n, k;
        cin>>n>>k;
        lli ans = 1e18;
        n -= k*(k+1)/2;
        if( n < 0) {
            cout<<-1<<endl;
            continue;
        }
        FOR(i, k+1){
            FOR(j, 17){
                int temp = n + 9*i*(j+1);
                if(temp % (k+1)) continue;
                temp /= k+1;
                if(!i) FOR(l, 9-k+i+1) ans = min(ans, solve(l, i, j, temp));
                else ans = min(ans, solve(9-k+i, i, j, temp));
            }
        }
        if(ans == 1e18) ans=-1;
        cout<<ans<<endl;
    }
}