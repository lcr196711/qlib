#include <graphics.h>
#include <conio.h>

void drawCircleGraphics(int xc, int yc, int radius) {
    // 初始化图形模式
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    // 设置颜色
    setcolor(WHITE);
    
    // 使用内置圆函数
    circle(xc, yc, radius);
    
    // 也可以使用中点圆算法手动绘制
    // midPointCircle(xc, yc, radius);
    
    getch();
    closegraph();
}

// 中点圆算法实现
void midPointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;
    
    while (x <= y) {
        // 八分对称性绘制8个点
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    int xc = 320, yc = 240, radius = 100;
    drawCircleGraphics(xc, yc, radius);
    return 0;
}