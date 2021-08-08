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
		int	x1, x2, y1, y2, r1, r2;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		//�� �ͷ��� �߽����� �������� r�� ���� �׷������� ������ ã���� �ȴ�.
		int c;	//������ ����;
		if (x1 == x2 && y1 == y2)	//�� �ͷ� ��ǥ�� ���� ��
		{
			if (r1 == r2) c = -1;	//�������� ������ ������ ���Ѵ�
			else c = 0;	//�ƴϸ� ���� ����
		}
		else //�� �ͷ� ��ǥ�� �ٸ� ��
		{
			double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));	//�� �ͷ� ������ �Ÿ� d
			if (r1 < d)	//r1 < d �� ��
			{
				if (r2 < d - r1) c = 0;	//r2 = 0 ���� r2�� ���� Ŀ���鼭 ������ 0��
				else if (r2 == d - r1) c = 1;	//1��
				else if (r2 < d + r1) c = 2;	//2��
				else if (r2 == d + r1) c = 1;	//1��
				else c = 0;	//0���� ��
			}
			else if (r1 == d)	//r1 = d �϶�
			{
				if (r2 < d + r1) c = 2;
				else if (r2 == d + r1) c = 1;
				else c = 0;
			}
			else //r1 > d �� ��
			{
				if (r2 < r1 - d) c = 0;
				else if (r2 == r1 - d) c = 1;
				else if (r2 < d + r1) c = 2;
				else if (r2 == d + r1) c = 1;
				else c = 0;
			}
		}
		std::cout << c << '\n';
	}
}