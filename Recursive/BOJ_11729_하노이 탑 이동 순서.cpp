#include <iostream>
#include <string>

void hanoi(int n, char origin, char destination, char other, std::string& str)
{//������ �ִ°�: origin, �̵��ؾ��ϴ� ��: destination, ������ ���: other
	if (n == 1)
	{
		str.push_back(origin);
		str.push_back(' ');
		str.push_back(destination);
		str.push_back('\n');
	}
	else
	{//n���� �ű�� ����
		hanoi(n - 1, origin, other, destination, str);	//n-1���� ���� �ű��
		str.push_back(origin);	//������ �Ѱ��� �ű��
		str.push_back(' ');
		str.push_back(destination);
		str.push_back('\n');
		hanoi(n - 1, other, destination, origin, str);	//���� �Ű�� n-1���� �ٽ� �ű�
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	int k = (1 << N) - 1;	//�ű� Ƚ�� = �������� �� a1*(r^n - 1) / (r - 1)
	//2^N = (1 << N) �̴�.
	std::cout << k << '\n';

	std::string str;
	hanoi(N, '1', '3', '2', str);

	std::cout << str;
	//hanoi�Լ� �ȿ��� �ű� ������ ���� ����ϴ°� ���� �ѹ��� ���ڿ��� ��Ƽ� ����ϴ°� �ξ� ������.
}