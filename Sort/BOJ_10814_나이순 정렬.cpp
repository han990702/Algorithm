#include <iostream>
#include <string>

class info
{
public:
	int age;
	std::string name;
	info() {}

	bool operator<=(const info& b)
	{
		if (this->age <= b.age) return true;
		else return false;
	}
};

template <typename T>
void merge_sort(T* a, int low, int high)
{
	if (low != high)	//low == high�� ���� ��ĭ¥���̹Ƿ� ���ĵ� ������ ���
	{
		int mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		
		T* sorted = new T[high - low + 1];

		int k = 0, i = low, j = mid + 1;
		while (i <= mid && j <= high)
		{
			sorted[k++] = (a[i] <= a[j] ? a[i++] : a[j++]);	//���ʰ� ������ �� �������� sorted�� �ֱ�
		}//��, stable sort�̱� ������ a[i] == a[j] �� ���� ������ ���������� �Ǵ�

		if (j > high)	//���ʺκ��� ���� ��� ������ ������ �Ű���(�̹� ���ĵǾ��ְ�, ���� ū �κ��̹Ƿ�)
		{
			while (i <= mid) a[--j] = a[mid--];
		}//�����ʺκ��� �������� �̹� �� ��ġ�� ����
		
		for (int q = low, w = 0; w < k; ++q, ++w)	//sorted�� a�� �Ű���
		{
			a[q] = sorted[w];
		}
	}
}

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	info* arr = new info[N];

	for (int i = 0; i < N; ++i) std::cin >> arr[i].age >> arr[i].name;
	merge_sort(arr, 0, N - 1);
	for (int i = 0; i < N; ++i) std::cout << arr[i].age << ' ' << arr[i].name << '\n';
}