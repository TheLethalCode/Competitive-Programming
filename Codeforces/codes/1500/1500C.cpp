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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector< vector< int > > A(n, vector< int >(m)), B(n, vector< int >(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }
    vector< int > inv(m), done(n), fifo;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            inv[j] += (B[i][j] > B[i+1][j]);
            if (i == n - 2 && !inv[j]) {
                fifo.push_back(j);
            } 
        }
    }
    for (int i = 0; i < fifo.size(); i++) {
        int col = fifo[i];
        for (int r = 0; r < n - 1; r++) {
            if (!done[r] && B[r][col] != B[r + 1][col]) {
                done[r] = 1;
                for (int j = 0; j < m; j++) {
                    if (B[r][j] > B[r+1][j]) {
                        inv[j]--;
                        if (!inv[j]) {
                            fifo.push_back(j);
                        }
                    }
                }
            }
        }
    }
    vector< int > temp(n);
    iota(temp.begin(), temp.end(), 0);
    reverse(fifo.begin(), fifo.end());
    for (int col : fifo) {
        stable_sort(temp.begin(), temp.end(), [&](int i, int j) {
            return A[i][col] < A[j][col];
        });
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[temp[i]][j] != B[i][j]) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << fifo.size() << "\n";
    for (int col : fifo) {
        cout << col + 1 << " ";
    }
    cout << "\n";
}