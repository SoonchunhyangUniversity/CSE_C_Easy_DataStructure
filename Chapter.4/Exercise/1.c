/*
    1. 리스트에 대한 설명 중 틀린 것은?
        (1) 구조체도 리스트의 요소가 될 수 있다.
        (2) 리스트의 요소 간에는 순서가 있다.
        (3) 리스트는 여러 가지 방법으로 구현될 수 있다.
        (4) 리스트는 집합과 동일하다.
        답 : (4)

    2. 다음은 순차적 표현과 연결된 표현을 비교한 것이다. 설명이 틀린 것을 모두 표시하여라.
        (1) 연결된 표현은 포인터를 가지고 있어 상대적으로 크기가 작아진다.
        (2) 연결된 표현은 삽입이 용이하다.
        (3) 순차적 표현은 연결된 표현보다 접근 시간이 많이 걸린다.
        (4) 연결된 표현으로 작성된 리스트를 2개로 분리하기가 쉽다.
        답 : (1),(3)

    3. 다음은 연결 리스트에서 있을 수 있는 여러 가지 경우를 설명한다. 잘못된 항목은?
        (1) 정적인 데이터보다는 변화가 심한 데이터에서 효과적인 방법이다.
        (2) 모든 노드는 데이터와 링크(포인터)를 가지고 있어야 한다.
        (3) 연결 리스트에서 사용한 기억 장소는 다시 사용할 수 없다.
        (4) 데이터들이 메모리상에 흩어져서 존재할 수 있다.
        답 : (3)

    4. 삽입과 삭제 작업이 자주 발생할 때 실행 시간이 가장 많이 소요되는 자료 구조는?
        (1) 배열로 구현된 리스트
        (2) 단순 연결 리스트
        (3) 원형 연결 리스트
        (4) 이중 연결 리스트
        답 : (1)

    5. 다음 중 NULL 포인터(NULL pointer)가 존재하지 않은 구조는 어느 것인가?
        (1) 단순 연결 리스트
        (2) 원형 연결 리스트
        (3) 이중 연결 리스트
        (4) 헤더 노드를 가지는 단순 연결 리스트
        답 : (2)

    6. 원형 연결 리스트에 대한 설명 중 틀린 것은?
        (1) 모든 노드들이 연결되어 있다.
        (2) 마지막에 삽입하기가 간단하다.
        (3) 헤더 노드를 가질 수 있다.
        (4) 최종 노드 포인터가 NULL이다.
        답 : (4)

    7. 리스트의 n번째 요소를 가장 빠르게 찾을 수 있는 구현 방법은 무엇인가?
        (1) 배열
        (2) 단순 연결 리스트
        (3) 원형 연결 리스트
        (4) 이중 연결 리스트
        답 : (1)

    8. 단순 연결 리스트의 노드 포인터 p가 마지막 노드를 가리킨다고 할 때, 다음 수식 중 참인 것은?
        (1) last == NULL
        (2) last->data == NULL
        (3) last->link == NULL
        (4) last->link->link == NULL
        답 : (3)

    9. 단순 연결 리스트의 노드들을 노드 포인터 p로 탐색하고자 한다. p가 현재 가리키는 노드에서 다음 노드로 가려면 어떻게 하여야 하는가?
        (1) p++;
        (2) p--;
        (3) p = p->link;
        (4) p = p->data;
        답 : (3)

    10. 단순 연결 리스트의 관련 함수 f가 헤드 포인터 head를 변경시켜야 한다면 함수 매개 변수로 무엇을 받아야 하는가?
        (1) head
        (2) &head
        (3) *head
        (4) head->link;
        답 : (2)

    11. A라는 공백 상태의 리스트가 있다고 가정하자. 이 리스트에 대하여 다음과 같은 연산들이 적용된 후의 리스트의 내용을 그려라.
        add_first(A, "first");
        add(A, 1, "second");
        add_last(A, "third");
        add(A, 2, "fourth");
        add(A, 4, "fifth");
        delete(A, 2);
        delet3(A, 2);
        replace(A, 1, "sizxth");
        답 :
        first
        second
        sixth

    12. 배열을 이용하여 구현한 리스트의 경우, 리스트의 연산 중 일부 연산만 구현되어 있다. 본문의 코드를 참조하여 리스트 ADT의 나머지 연산들도 구현하여보라.
        #include <stdio.h>
        #include <stdlib.h>

        #define MAX_LIST_SIZE 100 // 배열의 최대크기
        #define TRUE 1
        #define FALSE 0

        typedef int element;
        typedef struct
        {
            int list[MAX_LIST_SIZE];	  // 배열 정의
            int length;		  // 현재 배열에 저장된 자료들의 개수
        } ArrayListType;

        // 오류 처리 함수
        void error(char *message)
        {
            fprintf(stderr,"%s\n",message);
            exit(1);
        }
        // 리스트 초기화
        void init(ArrayListType *L)
        {
            L->length = 0;
        }
        // 리스트가 비어 있으면 1을 반환
        // 그렇지 않으면 0을 반환
        int is_empty(ArrayListType *L)
        {
            return L->length == 0;
        }
        // 리스트가 가득 차 있으면 1을 반환
        // 그렇지 많으면 1을 반환
        int is_full(ArrayListType *L)
        {
            return L->length == MAX_LIST_SIZE;
        }
        // 리스트 출력
        void display(ArrayListType *L)
        {
            int i;
            for(i=0;i<L->length;i++)
                printf("%d\n", L->list[i]);
        }
        // position: 삽입하고자 하는 위치
        // item: 삽입하고자 하는 자료
        void add(ArrayListType *L, int position, element item)
        {
            if( !is_full(L) && (position >= 0) && (position <= L->length) )
            {
                int i;
                for(i=(L->length-1); i>=position;i--)
                    L->list[i+1] = L->list[i];
                L->list[position] = item;
                L->length++;
            }
        }
        void add_first(ArrayListType *L, element item)
        {
            add(L,0,item);
        }
        void add_last(ArrayListType *L, element item)
        {
            add(L,L->length,item);
        }
        // position: 삭제하고자 하는 위치
        // 반환값: 삭제되는 자료
        element delete(ArrayListType *L, int position)
        {
            int i;
            element item;

            if( position < 0 || position >= L->length )
                error("위치 오류");
            item = L->list[position];
            for(i=position; i<(L->length-1);i++)
                L->list[i] = L->list[i+1];
            L->length--;

            return item;
        }
        void clear(ArrayListType *L)
        {
            L->length=0;
        }
        void replace(ArrayListType *L, int position, element item)
        {
            L->list[position]=item;
        }
        int is_in_list(ArrayListType *L, element item)
        {
            int i;
            for(i=0; i<(L->length);i++)
                if(L->list[i]==item) return TRUE;
            return FALSE;
        }
        element get_entry(ArrayListType *L, int position)
        {
            if( position < 0 || position >= L->length )
                error("위치 오류");
            return L->list[position];
        }
        main()
        {
            ArrayListType list1;

            // ListType를 정적으로 생성하고 ListType를 가리키는
            // 포인터를 함수의 파라미터로 전달한다.
            init(&list1);
            add_first(&list1, 10);
            add_first(&list1, 20);
            add_last(&list1, 30);
            display(&list1);
        }

    13. 단순 연결 리스트에서 삭제함수 delete 함수는 사실은 헤드포인터와 선행노드 포인터의 2개의 매개 변수만 있으면 작성이 가능하다. 이들 두 매개 변수만을 사용하여 다시 작성하라.
        remove_node(ListNode *head, ListNode *p)

        void remove_node( ListNode **phead, ListNode *p )
        {
        	ListNode *removed;
        	if( p == NULL )
            {
        		removed = (*phead);
        		*phead = (*phead)->link;
        	}
        	else
            {
        		removed=p->link;
        		p->link = removed->link;
        	}
        	free(removed);
        }

    14. 단순 연결 리스트에 정수가 저장되어 있다. 단순 연결 리스트의 모든 데이터 값을 더한 합을 출력하는 프로그램을 작성하시오.
        int sum( ListNode *head )
        {
            ListNode *p=head;
            int sum=0;
            while( p != NULL )
            {
                sum += p->data;
                p = p->link;
            }
            return sum;
        }

    15. 단순 연결 리스트에서 특정한 데이터값을 갖는 노드의 개수를 계산하는 함수를 작성하라.
        int count( ListNode *head, int x )
        {
            ListNode *p=head;
            int count=0;
            while( p != NULL ){
                if( p->data == x ) count++;
                p = p->link;
            }
            return count;
        }

    16. 단순 연결 리스트에서의 탐색함수를 참고하여 특정한 데이터값을 갖는 노드를 삭제하는 함수를 작성하라.
        void search_remove(ListNode **phead, int x)
        {
            ListNode *p, *prev=NULL;
            p = *phead;
            while( p != NULL )
            {
                if( p->data == x )
                {
                    remove_node(phead, prev, p);
                    if( prev!= NULL ) p=prev->link;
                    else p=*phead;
                }
                else
                {
                    prev=p;
                    p = p->link;
                }
            }
        }
    17. 단순 연결 리스트의 헤드 포인터가 주어져 있을 때 첫 번째 노드에서부터 하나씩 건너서 있는 노드를 전부 삭제하는 함수를 작성하라. 즉 홀수번째 있는 노드들이 전부 삭제된다.
        // 홀수번째 노드 삭제
        void remove_odd(ListNode **phead)
        {
            ListNode *p, *prev=NULL;
            int count=0;
            p = *phead;
            while( p != NULL )
            {
                if( (count%2)!=0 )
                {
                    remove_node(phead, prev, p);
                    if( prev!= NULL ) p=prev->link;
                    else p=*phead;
                }
                else
                {
                    prev=p;
                    p = p->link;
                }
                count++;
        }
    18. 두 개의 단순연결 리스트 A, B가 주어져 있을 경우, alternate 함수를 작성하라. alternate 함수는 A와 B로부터 노드를 번갈아 가져와서 새로운 리스트 C를 만드는 연산이다. 만약 입력리스트 중에서 하나가 끝나게 되면 나머지 노드들을 전부 C로 옮긴다. 함수를 구현하여 올바르게 동작하는지 테스트하라. 작성된 함수의 시간 복잡도를 구하라.
        void insert_node_last(ListNode **phead, element item)
        {
            ListNode *new_node = create_node(item, NULL);
            if( *phead == NULL ) *phead = new_node;
            else {
                ListNode *p = *phead;
                while(p->link != NULL) p = p->link;
                p->link = new_node;
            }
        }

        ListNode *alternate(ListNode *list1, ListNode *list2)
        {
            ListNode *list3=NULL;
            ListNode *p1, *p2, *p3=NULL;
            if( list1 == NULL )
                return list2;
            else if( list2 == NULL )
                return list1;
            else
            {
                p1 = list1;
                p2 = list2;
                while(( p1 != NULL ) || ( p2 != NULL ))
                {
                    if( p1 != NULL )
                    {
                        insert_node_last(&list3, p1->data);
                        p1=p1->link;
                    }
                    if( p2 != NULL )
                    {
                        insert_node_last(&list3, p2->data);
                        p2=p2->link;
                    }
                }
                return list3;
            }
        }

    19. 원형 연결 리스트에서 헤드 노드를 사용하면 탐색 연산을 조금 빠르게 할 수 있다. 즉 원형 연결 리스트에 아무런 역할도 하지 않는 헤드 노드를 하나 추가한다. 탐색 연산을 할 때 찾고자 하는 데이터를 헤드 노드에 미리 저장한다. 헤드 노드 다음 노드부터 탐색을 시작하여 만약 탐색이 헤드 노드에서 끝나게 되면 탐색은 실패한 것이다.
        (1) 다음과 같은 탐색 연산을 원형 연결 리스트에 대하여 구현하고 테스트하라.
            ListNode *search(ListNode *head. int data)
            {
                ListNode *current = head->link;
                head->data = data;
                while(current->data != x)
                {
                    current = current->link;
                }
                return ((current == head) ? NULL : current);
            }

        (2) 이 원형 연결 리스트에서의 탐색 연산 search와 단순 연결 리스트에서의 탐색 연산인 search의 실행 성능을 다음과 같이 비교하라.
            단순 연결 리스트와 원형 연결 리스트의 크기가 각각 100, 1000, 10000, 100000인 경우의 최악의 평균 실행 시간을 구하여 비교하라.
            실행 시간이 차이가 나는 이유를 설명하여라.

    20. 두 개의 단순 연결 리스트를 병합하는 함수를 조금 변경하여보자. 두 개의 연결 리스트 a = (a₁, a₂, ..., an), b = (b₁, b₂, ..., bn)가
        데이터 값을 오름차순으로 노드들이 정령되어 있는 경우, 이러한 정렬 상태를 유지하면서 합병을 하여 새로운 연결 리스트를 만드는 알고리즘 merge를 작성하라.
        a와 b에 있는 노드들은 전부 새로운 연결 리스트로 옮겨진다. 작성된 알고리즘의 시간 복잡도도 구하라.

    21. 보통 연결 리스트에서는 선행 노드를 알아야만 노드를 삭제할 수 있다. 그러나 다음과 같이 하면 선행 노드를 모르고도 노드를 삭제할 수 있다.
        먼저 원형 연결 리스트라고 가정하자. 어떤 노드를 가리키는 포인터 x가 주어진 경우, 그 노드의 후속 노드를 쉽게 차즐 수 있다.
        후속 노드를 y라고 하면 x에 y의 데이터 필드 값을 복사한다. 그리고 y를 삭제한다. 그러면 실질적으로는 x가 삭제 된 것처럼 된다.
        이런 식으로 노드를 삭제하는 함수 remove_node2를 작성하고 구현하여 테스트하라.

    22. 단순 연결 리스트 C를 두 개의 단순 연결 리스트 A와 B로 분리하는 함수 split를 작성하여보자. C의 홀수 번째 노드들은 모두 A로 이동되고
        C의 짝수 번째 노드들은 모두 B로 이동된다. 이 함수가 C를 변경하여서는 안 된다. 작성된 알고리즘의 시간 복잡도를 구하고 구현하여 수행하여보라.

    23. 두 개의 다항식이 다음과 같이 주어졌다. 이들을 연결 리스트를 이용하여 나타내고 본문의 프로그램을 이용하여 두 다항식의 합을 구해보라.
        A(X) = 3X^6 + 7X^3 + -2X^2 - 9
        B(X) = -2X^6 - 4X^4 + 6X^2 + 6X +1

    24. 다항식을 연결 리스트로 표현할 수 있음을 보였다. 다항식이 연결 리스트로 표현되어 있고, p를 다항식을 가리키는 포인터라고 할 때,
        어떤 실수 x에 대하여 이 다항식의 값을 계산하는 함수 poly_eval을 작성하라. 즉 다항식이 x^3 + 2x + 6이고, x = 2이면 2^3 + 2*2 + 6을 계산하는 함수를 작성하여보라.

    25. 다항식이 연결 리스트로 표현되어 있는 경우, 두 개의 다항식을 받아서 다항식의 뺄셈을 수행하는 함수 poly_sub를 작성하라.

    26. 다음의 연산에 대해 이중 연결 리스트가 단일 연결 리스트보다 좋은 점이 있는지를 설명하라.
        (1) 각 노드를 처리하기 위해 리스트를 순회한다.
        (2) loc의 위치에 있는 노드를 삭제한다.
        (3) loc의 위치에 있는 노드 바로 앞에 새 노드를 삽입한다.
        (4) loc의 위치에 있는 노드 바로 뒤에 새 노드를 삽입한다.

    27. 배열을 이용하여 숫자들을 입력받아 항상 정렬된 상태로 유지하는 리스트 SortedList를 구현하여보라.
        다음의 연산들을 구현하면 된다.
        - 객체 : n개의 element형으로 구성된 순서 있는 모임
        - 연산 :
            add(list, item) ::= 정렬된 리스트에 요소를 추가한다.
            delete(list, item) ::= 정렬된 리스트에서 item을 제거한다.
            clear(list) ::= 리스트의 모든 요소를 제거한다.
            is_in_list(list, item) ::= item이 리스트 안에 있는지를 검사한다.
            get_length(list) ::= 리스트의 길이를 구한다.
            is_empty(list) ::= 리스탁 비었는지 검사한다.
            is_full(list) ::= 리스트가 꽉 찼는지를 검사한다.
            display(list) ::= 리스트의 모든 요소를 검사한다.

    28. 단순 연결 리스트를 이용하여 숫자들을 항상 정렬된 상태로 유지하는 리스트 SortedList를 구현하여보라. 앞의 문제의 연산을 구현하면 된다.

    29. 이중 연결 리스트를 이용하여 숫자들을 항상 정렬된 상태로 유지하는 리스트 SortedList를 구현하여보라. 앞의 문제의 연산을 구현하면 된다.

    30. 본문에서 언급한 대로 연결 리스트에서 헤더 노드(header node)의 개념을 사용하는 것은 상당한 장점이 있다. 먼저 어떤 장점이
        있는지를 말하고 단순 연결 리스트의 함수들을 다음과 같은 헤더 노드의 포인터를 받아서 연산을 수행하도록 변경하여보라.
        // 연결 리스트 헤더
        typedef struct ListHeader
        {
            int length;
            ListNode *head;
            ListNode *tail;
        } ListHeader;

        // 헤더 노드를 이용한 삽입 함수
        void insert_node(HeaderNode *header, ListNode *p, ListNode *new_node)
        {
            // 작성하시오.
        }

        // 헤더 노드를 이용한 삭제 함수
        void remove_node(HeaderNode *header, ListNode *p, ListNode *removed)
        {
            // 작성하시오.
        }

        // 헤더 노드를 이용한 공백 검사 함수
        int is_empty(HeaderNode *header)
        {
            // 작성하시오.
        }

        // 헤더 노드를 이용한 공백 검사 함수
        int search(HeaderNode *header, element data)
        {
            // 작성하시오.
        }

    31. 행렬(matrix)은 숫자나 문자를 정사각형 또는 직사각형으로 배열하여 그 양끝을 괄호로 묶은 것으로 많은 문제를 수학적으로 해결하는 도구이다.
        희소 행렬(sparse matrix)은 많은 항들이 0인 행렬이다. 연결 리스트를 이용하여 희소 행렬을 표현하는 방법을 생각하여보고 구현하라.
*/
