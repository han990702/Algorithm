#include <iostream>
#include <algorithm>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	int* arr = new int[N];
	int* sorted_arr = new int[N];
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
		sorted_arr[i] = arr[i];
	}
	std::sort(sorted_arr, sorted_arr + N);	//1. ���� //O(nlogn)

	int i = 0;
	for (int j = 0, k = 1; j + k < N;)	//2. �ߺ��Ǵ� element�� ���� (unique�Լ��� ����) //O(n)
	{
		if (sorted_arr[j] == sorted_arr[j + k]) ++k;
		else
		{
			j += k;
			sorted_arr[++i] = sorted_arr[j];
			k = 1;
		}
	}

	for (int j = 0; j < N; ++j)
	{
		int low = 0, high = i;
		int mid = (low + high) / 2;
		while (sorted_arr[mid] != arr[j])	//3. ���� �Ǿ������Ƿ� ����Ž��
		{
			if (sorted_arr[mid] > arr[j]) high = mid - 1;
			else low = mid + 1;
			mid = (low + high) / 2;
		}
		std::cout << mid << ' ';
	}//���� �� �ߺ��� ������ �迭�� �� element�� ���� index�� ������ ��
}