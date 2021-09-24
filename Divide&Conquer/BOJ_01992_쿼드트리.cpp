#include <iostream>
#include <string>
int N;
char pixels[64][65];
std::string s;

char areBlackOrWhite(int r, int c, int N)    //��� ����������, �������, �Ѵ� �ƴ��� Ȯ��
{
    char first_color = pixels[r][c];
    for (int i = r; i < r + N; ++i) for (int j = c; j < c + N; ++j) if (first_color != pixels[i][j]) return 'f';
    return first_color;
}

void quadTree(int r, int c, int N)
{
    char bow = areBlackOrWhite(r, c, N);
    if (bow != 'f') s += bow;
    else //�ش� �κ��� ��� ������ Ȥ�� ��� ����� �ƴ� ��� 4�������� ����� ���ȣ��(��������)
    {
        s += '(';
        quadTree(r, c, N / 2);
        quadTree(r, c + N / 2, N / 2);
        quadTree(r + N / 2, c, N / 2);
        quadTree(r + N / 2, c + N / 2, N / 2);
        s += ')';
    }
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; ++i) std::cin >> pixels[i];
    quadTree(0, 0, N);
    std::cout << s;
}