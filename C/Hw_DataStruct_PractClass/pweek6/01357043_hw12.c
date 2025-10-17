#include <stdio.h>

static inline int max(int a, int b) { return a > b ? a : b; }
static inline int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    if (scanf("%d %d %d %d %d %d %d %d",
              &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != 8)
        return 0;

    // normalize each rectangle to (xmin, xmax, ymin, ymax)
    int ax1 = min(x1, x2), ax2 = max(x1, x2);
    int ay1 = min(y1, y2), ay2 = max(y1, y2);

    int bx1 = min(x3, x4), bx2 = max(x3, x4);
    int by1 = min(y3, y4), by2 = max(y3, y4);

    // overlap width/height on standard Cartesian plane
    int w = min(ax2, bx2) - max(ax1, bx1);
    int h = min(ay2, by2) - max(ay1, by1);

    int area = (w > 0 && h > 0) ? w * h : 0;
    printf("%d\n", area);
    return 0;
}
