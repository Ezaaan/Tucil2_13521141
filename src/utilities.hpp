#ifndef __UTILITIES__HPP__
#define __UTILITIES__HPP__

#include "point.cpp"

#define MAX_ARR 1000
#define MIN_COOR -1000
#define MAX__COOR 1000

void quicksort(Point arr[], int n);

void BruteForce(Point arr[], int n);

void DivideAndConquer(Point arr[], int n);

void split(Point parent[], Point child1[], Point child2[], int n);

#endif