#include <stdio.h>

typedef struct
{
	int x;
	int y;
} PointType;

// 기울기와 y절편을 계산
int get_line_parameter(PointType p1, PointType p2, float * slope, float * yintercept)
{
	if (p1.x == p2.x)
		return -1;
	else
	{
		*slope = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
		*yintercept = p1.y - (*slope) * p1.x;
		return 0;
	}
}

int main()
{
	PointType pt1 = { 3, 3 }, pt2 = { 6, 6 };
	float s, y;

	if (get_line_parameter(pt1, pt2, &s, &y) == -1)
		printf("ERROR\n");
	else
		printf("기울기는 %f, y절편은 %f\n", s, y);

	return 0;
}
