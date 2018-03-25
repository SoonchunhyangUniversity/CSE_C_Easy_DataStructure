// malloc을 이용하여 1000바이트의 메모리를
// 할당하고 free를 이용하여 메모리를 반납한다.

#include <stdio.h>
#include <malloc.h>

int main()
{
	char *string;

	string = (char *)malloc(1000);

	if (string == NULL)
		printf("Insufficient memory available\n");
	else
	{
		printf("Allocated 1000 bytes\n");
		free(string);
		printf("Memory freed\n");
	}

	return 0;
}
