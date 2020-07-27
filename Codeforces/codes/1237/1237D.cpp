#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int n;
int solve(int i, vi &ans, vi &next, vi &half){
    if(ans[i])
        return ans[i];
    if(half[i] == -1 && next[i] == -1)
        return ans[i]=-1;
    if(half[i] != -1 && (next[i]==-1 || half[i] < next[i]))
        return ans[i] = half[i]-i;
    int cnt = solve((next[i]%n), ans, next, half);
    return ans[i] = (cnt==-1?-1:next[i]-i+cnt);
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    vi v(2*n), next(n,-1), half(n, -1), ans(n, 0);;
    FOR(i, n) cin>>v[i], v[i+n]=v[i];
    vi stack; set< pa , greater< pa > > test;
    FOR(i, 2*n){
        while(!stack.empty() && v[stack.back()] < v[i])
            next[stack.back()] = i, stack.pop_back();
        while(!test.empty() && test.begin()->fi > v[i]*2)
            half[test.begin()->se] = i, test.erase(test.begin());
        if(i < n)
            test.insert({v[i], i}), stack.pb(i);
    }
    FOR(i, n)
        if(!ans[i]) solve(i, ans, next, half);
    debugA(ans);
}