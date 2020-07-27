#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==0)
            cout<<0;
        else if(b==0)
            cout<<1;
        else
        {
            switch(b%4)
            {
                case 1:cout<<a%10;
                        break;
                case 2:cout<<(a*a)%10;
                        break;
                case 3:cout<<(a*a*a)%10;
                        break;
                case 0:cout<<(a*a*a*a)%10;
                        break;
            }
        }
        cout<<endl;
    }
    return 0;
}