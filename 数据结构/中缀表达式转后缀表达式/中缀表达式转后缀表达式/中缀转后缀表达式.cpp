#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stack>
using namespace std;
char space = ' ';
char* Sep =&space;
char *p;
char str[1005];
double calculate(double a, double b, char c) {
	if (c == '+')  return b + a;
	if (c == '-')  return b - a;
	if (c == '*')  return b * a;
	if (c == '/')  return b / a;
}
int main() {
	while (gets_s(str)) {
		stack<double> S;
		p = strtok(str, Sep);
		do {
			if (isdigit(p[0]))
				S.push(atof(p));
			else {
				double a = S.top();
				S.pop();
				double b = S.top();
				S.pop();
				double temp = calculate(a, b, p[0]);
				S.push(temp);
			}
		} while ((p = strtok(NULL, Sep)));
		printf("%g\n", S.top());
	}
	system("pause");
	return 0;
}