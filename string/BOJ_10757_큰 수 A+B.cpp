#include <iostream>
#include <string>
#include <algorithm>
//ū �� ���, ���ڿ��� ó��

std::string operator+(std::string s1, std::string s2)	//+������ �����ε�
{
	std::reverse(s1.begin(), s1.end());	//����� ����ؾ� �ε��� ���� ����
	std::reverse(s2.begin(), s2.end());

	std::string& s3 = s1.size() > s2.size() ? s1 : s2;	//���� �� ���� s3�� ����
	char carry = 0;
	int i = 0;
	char tmp;
	for (; i < s1.size() && i < s2.size(); ++i)	//������ ���ڿ��� 12345, 123 �̸� 123 ������ ���
	{
		tmp = carry + s1[i] - '0' + s2[i] - '0';
		if (tmp > 9)
		{
			carry = 1;
			tmp -= 10;
		}
		else carry = 0;
		s3[i] = (tmp + '0');
	}

	for (; i < s3.size(); ++i)	//������ �κ� 45�� ���� ���
	{
		tmp = carry + s3[i] - '0';
		if (tmp == 10)
		{
			carry = 1;
			tmp = 0;
		}
		else carry = 0;
		s3[i] = (tmp + '0');
	}
	if (carry) s3.push_back('1');	//������ ĳ�� ������� �߰�
	
	std::reverse(s3.begin(), s3.end());
	return s3;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string a, b;
	std::cin >> a >> b;
	std::cout << a + b;
}