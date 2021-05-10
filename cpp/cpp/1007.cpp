#include "solution.h"

int a[20]; 
double const max = 9223372036854775807; 
double temp, ans; 
int x[20], y[20]; 
int sum_x, sum_y; 
int T, N, R; 

void combination(int N, int R, int q) {
	if (R == 0)
	{
		int sum_x_temp = sum_x; 
		int sum_y_temp = sum_y; 
		for (int i = 0; i < q; i++)
		{
			sum_x_temp -= 2 * x[a[i]];
			sum_y_temp -= 2 * y[a[i]];
			
			
		}

		temp = sqrt(pow(sum_x_temp, 2) + pow(sum_y_temp, 2)); 

		if (temp < ans) ans = temp; 

	}
	else if (N < R) return; 

	else
	{
		a[R - 1] = N - 1; 
		
		combination(N - 1, R - 1, q);
		combination(N - 1, R, q);
	}
}

int solution_1007() {

	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		sum_x = 0;
		sum_y = 0;
		ans = max; 
		std::cin >> N;
		for (int j = 0; j < N; j++)
		{
			std::cin >> x[j] >> y[j];
			sum_x += x[j]; 
			sum_y += y[j]; 
		}

		combination(N, N / 2, N / 2); 
		printf("%.12f\n", ans); 
	}

	return 0;
}