#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <bitset>
#include <cstring>
using namespace std;
#define ll long long int 
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
bitset<100000000> bs;
int ans[100000000];
int main()
{
    bs.set();
    bs[1]=bs[0]=0;
    std::vector<ll> prime;
    for(ll i=2;i<100000000;++i)
    {
        if(bs[i])
        {
            prime.push_back(i);
            for(ll j=i*i;j<100000000;j+=i)
                bs[j]=0;
        }
    }
    int l=prime.size();
    for(ll i=0;i<l;++i)
    {
        for(ll j=i;j<l;++j)
        {
            if((ll)(prime[i]*prime[j])>100000000)
                break;
                ans[prime[i]*prime[j]]=1;
        }
    }
    ll tot=0;
    for(int i=2;i<100000000;++i)
        if(ans[i])
            tot++;
    printf("%lld\n", tot);
    return 0;
}
