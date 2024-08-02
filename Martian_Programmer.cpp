#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
#define all(x) x.begin(), x.end()
#define setpr(x) cout<<setprecision(x)<<fixed
#define fastbuild ios::sync_with_stdio(false);  cin.tie(0);
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl

typedef long long ll;
using namespace std;

double A, H; 

/*
LINK BÀI: https://oj.vnoi.info/problem/icpc21_mn_e

ngủ H/3 -> H tiếng thì khả năng làm việc là 100%
ngủ 0 -> H/3 tiếng thì khả năng làm việc là 100%
ngủ 0 tiếng thì khả năng làm việc là 0%
ngủ 0 -> H/6 tiếng thì khả năng làm việc là A%

Độ hiệu quả công việc = tích của khả năng làm việc với số giờ thức
Độ hiệu quả công việc = f(x) * (H - số giờ ngủ)
(H - số giờ ngủ): số giờ thức

Nhận xét: 
	nếu ngủ 0 giờ -> H = 0
	nếu ngủ nhiều hơn 0 giờ -> H tăng lên 
	nếu ngủ nhiều quá, tiến tới ngủ quài -> H = 0
	gọi g(x): độ hiệu quả công việc, với x giờ ngủ
	g(x) = f(x) * (H-x)
	trong đó f(x) được tính như sau: 
		nếu x == H/6 -> A%
		nếu x >= H/3 -> 100% 
*/

double F(const double &x) {
  if (3.0 * x >= H) 
  {
    return 100.0; 
  }
  else if (6.0 * x >= H) {
    return ((((100.0 - A)) * 6.0) / H) * x + (A) - ((100.0 - A));
  }
  else {
    return 6*A*x/H;
  }
}

signed main() {
    fastbuild
    cin >> A >> H;
    double lo = 0.0;
    double hi = H;
    double good_time = 0;
    
    for(int i=1; i<=100; i++)
    {
        double u = (lo * 2 + hi) / 3.0;
        double v = (lo + hi * 2) / 3.0;
        double H1 = F(u) * (H - u);
        double H2 = F(v) * (H - v);
        if (H2 > H1) 
        {
            good_time = v;
            lo = u;
        } 
        else 
        {
            hi = v;
        }
    }
    
    setpr(8) << F(good_time) * (H - good_time) << "\n";
    return 0;
}
