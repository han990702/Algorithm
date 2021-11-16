#include <iostream>
#include <string>
#include <cmath>
int m, q, n;
std::string words[500];	//��� �ܾ��� ���
double B[500], T[500][500], M[500][500];	//Ȯ���� �αװ����� ����(����÷ο찡 �Ͼ �� �����Ƿ�)
std::string sentence[100];	//�з��Ⱑ �ν��� ���� R
int wordIdx[100];	//���� R�� �� �ܾ��� ��ȣ(��ü �ܾ��Ͽ����� ��ȣ)
double cache[500][100];
int choice[500][100];	//��(Ȯ���� ���� ���� ����)�� �����ϱ� ���� �迭

double solve(int prev = 0, int Sidx = 0)
{
	if (Sidx == n) return 0;
	if (cache[prev][Sidx] != 1.0) return cache[prev][Sidx];
	double ret = std::log(0);	//Ȯ�� 0, -���Ѵ�
	int trace = -1;	//Ȯ���� ���� ���� �ܾ��� �ε���
	for (int i = 0; i < m; ++i)	//��� �ܾ� �õ�
	{//������ ���� Q, �з��Ⱑ �ν��� ���� R�϶�
		//P(Q|R) = P(R|Q) * P(Q) / P(R) ���� P(R)�� Q�� �޶����� ������ �����Ƿ�
		//P(R|Q) * P(Q) �� �ִ��� ���ϸ� �ȴ�. (P(R|Q) = ��M[][], P(Q) = ��B[])
		double tmp = (Sidx ? T[prev][i] : B[i]) + M[i][wordIdx[Sidx]];	//�αװ��̹Ƿ� ������ �ʰ� ���Ѵ�.
		if (tmp != std::log(0))
		{
			tmp += solve(i, Sidx + 1);
			if (tmp > ret)
			{
				ret = tmp;
				trace = i;
			}
		}
	}
	choice[prev][Sidx] = trace;
	return cache[prev][Sidx] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> m >> q;
	for (int i = 0; i < m; ++i) std::cin >> words[i];
	for (int i = 0; i < m; ++i)
	{
		std::cin >> B[i];
		B[i] = std::log(B[i]);
	}
	for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j)
	{
		std::cin >> T[i][j];
		T[i][j] = std::log(T[i][j]);
	}
	for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j)
	{
		std::cin >> M[i][j];
		M[i][j] = std::log(M[i][j]);
	}
	while (q--)
	{
		std::cin >> n;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> sentence[i];
			int j = -1;
			while (sentence[i] != words[++j]);	//�ܾ� ��ȣ ã��
			wordIdx[i] = j;
		}
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cache[i][j] = 1.0;
		solve();
		//����
		int i = choice[0][0], j = 0;
		while (j != n)
		{
			std::cout << words[i] << ' ';
			i = choice[i][++j];
		}
		std::cout << '\n';
	}
}