#include <iostream>
#include <algorithm>
int K, cache[500][500], sectionSum[500][500];
//cache[i][j] = i~j�� ��ġ�� �ּ� ���, sectionSum[i][j] = i~j�� ���� ��
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--)
	{
		std::cin >> K;
		for (int i = 0; i < K; ++i)
		{
			std::cin >> sectionSum[i][i];
			cache[i][i] = 0;
		}
		for (int q = 1; q < K; ++q) for (int i = 0; i + q < K; ++i)
		{
			sectionSum[i][i + q] = sectionSum[i][i] + sectionSum[i + 1][i + q];
			cache[i][i + q] = 2147483647;
			for (int w = 0; w < q; ++w) //i~i+q�� �� �������� ������ ��ĥ �� �ּҺ���� ���� ã��
				cache[i][i + q] = std::min(cache[i][i + q], cache[i][i + w] + cache[i + w + 1][i + q]);
			cache[i][i + q] += sectionSum[i][i + q];	//�� ������ �����ϴ� �ּҺ�� + �� ������ ��ġ�� ���
		}
		std::cout << cache[0][K - 1] << '\n';
	}
}