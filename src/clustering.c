#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "clustering.h"

typedef struct {
    int *points;  
    int size;     
} Cluster;

double euclidean_distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double cluster_distance(Point *points, Cluster c1, Cluster c2) {
    double min_dist = DBL_MAX;
    for (int i = 0; i < c1.size; i++) {
        for (int j = 0; j < c2.size; j++) {
            double dist = euclidean_distance(points[c1.points[i]], points[c2.points[j]]);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }
    return min_dist;
}

void merge_clusters(Cluster *clusters, int c1, int c2, int *cluster_count) {
    int new_size = clusters[c1].size + clusters[c2].size;
    int *new_points = malloc(new_size * sizeof(int));

    for (int i = 0; i < clusters[c1].size; i++) {
        new_points[i] = clusters[c1].points[i];
    }
    for (int i = 0; i < clusters[c2].size; i++) {
        new_points[clusters[c1].size + i] = clusters[c2].points[i];
    }

    free(clusters[c1].points);
    clusters[c1].points = new_points;
    clusters[c1].size = new_size;

    free(clusters[c2].points);
    
    clusters[c2] = clusters[*cluster_count - 1];  
    
    (*cluster_count)--;  
}

void print_cluster_points(Point *points, Cluster cluster) {
    printf("Координаты точек: ");
    for (int i = 0; i < cluster.size; i++) {
        printf("(%.1f, %.1f) ", points[cluster.points[i]].x, points[cluster.points[i]].y);
    }
    printf("\n");
}


void agglomerative_clustering(Point *points, int n) {
    Cluster *clusters = malloc(n * sizeof(Cluster));
    for (int i = 0; i < n; i++) {
        clusters[i].points = malloc(sizeof(int));
        clusters[i].points[0] = i;
        clusters[i].size = 1;
    }

    int cluster_count = n;
    int step = 1;

    while (cluster_count > 1) {
        int c1 = -1, c2 = -1;
        double min_dist = DBL_MAX;

        for (int i = 0; i < cluster_count; i++) {
            for (int j = i + 1; j < cluster_count; j++) {
                double dist = cluster_distance(points, clusters[i], clusters[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    c1 = i;
                    c2 = j;
                }
            }
        }

        printf("Шаг %d: объединяем кластеры %d и %d      %d\n", step++, c1, c2, cluster_count);
        printf("Кластер %d: ", c1);
        print_cluster_points(points, clusters[c1]);
        printf("Кластер %d: ", c2);
        print_cluster_points(points, clusters[c2]);
        merge_clusters(clusters, c1, c2, &cluster_count);
    }

    for (int i = 0; i < cluster_count; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}
