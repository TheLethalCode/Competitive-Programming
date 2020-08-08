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

int sk[MAXC];
struct comp{
    bool operator()(const int& i, const int& j) const {
        return make_pair(sk[i], -i) > make_pair(sk[j], -j);
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        FOR(i, n){
            cin >> sk[i];
        }
        int left = m-1, right = n - m, cnt = 0 ;
        set< int, comp > S;
        for(int i=0;i<=left;i++){
            S.insert(i);
        }
        for(int j=right;j<=n-1;j++){
            S.insert(j);
        }
        vector< bool > done(n, false);
        while(cnt < m){
            int f = *S.begin();
            S.erase(S.begin());
            done[f] = 1;
            if(f <= left){
                left++;
                while(left < n && done[left]){
                    left++;
                }
                if(left < n){
                    S.insert(left);
                }
            }
            if(f >= right){
                right--;
                while(right >= 0 && done[right]){
                    right--;
                }
                if(right >= 0){
                    S.insert(right);
                }
            }
            cout << f + 1 << " ";
            cnt++;
        }
        cout << '\n';
    }
    
}