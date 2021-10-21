#include <iostream>
#include <memory.h>
int ground[100][100];
bool cache[100][100];	
int n;

bool solve(int r = 0, int c = 0)
{
	if (r == n - 1 && c == n - 1) return true;	//������ ĭ�� �����ϸ� ���� /������ĭ�� �����ϸ� ��������� ȣ���� �Լ��� ��� true�� ������.

	int jump = ground[r][c];
	if (c + jump < n && !cache[r][c + jump] && solve(r, c + jump)) return true;
	//���������� jumpĭ ���� ���, ������ ����� �ʰ� ĳ�ÿ� false�� ������(��ΰ� ���ٰ� Ȯ������ �������) ���ȣ��. �� ��ο��� �����ϸ� ��� true ����.
	if (r + jump < n && !cache[r + jump][c] && solve(r + jump, c)) return true;
	//�����ʿ��� ���н� �Ȱ��� ������� �Ʒ��� ��.
	cache[r][c] = true;	//�Ѵ� ���н� �޸������̼�(�ش� ĭ�� ��ΰ� ������ Ȯ����)
	return false;
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
			for (int j = 0; j < n; ++j) std::cin >> ground[i][j];
			memset(cache[i], 0, n);
		}

		if (solve()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
}