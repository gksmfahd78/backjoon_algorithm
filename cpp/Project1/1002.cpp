#include "solution.h"

using namespace std;

#define loop(i,n) for(int i=0;i<n;++i)
#define eps 1e-9

int solution_1002() {
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	double x1, x2, y1, y2, r1, r2;
	while (t--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1" << '\n';
			continue;
		}

		double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		double s_r = min(r1, r2), l_r = max(r1, r2);
		int ans;

		if (d + s_r - l_r < eps) {
			if (d + s_r - l_r > -eps)
				ans = 1;
			else
				ans = 0;
		}
		else {
			if (fabs(s_r + l_r - d) < eps)
				ans = 1;
			else if (d - s_r - l_r > eps)
				ans = 0;
			else
				ans = 2;
		}
		cout << ans << '\n';
	}
	return 0;
}