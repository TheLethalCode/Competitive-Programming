#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 998244353
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
template <class T> inline bool chmin(T a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
map< lli, vector< pair< lli, int > > > mp;
int n;

lli pomo(lli n, lli p){
    if(!p){
        return 1;
    }
    else if(p&1){
        return pomo(n, p-1) * n % mod;
    }
    else{
        lli t = pomo(n, p>>1);
        return t * t % mod;
    }
}

void calc(int i, vector< pair< lli, int> > fact, lli num){
    if(i == n){
        mp[num] = fact;
        return;
    }
    while(fact[i].se >= 0){
        calc(i+1, fact, num);
        fact[i].se--;
        num/=fact[i].fi;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli D, num;
    cin>>D;
    vector< pair< lli, int > > fact;
    vector< lli > f(100, 1), finv(100, 1);
    num = D;
    for(lli i=2;i*i <= D;i++){
        int cnt = 0;
        while(D % i == 0){
            D/=i;
            cnt++;
        }
        if(cnt){
            fact.pb(i, cnt);
        }
    }
    if(D != 1){
        fact.pb(D, 1);
    }
    n = sz(fact);
    calc(0, fact, num);
    for(int i=1;i<100;i++){
        f[i] = f[i-1] * i % mod;
        finv[i] = pomo(f[i], mod-2);
    }
    int q;
    cin>>q;
    while(q--){
        lli u, v, g = 0, l=0, ans = 1;
        cin>>u>>v;
        auto x = mp[u], y = mp[v];
        FOR(i, n){
            if(x[i].se == y[i].se){
                continue;
            }
            else if(x[i].se > y[i].se){
                g+=x[i].se - y[i].se;
                ans = ans * finv[x[i].se-y[i].se] % mod;
            }
            else{
                l+=y[i].se - x[i].se;
                ans = ans * finv[y[i].se-x[i].se] % mod;
            }
        }
        cout<< (ans * f[g] % mod ) * f[l] % mod << "\n";
    }
}