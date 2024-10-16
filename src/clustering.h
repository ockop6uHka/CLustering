#ifndef CLUSTERING_H
#define CLUSTERING_H

typedef struct {
    double x, y;
} Point;


void agglomerative_clustering(Point *points, int n);

#endif
