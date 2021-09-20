#include <iostream>
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;

    /*
    �� ��ư�� 4�� �̻� ������ ���� �ǹ̰� ����.
    ��ư�� ������ ������ ����� ������ ��ġ�� �ʴ´�. �̹Ƿ� 
    4^10�� ����Ǽ��� ��� Ž���ϴ� ����Ž�� Ǯ�̸� �ǵ��ϰ� �� ����������

    �������� �־��� ��ư-�ð� ������ ���
    �ð迡 ����� ��ư�� �ϳ��ۿ� ���� �ð��� ��ư�� ã�Ƽ�
    �� ��ư�� 3ȸ ���Ϸ� ������ ������ �����(���̻� �������ʴ�) ������ 10����(��ư ����) �����ϸ�
    �ּ� Ƚ���� ���� �� �ִ�.

    �׸��� ����� ��ư���� ��� ���� �ð谡 �� �� �̻� �ִ� ���
    �ð���� ����(�ð�)�� �ٸ��� ��� 12�÷� ���ߴ°� �Ұ����� ����̹Ƿ� -1�� ����ϸ� �ȴ�.
    ex) �ʱ� �Է��� 8��, 12�� �ð��� �ð��� �ٸ��� 4����ư�� �ƹ��� ������ ���ÿ� 12�ð� �� �� ����.
    14, 15�� �ð��� �ð��� �ٸ��� �׿� ����� � ��ư�� ������ ���ÿ� 12�ð� �� �� ����.
    */

    int Clock[16];
    while (C--)
    {
        for (int i = 0; i < 16; ++i)
        {
            std::cin >> Clock[i];
        }
        if (Clock[8] != Clock[12] || Clock[14] != Clock[15]) std::cout << "-1\n";
        else
        {
            int cnt = 0;
            while (Clock[8] % 12 != 0)  //4����ư
            {
                Clock[6] += 3;
                Clock[7] += 3;
                Clock[8] += 3;
                Clock[10] += 3;
                Clock[12] += 3;
                ++cnt;
            }
            while (Clock[6] % 12 != 0)  //3
            {
                Clock[0] += 3;
                Clock[4] += 3;
                Clock[5] += 3;
                Clock[6] += 3;
                Clock[7] += 3;
                ++cnt;
            }
            while (Clock[10] % 12 != 0) //2
            {
                Clock[4] += 3;
                Clock[10] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            while (Clock[11] % 12 != 0) //1
            {
                Clock[3] += 3;
                Clock[7] += 3;
                Clock[9] += 3;
                Clock[11] += 3;
                ++cnt;
            }
            while (Clock[7] % 12 != 0) //7
            {
                Clock[4] += 3;
                Clock[5] += 3;
                Clock[7] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            if (Clock[9] % 12 != Clock[13] % 12)
            {
                std::cout << "-1\n";
                continue;
            }
            while (Clock[9] % 12 != 0) //9
            {
                Clock[3] += 3;
                Clock[4] += 3;
                Clock[5] += 3;
                Clock[9] += 3;
                Clock[13] += 3;
                ++cnt;
            }
            if (Clock[4] % 12 != Clock[5] % 12)
            {
                std::cout << "-1\n";
                continue;
            }
            while (Clock[4] % 12 != 0) //8
            {
                Clock[1] += 3;
                Clock[2] += 3;
                Clock[3] += 3;
                Clock[4] += 3;
                Clock[5] += 3;
                ++cnt;
            }
            while (Clock[1] % 12 != 0) //0
            {
                Clock[0] += 3;
                Clock[1] += 3;
                Clock[2] += 3;
                ++cnt;
            }
            while (Clock[0] % 12 != 0) //5
            {
                Clock[0] += 3;
                Clock[2] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            if (Clock[3] % 12 != Clock[14] % 12 || Clock[14] % 12 != Clock[15] % 12)
            {
                std::cout << "-1\n";
                continue;
            }
            while (Clock[3] % 12 != 0) //6
            {
                Clock[3] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            std::cout << cnt << '\n';
        }
    }
}