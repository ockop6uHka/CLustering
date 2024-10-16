#include <stdio.h>
#include "clustering.h"

int main() {
    Point points[] = {
        {0.0, 0.0}, {1.0, 1.0}, {5.0, 5.0}, {6.0, 6.0}, {8.0, 8.0}
    };
    int n = sizeof(points) / sizeof(points[0]);

    Point points2[] = {
        {2.0, 3.0}, {3.0, 4.0}, {5.0, 6.0}, {8.0, 8.0}, {10.0, 12.0},
        {12.0, 14.0}, {15.0, 15.0}, {18.0, 18.0}, {20.0, 22.0}, {25.0, 25.0}
    };
    int n2 = sizeof(points2) / sizeof(points2[0]);

    Point points3[] = {
        {0.0, 0.0}, {1.0, 1.0}, {10.0, 10.0}, {11.0, 11.0}, 
        {20.0, 20.0}, {21.0, 21.0}, {30.0, 30.0}, {31.0, 31.0}
    };
    int n3 = sizeof(points3) / sizeof(points3[0]);

    Point points4[] = {
        {1.2, 3.4}, {2.3, 3.5}, {5.6, 7.8}, {8.1, 9.2}, {2.4, 2.8}, {9.3, 8.7}, {10.5, 11.2},
        {6.7, 5.4}, {7.3, 2.9}, {3.8, 1.6}, {11.1, 12.3}, {13.5, 14.7}, {15.2, 16.8},
        {17.4, 18.2}, {19.6, 20.8}, {22.1, 23.5}, {24.2, 25.4}, {26.8, 27.3}, {29.1, 30.5}, {32.2, 33.4}
    };
    int n4 = sizeof(points4) / sizeof(points4[0]);

    Point points5[] = {
        {0.0, 0.0}, {0.1, 0.2}, {0.2, 0.3}, {0.3, 0.4}, {0.4, 0.5}, {100.0, 100.0}
    };
    int n5 = sizeof(points5) / sizeof(points5[0]);

    Point points6[] = {
        {0.0, 0.0}, {1.0, 0.0}, {2.0, 0.0}, {3.0, 0.0}, {4.0, 0.0}, {5.0, 0.0}, {6.0, 0.0}, {7.0, 0.0}, {8.0, 0.0}, {9.0, 0.0}
    };
    int n6 = sizeof(points6) / sizeof(points6[0]);


    printf("Иерархическая кластеризация (агломеративный метод)\n\n");
    
    printf("Тест 1: Набор из 5 точек\n\n");
    agglomerative_clustering(points, n);
    printf("\n--------------------------------------\n\n");

    printf("Тест 2: Набор из 10 точек\n\n");
    agglomerative_clustering(points2, n2);
    printf("\n--------------------------------------\n\n");

    printf("Тест 3: Разделенные группы точек\n");
    agglomerative_clustering(points3, n3);
    printf("\n--------------------------------------\n\n");

    printf("Тест 4: Набор из 20 случайных точек\n");
    agglomerative_clustering(points4, n4);
    printf("\n--------------------------------------\n\n");

    printf("Тест 5: Плотная группа точек и одна удаленная точка\n");
    agglomerative_clustering(points5, n5);
    printf("\n--------------------------------------\n\n");

    printf("Тест 6: Выровненные в одну линию точки\n");
    agglomerative_clustering(points6, n6);
    printf("\n");


    return 0;
}
