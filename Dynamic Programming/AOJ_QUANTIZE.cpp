#include <iostream>
#include <algorithm>
#include <cmath>
int arr[100];
int N, S;
int cache[100][10];
int sum[100], sqsum[100]; //���� 0~i������ ������ ��, ������ ������ ��

//n���� ���Ҹ� s���� �������� ���� ���¿��� ������ N-n���� ���Ҹ� S-s���� �������� ������ ��� �� ���������� ���� �ּ��� ��츦 ã�� �Լ�
int solve(int n = 0, int s = 0)
{
	if (s == S) return 0;	//��� ���Ұ� ����ȭ �� ���
	if (cache[n][s] != -1) return cache[n][s];

	int ret = 987654321;

	//�̹� ������ i���� ���Ҹ� �����ϴ� ���(��, ������ ������ ��� ���� ��� ���Ҹ� �����ϴ� ����� i = N - n ���� ����)
	//N - n - (S - 1 - s) �� �̹� �������� ������ �� �ִ� �ִ� �����̴�.(N - n = ���� ���� ��, S - 1 - s = ������ �����鿡�� �ʿ��� �ּ� ���� ��)
	for (int i = (s != S - 1 ? 1 : N - n); i <= N - n - (S - 1 - s); ++i)
	{
		int sumi = sum[n + i - 1] - (n == 0 ? 0 : sum[n - 1]);	//arr[n]~arr[n + i - 1]�� ��(i���� ��)
		int q = (int)((double)sumi / i + 0.5);	//����� �ݿø�

		//���������� �� = (arr[] - q)^2 �� �����ϸ� �Ʒ����� �ȴ�.
		int tmp = sqsum[n + i - 1] - (n == 0 ? 0 : sqsum[n - 1]) - 2 * q * sumi + q * q * i;

		ret = std::min(ret, tmp + solve(n + i, s + 1));
	}
	return cache[n][s] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> N >> S;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> arr[i];
			for (int j = 0; j < S; ++j) cache[i][j] = -1;
		}

		if (S >= N) std::cout << "0\n";	//S >= N�� ��� ������ ���� �� ��ü�� ����ȭ �� ������ �� �� �����Ƿ� ���������� ���� 0�̴�.
		else
		{
			//������ ������ ����� ����, �������� �� ������ ���ҳ��� ���� ���ڷ� ����ȭ �� ��� ���� ������ ���� �۾�����.
			//���� S���� �������� ������ �� ������ �� ���� ���Ҹ� �����ϴ����� ���� ����Ž�� �ϸ� �ȴ�.
			std::sort(arr, arr + N);

			//������ ���� ����ð��� ���ϱ� ���� ������ �迭�� ����س��´�.
			sum[0] = arr[0];
			sqsum[0] = std::pow(arr[0], 2);
			for (int i = 1; i < N; ++i)
			{
				sum[i] = sum[i - 1] + arr[i];
				sqsum[i] = sqsum[i - 1] + std::pow(arr[i], 2);
			}

			std::cout << solve() << '\n';
		}
	}
}