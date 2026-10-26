#include <stdio.h>
#include <math.h>

void drawCircleConsole(int radius) {
    int diameter = radius * 2;
    char canvas[diameter + 1][diameter * 2 + 1];
    
    // 初始化画布为空格
    for (int y = 0; y <= diameter; y++) {
        for (int x = 0; x <= diameter * 2; x++) {
            canvas[y][x] = ' ';
        }
    }
    
    // 使用中点圆算法绘制圆
    for (int angle = 0; angle < 360; angle++) {
        double rad = angle * M_PI / 180.0;
        int x = (int)(radius + radius * cos(rad) * 2 + 0.5);  // *2 因为字符宽高比约1:2
        int y = (int)(radius + radius * sin(rad) + 0.5);
        if (x >= 0 && x <= diameter * 2 && y >= 0 && y <= diameter) {
            canvas[y][x] = '*';
        }
    }
    
    // 输出画布
    for (int y = 0; y <= diameter; y++) {
        for (int x = 0; x <= diameter * 2; x++) {
            putchar(canvas[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    int radius;
    printf("请输入圆的半径 (建议 5-20): ");
    scanf("%d", &radius);
    
    if (radius < 1) radius = 10;
    if (radius > 30) radius = 30;
    
    printf("\n绘制半径为 %d 的圆:\n\n", radius);
    drawCircleConsole(radius);
    
    return 0;
}