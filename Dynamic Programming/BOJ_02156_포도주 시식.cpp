#include <iostream>
#include <algorithm>
int n, quantity[10000], cache[10000][3];
int solve(int idx, int k)	//k = idx������ �������� ���� �� �ִ� �������� ��
{
	if (idx == n) return 0;
	if (cache[idx][k] != -1) return cache[idx][k];
	//k = 0�̸� idx�� �����ִ� ������ �ʰ�, �׷��� ������ ���ô� ���� ������ �ʴ� ��� �� ū ��� ����
	return cache[idx][k] = std::max((k ? quantity[idx] + solve(idx + 1, k - 1) : 0), solve(idx + 1, 2));
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) cache[i][j] = -1;
	for (int i = 0; i < n; ++i) std::cin >> quantity[i];
	std::cout << solve(0, 2);
}