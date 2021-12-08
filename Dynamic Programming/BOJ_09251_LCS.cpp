#include <iostream>
#include <string>
#include <algorithm>
std::string A, B;
int cache[1000][1000];
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> A >> B;
	//cache[i][j] �� A[0:i], B[0:j] ���� LCS�� ���� ��� ����.
	//A[i] == B[j]�̸� A[0:i-1], B[0:j-1]�� LCS�� �ڿ� �ϳ��� �߰��� �� �����Ƿ� cache[i-1][j-1] + 1 �̴�.
	//!= �̸� A[0:i], B[0:j-1] �� LCS�� ������ cache[i][j-1] �� A[0:i-1], B[0:j]�� LCS�� ������ cache[i-1][j] �� �� ū ���� ����.
	for (int i = 0; i < A.size(); ++i) for (int j = 0; j < B.size(); ++j)
	{
		if (A[i] == B[j]) cache[i][j] = (i == 0 || j == 0 ? 1 : cache[i - 1][j - 1] + 1);
		else cache[i][j] = std::max((j == 0 ? 0 : cache[i][j - 1]), (i == 0 ? 0 : cache[i - 1][j]));
	}
	std::cout << cache[A.size() - 1][B.size() - 1];
}