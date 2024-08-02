#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
#define all(x) x.begin(), x.end()
#define setpr(x) cout<<setprecision(x)<<fixed
#define fastbuild ios::sync_with_stdio(false);  cin.tie(0);
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl

typedef long long ll;
using namespace std;

/*
    LINK BÀI: https://www.codechef.com/problems/AMCS03
    Nhận xét 1: 
        Người A (người có tốc độ S(i) nhanh nhất) xuất phát tại vị trí thấp nhất
        Người B (người có tốc độ S(i) chậm nhất) xuất phát tại vị trí cao nhất (B[i].point > A[i].point)
        Thì sau khoản thời gian là T kiểu gì A và B cũng gặp nhau, sau đó người A sẽ chạy trước B

 khoản cách 2 người gặp nhay

        \         /
         \       /
          \     / 
           \   /
            \ / 
       điểm gặp nhau

    Nhận xét 2: 
        người A (có tốc độ s(i) nhanh nhất) xuất phát tại vị trí cao nhât
        người B (có tốc độ s(i) chậm nhât) xuất phát thấp nhấn
        2 người vĩnh viễn ko gặp nhau
           /
          /
         /
        /
       /
    
    P(i) = S(i)*t + D(i)
    define F(t) = max( all(P[i]) ) - min( all(P[i]) )
    
    với thời gian là u và v tính P(i) = S(i) * u + D(i) và P(i) = * v + D(i)
*/
signed main()
{
    fastbuild
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++)
    {
        int vantoc; cin >> vantoc;
        int xuatphat; cin >> xuatphat;
        a[i] = {vantoc, xuatphat};
    }
    double lo = 0.0;
    double hi = k;
    double best_time;
    for(int i=1; i<=990; i++)
    {
        double u = (lo*2 + hi)/3.0;
        double v = (lo+ hi*2)/3.0;
        vector<double> P_For_u(n), P_For_v(n);
        double Maxu = INT_MIN * 1.0;
        double Minu = INT_MAX * 1.0;
        double Maxv = INT_MIN * 1.0;
        double Minv = INT_MAX * 1.0;
        for(int i=0; i<n; i++)
        {
            P_For_u[i] = 1.0*a[i].first * u + 1.0*a[i].second; 
            Maxu = max(Maxu, P_For_u[i]); Minu = min(Minu, P_For_u[i]);

            P_For_v[i] = 1.0*a[i].first * v + 1.0*a[i].second;
            Maxv = max(Maxv, P_For_v[i]); Minv = min(Minv, P_For_v[i]);
            
        }
        double Fu = 1.0*Maxu - 1.0*Minu;
        double Fv = 1.0*Maxv - 1.0*Minv;
        if(Fv > Fu)
        {
            best_time = Fv;
            hi = v;
        }
        else if(Fv < Fu)
        {
            best_time = Fu;
            lo = u;
        }
        else 
        {
            best_time = Fv;
            hi = v;
            lo = u;
        }
    }
    setpr(6) << best_time;
    return 0;
}

// #include <iostream> 
// #include <iomanip> 
// #include <math.h>
// struct programmer {
//   double distance;
//   double speed; 
// };
// programmer a[100005]; 
// int n; 
// double K; 

// double f(const double &x) {
//   double minValue = a[1].speed * x + a[1].distance;
//   double maxValue = a[1].speed * x + a[1].distance;  
//   for (int i = 2; i <= n; i++) {
//     minValue = std::min(minValue, a[i].speed * x + a[i].distance);
//     maxValue = std::max(maxValue, a[i].speed * x + a[i].distance);
//   }
//   return maxValue - minValue; 
// }

// int main () {
//   std::cin >> n >> K;
//   for (int i = 1; i <= n; i++) {
//     std::cin >> a[i].speed >> a[i].distance; 
//   }
//   double lo = 0.00000;
//   double hi = K; 
//   for (int step = 1; step <= 100; step++) {
//     double u = (2.0 * lo + hi) / 3.0;
//     double v = (lo + 2.0 * hi) / 3.0; 
//     if (f(u) > f(v)) {
//       lo = u; 
//     }
//     else {
//       hi = v; 
//     }
//   }
//   std::cout << std::fixed << std::setprecision(6) << f(lo); 
//   return 0; 
// }