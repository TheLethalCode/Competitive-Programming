#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007LL
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

lli N, ans = 0;
int M;

struct mat{
    lli v[101][101];
    mat(){
        FOR(i, M) FOR(j, M) v[i][j] = 0;
    }
    void init(){
        FOR(i, M-1) v[i][i+1] = 1;
        v[M-1][0] = v[M-1][M-1] = 1;
    }
    void iden(){
        FOR(i, M) v[i][i]=1;
    }
};

mat operator *(mat l, mat r){
    mat ans;
    FOR(i, M) FOR(k, M) FOR(j, M) {
        ans.v[i][j] += l.v[i][k] * r.v[k][j];
        if(ans.v[i][j] >= mod*mod) ans.v[i][j] -= mod*mod;
    }
    FOR(i, M) FOR(j, M) if(ans.v[i][j] >=  mod) ans.v[i][j] %= mod;
    return ans;
}

mat modpow(lli p){
    if(!p) {
        mat temp;
        temp.iden();
        return temp;
    }
    if(p&1){
        mat temp;
        temp.init();
        return temp*modpow(p-1);
    }
    mat temp = modpow(p>>1);
    return temp*temp;
}

int main(int argc, char **argv)
{
    crap;
    cin>>N>>M;
    mat temp = modpow(N);
    FOR(i, M) ans += temp.v[0][i];
    cout<<ans % mod<<endl;
}