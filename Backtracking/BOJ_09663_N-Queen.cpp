#include <iostream>
#include <cmath>
#define empty -987654321
int NQ(int* horizontal, int N, int vertical = 0)    //horizontal�� �ε���: ������ǥ, vertical: ������ǥ
{
    if (N == vertical) return 1;    //���� N�� ���̸� ����� �� 1 �߰�

    int cases = 0;  //����� ��
    for (int i = 0; i < N; ++i)
    {
        if (horizontal[i] == empty) //empty�� �ƴϸ� �ǳ� ��(�ش� ���� ���� ������ �ǳ� ��)
        {
            bool dup = false;
            for (int j = 0; j < N; ++j) if (abs(i - j) == abs(vertical - horizontal[j]))
            {//�밢�� ��ġ�� �̹� ���� ������ ���� ���� �� ����(����, ������ǥ������ ���� ���밪�� ���� ������ �밢����ġ)
                dup = true;
                break;
            }
            if (!dup)   //empty��  �ƴϰ�, ��, ��, �밢���� �ߺ��� ���� �� ���� ����
            {
                horizontal[i] = vertical; //(vertical, i) �� �� ����
                cases += NQ(horizontal, N, vertical + 1);   //���� �࿡�� �� ���� �� ã��
                horizontal[i] = empty;  //���ƿ� �� �����(��Ʈ��ŷ)
            }
        }
    }

    return cases;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int* horizontal = new int[N];   //horizontal�� index�� ������ǥ(��)�� ��Ÿ����, element���� (���� �ִ� ���)������ǥ(��)�� ������
    for (int i = 0; i < N; ++i) horizontal[i] = empty;  //element�� empty(-987654321)�̸� ���� ���� �� ��

    std::cout << NQ(horizontal, N);
}