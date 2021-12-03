#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory.h>
int N;
double dist[15][15], cache[15][1 << 15];
//city���� ����Ͽ� ���� �湮���� ���� ���ø� ��� �湮�ϴ� �ּ� �Ÿ��� �����ϴ� �Լ�
double solve(int city, int visit)	//visit: ���ݱ��� �湮�ߴ� ������ ����(2^�湮��city �� ��)
{
	if (visit == (1 << N) - 1) return 0.0;	//��� ���ø� �湮�� ���
	if (cache[city][visit]) return cache[city][visit];
	double ret = INFINITY;	//�湮���� ���� ���ø� �湮�ϰ�, ���� �ּҰŸ��� ã�´�.
	for (int i = 0; i < N; ++i) if (!(visit & (1 << i))) ret = std::min(ret, dist[city][i] + solve(i, visit + (1 << i)));
	return cache[city][visit] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	std::cout << std::fixed << std::setprecision(10);
	while (C--)
	{
		std::cin >> N;
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> dist[i][j];
		double result = INFINITY;
		for (int i = 0; i < N; ++i) result = std::min(result, solve(i, 1 << i));
		std::cout << result << '\n';
		memset(cache, 0, 15 * (1 << 15) * sizeof(double));
	}
}