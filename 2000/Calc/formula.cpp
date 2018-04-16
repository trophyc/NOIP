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
float Calculate (Expr& l, Expr& r);

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

	printf ("%c=%.3f\n", v, Calculate(left, right));
	return 0;
}


void GetExpr (char* buf, int len, int& i, Expr& e, char& v)
{
	int tmp = 0;
	bool digitFlag = false;
	char c = buf[i];

	while (c != '=' && c != '\0' && i < len) {
		if (c == '+') {
			e.number  += tmp * e.sign;
			e.sign = 1;
			tmp = 0;
			digitFlag = false;
		} else if (c == '-') {
			e.number += tmp * e.sign;
			e.sign = -1;
			tmp = 0;
			digitFlag = false;			
		} else if (IsLowerCase(c)) {
			v = c;
			if (!digitFlag) {
				e.factor += e.sign;
			} else {
				e.factor += tmp * e.sign;
			}
			tmp = 0;
			digitFlag = false;				
		} else if (IsDigit(c)) {
			tmp *= 10;
			tmp += c - '0';
			digitFlag = true;
		}
		
		i++;
		if (i >= len) {
			break;
		}
		c = buf[i];
	}
	e.number += tmp * e.sign;
}

float Calculate (Expr& l, Expr& r)
{
	float factor = l.factor - r.factor;
	float number = r.number - l.number;
	return (number/factor);
}
