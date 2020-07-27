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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

int main(int argc, char **argv)
{
    crap;
    int n, cnt=0;
    cin>>n;
    vi v(n), temp(n);
    FOR(i, n) cin>>v[i];
    FOR(i, n) FOR(j, i) if(v[i]<v[j]) cnt++;
    cout<<cnt<<endl;
    iota(all(temp), 0), sort(all(temp), [&](int x, int y){
        if(v[x]==v[y]) return x < y;
        return v[x]<v[y];
    });
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>0;j--){
            if(temp[j] < temp[j-1]){
                cout<<temp[j]+1<<" "<<temp[j-1]+1<<"\n";
                swap(temp[j], temp[j-1]);
            }
        }
    }
}