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
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    vector< set<int> > v(3);
    
    cout<<"YES"<<endl;
    FOR(i, 3)
        FOR(j, 3){
            if(i==j) continue;
            int k = 3 - i - j;
            string temp = "", tr = "";
            temp += 'a'+i, temp += 'a'+j, temp += 'a'+k;
            tr += 'a'+i, tr+='a'+i, tr += 'a'+j, tr+='a'+j, tr += 'a'+k, tr+='a'+k;
            string du = temp + temp;
            if(du.find(s) == string::npos && du.find(t) == string::npos){
                FOR(i, n)
                    cout<<temp;
                cout<<endl;
                return 0;
            }
            if(tr.find(s) == string::npos && tr.find(t) == string::npos){
                FOR(r, n)
                    cout<<(char)('a'+i);
                FOR(r, n)
                    cout<<(char)('a'+j);
                FOR(r, n)
                    cout<<(char)('a'+k);
                cout<<endl;
                return 0;
            }
        }   
}