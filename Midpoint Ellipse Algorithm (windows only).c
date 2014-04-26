/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Midpoint Ellipse Algorithm in C. 
* Runs only on windows due to dependency on 'graphics.h' header file.
*/

#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void plotpoints(int cx, int cy, int x, int y)
{
    putpixel(cx + x, cy + y, 4);
    putpixel(cx - x, cy + y, 4);
    putpixel(cx + x, cy - y, 4);
    putpixel(cx - x, cy - y, 4);
}

void main()
{
    int cx, cy, rx, ry;
    
    printf("Enter the center ");
    scanf("%d%d", &cx, &cy);
    printf("x radius : ");
    scanf("%d", &rx);
    printf("y radius : ");
    scanf("%d", &ry);
    
    long rx2 = (long) rx * rx;
    long ry2 = (long) ry * ry;
    long trx2 = 2 * rx2;
    long try2 = 2 * ry2;
    long p, x = 0, y = ry;
    long px = 0;
    long py = trx2 * y;
    
    p = (long) ((ry2 - (rx2 * ry) + (0.25 * rx2)) + 0.5);
    
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");
    cleardevice();
    
    putpixel(cx, cy, 15);
    
    while (px < py) {
       plotpoints(cx, cy, x, y);
       x++;
       px += try2;
       if (p < 0)
           p += ry2 + px;
       else {
           y--;
           py -= trx2;
           p += ry2 + px - py;
       }
   }
   py = trx2 * y;
   px = try2 * x;
   p = (long) ((ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2) + 0.5);
   while (y >= 0) {
       plotpoints(cx, cy, x, y);
       y--;
       py -= trx2;
       if (p > 0)
           p += rx2 - py;
       else {
           x++;
           px += try2;
           p += rx2 - py + px;
       }
   }
   
   getch();
}