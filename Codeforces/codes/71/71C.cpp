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
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int ch=0;
    for(int te=1;te<=n/3;te++)
    {
        if(n%te)
            continue;
        int nu=te,fi=0;
        for(int j=0;j<nu;j++)
        {
            int i=j,fl=0;
            do
            {
                if(!v[i])
                {
                    fl=1;
                    break;
                }
                i=(i+nu)%n;
            }while(i!=j);
            if(!fl)
            {
                fi=1;
                break;
            }
        }
        if(fi)
        {
            ch=1;
            break;
        }
    }
    if(ch)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
}