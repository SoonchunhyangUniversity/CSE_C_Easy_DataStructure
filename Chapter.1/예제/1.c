#include <stdio.h>
#define MAX_ELEMENTS 100

int score[MAX_ELEMENTS]; // 자료 구조

int main()
{
    int n; // 학생의 숫자는 n
    int i, tmp;

    tmp = score[0];

    for(i = 0; i <= n; i++) // 알고리즘
    {
        if(score[i] > tmp)
        {
            tmp = score[i];
        }
    }

    printf("%d\n", tmp);

    return 0;
}
