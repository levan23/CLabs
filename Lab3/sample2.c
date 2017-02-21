#include <stdio.h>
#include <math.h>

typedef struct point{
	int x;
	int y;
}point;

int main(void){
	double length;
	point segment[2];
	printf("Enter the start and the end of a line segment x1 y1 x2 y2\n");
	scanf("%d%d%d%d",&segment[0].x,&segment[0].y,&segment[1].x,&segment[1].y);
	length=sqrt(pow(segment[1].x-segment[0].x,2)+pow(segment[1].y-segment[0].y,2));
	printf("Segment length is: %lg\n",length);
	
	return 0;
}
