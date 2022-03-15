
#include <bits/stdc++.h>
using namespace std;

void printSubSeqRec(string str, int n, int index = -1,
					string curr = "")
{
	if (index == n)
		return;

	if (!curr.empty()) {
		cout << curr << "\n";
	}

	for (int i = index + 1; i < n; i++) {

		curr += str[i];
		printSubSeqRec(str, n, i, curr);

		// backtracking
		curr = curr.erase(curr.size() - 1);
	}
	return;
}

void printSubSeq(string str)
{
	printSubSeqRec(str, str.size());
}

int main()
{
	string str = "cab";
	printSubSeq(str);
	return 0;
}


Input : abc
Output : a, b, c, ab, bc, ac, abc

Input : aaa
Output : a, aa, aaa
