/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* 2D Transformation Rotation in C. 
* Runs only on windows due to dependency on 'graphics.h' header file.
*/

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
 
void rotate( int figure[], int edges, double angle, int cx, int cy )
{
	double x, y;
	angle = -1 * (angle*3.14/180);
	double cos_a = cos(angle);
	double sin_a = sin(angle);
 
	for(int i=0; i < edges; i++)
	{
		x = figure[2*i] - cx;
		y = figure[2*i+1] - cy;
		figure[2*i] = ceil( (x * cos_a) - (y * sin_a) + cx );
		figure[2*i+1] = ceil( (x * sin_a)+(y * cos_a) + cy );
	}
}
 
void main()
{
	int figure[20], edges;  // A Figure with Max 10 edges.
	double angle;
	int cx=0, cy=0;
	int gd = DETECT, gm;
	initgraph( &gd, &gm, "" );
	int max_y = getmaxy();
	clrscr();
	cleardevice();
 
	printf( "Number of edges: " );
	scanf( "%d", &edges );
 
	for(int i=0; i < edges; i++)
	{
		printf( "Enter edge (x%d,y%d) : ", i , i );
		scanf( "%d %d", &figure[2*i], &figure[2*i+1] );
	}
	figure[2*i] = figure[0];
	figure[2*i+1] = figure[1];
	edges += 1;
 
	printf( "Enter angle of rotation in degrees: ");
	scanf( "%lf", &angle);
 
	printf( "Enter the center of rotation: \n");
	printf( "cx: ");
	scanf( "%d", &cx);
	printf( "cy: ");
	scanf( "%d", &cy);
	cy = max_y - cy;
 
	cleardevice();
	setbkcolor(WHITE);
 
	setcolor(GREEN);
	setlinestyle(SOLID_LINE, 0, 3);
	drawpoly( edges, figure );
	getch();
 
	for(int i=0; i < edges; i++)
		figure[2*i+1] = max_y - figure[2*i+1];
	rotate(figure,edges,angle,cx,cy);
	for(int i=0; i < edges; i++)
		figure[2*i+1] = max_y - figure[2*i+1];
 
	setcolor(RED);
	drawpoly( edges, figure );
	getch();
}