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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        vi cnt(26, 0);
        FOR(i, n) cnt[s[i]-'a']++;
        int m, wt=0;
        cin>>m;
        
        vi v(m), ans(m, -1);
        FOR(i, m) cin>>v[i], wt += (v[i]==0);
        
        int done=0, prev=26;
        while(done<m){
            for(int j=prev-1;j>=0;j--) if(cnt[j]>=wt) {
                prev=j;
                break;
            }
            wt = 0;
            vi temp;
            FOR(i, m) if(!v[i] && ans[i]==-1) ans[i]=prev, done++, temp.pb(i);
            FOR(i, m) {
                if(ans[i]==-1){
                    int qw = 0;
                    for(int pos : temp) qw+=abs(pos-i);
                    v[i]-=qw, wt+=(v[i]==0);
                }
            }
        }
        FOR(i, m) cout<<(char)('a'+ans[i]);
        cout<<endl;
    }
}