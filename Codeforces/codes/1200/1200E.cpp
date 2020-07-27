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

#define base1 67

// %
lli val(char x){
    if(x>='0' && x<='9') return x-'0'+1;
    if(x>='a' && x<='z') return (x-'a')+11;
    return (x-'A')+37;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vector< string > v(n);
    FOR(i, n) cin>>v[i];
    string ans = v[0];
    FOR(i, n-1){
        int x = ans.length(), k = v[i+1].length(), j=0, fl=0;
        lli kN = 0, xN=0, po1 = 1;
        while(j<k && j<x){
            kN = (kN*base1 + val(ans[x-1-j]))%mod;
            xN = (xN + val(v[i+1][j])*po1)%mod;
            if(kN == xN) fl=j+1;
            po1 = (po1 * base1) % mod, j++;
        }
        ans+=v[i+1].substr(fl); 
    }
    cout<<ans<<endl;
}