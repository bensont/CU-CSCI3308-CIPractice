/*
 * geometry.c
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * This file contains a simple geomtery functions.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

#include "geometry.h"

#define FUZZY_EQ 0.01

#define DEBUG(file, line, func, msg) fprintf(stderr, "DEBUG - %s_%d_%s: %s", file, line, func, msg);

double coord_2d_dist(const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return NAN;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return NAN;
    }

    /* Maths */
    return sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));

}

bool coord_2d_eq(const coord_2d_t* a, const coord_2d_t* b){

    /* Equal if dist <= FUZZY_EQ */
    if(coord_2d_dist(a, b) <= FUZZY_EQ){
        return true;
    }
    else{
        return false;
    }

}

void coord_2d_midpoint(coord_2d_t* mid, const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!mid){
        DEBUG(__FILE__, __LINE__, __func__, "'mid' must not be NULL");
        return;
    }
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return;
    }

    /* Maths */
    mid->x = ((a->x + b->x) / 2.0 );
    mid->y = ((a->y + b->y) / 2.0 );

}

double cord_2d_area_triangle(const coord_2d_t* a, const coord_2d_t* b, const coord_2d_t* c){
  double this_area;
  double this_height;
  double this_base;

  /* Find the midpoint between b and c for height base point*/
  coord_2d_t this_midpoint;
  coord_2d_midpoint(&this_midpoint, b, c);
  /* Find the distance between the midpoint and a for height*/
  this_height = coord_2d_dist(a,&this_midpoint);

  /* Find the distance between b and c for base*/
  this_base = coord_2d_dist(b,c);

  /* Find the area of the tiangle */
  this_area = (this_base * this_height) / 2;
  return this_area;
}
