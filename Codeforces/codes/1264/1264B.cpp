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

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    vi v(4);
    int sum = 0;
    FOR(i, 4) cin>>v[i], sum+=v[i];
    if(sum == 1){
        cout<<"YES"<<endl;
        FOR(i, 4)
            FOR(j, v[i])
                cout<<i<<" ";
        cout<<endl;
        return 0;
    }
    if((!v[1] && v[0]) || (!v[2] && v[3])){
        cout<<"NO"<<endl;
        return 0;
    }
    FOR(i, 3){
        if(v[i] + v[i+1] == sum){
            if(abs(v[i] - v[i+1]) <= 1){
                cout<<"YES"<<endl;
                int x;
                if(v[i] < v[i+1]) x = i+1;
                else x = i;
                FOR(j, v[2*i+1-x]) cout<<x<<" "<<(2*i+1-x)<<" ", v[x]--;
                if(v[x]) cout<<x;
                cout<<endl;
                return 0;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    FOR(i, 4){
        if(v[i] == sum){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(v[3]>v[2] || v[0]>v[1]){
        cout<<"NO"<<endl;
        return 0;
    }
    if(abs((v[2]-v[3]) - (v[1]-v[0])) <= 1){
        cout<<"YES"<<endl;
        if((v[2]-v[3]) > (v[1]-v[0])) cout<<"2 ", v[2]--;
        FOR(i, v[3])
            cout<<"3 2 ", v[2]--;
        FOR(i, v[2])
            cout<<"1 2 ", v[1]--;
        FOR(i, v[0])
            cout<<"1 0 ", v[1]--;
        if(v[1]) cout<<"1 ";
        cout<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}