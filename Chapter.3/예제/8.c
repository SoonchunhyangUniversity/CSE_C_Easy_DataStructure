#include <stdio.h>

int main()
{
	struct
	{
		int i;
		float f;
	} s, *ps;

	ps = &s;
	ps->i = 2;
	ps->f = 3.14;

	printf("ps->i = %d, ps->f = %f\n", ps->i, ps->f);

	return 0;
}
