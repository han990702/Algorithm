#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
int n, w;
std::string name[100];
int volume[100], necessary[100];
int cache[101][1001];

int solve(int idx = 0, int vol = 0)	//������ �� ������ ������ ���� vol�̰� ���� idx~n-1���� �����߿� ����� �� �ִ��� ���ڵ��� ����
{
	if (idx == n) return 0;
	if (cache[idx][vol]) return cache[idx][vol];

	int ret = solve(idx + 1, vol);	//idx�� �Ȱ��� ���
	if (vol + volume[idx] <= w)	ret = std::max(ret, necessary[idx] + solve(idx + 1, vol + volume[idx]));	//idx�� ���� ���
	return cache[idx][vol] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		memset(cache, 0, 101 * 1001 * sizeof(int));
		std::cin >> n >> w;
		for (int i = 0; i < n; ++i) std::cin >> name[i] >> volume[i] >> necessary[i];
		std::cout << solve() << ' ';
		//� ������ �ִ����ڵ����� �����ϱ�
		int idx = 0, vol = 0, cnt = 0;
		std::vector<std::string*> picked;
		while (idx != n)
		{
			if (cache[idx][vol] == cache[idx + 1][vol]) ++idx;	//���� ������ idx�� �Ȱ� ���̴�.
			else
			{//idx�� �� ���
				picked.push_back(&name[idx]);
				vol += volume[idx++];
				++cnt;
			}
		}
		std::cout << cnt << '\n';
		for (int i = 0; i < picked.size(); ++i) std::cout << *picked[i] << '\n';
	}
}