
typedef signed int SI4;
typedef signed long long int SI8;
typedef unsigned char UI1;
typedef unsigned int UI4;

#define MASTER_MAX( value1, value2 ) (((value1) > (value2)) ? (value1) : (value2))
#define MASTER_MIN( value1, value2 ) (((value1) < (value2)) ? (value1) : (value2))
#define MASTER_IMAX( value1, value2 ) (value1) = MASTER_MAX(value1, value2)
#define MASTER_IMIN( value1, value2 ) (value1) = MASTER_MIN(value1, value2)

typedef struct {
    SI4 x;
    SI4 y;
} Point;

SI4
compare_points( const void * data1, const void * data2 ) {
    const Point * p1 = (const Point *)data1;
    const Point * p2 = (const Point *)data2;
    if (p1->x != p2->x)
        return (p1->x < p2->x) ? (-1) : (+1);
    if (p1->y != p2->y)
        return (p1->y < p2->y) ? (-1) : (+1);
    return 0;
}

#include <limits.h>

UI1
isRectangleCover( SI4** rectangles, SI4 rectanglesSize, SI4 * rectanglesColSize ) {
    Point * container = malloc(rectanglesSize * 4 * sizeof(Point));
    Point corners[4];
    UI1 cornerPtr = 0;
    UI4 containerPtr = 0;
    SI8 sumArea = 0;
    UI4 index = 0;
    UI4 jndex;
    SI4 x1;
    SI4 y1;
    SI4 x2;
    SI4 y2;
    SI4 bigX1 = INT_MAX;
    SI4 bigY1 = INT_MAX;
    SI4 bigX2 = INT_MIN;
    SI4 bigY2 = INT_MIN;
    for (; index < rectanglesSize; index += 1) {
        x1 = rectangles[index][0];
        y1 = rectangles[index][1];
        x2 = rectangles[index][2];
        y2 = rectangles[index][3];
        sumArea += (SI8)(x2 - x1) * (SI8)(y2 - y1);
        MASTER_IMIN(bigX1, x1);
        MASTER_IMAX(bigX2, x2);
        MASTER_IMIN(bigY1, y1);
        MASTER_IMAX(bigY2, y2);
        container[containerPtr].x = x1;
        container[containerPtr].y = y1;
        container[(containerPtr += 1)].x = x1;
        container[containerPtr].y = y2;
        container[(containerPtr += 1)].x = x2;
        container[containerPtr].y = y1;
        container[(containerPtr += 1)].x = x2;
        container[containerPtr].y = y2;
		containerPtr += 1;
    }
    if (sumArea != (SI8)(bigX2 - bigX1) * (SI8)(bigY2 - bigY1)) {
        free(container);
        return 0;
    }
    qsort(container, containerPtr, sizeof(Point), compare_points);
    for (index = 0; index < containerPtr;) {
        jndex = index + 1;
        while (jndex < containerPtr && container[index].x == container[jndex].x && container[index].y == container[jndex].y)
            jndex += 1;
        if ((jndex - index) & 1) {
            if (cornerPtr >= 4) {
                free(container);
                return 0;
            }
            corners[cornerPtr] = container[index];
            cornerPtr += 1;
        }
        index = jndex;
    }
    free(container);
    if (cornerPtr != 4)
        return 0;
    return corners[0].x == bigX1 && corners[0].y == bigY1 &&
           corners[1].x == bigX1 && corners[1].y == bigY2 &&
           corners[2].x == bigX2 && corners[2].y == bigY1 &&
           corners[3].x == bigX2 && corners[3].y == bigY2;
}