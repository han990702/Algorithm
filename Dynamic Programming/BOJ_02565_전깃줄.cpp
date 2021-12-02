#include <iostream>
#include <algorithm>
int n, pole[501], cache[501];	
int solve(int idx = 0)
{
	if (cache[idx] != -1) return cache[idx];
	int ret = 0;
	for (int i = idx + 1; i <= 500; ++i) if (pole[idx] < pole[i]) ret = std::max(ret, solve(i) + 1);
	return cache[idx] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{//���������뿡���� ��ġ�� tmp, �����ʿ� ����� ��ġ�� pole[tmp]��� �ϸ� ���� �������� ��ġ ������� ������ �������� ��ġ�� �ڵ����� ���ĵȴ�.
		int tmp;
		std::cin >> tmp;
		std::cin >> pole[tmp];
		cache[tmp] = -1;
	}
	cache[0] = -1;
	std::cout << n - solve();
	//�������� �ʴ� �ִ� �������� ���� ���� ��
	//���� �������� ��ġ�� ������ ������ �׿� ����� ������ �������� ��ġ�� �����ؾ� �������� �ʴ� ���̹Ƿ�
	//���ĵ� ������ �������� ��ġ ������ ���� �� �����ϴ� �κм����� ���̸� ���ϸ� �ȴ�.
	//���־� �ϴ� �������� �ּ� ������
	//�������� ���� - �������� �ʴ� �ִ� �������� �����̴�.
}