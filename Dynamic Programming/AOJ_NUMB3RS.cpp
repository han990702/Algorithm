#include <iostream>
#include <iomanip>
int n, d, p;
bool way[50][50];
int numWay[50];
double probability[100][50];	//[d][n]�ϰ�� d��° �� n ������ ���� Ȯ��
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	std::cout << std::fixed << std::setprecision(8);
	while (C--)
	{
		std::cin >> n >> d >> p;
		for (int i = 0; i < n; ++i)
		{
			numWay[i] = 0;
			for (int j = 0; j < n; ++j)
			{
				std::cin >> way[i][j];	//i-j���������� ��� ���� �Է�
				if (way[i][j]) ++numWay[i];	//i�������� �ٸ������� ���� ����� �� ī��Ʈ(=�ٸ��������� i������ ���� ����� ��)
			}
		}
		//
		for (int i = 0; i < n; ++i)	//ù°�� �� ������ ���� Ȯ�� ���
		{
			if (way[p][i]) probability[0][i] = (double)1 / numWay[p];	//i������ ���� ���� �ִ°��
			else probability[0][i] = 0.0;	//���°��
		}
		for (int i = 1; i < d; ++i) for (int j = 0; j < n; ++j)	//i��° �� j������ ���� Ȯ�� ���
		{
			probability[i][j] = 0.0;
			for (int k = 0; k < n; ++k)	//j������ ���� ��ΰ� �ִ� ��� k������ ����, ���� k�������־��� Ȯ�� * k�������� j������ �� Ȯ�� �� ��
			{
				if (way[j][k]) probability[i][j] += probability[i - 1][k] / numWay[k];
			}
		}
		//
		int t, q;
		std::cin >> t;
		for (int i = 0; i < t; ++i)
		{
			std::cin >> q;
			std::cout << probability[d - 1][q] << ' ';
		}
		std::cout << '\n';
	}
}