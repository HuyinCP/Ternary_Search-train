#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
#define all(x) x.begin(), x.end()
#define setpr(x) cout<<setprecision(x)<<fixed
#define fastbuild ios::sync_with_stdio(false);  cin.tie(0);
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl

typedef long long ll;
using namespace std;
/*  
Link Bài: https://codeforces.com/problemset/problem/1288/A
    đặt f(x) = d / (x + 1)
    ta thấy khi x càng lớn thì f(x) càng nhỏ, hàm nghịch biến
    làm kịp nếu n-x >= f(x)
    n - x >= d / (x + 1)
    chúng ta sẽ đi chặt số x sao cho (n-x)*(x+1) >= d
    với x nằm trong khoản (0, 10^9)

*/
signed main()
{

    fastbuild
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--)
    {
        int n, d; cin >> n >> d;
        if(n >= d)
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            bool ok = 0;
            int lo = 0, hi = n;
            while(lo <= hi)
            {
                int mid = (lo+hi)/2;
                int val = (n-mid)*(mid+1);
                if(val >= d)
                {
                    ok = 1;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            cout << (ok?"YES":"NO") << endl;
        }
    }
    return 0;
}

