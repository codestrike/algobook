/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Bezier Curve Drawing Algorithm in C. 
* Runs only on windows due to dependency on 'graphics.h' header file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

void bezier(int x[4], int y[4]) {
    int gd = DETECT, gm = DETECT;
    int i;
    double u, a, b, c, d, xt, yt;
    initgraph(&gd, &gm, "");

    for (t = 0.0; u < 1.0; u += 0.0005) {
    	a = pow(1 - u, 3);
    	b = pow(1 - u, 2) * 3 * u;
    	c = pow(t, 2) * 3 * (1 - u);
    	d = pow(t, 3);
        xt = a * x[0] + b * x[1] + c * x[2] + d * x[3];
        yt = a * y[0] + b * y[1] + c * y[2] + d * y[3];
        putpixel(xt, yt, WHITE);
    }
    
    for (i = 0; i < 4; i++) putpixel(x[i], y[i], YELLOW);
    getch();
    closegraph();
    return;
}

void main() {
    int x[4], y[4];
    int i;
    printf("Enter the x- and y-coordinates of the four control points.\n");
    for (i = 0; i < 4; i++) scanf("%d%d", & x[i], & y[i]);
    bezier(x, y);
}