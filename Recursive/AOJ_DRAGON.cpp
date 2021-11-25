#include <iostream>
#include <string>
std::string solve(int left, int right)	//n���� ��ü ���ڿ����� ����� �κ� ���ڿ��� ����. �κ� ���ڿ��� �ε����� ù��left, ������ ��right
{
	if (right == 1) return "FX";	//right�� 1�̸� 0���� �̹Ƿ� FX����
	//���ڿ��� �׻� FX_YF_ (_�� +Ȥ��-) �� �ݺ����� �����ǰ� �̴� �� ������ FX_ Ȥ�� YF_ �� ġȯ�� ���̴�.
	//left, right��°�� ���ڰ� �ִ� �κ�(FX_YF_)�� �� ������ ��� �κ�(FX_ or YF_)���� ġȯ�� ������ ����Ͽ� ���ȣ���Ѵ�.
	int tmpl = (left % 6 <= 4 ? left / 6 * 6 : left), tmpr = (right % 6 <= 4 ? right / 6 * 6 + 4 : right);
	std::string s = solve(tmpl / 2, tmpr / 2 - (right % 6 <= 4 ? 1 : 0));	//�� ������ ���ڿ����� �ʿ��� �κи� ���� ����
	std::string ret;
	for (int i = 0; i < s.size(); ++i)	//�� ���� ���ڿ� s�� �̹� ���� ���ڿ� ret�� ġȯ
	{
		if (s[i] == 'X') ret += "X+YF";
		else if (s[i] == 'Y') ret += "FX-Y";
		else ret.push_back(s[i]);
	}
	return ret.substr(left - tmpl, right - left + 1);	//�ʿ��� �κи� ����
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		int n, p, l;
		std::cin >> n >> p >> l;	//n�� �ʿ� ����.
		std::cout << solve(p - 1, p + l - 2) << '\n';
	}
}