#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
#define fastbuild ios::sync_with_stdio(false); cin.tie(0);
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl

typedef long long ll;
using namespace std;


/*
    Link bai: https://codeforces.com/contest/1978/problem/B
    Hàm lợi nhuận f(k) = (n-k)*a - (k*(k-1) / 2)
    đây là hàm bậc 2, nó sẽ tăng tói ngưỡn k nào đố rồi sẽ giảm
*/
ll f(ll n, ll a, ll b, ll k)
{
    ll price = 1ll*(n-k)*a;
    ll Price_sell = 1ll*k*b - 1ll*(k*(k-1))/2;
    return  price + Price_sell;
}

signed main() 
{
    fastbuild
    ll t; cin >> t;
    while (t--) 
    {
        ll n, a, b;
        cin >> n >> a >> b;
        ll lo = 0;
        ll hi = min(n, b);
        ll Max = 0;
        while(lo <= hi)
        {
            ll u = (lo*2 + hi) / 3;
            ll v = (lo + hi*2) / 3;
            ll profit1 = f(n, a, b, u);
            ll profit2 = f(n, a, b, v);
            if(profit1 > profit2)
            {
                Max = max(Max, profit1);
                hi = v - 1;
            }
            else
            {
                Max = max(Max, profit2);
                lo = u + 1;
            }
        }
        cout << Max << endl;
    }
    return 0;
}
