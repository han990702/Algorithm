#include <iostream>
#include <string>
#include <set>
#include <memory.h>
/*
������ȹ���� ����ϴ°��� �׷��� ��������� �ð� ���̸� �� �� �ִ� �Է� ����
1
a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a
2
ahfjsdhfjkdshfkjdshfkdsaojajfjaljaflkajflkdsaljflkaflsaffasfa54656454aafasfsdafsaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb

���:
ahfjsdhfjkdshfkjdshfkdsaojajfjaljaflkajflkdsaljflkaflsaffasfa54656454aafasfsdafsaaaaaaaaaaaaaaaaaaaa
*/
bool cache[100][100];	//w[i]������ ���ڿ��� s[j]������ ���ڿ��� ��ġ���� �ʴ´ٸ� cache[i][j] = true�� ĳ��.(�ߺ� ������ ����)
bool solve(std::string& w, const std::string& s, int i = 0, int j = 0)
{
	while (true)
	{
		if (cache[i][j]) return false;	//�̹� ���Ǿ��ִ� ��� �ٷ� return

		if (i == w.size())
		{
			if (j < s.size())	//w�� ���� �����ߴµ� s�� ���� �ƴ϶�� ��ġ���� �ʴ� �����.
			{
				cache[i][j] = true;
				return false;
			}
			else return true;	//��ġ�Ǵ� ���
		}
		else if (j == s.size() && w[i] != '*') //w�� ���� �ƴϰ� s�� ���� �����ߴµ� w[i]�� *�� �ƴϸ� ��ġ���� �ʴ� �����.
		{
			cache[i][j] = true;
			return false;
		}

		if (w[i] == '*')	//*�̸� *�� 0ĭ~������ ��� ĭ�� �����Ǵ� ��츦 ��� ���ȣ��
		{	
			//�ѹ��̶� solve�� true�� ������ ��� ���ȣ���� true�� �����ϰ� ���α׷� ����
			for (int q = j; q <= s.size(); ++q) if (solve(w, s, i + 1, q)) return true;	
			cache[i][j] = true;	//for������ �ѹ��� return true�� ���� �ʾҴٸ� ��ġ���� ��������.
			return false;
		}
		else if (w[i] != '?' && w[i] != s[j])	//?�� �ƴϰ� ��ġ���� �ʴ°��
		{
			cache[i][j] = true;
			return false;
		}
		else ++i, ++j;	//������� ������ w[i]�� ? �̰ų� w[i] == s[j] ��. ���� ĭ Ȯ��
	}
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::string w;
		std::cin >> w;
		int n;
		std::cin >> n;
		std::set<std::string> s;	//��½� ���ĵ� ������ ����ؾ� �ϱ� ������ set ���
		while (n--)
		{
			std::string tmp;
			std::cin >> tmp;
			s.insert(tmp);
		}

		for (std::set<std::string>::iterator it = s.begin(); it != s.end(); ++it)
		{
			memset(cache, 0, 100 * 100);	//ĳ�� �ʱ�ȭ
			if (solve(w, *it)) std::cout << *it << '\n';
		}
	}
}