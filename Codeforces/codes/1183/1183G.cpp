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
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vi v(n+1), f(n+1), st(n), cnt[n+1];
        FOR(i, n) {
            int a, b;
            cin>>a>>b;
            v[a]++, f[a]+=b;
        };
        iota(st.begin(), st.end(), 1);
        sort(st.begin(), st.end(), [&](int i, int j){
            return v[i]>v[j];
        });
        FOR(i, n) cnt[v[i+1]].pb(f[i+1]);
        int ans = 0, ans1 = 0, prev=n+1;
        multiset< int, greater<int> > val;
        for(int i=0;i<n && prev>1;i++){
            prev=min(prev-1, v[st[i]]), ans+=prev;
            for(auto in : cnt[prev]) val.insert(in);
            ans1+=min(*val.begin(), prev), val.erase(val.begin()); 
        }
        cout<<ans<<" "<<ans1<<endl;
    }
}