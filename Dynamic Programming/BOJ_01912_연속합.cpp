#include <iostream>
#include <algorithm>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, arr[100000];
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	int sum = -1000, psum = -1000;
	for (int i = 0; i < n; ++i)
	{//psum == arr[0:i]���� arr[i]�� �����ϴ� �ִ��� ������
		psum = std::max(psum + arr[i], arr[i]);
		sum = std::max(sum, psum);
	}//sum == arr[0:i] ���� �ִ��� ������
	std::cout << sum;
}