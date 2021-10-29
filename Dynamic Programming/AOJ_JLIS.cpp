#include <iostream>
#include <algorithm>
int nA, nB;
int progressionA[100];
int progressionB[100];
int cache[101][101];

//main���� �Լ��� ó�� ȣ���� �� ������ ó���� ���� �ʱ� ���ؼ� -1, -1���� �����ϴ� ������ ��
int solve(int idxA = -1, int idxB = -1)
{
	if (cache[idxA + 1][idxB + 1]) return cache[idxA + 1][idxB + 1];	//�̹� ĳ�ÿ� ������ �ٷ� ����

	long long tmp = std::max((idxA != -1 ? progressionA[idxA] : -2147483649), (idxB != -1 ? progressionB[idxB] : -2147483649));
	//tmp = ������ ���� ��
	int count = 0;
	for (int i = idxA + 1; i < nA; ++i) if (progressionA[i] > tmp) count = std::max(count, solve(i, idxB));
	for (int i = idxB + 1; i < nB; ++i) if (progressionB[i] > tmp) count = std::max(count, solve(idxA, i));

	return cache[idxA + 1][idxB + 1] = ++count;	//ĳ���� ����
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> nA >> nB;
		for (int i = 0; i < nA; ++i) std::cin >> progressionA[i];
		for (int i = 0; i < nB; ++i) std::cin >> progressionB[i];
		for (int i = 0; i <= nA; ++i) for (int j = 0; j <= nB; ++j) cache[i][j] = 0;

		std::cout << solve() - 1 << '\n';	//�ƹ��͵� ���� ���� -1, -1�� ���µ� ���� ������ 1�� ����
	}
}