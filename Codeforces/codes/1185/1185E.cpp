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
        int n, m, k, fl=0;
        cin>>n>>m;
        vpa pos[26];
        int v[n][m];
        set< int > cnt[2][26];
        FOR(i, n) FOR(j, m){
            char x; cin>>x;
            if(x=='.'){
                v[i][j]=-1;
                continue;
            }
            v[i][j]=x-'a';
            pos[x-'a'].pb({i, j}), cnt[0][x-'a'].insert(i), cnt[1][x-'a'].insert(j);
            
        }
        for(k=25;k>=0 && pos[k].empty();k--);
        vector< pair< pa, pa > > ans(k+1, {{-1, -1},{-1, -1}});
        for(int i=0;i<=k && !fl;i++) {
            if(cnt[0][i].size()>1 && cnt[1][i].size()>1) {
                fl=1;
                break;
            }
            if(pos[i].empty()) continue;
            
            sort(all(pos[i]));
            pa st = pos[i][0], en = pos[i].back(), di={en.fi-st.fi, en.se-st.se};
            ans[i].fi=st, ans[i].se=en;
            if(pos[i].size()==1) continue;

            for(;st <= en && !fl; st.fi+=!!di.fi, st.se+=!!di.se) if(v[st.fi][st.se]<i) fl=1;
        }
        if(fl) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl<<k+1<<endl;
            FOR(i, k+1) {
                if(ans[i].fi.fi == -1) ans[i]=ans[k];
                cout<<ans[i].fi.fi+1<<" "<<ans[i].fi.se+1<<" "<<ans[i].se.fi+1<<" "<<ans[i].se.se+1<<endl;
            }
        }
        
    }
}