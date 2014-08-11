#ifndef G3D_UTILS_H
#define G3D_UTILS_H

#include "../VectorLib/Vector.h"
#include "Camera3D.h"

struct Triangle2d
{
    Vector2d A;
    Vector2d B;
    Vector2d C;
};

struct Line2d
{
    Vector2d A, B;
};

class Triangle3d
{
public:
    Vector3d A, B, C;

    Vector3d normal(void);

    Triangle3d transform(float scale, const Quaternion& rot, const Vector3d& trans);

    Triangle3d center();
};


Vector2d projectPoint3d(Camera3d& camera, Vector3d point);
Triangle2d projectTri3d(Camera3d& camera, Triangle3d tri);
Vector3d lineAndPlaneIntersection(Vector3d L_0, Vector3d L_d, Vector3d P_0, Vector3d P_n);

Vector3d rayAndTriangleIntersection(Vector3d R_0, Vector3d R_d, Triangle3d);


#endif // G3D_UTILS_H
