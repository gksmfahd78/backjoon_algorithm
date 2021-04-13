#include "solution.h"

int a[20]; // ���� ���� (������ ���� ������ �����ϴ� �迭)
double const max = 9223372036854775807; // �ִ밪
double temp, ans; // �ӽð�, ����
int x[20], y[20]; // x��ǥ, y��ǥ
int sum_x, sum_y; // �Է¹��� �� ��ǥ ���� �հ�
int T, N, R; // �׽�Ʈ���̽�,�� ����, �� �����ǹ�ƴ

void combination(int N, int R, int q) // N : �� ����, R : �� ������ ��ƴ(N/2), q : ������ ���� ������ ���� 
{
	if (R == 0)
	{
		int sum_x_temp = sum_x; // ������ ���� ���� (X)
		int sum_y_temp = sum_y; // ������ ���� ����(Y)
		for (int i = 0; i < q; i++)
		{
			sum_x_temp -= 2 * x[a[i]];
			sum_y_temp -= 2 * y[a[i]];
			//(ex : ��ǥ���� sum = A+B+C+D ��� �ϸ� => sum_temp = A-B+C-D or A+B-C-D ������� �ٲ��ִ� �۾�)
			//(ex : A+B-C-D = A+B+C+D - 2*C - 2*D )
		}

		temp = sqrt(pow(sum_x_temp, 2) + pow(sum_y_temp, 2)); // ������ ���� ����

		if (temp < ans) ans = temp; // �ּҰ� ����

	}
	else if (N < R) return; // N���� R�� �� ũ�� �ԷµǴ� ���� ����

	else
	{
		a[R - 1] = N - 1; // ���� ����
		// nCr = (n-1)C(r-1) + (n-1)C(r) �� �̿��� ����Լ�
		combination(N - 1, R - 1, q);
		combination(N - 1, R, q);
	}
}

int solution_1007()
{

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		sum_x = 0;
		sum_y = 0;
		ans = max; // �ִ밪 ����
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d %d", &x[j], &y[j]);
			sum_x += x[j]; //x��ǥ�� �հ�
			sum_y += y[j]; //y��ǥ�� �հ�
		}

		combination(N, N / 2, N / 2); // ������ �̿��� ����� �� Ž��
		printf("%.12f\n", ans); // �������
	}

}