#include <iostream>
#include "funcs.h"
#include "coord3d.h"
int main()
{
  //Task A
  std::cout << "Task A \n\n";
  Coord3D point = {18, -50, 39};
  std::cout << "Length of point (" << point.x << ", " << point.y << ", " << point.z << ")\n";
  std::cout << length(&point) << std::endl << std::endl;; // 65.91661399070799

  //Task B
  std::cout << "Task B \n\n";
  Coord3D p1 = {23, -59, -21};
  Coord3D p2 = {-3, 70, 123};

  std::cout << "Point 1: (" << p1.x << ", " << p1.y << ", " << p1.z << "), " << &p1 << "\n";
  std::cout << "Point 2: (" << p2.x << ", " << p2.y << ", " << p2.z << "), " << &p2 << "\n";
  std::cout << "Address Further from Origin = " << fartherFromOrigin(&p1, &p2) << std::endl;

  //Task C & E
  std::cout << "Task C & E\n\n";
  // Coord3D pointP = {10, 20, 30};
  Coord3D *pointP = createCoord3D(10, 20, 30);
  // Coord3D pointQ = {-20, 21, -22};
  Coord3D *velocity = createCoord3D(0, 5, -3);
  std::cout << "Vel: (" << (*velocity).x << ", " << (*velocity).y << ", " << (*velocity).z << "), Time: 10\n";
  std::cout << "Point Before:\n";
  std::cout << (*pointP).x << ", " << (*pointP).y << ", " << (*pointP).z << std::endl;
  move(pointP, velocity, 10.0);
  std::cout << "Point After:\n";
  std::cout << (*pointP).x << ", " << (*pointP).y << ", " << (*pointP).z << std::endl;
  deleteCoord3D(pointP);
  deleteCoord3D(velocity);
  std::cout << "Released Memory.\n";
}
