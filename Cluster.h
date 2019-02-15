//
// Created by Alessandro Sestini on 08/11/17.
//

#ifndef K_MEANS_MIO_CPP_CLUSTER_H
#define K_MEANS_MIO_CPP_CLUSTER_H


#include <queue>
#include "Point.h"
#include <omp.h>

class Cluster {
public:
    Cluster(double x_coord, double y_coord){
        new_x_coord = 0;
        new_y_coord = 0;
        size = 0;
        this->x_coord = x_coord;
        this->y_coord = y_coord;
    }

    Cluster(){
        new_x_coord = 0;
        new_y_coord = 0;
        size = 0;
        this->x_coord = 0;
        this->y_coord = 0;
    }

    void add_point(Point point){
#pragma omp atomic
        new_x_coord += point.get_x_coord();
#pragma omp atomic
        new_y_coord += point.get_y_coord();
#pragma omp atomic
        size++;
    }

    void free_point(){
        this->size = 0;
        this->new_x_coord = 0;
        this->new_y_coord = 0;
    }

    double get_x_coord(){
        return this->x_coord;
    }

    double get_y_coord(){
        return this->y_coord;
    }

    bool update_coords(){


        if(this->x_coord == new_x_coord/this->size && this->y_coord == new_y_coord/this->size){
            return false;
        }

        this->x_coord = new_x_coord/this->size;
        this->y_coord = new_y_coord/this->size;

        return true;

    }

private:
    double x_coord;
    double y_coord;
    //Accumulate the Point coords here
    double new_x_coord;
    double new_y_coord;
    //Number of points inside this Cluster
    int size;

};


#endif //K_MEANS_MIO_CPP_CLUSTER_H