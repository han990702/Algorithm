#include <iostream>
#include <iomanip>
int n, m;
double cache[1001][1001];

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	std::cout << std::fixed << std::setprecision(10);
	while (C--)
	{
		std::cin >> n >> m;
		if (n > 2 * m) std::cout << 0.0 << '\n';	//���� �񰡿͵� ���� ������ �� ���� ���
		else if (n <= m) std::cout << 1.0 << '\n';	//�� ���� �ʾƵ� ���� �����ϴ� ���
		else
		{	//cache[d][r] = d�ϵ��� r�� �� ���� ��, ���� m-d�� ���� ���� ������ Ȯ��
			for (int i = 0; i < n - m; ++i) cache[m][i] = 0;	//�� m�� �� n-m�� �̸����� �� �� ��� n���Ϳ� �������� ����, �� Ȯ�� 0
			for (int i = n - m; i <= m; ++i) cache[m][i] = 1;	//n-m�� �̻� �� �� ��� n���Ϳ� ������, Ȯ�� 1

			//i���� j�� �� ���� ��, ���� ������ Ȯ���� �Ʒ� �İ� ����.
			for (int i = m - 1; i >= 0; --i) for (int j = 0; j <= i; ++j) cache[i][j] = 0.75 * cache[i + 1][j + 1] + 0.25 * cache[i + 1][j];
			// == ���� �� �� �� Ȯ�� 0.75 * �� ��� ���� ������ Ȯ�� + ���� �� �� �ȿ� Ȯ�� 0.25 * �� ��� ���� ������ Ȯ��

			std::cout << cache[0][0] << '\n';
		}
	}
}