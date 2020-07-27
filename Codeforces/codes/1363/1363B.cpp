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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        vector< vi > v(n+1, vi(2,0));
        FOR(i, n){
            v[i+1]=v[i];
            v[i+1][s[i]-'0']++;
        }
        int ans=1e9;
        FOR(i, n+1){
            int temp=0;
            temp+=v[i][1]-v[0][1];
            temp+=v[n][0]-v[i][0];
            ans=min(ans, temp);
        }
        FOR(i, n+1){
            int temp=0;
            temp+=v[i][0]-v[0][0];
            temp+=v[n][1]-v[i][1];
            ans=min(ans, temp);
        }
        cout<<ans<<endl;
    }
}