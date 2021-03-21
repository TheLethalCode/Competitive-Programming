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
#define MAXC 5005
// %

vector< vector < bool > > E(MAXC, vector< bool >(MAXC, 0));

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector< lli > tag(N + 1), S(N + 1);
        for (int i = 0; i < N; i++) {
            cin >> tag[i + 1];
        }
        for (int i = 0; i < N; i++) {
            cin >> S[i + 1];
        }
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                E[j+1][i+1] = E[i+1][j+1] = (tag[i+1] != tag[j+1]);
            }
        }
        
        lli back[N + 2], ansWithEdge[N + 2], ans[N + 2];
        memset(back, 0, sizeof(back));
        memset(ansWithEdge, 0, sizeof(ansWithEdge));
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= N; i++) {
            back[i] = max(back[i-1], E[i][N]? abs(S[N] - S[i]): 0);
            ans[i] = back[i-1];
            ansWithEdge[i] = (E[i][N]? ans[i] + abs(S[N] - S[i]): 0);
        }
        for (int i = N - 1; i; i--) {
            for (int j = 1; j <= i; j++) {
                back[j] = max(back[j - 1], E[i][j]? abs(S[i] - S[j]) + ansWithEdge[j]: 0);
                ans[j] = max(back[j - 1], ansWithEdge[i]);
                ansWithEdge[j] = max(ansWithEdge[j], E[i][j]? ans[j] + abs(S[i] - S[j]): 0);
            }
        }
        cout << *max_element(ans + 1, ans + N + 1) << "\n";
    }
}