#include <iostream>
#include <algorithm>
int n, seq[1001], cache[1001][2];
int solve(int idx = 0, bool k = true)	//k = true�̸� ����, false�̸� ����
{
	if (cache[idx][k] != -1) return cache[idx][k];
	int ret = 0;
	if (k) for (int i = idx + 1; i <= n; ++i)
	{//k = true�̸� i���� ������ ���̹Ƿ� ��� �����ϴ� ���� i�� �������ʹ� �����ϴ� ��� �� �� ū ���� ����
		if (seq[idx] < seq[i])	ret = std::max(ret, std::max(solve(i), solve(i, false)) + 1);
	}
	else for (int i = idx + 1; i <= n; ++i)
	{//k = false�̸� �����δ� ��� �����ؾ���(�ѹ� �����ϱ� �����ϸ� ������ ����)
		if (seq[idx] > seq[i]) ret = std::max(ret, solve(i, false) + 1);
	}
	return cache[idx][k] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> seq[i];
		cache[i][0] = cache[i][1] = -1;
	}
	cache[0][0] = cache[0][1] = -1;
	std::cout << solve();
}