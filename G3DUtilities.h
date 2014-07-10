#ifndef G3D_UTILS_H
#define G3D_UTILS_H

#include "Energia.h"
#include "../Vector/Vector.h"
#include "Camera3D.h"

struct tri_2d_t
{
    float x1,x2,x3,y1,y2,y3;
};

class Triangle3d
{
public:
    Vector3d A, B, C;

    Vector3d normal(void)
    {
        return ((B-A).cross(C-A)).unit();
    }

    Triangle3d transform(float scale, Quaternion rot, Vector3d trans)
    {
        Triangle3d ret = *this;

        ret.A *= scale;
        ret.B *= scale;
        ret.C *= scale;

        ret.A.rotate(rot);
        ret.B.rotate(rot);
        ret.C.rotate(rot);

        ret.A += trans;
        ret.B += trans;
        ret.C += trans;

        return ret;
    }
};

Vector2d projectPoint3d(Camera3d& camera, Vector3d point);
tri_2d_t projectTri3d(Camera3d& camera, Triangle3d tri);
Vector3d lineAndPlaneIntersection(Vector3d L_0, Vector3d L_d, Vector3d P_0, Vector3d P_n);

#endif // G3D_UTILS_H
