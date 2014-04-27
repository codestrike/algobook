/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* 2D transformation Translation in C. 
* Runs only on windows due to dependency on 'graphics.h' header file.
*/

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
 
void translation( int figure[], int edges, int dx, int dy )
{
	for(int i=0; i < edges; i++)
	{
		figure[2*i] += dx;
		figure[2*i+1] += dy;
	}
}
 
void main()
{
	int figure[20], edges, dx, dy; // A Figure with Max 10 edges.
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
 
	initgraph( &gd, &gm, "" );
	cleardevice();
 
	drawpoly( edges, figure );
	getch();
 
	translation(figure,edges,dx,dy);
 
	setcolor(RED);
	drawpoly( edges, figure );
	getch();
}