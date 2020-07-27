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
    int n;
    cin>>n;
    vli v(n), vis(61, 0);
    map< int, vi > mp;
    FOR(i, n) cin>>v[i], mp[v[i]].pb(i), vis[v[i]+30]=1;

    lli ans = 0;
    for(int x=-30;x<=30;x++){
        if(!vis[x+30]) continue;

        vi te = mp[x];
        int m = te.size();
        for(int i=0;i<m;i++){
            int el = te[i];
            int l = -1, r = n;
            for(int j=x+1;j<=30;j++){
                if(!vis[j+30])continue;
                vi temp = mp[j];
                int pos = lower_bound(all(temp), el) - temp.begin();
                if(pos)
                    l = max(temp[pos-1], l);
                if(pos != temp.size())
                    r = min(r, temp[pos]);
            }
            l=min(el, l+1), r=max(el, r-1);
            
            
            vi pos;
            int j = i;
            while(j<m && (te[j] >= l && te[j]<=r))
                pos.pb(te[j]), j++;
            i = j-1;

            vli end(r-l+1, -1e9), start(r-l+1, -1e9);
            for(int i=l;i<=r;i++){
                if(i==l){
                    end[i-l]=v[i];
                    continue;
                }
                end[i-l] = max(end[i-1-l] + v[i], v[i]);
            }
            for(int i=r;i>=l;i--){
                if(i==r){
                    start[i-l]=v[i];
                    continue;
                }
                start[i-l] = max(start[i+1-l] + v[i], v[i]);
            }
            for(int el1 : pos){
                lli temp = 0;
                if(el1 != r)
                    temp = max(temp, start[el1+1-l]);
                if(el1 != l)
                    temp += max(0LL, end[el1-1-l]);
                ans = max(ans, temp);
            }
        }
    }
    cout<<ans<<endl;
}