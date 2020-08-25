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

void linearSieve(){
    vector < int > prime;
    vector< bool > is_prime(MAXC, 1);
    is_prime[1] = is_prime[0] = 0;
    for (int i = 2; i < MAXC; i++) {
        if (is_prime[i]) {
            prime.pb(i);
        }
        for (auto p : prime) {
            if (p * i >= MAXC) {
                break;
            }
            is_prime[p * i] = false;
            if (i % p == 0) {
                break;
            }
        }
    }
}