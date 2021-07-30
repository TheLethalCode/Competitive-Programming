#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define C1 200005
#define C2 2005

int n;
lli ar[C1];
vector < int > edge[C1];

void dfs(int u, lli &big, lli &sum, int &cnt) {
    big = 0, cnt = 0, sum = 0;
    for (int v : edge[u]) {
        lli tempL, tempS;
        int tempN;
        dfs(v, tempL, tempS, tempN);
        big = max(big, tempL);
        cnt += tempN;
        sum += tempS;
    }
    if(edge[u].empty()) {
        cnt++;
        big = ar[u];
    } else {
        lli temp = max(0LL, ar[u] - (big * cnt - sum));
        big += (temp + cnt - 1) / cnt;
    }
    sum += ar[u];
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        edge[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    lli ans, dum1;
    int dum2;
    dfs(1, ans, dum1, dum2);
    cout << ans << "\n";
}