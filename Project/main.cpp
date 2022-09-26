#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> vt(3, 0);
	string s("");
	int idx = 0;
	for (int i = 0; i < dartResult.length(); i++)
	{
		int pow = 0;
		if (dartResult[i] == 'S')
			pow = 1;
		else if (dartResult[i] == 'D')
			pow = 2;
		else if (dartResult[i] == 'T')
			pow = 3;
		else if (dartResult[i] == '*')
		{
			vt[idx - 1] *= 2;
			if (idx > 1)
				vt[idx - 2] *= 2;
		}
		else if (dartResult[i] == '#')
		{
			vt[idx - 1] *= -1;
		}
		else
			s += dartResult[i];
		if (pow != 0)
		{
			int score = stoi(s);
			vt[idx++] = std::pow(score, pow);
			s = "";
		}
	}
	for (int i = 0; i < 3; i++)
		answer += vt[i];
	return answer;
}

void main()
{
	//test
	//auto ret = solution("1S2D*3T");
}