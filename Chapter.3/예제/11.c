#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Example
{
	int number;
	char name[10];
};

int main()
{
	struct Example *p;

	p = (struct Example *)malloc(2 * sizeof(struct Example));

	if (p == NULL)
	{
		fprintf(stderr, "can't allocate memory\n");
		exit(1);
	}

	p->number = 1;
	strcpy(p->name, "Park");
	(p + 1)->number = 2;
	strcpy((p + 1)->name, "Kim");

	printf("%s = %d, %s = %d\n", p->name, p->number, (p + 1)->name, (p + 1)->number);

	free(p);

	return 0;
}
