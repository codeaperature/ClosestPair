//
//  https://www.codeeval.com/open_challenges/51/
//  closestpair
//
//  Created by Stephan Warren on 12/25/14.
//  Copyright (c) 2014 Stephan Warren. All rights reserved.
//
/*
 
 CLOSEST PAIR
 CHALLENGE DESCRIPTION:
 
 Credits: Programming Challenges by Steven S. Skiena and Miguel A. Revilla
 
 You will be given the x/y co-ordinates of several locations. You will be laying out 1 cable between two of these locations. In order to minimise the cost, your task is to find the shortest distance between a pair of locations, so that pair can be chosen for the cable installation.
 
 INPUT SAMPLE:
 
 Your program should accept as its first argument a path to a filename. The input file contains several sets of input. Each set of input starts with an integer N (0<=N<=10000), which denotes the number of points in this set. The next N line contains the coordinates of N two-dimensional points. The first of the two numbers denotes the X-coordinate and the latter denotes the Y-coordinate. The input is terminated by a set whose N=0. This set should not be processed. The value of the coordinates will be less than 40000 and non-negative. eg.
 
 
 5
 0 2
 6 67
 43 71
 39 107
 189 140
 0
 OUTPUT SAMPLE:
 
 For each set of input produce a single line of output containing a floating point number (with four digits after the decimal point) which denotes the distance between the closest two points. If there is no such two points in the input whose distance is less than 10000, print the line INFINITY. eg.
 
 
 
 36.2215
 
*/




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {int x; int y;} point_t;

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    //    printf("FILE * = %p\n", file);
    int cnt;
    double closest;
    double squarert;
    unsigned long losqrt;
    int dx, dy;
    while(fscanf(file, "%d", &cnt) == 1) {
        if(cnt == 0) break;
        closest = (double) 10000.1;
        losqrt = ULONG_MAX;
        point_t * pt = (point_t *) malloc(cnt * sizeof(point_t));
        for(short i = 0; i < cnt; i++) {
            if(fscanf(file, "%d %d", &pt[i].x, &pt[i].y) != 2) printf("Prob\n");
        }
        for(short i = 0; i < cnt - 1; i++) {
            for(short j = i+1; j < cnt; j++) {
                dx = pt[i].x - pt[j].x;
                dy = pt[i].y - pt[j].y;
                unsigned long sqs = ((long) (dx * dx) + (long) (dy * dy));
                if(losqrt > sqs) {
                    losqrt = sqs;
                    squarert = sqrt((double) sqs);
//                    printf("(%d, %d), (%d, %d) = sq = %0.4lf, closest = %0.4lf\n",
//                           pt[i].x, pt[i].y, pt[j].x, pt[j].y, squarert, closest);
                    if(squarert < closest) closest = squarert;
                }
            }
        }
        
        if(closest < 10000.0) printf("%0.4lf\n", closest);
        else printf("INFINITY\n");
    }
    return 0;
}
