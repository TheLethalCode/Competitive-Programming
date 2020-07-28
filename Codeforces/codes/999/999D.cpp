#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

int n, m, a, b, t, q, x, ok, cnt, V[MAXC];
lli k, r, y, z, ans;
string s, c;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector< int > cnt(m), which[m];
    vector< pair< int, int > > amt;
    int f = n / m;
    FOR(i, n){
        cin >> V[i];
        cnt[V[i] % m]++;
        which[V[i] % m].pb(i);
    }
    FOR(i, 2*m){
        int cur = i % m;
        if(cnt[cur] > f){
            amt.pb(cur, cnt[cur] - f);
            x += cnt[cur] - f;
            cnt[cur] = f;
        }
        while(!amt.empty() && cnt[cur] < f){
            int temp, in = amt.back().fi, dis = (cur - in + m)%m;
            if(amt.back().se + cnt[cur] <= f){
                temp = amt.back().se;
                amt.pop_back();
            }
            else{
                temp = f-cnt[cur];
                amt.back().se -= temp;
            }
            cnt[cur] += temp;
            x -= temp;
            FOR(i, temp){ 
                V[which[in].back()] += dis;
                which[in].pop_back();
            }
        }
        ans += x;
    }
    cout << ans << '\n';
    FOR(i, n){
        cout << V[i] << ' ';
    }
    cout << '\n';
}