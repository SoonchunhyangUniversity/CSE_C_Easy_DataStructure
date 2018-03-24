#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

struct
{
	float coef;
	int expon;
} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };

int avail = 6;
// 두 개의 정수를 비교
char compare(int a, int b)
{
	if (a > b)
		return '>';
	else if (a == b)
		return '=';
	else
		return '<';
}
// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}
// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	float tempcoef;
	*Cs = avail;

	while (As <= Ae && Bs <= Be)
	{
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>': // A의 차수 > B의 차수
			attach(terms[As].expon, terms[As].expon);
			As++;
			break;
		case '=': // A의 차수 = B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++;
			Bs++;
			break;
		case '<': // A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		}
		// A의 나머지 항들을 이동함
		for (; As <= Ae; As++)
			attach(terms[As].coef, terms[As].expon);
		// B의 나머지 항들을 이동함
		for (; Bs <= Be; Bs++)
			attach(terms[Bs].coef, terms[Bs].expon);
		*Ce = avail - 1;
	}
}

int main()
{
	int Cs, Ce;

	poly_add2(0, 2, 3, 5, &Cs, &Ce);

	return 0;
}
