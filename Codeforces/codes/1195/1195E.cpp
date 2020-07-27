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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %

int n, m, a, b, mat[3000], smr[3000][3000];
lli g, x, y, z, ans=0;

struct linque{
    deque<int> q;
    void push(int x) {
        while(!q.empty() && q.back() > x)
            q.pop_back();
        q.push_back(x);
    }
    int mini(){
        return q.front();
    }
    void pop(int x){
        if(!q.empty() && q.front()==x)
            q.pop_front();
    }
};

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m>>a>>b;
    cin>>g>>x>>y>>z;
    FOR(i, n){
        linque s;
        FOR(j, m){
            if(j-b>=0) s.pop(mat[j-b]);
            s.push(mat[j]=g);
            if(j>=b-1) smr[i][j-b+1] = s.mini();
            g = (g*x+y)%z;
        }
    }
    FOR(j, m-b+1){
        linque s;
        FOR(i, n){
            if(i-a>=0) s.pop(smr[i-a][j]);
            s.push(smr[i][j]);
            if(i>=a-1) ans += s.mini();
        }
    }
    cout<<ans<<endl;
}