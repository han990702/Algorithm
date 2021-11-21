#include <iostream>
#include <memory.h>
int N, K, seq[501];
int cache[501];		//cache[idx] = seq[idx]�� �����ϴ� lis�� ����
long long count[501];	//count[idx] = seq[idx]�� �����ϴ� lis�� ����
int solve(int prev = 0)	//seq[prev]������ ������ ���� lis�� ���̸� �����ϴ� �Լ�
{
	if (cache[prev]) return cache[prev];
	int ret = 0;
	count[prev] = 1;
	for (int i = prev + 1; i <= N; ++i) if (seq[prev] < seq[i]) //seq[prev]���� ū ���� �� �� �ִ�.
	{
		int tmp = solve(i) + 1;
		if (ret < tmp)	//�ִ��� �����ϱ� ���� ���������� ũ�� ��ü�Ѵ�.
		{
			ret = tmp;
			count[prev] = count[i];
		}
		else if (ret == tmp)	//ret == tmp�̸� lis�̹Ƿ� lis�� ���� �߰�(�� ū tmp�� �����ϱ� ��������)
		{
			count[prev] += count[i];	//count[prev] = count[i]�� ��(i�� lis�� i�� �ش�)
			if (count[prev] > 2147483647) count[prev] = 2147483648;	//�����÷ο� ����(K�� �ִ� 2147483647�̹Ƿ�)
		}
	}
	return cache[prev] = ret;
}
void kth(int idx, int L, int k)	//k��° lis�� ���
{
	if (L == -1) return;
	//lis�� �׻� ���������� �������� Ž���ǹǷ� ���������� Ž���ϱ� ���ؼ��� �� �տ� �� ���ڸ� ������ �� �ڿ��� ������ Ž���ϸ鼭 ���� �Ѵ�.
	for (int i = N; i >= idx; --i) if (cache[i] == L && seq[idx - 1] < seq[i])	//������ ������ ���ں��� ũ��, lis�� ���̰� L�� i�� �ش�(i�� �ε����̴�)
	{
		if (count[i] >= k)	//k���� seq[i]�� �����ϴ� lis�� ������ ���ų� ������ seq[i]�� k��° lis�� �ִ� ���ڰ� �����Ƿ�
		{
			std::cout << seq[i] << ' ';	//����ϰ�
			kth(i + 1, L - 1, k);	//���� ���ڸ� ã�´�.
			return;
		}
		else k -= count[i];	//�׷��� ������ �������ڸ� ã�´�(count[i]���� �ǳʶڴ�)
	}
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		memset(cache, 0, 501 * sizeof(int));
		std::cin >> N >> K;
		for (int i = 1; i <= N; ++i) std::cin >> seq[i];
		int L = solve();	//L = lis�� ����
		std::cout << L << '\n';
		kth(1, L - 1, K);
		std::cout << '\n';
	}
}