#include <iostream>
#include <vector>
#include <algorithm>
int Clock[16];  //�ð��� ����
int clock_count[16];    //�� �ð��� ���°� ���ϴ� Ƚ��(����� ��ư���� ������ Ƚ���� ��)
std::vector<std::vector<int>> button = { { 0, 1, 2 },   //button[i] : ��ư�� ����� �ð��� ��ȣ��
    { 3, 7, 9, 11 },
    { 4, 10, 14, 15 },  
    { 0, 4, 5, 6, 7 },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15 },
    { 3, 14, 15 },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5 },
    { 3, 4, 5, 9, 13 } };
//�� ��ư�� 4�� �̻� ������ ���� �ǹ̰� ����.
//��ư�� ������ ������ ����� ����.
int twelve_clock(int idx = 0, int cnt = 0, int ret = 987654321)
{
    if (cnt >= ret) return ret; //��ư�� ������ Ƚ���� ������ �ּڰ��� ������� ���̻� ������ �ʿ䰡 ����(�ð�����)
    if (idx == 10)  //��� ��ư�� ������ Ƚ���� ��������
    {
        bool twelve = true;
        for (int i = 0; i < 16; ++i)
        {
            if ((Clock[i] + 3 * (clock_count[i] % 4)) % 12 != 0)    //�� �ð��� ���¸� �ٲ���
            {
                twelve = false;
                break;
            }
        }
        if (twelve) return cnt; //��� �ð谡 12���̸� return cnt;
        return ret; //�ƴϸ� ������ �ּڰ� return
    }
    for (int i = 0; i < 4; ++i) //�� ��ư i�� 0, 1, 2, 3�� ������
    {
        for (int j = 0; j < button[idx].size(); ++j) clock_count[button[idx][j]] += i;
        ret = std::min(ret, twelve_clock(idx + 1, cnt + i, ret));
        for (int j = 0; j < button[idx].size(); ++j) clock_count[button[idx][j]] -= i;
    }
    return ret;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;

    while (C--)
    {
        for (int i = 0; i < 16; ++i)
        {
            std::cin >> Clock[i];
            clock_count[i] = 0;
        }
        int ans = twelve_clock();
        std::cout << (ans != 987654321 ? ans : -1) << '\n';
    }
}