#include <iostream>
#include <algorithm>
int N;
int cost[1000][3];	//cost[i][j] = i��° ���� j������ ĥ�ϴ� ���(j = 0 ������ 1 �ʷϻ� 2 �Ķ���)
int cache[1000][3];	//cache[i][j] = i-1 ��° ���� j�� �� �� ������ i~N-1���� ĥ�ϴ� �ּ� ���
int solve(int idx, int prev_color)
{
	if (idx == N) return 0;
	if (cache[idx][prev_color]) return cache[idx][prev_color];
	int ret = 987654321;
	for (int c = 0; c < 3; ++c)
	{//������ ���� ���� ���Ѵ�. �� idx == 0�̸� 3���� ������ ��� �õ��Ѵ�.
		if (c != prev_color || idx == 0) ret = std::min(ret, cost[idx][c] + solve(idx + 1, c));
	}
	return cache[idx][prev_color] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	std::cout << solve(0, 0);
}