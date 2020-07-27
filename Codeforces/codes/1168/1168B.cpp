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
    string s;
    cin>>s;
    int n = s.length();
    set< pa > st[4], fin;
    FOR(x, n){
        for(int k=1;k<=4;k++){
            if(x+2*k>=n) continue;
            if(s[x+k]==s[x] && s[x+2*k]==s[x]){
                st[k-1].insert({x, x+2*k});
            }
        }
    }
    vi arr(n+1, 1e9);
    FOR(te, 4){
        for(pa el : st[te]){
            int fl=0;
            for(int i=el.fi;i<=el.se;i++){
                if(arr[i] <= el.se){
                    fl=1;
                    break;
                }
            }
            if(!fl){
                fin.insert(el);
                arr[el.fi]=el.se;
            }
        }
    }
    int pr = 0;
    while(pr<n && arr[pr] == 1e9) pr++;
    if(arr[pr]==1e9){
        cout<<0<<endl;
        return 0;
    }

    lli ans = 1LL*(pr+1)*(n-arr[pr]);
    for(int i=pr+1;i<n;i++){
        if(arr[i]==1e9) continue;
        ans += 1LL*(i-pr)*(n-arr[i]);
        pr=i;
    }
    cout<<ans<<endl;
}