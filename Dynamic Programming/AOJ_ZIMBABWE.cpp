#include <iostream>
#include <string>
#include <algorithm>
std::string e, sorted;
int m, cache[20][1 << 15][2];
int solve(int idx = 0, int r = 0, int picked = 0, bool less = false)
{
	if (cache[r][picked][less] != -1) return cache[r][picked][less];
	if (idx == e.size())
	{
		if (r == 0 && less) return cache[r][picked][less] = 1;	//�������� �������� 0�̰� e���� �۴ٸ� ����Ǽ� 1�߰�
		else return cache[r][picked][less] = 0;
	}
	int ret = 0;
	for (int i = 0; i < sorted.size(); ++i)
		//������ ���� �����̰�, (ù��° ���ڰų�, �� ���ڿ� �ٸ��ų�, �� ���ڿ� ������ �̹� ���� �����̸�) �̴´�.(�ߺ��Ǵ� ���ڰ� ���� �� ���� ��츦 ������ ���°� ����)
		if (!(picked & (1 << i)) && (i == 0 || sorted[i - 1] != sorted[i] || (picked & (1 << (i - 1)))))
		{
			//���ݱ��� ���� ����� �̹� e���� ���� ���
			if (less || e[idx] > sorted[i]) ret = (ret + solve(idx + 1, (r * 10 + sorted[i] - '0') % m, picked | (1 << i), true)) % 1000000007;
			//���ݱ����� e�� ���� ���(������ ��� �̴��Ŀ� ���� e���� Ŭ ���� ����)
			else if (e[idx] == sorted[i]) ret = (ret + solve(idx + 1, (r * 10 + sorted[i] - '0') % m, picked | (1 << i), false)) % 1000000007;
			//�տ��� ���ڸ� � ������ �̾Ҵ����� ���� ���� ������ r �� ���� picked�� ���� less�� ������ �׻� ���� ����̴�.
		}
	return cache[r][picked][less] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> e >> m;
		sorted = e;
		std::sort(sorted.begin(), sorted.end());
		for (int i = 0; i < m; ++i) for (int j = 0; j < (1 << e.size()); ++j) cache[i][j][0] = cache[i][j][1] = -1;
		std::cout << solve() << '\n';
	}
}