/*
    1. 팩토리얼을 계산하는 순환 호출 함수 factorial에서 매개 변수로 5를 주었다면
       최대 몇 개의 factorial 함수의 활성 레코드가 동시에 존재할 수있는가?
            최대 5개의 활성 레코드가 존재할 수 있다.

    2. 순환 호출을 하였을 경우에 활성 레코드들이 저장되는 위치는 어디인가?
        (1) 순환 호출 함수 내부     (2) 변수
        (3) 배열                    (4) 스택                답 : (4)

    3. 다음 중 활성 레코드에 저장되지 않는 것은 무엇인가?
        (1) 매개 변수의 값
        (2) 함수 호출이 끝나고 복귀할 주소
        (3) 지역 변수
        (4) 순환 호출의 순차 번호                           답 : (4)

    4. 다음 중 순환 호출이 불가능한 언어는?
        (1) C언어
        (2) Pascal 언어
        (3) Basic 언어
        (4) Java 언어                                       답 : (3)

    5. 하나의 함수가 호출할 수 있는 순환 호출의 개수는?
        (1) 1번
        (2) 2번
        (3) 스택이 허용하는 한도
        (4) 무제한                                         답 : (3)

    6. 다음의 순환 호출 함수에서 잘못된 점은 무엇인가?
        int rescrusive(int n)
        {
            if (n <= 1) return 0;
            return n * rescrusive(n);
        }
        순환 호출을 할 때 파라미터의 값이 줄어 들지 않았다.
        return n * rescrusive(n); -> return n * rescrusive(n - 1);

    7. 다음의 순환 호출 함수에서 잘못된 점은 무엇인가?
        int rescrusive(int n)
        {
            printf("rescrusive(%d)\n", n);
            return n * rescrusive(n - 1);
        }
        순환 호출을 끝내는 문장이 빠져있다.    if (n == 1) return 0;

    8. 다음 함수를 sum(5)로 호출하였을 때, 화면에 출력되는 내용과 함수의 반환 값을 구하라.
        int sum(int n)                                                      5
        {                                                                   4
            printf("%d\n", n);                               답 :           3
            if (n < 1) return 1;                                            2
            else return (n + sum(n - 1));                                   1
        }                                                                   0
                                                                            함수의 반환 값 = 15

    9. 다음 함수를 rescrusive(5)로 호출하였을 때, 화면에 출력되는 내용과 함수의 반환 값을 구하라.
        int rescrusive(int n)                                               5
        {                                                                   4
            printf("%d\n", n);                         답 :                 3
            if (n < 1) return 2;                                            2
            else return ( 2 * rescrusive(n - 1) + 1);                       1
        }                                                                   0
                                                                            함수의 반환 값 = 95

    10. 다음 함수를 rescrusive(10)로 호출하였을 때, 화면에 출력되는 내용과 함수의 반환 값을 구하라.
        int rescrusive(int n)                                               10
        {                                                                   7
            printf("%d\n", n);                            답 :              4
            if (n < 1) return -1;                                           1
            else return ( rescrusive(n - 3) + 1);                           -2
        }                                                                   함수의 반환 값 = 3

    11. 다음 함수를 rescrusive(5)로 호출하였을 때, 화면에 출력되는 내용을 써라.
        void rescrusive(int n)                                              1
        {                                                                   2
            if (n != 1) rescrusive(n - 1);                    답 :          3
            printf("%d\n", n);                                              4
        }                                                                   5

    12. 다음 함수에서 asterisk(5)를 호출할 때 출력되는 *의 개수는?
        void asterisk(int i)
        {
            if (i > 1)
            {
                asterisk(i / 2);
                asterisk(i / 2);
            }
            printf("*");
        }                                           답 : 7개

    13. 다음과 같은 함수를 호출하고 "rescrusive" 문자열을 입력한 다음, 엔터키를 눌렀다면 화면에 출력되는 것은?
        void unknown()
        {
            int ch;
            if ((ch == getchar()) != '\n')
                unknown();
            putchar(ch);
        }                               답 : evisurcser

    14. 다음을 계산하는 순환적인 프로그램을 작성하라.
        1 + 2 + 3 + ... + n

        int rescrusive(int n)
        {
            if (n == 1) return 1;
            else return n * rescrusive(n - 1);
        }

    15. 다음을 계산하는 순환적인 프로그램을 작성하라.
        1 + 1 / 2 + 1 / 3 + ... 1 / n

        double rescrusive(int n)
        {
            if (n == 1) return 1.0;
            else return (1.0 / n) + rescrusive(n - 1);
        }

    16. 순환 호출되는 것을 이해하기 위하여 fib 함수를 다음과 같이 바꾸어서 실행하여보라.
        fib(6)을 호출할 때 화면에 출력되는 내용을 써라.
        int fib(int n)
        {
            printf("fib(%d) is called\n", n);
            if (n == 0) return 0;
            if (n == 1) return 1;
            return (fib(n - 1) + fib(n - 2));
        }
        답 :
        fib(6) is called
        fib(5) is called
        fib(4) is called
        fib(3) is called
        fib(2) is called
        fib(1) is called
        fib(0) is called
        fib(1) is called
        fib(2) is called
        fib(1) is called
        fib(0) is called
        fib(3) is called
        fib(2) is called
        fib(1) is called
        fib(0) is called
        fib(1) is called
        fib(4) is called
        fib(3) is called
        fib(2) is called
        fib(1) is called
        fib(0) is called
        fib(1) is called
        fib(2) is called
        fib(1) is called
        fib(0) is called

    17. 다음의 순환적인 프로그램을 반복 구조를 사용한 비순환적 프로그램으로 바꾸어라.
        int sum(int n)
        {
            if (n == 1) return 1;
            else return (n + sum(n - 1));
        }

        답 : int sum(int n)
	         {
		        int i, sum =0;
                for(i = 1; i <= sum; i++)
                    sum += i;

                return sum;    
	         }

    18. 이항 계수(binomial coefficient)를 계산하는 순환 함수를 작성하라. 이항 계수는 다음과 같이 순환적으로 정의된다.
        반복 함수로도 구현해보라. nCk

        int bin(int n, int k)
        {
	        if( k==0 || n==0 )
		        return 1;
	        else
		        return bin(n-1,k-1)+bin(n-1,k);
        }

    19. Ackermann 함수는 다음과 같이 순환적으로 정의된다.
        A(0, n) = n + 1;
        A(m , 0) = A(m - 1, 1);
        A(m, n) = A(m - 1, A(m, n - 1)) m, n >= 1

        (1) A(3, 2)와 A(2, 3)의 값을 구하라.
            A(3, 2) = 29    A(2, 3) = 9
        (2) Ackermann 함수를 구하는 순환적인 프로그램을 작성하라.
            int ack(int m, int n)
            {
                if (m == 0) return( n + 1 );
                if (n == 0) return( ack(m - 1, 1) );
                return( ack(m - 1, ack(m, (n - 1))) );
            }
        (3) 위의 순환적인 프로그램을 for, while, do와 같은 반복 구조를 사용한 비순환적 프로그램으로 바꾸어라.
            int ack2(int m, int n)
            {
                while (m != 0)
                {
                 if (n == 0)
                     n = 1;
                 else
                     n = ack2(m, n-1);
                 m = m - 1;
                }
                return n+1;
            }

    20. 본문의 순환적인 피보나치 수열 프로그램과 반복적인 피보나치 수열 프로그램의 수행 시간을 측정하여 비교하라.
        어떤 결론을 내릴 수 있는가?
            답 : 순환적인 피보나치 프로그램은 거의 사용하지 못할 정도로 많은 수행시간을 요구한다.

    21. 순환 호출에서는 순환 호출을 할 때마다 문제의 크기가 작아져야 한다.
        (1) 팩토리얼 계산 문제에서 순환 호출이 일어날 때마다 문제가 어떻게 작아지는가?
            답 : n! = n * (n-1)! 으로 n을 곱한 다음 (n-1)!을 구한다.
        (2) 하노이탑에서 순환 호출이 일어날 때마다 문제가 어떻게 작아지는가?
            답 : 하나의 원판은 이동시킨 다음에 나머지 원판에 대하여 순환호출을 한다.

    22. 하노이탑 문제에서 64개의 원판을 옮기는 데 걸리는 시간을 계산하라. 단, 한 개의 원판을 옮기는 데 걸리는 시간을 1초라고 가정한다.
        답 : f(64) = 2^64 - 1 = 18446744073709551615 = 1844경6744조0737억0955만1615

*/
