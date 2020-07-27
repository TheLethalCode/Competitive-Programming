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

vi v, ans;

void op(int i){
    swap(v[i], v[i+1]);
    swap(v[i], v[i+2]);
    if(sz(ans)>=2 && ans[sz(ans)-1]==i+1 && ans[sz(ans)-2]==i+1)
        ans.pop_back(), ans.pop_back();
    else ans.pb(i+1);
}

void reach(int x,int y){
    while(y > x+1) op(y-2), y-=2;
    if(y == x+1) op(y-1), op(y-1);
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, st=0, temp=0;
        ans.clear();
        cin>>n;
        v.resize(n);
        vi ar(501, -1);
        int val=-1, x, y;
        FOR(i, n) {
            cin>>v[i];
            if(ar[v[i]]!=-1) val=v[i], x=ar[v[i]], y=i;
            ar[v[i]]=i;
        }
        if(val!=-1) v[x]=v[y]=2000;
        while(n-st>3){
            int mi = 1000, in;
            for(int j=st;j<n;j++) if(v[j]<mi) mi=v[j], in = j;
            reach(st, in);
            st++;
        }
        if(val==-1){
            while(!(v[st]<=v[st+1] && v[st+1]<=v[st+2])) {
                op(st), temp++;
                if(temp>5){
                    cout<<-1<<endl;
                    goto brk;
                }
            }
        }
        else{
            while(v[st+1]!=2000 || v[st+2]!=2000) op(st);
            while(st>=0 && val < v[st]) op(st), op(st), st--;
        }
        cout<<sz(ans)<<endl;
        FORR(x, ans) cout<<x<<" ";
        cout<<endl;
        brk:;
    }
}