#include <iostream>
int n;
int cache[101][101];

//���� �ٿ� p���� �簢���� ���� �� �� �Ʒ� �� �� �̻� a���� �簢���� ��ġ�ϴ� ����� ��
int solve(int p, int a)	//p: ���� ���� �簢�� ����, a: ���� �簢�� ����
{
	if (a == 0) return 1;
	if (cache[p][a]) return cache[p][a];

	int sum = 0; //���� ���� p���� �� �̹� ���� i���̸� p + i - 1���� ��찡 ����Ƿ� ������. ���ٿ� �ƹ��͵� ���°��(ó��ȣ��, p = 0) 1�� ����
	for (int i = 1; i <= a; ++i) sum = (sum + (p ? p + i - 1 : 1) * solve(i, a - i)) % 10000000;
	return cache[p][a] = sum;
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
		std::cout << solve(0, n) << '\n';
	}
}