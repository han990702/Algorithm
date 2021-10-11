#include <iostream>
#include <algorithm>
int arr[20000];
int rectangle(int left, int right)  //�������� Ǯ��
{
    if (left == right) return arr[left];    //base case, �� ĭ�� ��� �� ĭ�� ���� = ����
    //��Ÿ�� n���� �������� �������� �� ���̰� �ִ��� ���簢����
    //������ ������ ��� �� �ϳ��� �ִ�.
    //mid�� ��������
    //1. ���� �κ�(mid����)
    //2. ������ �κ�(mid����)
    //3. mid�� mid + 1�� �����ϴ� �κ�(��� �� ĭ�� �ݵ�� �����ϴ� �κ�)

    //3�������� ����(1, 2������ ���ȣ��)
    int mid = (left + right) / 2;
    int min_height = arr[mid] < arr[mid + 1] ? arr[mid] : arr[mid + 1];
    //midĭ�� mid + 1ĭ �� �� ���� ���̸� �������� �߶�� ���簢���� ��
    int max_area = min_height * 2;
    int i = mid, j = mid + 1;
    //����� �������� ����ĭ�� �� ������ ��������, ������ĭ�� �� ������ ���������� �� ĭ�� ����(���� ĭ���� ���� �ִ���̸� ��ġ�� ����)
    //�� ���� ������ �� ���� �ݺ��ϸ� ���簢���� �ִ���̸� �� �� �ִ�.
    while (i != left || j != right)
    {
        int k;
        if (i == left) k = ++j; //�������� ���̻� �� �� ���� ��� ���������� ����
        else if (j == right) k = --i;   //���������� ���̻� �� �� ���� ��� �������� ����
        else if (arr[i - 1] > arr[j + 1]) k = --i;  //������ �� ���� ��� ��������
        else k = ++j;   //����������

        min_height = std::min(arr[k], min_height);  //���� ���� ����
        max_area = std::max(min_height * (j - i + 1), max_area);    //�ִ񰪰� ���Ͽ� �� ũ�� �ٲ�
    }
    //�� ���� ��� �� �ִ� ����
    return std::max(max_area, std::max(rectangle(left, mid), rectangle(mid + 1, right)));
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;
    while (C--)
    {
        int N;
        std::cin >> N;
        for (int i = 0; i < N; ++i) std::cin >> arr[i];
        std::cout << rectangle(0, N - 1) << '\n';
    }
}