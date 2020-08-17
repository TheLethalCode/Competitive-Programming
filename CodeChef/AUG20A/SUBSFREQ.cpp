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
#define MAXC 500005
// %

lli pomo(lli n, lli p){
    if(!p){
        return 1;
    }
    if(p&1){
        return pomo(n, p-1) * n % mod;
    }
    lli t = pomo(n, p>>1);
    return t * t % mod;
}

vector< lli > fact(MAXC, 1), Ifact(MAXC, 1);

lli nCr(int n, int r){
    lli down = Ifact[r] * Ifact[n-r] % mod;
    return fact[n] * down % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=1;i<MAXC;i++){
        fact[i] = fact[i-1] * i % mod;
        Ifact[i] = pomo(fact[i], mod - 2);
    }
    while(t--){
        int n;
        cin >> n;
        vector< int > cnt(n+1), Ccnt(n+1), Cnum;
        vector< lli > ans(n+1);
        set< int > num;
        FOR(i, n){
            int x;
            cin >> x;
            cnt[x]++;
            num.insert(x);
        }
        FOR(i, n){
            if(cnt[i+1]){
                Ccnt[cnt[i+1]]++;
                if(Ccnt[cnt[i+1]] == 1){
                    Cnum.pb(cnt[i+1]);
                }
            }
        }
        sort(Cnum.begin(), Cnum.end());
        int y = Cnum.size();
        vector< lli > ncr[y], Incr[y];
        vector< int > CnumI(n+1);
        FOR(i, y){
            lli sum = 0;
            FOR(j, Cnum[i] + 1){
                sum = (sum + nCr(Cnum[i], j)) % mod;
                ncr[i].pb(sum);
                Incr[i].pb(pomo(sum, mod-2));
            }
            CnumI[Cnum[i]] = i;
        }
        int i = 1, sat = 0, pref = 1;
        while(!num.empty()){
            if(Cnum[sat] < i){
                pref = pref * pomo(ncr[sat].back(), Ccnt[Cnum[sat]]) % mod;
                sat++;
            }
            lli cur = pref;
            for(int j = sat; j < y; j++){
                cur = cur * pomo(ncr[j][i], Ccnt[Cnum[j]]) % mod; 
            }
            int prev = -1;
            for(auto it = num.begin(); it != num.end();){
                int x = *it;
                if(prev != -1){
                    cur = cur * ncr[prev][i-1] % mod;
                }
                prev = CnumI[cnt[x]];
                cur = cur * Incr[prev][i] % mod;
                ans[x] = (ans[x] + cur * nCr(Cnum[prev], i)) % mod;
                if(cnt[x] == i){
                    it = num.erase(it);
                }
                else{
                    it++;
                }
            }
            i++;
        }
        FOR(i, n){
            cout << ans[i+1] << ' ';
        }
        cout << '\n';
    }
}