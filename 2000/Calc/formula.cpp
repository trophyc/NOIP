#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

struct Expr
{
	int number;
	int factor;
	int sign;
};

#define IsDigit(c) (c >= '0' && c <= '9')
#define IsLowerCase(c) (c >='a' && c <= 'z')

void GetExpr (char* buf, int len, int& i, Expr& e, char& var);
double Calculate (Expr& l, Expr& r);

int main ()
{
	char buf[MAX_LINE];	
	memset (buf, 0, sizeof(buf));
	Expr left = {0, 0, 1};
	Expr right = {0, 0, 1};
	
	fgets (buf, MAX_LINE, stdin);
	int i = 0;
	char v;
	GetExpr(buf, strlen (buf), i, left, v);
	i++;
	GetExpr(buf, strlen(buf), i, right, v);
	printf ("%s", buf);
	printf ("Left, Number = %d, Factor = %d\n", left.number, left.factor);
	printf ("Right, Number = %d, Factor = %d\n", right.number, right.factor);
	printf ("%c = %lf\n", v, Calculate(left, right));
	return 0;
}

void GetExpr (char* buf, int len, int& i, Expr& e, char& v)
{
	int tmp = 0;
	
	char c = buf[i];
	while (c != '=' && c != '\0' && i < len) {
		if (c == '+') {
			e.number  += tmp * e.sign;
			e.sign = 1;
			tmp = 0;
		} else if (c == '-') {
			e.number += tmp * e.sign;
			e.sign = -1;
			tmp = 0;
		} else if (IsLowerCase(c)) {
			v = c;
			if (tmp == 0) {
				e.factor += e.sign;
			} else {
				e.factor += tmp * e.sign;
			}
			tmp = 0;
		} else if (IsDigit(c)) {
			tmp *= 10;
			tmp += c - '0';
		}
		
		i++;
		if (i >= len) {
			break;
		}
		c = buf[i];
	}
	e.number += tmp * e.sign;
}

double Calculate (Expr& l, Expr& r)
{
	double factor = l.factor - r.factor;
	double number = r.number - l.number;
	return (number/factor);
}
