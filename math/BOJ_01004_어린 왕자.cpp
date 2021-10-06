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
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		int n;
		std::cin >> n;
		int cnt = 0;	//������� �����ϴ� �� + �������� �����ϴ� ��
		while (n--)
		{
			int cx, cy, r;
			std::cin >> cx >> cy >> r;
			bool both = false;
			if (std::pow(cx - x1, 2) + std::pow(cy - y1, 2) < std::pow(r, 2))
			{//���� �߽ɰ� ����� ������ ���̰� ���������� ª���� �� �ȿ� �ִ°�. sqrt����� �ʿ� ����(r�� �����ؼ� ��)
				++cnt;
				both = true;
			}
			if (std::pow(cx - x2, 2) + std::pow(cy - y2, 2) < std::pow(r, 2))
			{//������
				if (both) --cnt;	//�����, �������� �Ѵ� ������ ��� ����/��Ż�� �ʿ� �����Ƿ� 1�� ����
				else ++cnt;
			}
		}
		std::cout << cnt << '\n';
	}
}