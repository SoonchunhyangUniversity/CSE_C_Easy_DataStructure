#include <stdio.h>
#define MAX_SIZE 10
// 배열을 매개 변수로 받는 함수
void sub(int var, int list[])
{
    var = 10;
    list[0] = 10;
}
// 주 함수
void main()
{
    int var; // 정수 변수의 선언
    int list[MAX_SIZE]; // 정수 배열의 선언

    var = 0;
    list[0] = 0;
    sub(var, list);
    printf("var = %d, list[0] = %d\n", var, list[0]);
}
