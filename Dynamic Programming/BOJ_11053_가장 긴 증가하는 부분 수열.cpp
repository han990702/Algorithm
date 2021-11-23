#include <iostream>
#include <algorithm>
int n, seq[1001], cache[1001];
int solve(int idx = 0)
{
	if (cache[idx] != -1) return cache[idx];
	int ret = 0;
	//seq[idx] �ڿ��ְ� �� ū ���� ���� �� �ִ�. �� �� ���� �� ��츦 ret�� ����
	for (int i = idx + 1; i <= n; ++i) if (seq[idx] < seq[i]) ret = std::max(ret, solve(i) + 1);
	return cache[idx] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> seq[i];
		cache[i] = -1;
	}
	cache[0] = -1;
	std::cout << solve();
}