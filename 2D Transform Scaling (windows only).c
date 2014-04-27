/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* 2D Transformation Scaling in C. 
* Runs only on windows due to dependency on 'graphics.h' header file.
*/

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
 
void scale( int figure[], int edges, int dx, int dy, int cx, int cy )
{
	for(int i=0; i < edges; i++)
	{
		figure[2*i] = (figure[2*i] - cx) * dx + cx;
		figure[2*i+1] = (figure[2*i+1] - cy) * dy + cy;
	}
}
 
void main()
{
	int figure[20], edges; // A Figure with Max 10 edges.
	int dx, dy, cx=0, cy=0; 
	int gd = DETECT, gm;
	clrscr();
 
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
 
	printf( "Enter dx: ");
	scanf( "%d", &dx);
	printf( "Enter dy: ");
	scanf( "%d", &dy);
 
	printf( "Enter the center of scaling: \n");
	printf( "cx: ");
	scanf( "%d", &cx);
	printf( "cy: ");
	scanf( "%d", &cy);
 
	initgraph( &gd, &gm, "" );
	cleardevice();
	setbkcolor(WHITE);
 
	setcolor(GREEN);
	setlinestyle(SOLID_LINE, 0, 3);
	drawpoly( edges, figure );
	getch();
 
	scale(figure,edges,dx,dy,cx,cy);
 
	setcolor(RED);
	drawpoly( edges, figure );
	getch();
}