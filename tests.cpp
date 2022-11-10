#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"


// add your tests here
TEST_CASE("Test Length of Vector function"){
    Coord3D point = {5, 10, 20};
    CHECK((length(&point) - 22.9128784747792) < 0.0001);
    point = {1, 2, 3};
    CHECK((length(&point) - 3.7416573867739413) < 0.0001);
    point = {-41, 0, 26};
    CHECK((length(&point) - 48.54894437575342) < 0.0001);
}
TEST_CASE("Test Further from Origin function"){
    Coord3D p1 = {1, 2, 3};
    Coord3D p2 = {2, 3, 4};
    CHECK(fartherFromOrigin(&p1, &p2) == &p2);
    p1 = {5, -2, 9}; // 10.4
    p2 = {10, 0, -7}; // 12
    CHECK(fartherFromOrigin(&p1, &p2) == &p2);
    p1 = {-230, 70, -50}; // 245.5
    p2 = {-100, -100, -1}; // 141
    CHECK(fartherFromOrigin(&p1, &p2) == &p1);
}
TEST_CASE("Test move function"){
    Coord3D position = {0, 0, 0};
    Coord3D velocity = {1, 1, 1};
    move(&position, &velocity, 5);
    CHECK((position.x == 5 && position.y == 5 && position.z == 5));

    position = {-100, 58, 216};
    velocity = {22, -1, 17};
    move(&position, &velocity, 10);
    CHECK((position.x == 120 && position.y == 48 && position.z == 386));
}

TEST_CASE("Test Creating and Deleting Object functions"){
    Coord3D *point1 = createCoord3D(1, 2, 3);
    Coord3D *point2 = createCoord3D(-12, 50, 70);
    Coord3D *point3 = createCoord3D(-129, -500, -980);

    CHECK(((*point1).x == 1 && (*point1).y == 2 && (*point1).z == 3));
    deleteCoord3D(point1);
    CHECK((*point1).x != 1); 
    CHECK(((*point2).x == -12 && (*point2).y == 50 && (*point2).z == 70));
    deleteCoord3D(point2);
    CHECK((*point2).x != -12);
    CHECK(((*point3).x == -129 && (*point3).y == -500 && (*point3).z == -980));
    deleteCoord3D(point3);
    CHECK((*point3).x != -129);
}