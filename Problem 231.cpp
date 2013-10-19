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
int a[20000000];
ll ans;
void prime(ll n)
{
    int count;
    for(ll i=2;i*i<=n;++i)
    {
        count=0;
        while(n%i==0)
            n/=i, count++;
        a[i]+=count;
    }
    if(n>1)
        a[n]+=1;
}
void solve(ll n)
{
    for(ll i=2;i*i<=n;++i)
    {
        int count=0;
        while(n%i==0)
            n/=i, count++;
        a[i]-=count;
    }
    if(n>1)
        a[n]-=1;
}
int main()
{
    for(ll i=15000001;i<=20000000;++i)
        prime(i);
    for(ll i=2;i<=5000000;++i)
        solve(i);
    for(ll i=2;i<20000000;++i)
        ans+=(a[i]*i);
    printf("%lld\n", ans);
    return 0;
}
