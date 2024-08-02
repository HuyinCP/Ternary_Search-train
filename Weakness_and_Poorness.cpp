#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
#define fastbuild ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
/*
LINK BAI: https://codeforces.com/contest/578/problem/C
Nhận xét:

    khi mà x càng bé (tiến tới âm vô cùng) : [a0 - x , a1 - x, a2 - x, a3 - x, .. a[n-1] - x] càng lớn -> có tổng càng lớn
    khi mà x càng lớn (tiến tới dương vô cùng) : [a0 - x , a1 - x, a2 - x, a3 - x, .. a[n-1] - x] càng bé -> do lấy abs nên cũng có tổng lớn
    \      /
     \    /
      \  /
       \/ 
       số x 

    b[i] = a[i] - x
    sum[i] = b[1] + b[2] + b[3] + .. + b[i]
    weakness = max(sum[r] - sum[l-1]) với mọi j < i
    tìm weaknees bé nhất ?? 

    Cal xem Max_u tính tới hiện tại là bao nhiêu (tính tới i) ?
    Cal xem Min_u tính tới hiện tại là bao nhiêu (tính tới i) ?
    Cal xem Max_v tính tới hiện tại là bao nhiêu (tính tới i) ?
    Cal xem Min_v tính tới hiện tại là bao nhiêu (tính tới i) ?

*/
int n;
vector<double> a(1000000);
double f(const double &x)
{
    for(int i = 0; i < n; i++) 
    {
        a[i] -= x; 
    }
    double ret = 0.000;
    double minValue = 0.000;
    double maxValue = 0.000;
    double sum = 0.000; 
    for(int i = 0; i < n; i++) 
    {
        sum += a[i];
        ret = max(ret, sum - minValue);
        ret = max(ret, maxValue - sum); 
        minValue = min(minValue, sum);
        maxValue = max(maxValue, sum); 
    }
    minValue = 0.000;
    maxValue = 0.000; 
    sum = 0.000; 
    for (int i = n - 1; i >= 0; i--) 
    {
        sum += a[i]; 
        ret = max(ret, sum - minValue); 
        ret = max(ret, maxValue - sum); 
        minValue = min(minValue, sum);
        maxValue = max(maxValue, sum); 
    }
    for(int i = 0; i < n; i++) 
    {
        a[i] += x; 
    }
    return ret;
}

signed main() 
{
    fastbuild;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x; cin >> x;
        a[i] = x;
    }

    double lo = -10001.0, hi = 10001.0;
    double best_sum = 0.0;
    // log(2/3)[11042 / 10^-6] = 88 
    for (int i = 0; i < 88; i++) 
    {  
        double u = (2.0 * lo + hi) / 3.0;
        double v = (lo + 2.0 * hi) / 3.0;
        vector<double> bu(n), bv(n);
        double Fu = f(u);
        double Fv = f(v); 
        if (Fu > Fv) 
        {
            best_sum = Fu; 
            lo = u; 
        }
        else 
        {
            best_sum = Fv;
            hi = v;  
        }
    }

    cout << setprecision(7) << fixed << best_sum;
    return 0;
}
