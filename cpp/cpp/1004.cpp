#include "solution.h"
using namespace std;

int solution_1004() {
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	while (T--) {
		int x1, y1, x2, y2, N;
		cin >> x1 >> y1 >> x2 >> y2 >> N;
		int ans = 0;
		while (N--) {
			int a, b, r; cin >> a >> b >> r;

			bool F1 = false, F2 = false;
			if (r * r > (a - x1)* (a - x1) + (b - y1) * (b - y1)) F1 = true;
			if (r * r > (a - x2)* (a - x2) + (b - y2) * (b - y2)) F2 = true;

			if (F1 ^ F2) ++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}