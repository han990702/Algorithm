#include <iostream>
#include <cmath>
int main()
{//�̹����� ���װ���� ��ȭ���� �̿��ϴ°� �ǵ��� ����������, ���� �ٸ��� �����Ͽ���.
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	//���װ���� ������ N!/((N-K)!*K!)���� K!�κ��� ������ ��� �����ϹǷ� ����� ������ ó���ϰ�,
	//���� �κ��� ����, �и� ���� ���μ����ظ� �ؼ� ����ϸ� �и�� 1�� �ǹǷ�
	//���� ���ںκ��� 10007�� ���� �������� ���ϸ� �ȴ�.

	int N, K;
	std::cin >> N >> K;
	if (K <= N / 2) K = N - K;	//nCk = nCn-k �̹Ƿ� �ݺ����� �ݺ�Ƚ���� �������� ����
	int numerator[1000] = { 0 };	//������ ���μ����� (i^numerator[i]�� ����)
	int denominator[1000] = { 0 };	//�и��� ���μ�����
	for (int i = K + 1, j = 1; i <= N; ++i, ++j)
	{
		int q = i;	//������ ���μ�����
		while (true)
		{
			if (q % 2 == 0)
			{
				++numerator[2];
				q /= 2;
			}
			else break;
		}
		int z = 3;
		while (q != 1)
		{
			if (z > sqrt(q))
			{
				++numerator[q];
				break;
			}

			if (q % z == 0)
			{
				++numerator[z];
				q /= z;
			}
			else z += 2;
		}
		//
		q = j;	//�и��� ���μ�����
		while (true)
		{
			if (q % 2 == 0)
			{
				++denominator[2];
				q /= 2;
			}
			else break;
		}
		z = 3;
		while (q != 1)
		{
			if (z > sqrt(q))
			{
				++denominator[q];
				break;
			}

			if (q % z == 0)
			{
				++denominator[z];
				q /= z;
			}
			else z += 2;
		}
	}

	N = 1;
	for (int i = 0; i < 1000; ++i)
	{
		numerator[i] -= denominator[i];	//���
		N *= pow(i, numerator[i]);
		N %= 10007;
	}
	std::cout << N;
}