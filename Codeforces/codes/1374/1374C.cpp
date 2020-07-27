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

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, cnt=0;
        cin>>n;
        string s;
        cin>>s;
        vi st;
        FORR(x, s){
            if(x=='(') st.pb(x);
            else if(!st.empty() && st.back()=='(') st.pop_back();
            else st.pb(x);
        }
        while(!st.empty() && st.back()=='(') st.pop_back(), cnt++;
        cout<<cnt<<endl;
    }
}