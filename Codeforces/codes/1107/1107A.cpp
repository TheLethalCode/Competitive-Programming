#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n==2 && s[0]>=s[1])
            cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<s[0]<<" ";
            for(int i=1;i<n;i++)
                cout<<s[i];
        }
        cout<<endl;
    }
}