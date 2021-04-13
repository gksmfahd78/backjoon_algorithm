#include "solution.h"

using namespace std;

const int MAX = 10000;

int N; 
int sfNum; 
int cirTagon[MAX][2]; 
int cache[MAX][4][4];

int covered(int idx, int prev, int last) {
	int &result = cache[idx][prev][last];

	if (result != -1) return result;

	bool inner, outer, both; 
	
	inner = (cirTagon[idx][0] + cirTagon[idx ? idx - 1 : N - 1][0] <= sfNum); 
	outer = (cirTagon[idx][1] + cirTagon[idx ? idx - 1 : N - 1][1] <= sfNum);

	both = (cirTagon[idx][0] + cirTagon[idx][1] <= sfNum);

	if (idx == N - 1) {
		if (idx == 0) return both ? 1 : 2; 

		result = 2; 

		if (last == 0) {
			if (inner && !(prev & 1)) result = 1; 
			if (outer && prev < 2) result = 1; 
			if (both) result = 1; 
			if (inner && outer && prev == 0) result = 0; 
		} 
		else if (last == 1) 
			if (outer && prev < 2) result = 1;
		else if (last == 2) 
			if (inner && !(prev & 1)) result = 1;

		return result;
	}
	
	result = 2 + covered(idx + 1, 0, idx ? last : 0);

	if (inner && !(prev & 1)) result = min(result, 1 + covered(idx + 1, 1, idx ? last : 1));
	if (outer && prev < 2) result = min(result, 1 + covered(idx + 1, 2, idx ? last : 2));
	if (inner && outer && prev == 0) result = min(result, covered(idx + 1, 3, idx ? last : 3));
	if (both) result = min(result, 1 + covered(idx + 1, 3, idx ? last : 0));

	return result;

}


int solution_1006() {

	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		memset(cache, -1, sizeof(cache));
		memset(cirTagon, 0, sizeof(cirTagon));
		cin >> N >> sfNum;
		for (int i = 0; i < N; i++) cin >> cirTagon[i][0];
		for (int i = 0; i < N; i++) cin >> cirTagon[i][1];

		cout << covered(0, 0, 0) << endl;

	}
	return 0;
}