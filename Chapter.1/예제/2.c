#include <stdio.h>

int seq_search(int list[], int n, int key)
{
    int i;

    for(i = 0; i <= n; i++)
    {
        if(list[i] == key)
            return i; // 탐색에 성공하면 키 값의 인덱스 반환
    }
    return -1; // 탐색에 실패하면 -1 반환
}

int main()
{
    int arr[3] = { 0 , 1 , 2};
    int result_idx;

    result_idx = seq_search(arr, 3, 1);

    printf("%d\n", result_idx);

    return 0;
}
