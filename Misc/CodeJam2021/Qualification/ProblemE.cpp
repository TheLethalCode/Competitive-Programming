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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double prob(double S, double Q) {
    return 1 / (1 + exp(Q - S));
}

pair< vector< string >, int > generateTest() {
    vector< double > skill(100), diff(10000);
    uniform_real_distribution<double> dist(-3.0, 3.0);
    uniform_int_distribution<int> distCheat(0, 99);
    bernoulli_distribution isCheat(0.5);
    int cheat = distCheat(rng);
    for (int i = 0; i < 100; i++) {
        skill[i] = dist(rng);
    }
    for (int i = 0; i < 10000; i++) {
        diff[i] = dist(rng);
    }

    vector< string > v(100, string(10000, '0'));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10000; j++) {
            bernoulli_distribution temp(prob(skill[i], diff[j]));
            if ((i == cheat && isCheat(rng)) || temp(rng)){
                v[i][j] = '1';
            }
        }
    }

    return {v, cheat};
}


int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 500, cnt = 0;
    for (int x = 1; x <= t; x++) {
        // auto = generateTest()
        vector< string > v(100);

        vector< int > num(10000), diff(10000);
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 10000; j++) {
                num[j] += (v[i][j] == '1');
            }
        }
        iota(diff.begin(), diff.end(), 0);
        sort(diff.begin(), diff.end(), [&](int i, int j) {
            return num[i] > num[j];
        });
        
        vector< double > anomaly(100);
        for (int i = 0; i < 100; i++) {
            int inv = 0, cnt0 = 0, cnt1 = 0;
            for (int j = 0; j < 10000; j++) {
                if (v[i][diff[j]] == '1') {
                    inv += cnt0;
                    cnt1++;
                } else {
                    cnt0++;
                }
            }
            anomaly[i] = inv;
            anomaly[i] /= cnt0 * cnt1;
        }
        int who = max_element(anomaly.begin(), anomaly.end()) - anomaly.begin();
        cout << "Case #"<< x <<": " << who << "\n";
    }
}