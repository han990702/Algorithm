#include <iostream>
#include <algorithm>
#include <string>
int bino[200][100];	//bino[n + m][n] = ���װ��. ����n��, ����m���� �����ϴ� ����� ��
std::string solve(int n, int m, int k)
{
	if (n == 0) return std::string(m, 'o');	//n==0�̸� �������� m���� �������� ä���.
	//�̹�ĭ�� ������ ������ ���� ����Ǽ� bino[n + m - 1][n - 1] �� k���� ũ�ų� ������ ������ ����
	if (bino[n + m - 1][n - 1] >= k) return "-" + solve(n - 1, m, k);
	//�׷��� ������ ������ �����ϴ� ����� �� bino[n + m - 1][n - 1]��ŭ�� �ǳ� �� �� �����Ƿ� ������ ����
	else return "o" + solve(n, m - 1, k - bino[n + m - 1][n - 1]);
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	for (int i = 0; i < 200; ++i)	//���װ�� ���� ���
	{
		for (int j = 0; j <= i && j < 100; ++j)
		{
			if (j == 0 || j == i) bino[i][j] = 1;
			else bino[i][j] = std::min(1000000000, bino[i - 1][j - 1] + bino[i - 1][j]);
		}	//k�� �ִ��� 10���̹Ƿ� 10���� �Ѿ�� ���� 10������ ����(�����÷ο� ����)
	}

	int C;
	std::cin >> C;
	while (C--)
	{
		int n, m, k;
		std::cin >> n >> m >> k;
		std::cout << solve(n, m, k) << '\n';
	}
}