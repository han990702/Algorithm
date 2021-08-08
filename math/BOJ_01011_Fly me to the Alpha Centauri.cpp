#include <iostream>
#include <cmath>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--)
	{
		int x, y;
		std::cin >> x >> y;
		x = y - x;
		//2 6 12 20 30 42... ��Ģ
		//���������� �� : (ù�� + ��������) * ���� ���� / 2 
		//((n + 2) * (n / 2)) / 2 = n(n+2)/4 = x
		//n^2 + 2n -4x = 0
		//¦�����ǰ����� ��� �κ� : -1 + sqrt(1 + 4 * x)		�� �ø�
		long long n = ceil(-1 + sqrt(1 + 4 * (long long)x));	//4�� ���Ұ��̹Ƿ� int���� overflow ���ɼ�
		if (n % 2) ++n;
		if (n * (n + 2) / 4 - x >= n / 2) --n;
		std::cout << n << '\n';
	}
}