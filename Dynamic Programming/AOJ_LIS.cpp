#include <iostream>
#include <algorithm>
int n;
int progression[500];
int cache[500];

int solve(int idx)	//�Լ� ȣ�� == �κм����� progression[idx] �� �߰��ϴ°�
{
	if (cache[idx]) return cache[idx];	//�̹� ĳ�ÿ� ������ �ٷ� ����

	int count = 0;
	for (int j = idx + 1; j < n; ++j) if (progression[j] > progression[idx])
	{//������ ������ ã�ƾ� �ϹǷ� ������(progression[idx]���� ū ���� �κм����� �����ϸ� �ȴ�.)
		count = std::max(count, solve(j));	//�� �� ���� ū ���� count�̴�
	}
	return cache[idx] = ++count;	//ĳ���� ����
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> n;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> progression[i];
			cache[i] = 0;
		}

		int max = 0;
		for (int i = 0; i < n; ++i)	//��� ���Ҹ� �κм����� ù ���ҷ� �Ͽ� ȣ��
		{
			max = std::max(max, solve(i));
		}
		std::cout << max << '\n';	
	}
}