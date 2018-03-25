#include <stdio.h>

void foo(int a)
{
	printf("foo : %d\n", a);
}

int main()
{
	// f는 함수의 주소를 담는 포인터 타입이다.
	void(*f)(int);

	f = foo;
	f(10); // = foo(10)
	(*f)(10); // = f(10)

	return 0;
}
