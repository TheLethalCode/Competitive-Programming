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
int main(int argc, char **argv)
{
    crap;
    while(1){
        int cnt=0;
        string s;
        cin>>s;
        if(s!="start") return 0;

        lli x = 1, y=2;
        char ch = 'y';
        while(ch=='y'){
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>ch, cnt++;
            x*=2, y*=2;
        }
        x/=2, y/=2;
        if(x==1){
            cout<<"? 0 1"<<endl;
            cin>>ch;
            if(ch=='x') cout<<"! 1"<<endl;
            else cout<<"! 2"<<endl;
            continue;
        }
        int mid; 
        while(abs(y-x)>1){
            mid = x+y>>1;
            cout<<"? "<<mid<<" "<<y<<endl;
            cin>>ch, cnt++;
            if(ch=='x') x=mid;
            else y=mid;
        }
        cout<<"? "<<x<<" "<<y<<endl;
        cin>>ch;
        if(ch=='y') cout<<"! "<<x<<endl;
        else cout<<"! "<<y<<endl;
    }
}