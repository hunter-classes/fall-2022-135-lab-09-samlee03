#include <iostream>
#include "funcs.h"
#include "cmath"
#include "coord3d.h"
// add functions here

double length(Coord3D *p){
    Coord3D point = *p;
    double distance = (point.x * point.x) + (point.y * point.y) + (point.z * point.z);
    return sqrt(distance);
}

Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    Coord3D point1 = *p1;
    Coord3D point2 = *p2;
    if (length(p1) < length(p2)){
        return p2;
    } else {
        return p1;
    }
}
void move(Coord3D *ppos, Coord3D *pvel, double dt){
    Coord3D new_pos = *ppos;
    // std::cout << new_pos.x;
    //copy
    Coord3D point = *ppos;
    Coord3D velocity = *pvel;
    //std::cout << point.x << ", " << point.y << ", " << point.z << "\n";
    double x = point.x + (velocity.x * dt);
    double y = point.y + (velocity.y * dt);
    double z = point.z + (velocity.z * dt);

    *ppos = {x, y, z};
    // std::cout << point.x << ", " << point.y << ", " << point.z << "\n";
}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *coord3D = new Coord3D();
    *coord3D = {x, y, z};

    return coord3D;
}
void deleteCoord3D(Coord3D *p) {
    delete p;
}