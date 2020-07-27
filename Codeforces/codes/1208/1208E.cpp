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
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    lli sum = 0;
    vector< int > V[n];
    multiset< int, greater<int> > S[n];
    int L[n] = {}, R[n] = {}, up = -1, down = n-1;
    FOR(i, n){
        int l;
        cin >> l;
        V[i].resize(l+2);
        FOR(j, l){
            cin >> V[i][j+1];
        }
        V[i][0] = V[i][l+1] = 0;
        S[i].insert(0);
    }
    sort(V, V + n, [](vector< int > &a, vector< int > &b){
        return a.size() > b.size();
    });
    for(int j=1; j <= w; j++){
        while(up < n-1 && V[up+1].size()-2 >= w-j+1){
            up++;
        }
        while(down>=0 && V[down].size()-1 == R[down]){
            down--;
        }
        FOR(k, up+1){
            sum -= *S[k].begin();
            S[k].erase(S[k].find(V[k][L[k]++]));
            if(S[k].size()){
                sum += *S[k].begin();
            }
        }
        FOR(k, down+1){
            if(S[k].size()){
                sum -= *S[k].begin();
            }
            S[k].insert(V[k][++R[k]]);
            sum += *S[k].begin();
        }
        cout << sum << " ";
    }
    cout << '\n';
}