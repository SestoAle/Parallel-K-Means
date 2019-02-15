//
// Created by Alessandro Sestini on 08/11/17.
//

#ifndef K_MEANS_MIO_CPP_POINT_H
#define K_MEANS_MIO_CPP_POINT_H


#include <printf.h>

class Point {

public:
    Point(double x_coord, double y_coord){
        this->x_coord = x_coord;
        this->y_coord = y_coord;
        cluster_id = 0;
    }

    Point(){
        x_coord = 0;
        y_coord = 0;
        cluster_id = 0;
    }

    double get_x_coord(){
        return this->x_coord;
    }

    double get_y_coord(){
        return this->y_coord;
    }

    int get_cluster_id(){
        return cluster_id;
    }

    void set_cluster_id(int cluster_id){
        this->cluster_id = cluster_id;
    }

private:
    double x_coord;
    double y_coord;
    //Cluster id of this Point
    int cluster_id;
};


#endif //K_MEANS_MIO_CPP_POINT_H
