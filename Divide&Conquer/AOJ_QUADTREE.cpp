#include <iostream>
#include <string>
std::string reverse(std::string::iterator& it)
{
    char c = *(it++);
    if (c == 'x')
    {
        std::string top = reverse(it);
        top += reverse(it);
        std::string bottom = reverse(it);
        bottom += reverse(it);
        return "x" + bottom + top;  //�� �ܰ迡�� x�� ��� ���Ʒ��� ������ ����� ����
    }
    else return std::string(1, c);
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;
    while (C--)
    {
        std::string s;
        std::cin >> s;
        std::string::iterator i = s.begin();
        std::cout << reverse(i) << '\n';
    }
}