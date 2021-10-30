#include <iostream>
#include <string>
#include <algorithm>
std::string s;
int cache[10000];

int solve(int idx = 0)
{
	if (cache[idx]) return cache[idx];

	int ret = 987654321;
	int num = s.size() - idx;	//���� ���� ��
	if (num == 0) return 0;	//basecase
	if (num > 5) num = 5;
	for (int i = 3; i <= num; ++i)
	{
		bool undecided = false;
		int difficulty = 1;
		for (int j = 1; j < i; ++j)	//���̵� 1���� Ȯ��
		{
			if (s[idx] != s[idx + j])
			{
				undecided = true;
				break;
			}
		}

		if (undecided)
		{
			undecided = false;
			int difference = s[idx + 1] - s[idx];	//����
			for (int j = 2; j < i; ++j)	//������������ Ȯ��(������ 1�̸� ���̵� 2, �ƴϸ� ���̵� 5)
			{
				if (s[idx + j - 1] + difference != s[idx + j])
				{
					undecided = true;
					break;
				}
			}
			if (!undecided) difficulty = ((difference == 1 || difference == -1) ? 2 : 5);
			else
			{	//���̵��� 4���� Ȯ��
				if (i == 5)
				{
					if (s[idx] == s[idx + 2] && s[idx] == s[idx + 4] && s[idx + 1] == s[idx + 3]) difficulty = 4;
					else difficulty = 10;
				}
				else if (i == 4)
				{
					if (s[idx] == s[idx + 2] && s[idx + 1] == s[idx + 3]) difficulty = 4;
					else difficulty = 10;
				}
				else
				{
					if (s[idx] == s[idx + 2]) difficulty = 4;
					else difficulty = 10;
				}
			}
		}

		ret = std::min(ret, difficulty + solve(idx + i)); //(i��¥��(3~5) ������ ���̵� + ���� �κ� ��ü�� �ּ� ���̵�) �� �ּڰ�
	}
	return cache[idx] = ret;
	//num <= 2�� ��� �� ������ ����� �����Ƿ� for���� �������� �ʰ� �ǹ̾��� ū ���� 987654321�� �����Ѵ�.
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> s;
		for (int i = 0; i <= s.size(); ++i) cache[i] = 0;
		std::cout << solve() << '\n';
	}
}