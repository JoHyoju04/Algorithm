#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int DP[1002][1002];
string s1, s2;
int len1, len2;

int main()
{
	cin >> s1 >> s2;

	len1 = s1.size();
	len2 = s2.size();

	for (int i = 1; i <= len2; i++)
	{
		for (int j = 1; j <= len1; j++)
		{
			if (s2[i - 1] == s1[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[len2][len1];
}