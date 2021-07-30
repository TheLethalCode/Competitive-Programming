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

bool arr[C2][C2];
int n, m;

struct ans {
    int a, b, c, d, e, f;
    ans(int _a, int _b, int  _c, int _d, int _e, int _f, bool act = true) {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        e = _e;
        f = _f;
        if (act) {
           apply();
        }
    }
    void apply() {
        arr[a][b] ^= 1;
        arr[c][d] ^= 1;
        arr[e][f] ^= 1;
    }
    friend ostream& operator<< (ostream &str, ans W);
};
ostream& operator<< (ostream &str, ans W) {
    str << W.a + 1 << " " << W.b + 1 << " " << W.c + 1 << " " << W.d + 1 << " " << W.e + 1 << " " << W.f + 1 << "\n";
    return str;
} 

vector< ans > res;

bool done() {
    int a = n - 2, b = m - 2;
    return !bool(arr[a][b] + arr[a][b+1] + arr[a+1][b] + arr[a+1][b+1]);
}

void solve() {
    int a = n - 2, b = m - 2;
    vector < ans > chuck;
    chuck.emplace_back(a, b, a, b + 1, a + 1, b, false);
    chuck.emplace_back(a, b, a, b + 1, a + 1, b + 1, false);
    chuck.emplace_back(a, b + 1, a + 1, b + 1, a + 1, b, false);
    chuck.emplace_back(a + 1, b + 1, a + 1, b, a, b, false);
    for (int i = 0; i < 16 && !done(); i++) {
        for (int j = 0; j < 4; j++) {
            if (i & 1 << j) {
                chuck[j].apply();
            }
        }
        for (int j = 0; j < 4; j++) {
            if (i & 1 << j) {
                if (done()) {
                    res.push_back(chuck[j]);
                } else {
                    chuck[j].apply();
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        res.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                arr[i][j] = s[j] - '0';
            }
        }
        for (int j = 0; j < m - 2; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (arr[i][j] && arr[i+1][j]) {
                    res.emplace_back(i, j, i + 1, j, i + 1, j + 1);
                } else if (arr[i][j]) {
                    res.emplace_back(i, j, i, j + 1, i + 1, j + 1);
                } else if (arr[i+1][j]) {
                    res.emplace_back(i + 1, j, i, j + 1, i + 1, j + 1);
                }
            }
        }

        int j = m - 2;
        for (int i = 0; i < n - 2; i++) {
            if (arr[i][j] && arr[i][j + 1]) {
                res.emplace_back(i, j, i, j + 1, i + 1, j + 1);
            } else if (arr[i][j]) {
                res.emplace_back(i, j, i + 1, j, i + 1, j + 1);
            } else if (arr[i][j+1]) {
                res.emplace_back(i, j + 1, i + 1, j, i + 1, j + 1);
            }
        }

        solve();
        cout << res.size() << "\n";
        for (auto x: res) {
            cout << x;
        }
    }
}