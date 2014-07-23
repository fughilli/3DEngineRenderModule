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

    Vector3d normal(void)
    {
        return ((B-A).cross(C-A)).unit();
    }

    Triangle3d transform(float scale, const Quaternion& rot, const Vector3d& trans)
    {
        Triangle3d ret = *this;

        ret.A *= scale;
        ret.B *= scale;
        ret.C *= scale;

        ret.A = ret.A.rotate(rot);
        ret.B = ret.B.rotate(rot);
        ret.C = ret.C.rotate(rot);

        ret.A += trans;
        ret.B += trans;
        ret.C += trans;

        return ret;
    }

    Triangle3d center()
    {
        Triangle3d ret = *this;

        Vector3d average = (A + B + C) / 3;
        ret.A -= average;
        ret.B -= average;
        ret.C -= average;

        return ret;
    }
};

Vector2d projectPoint3d(Camera3d& camera, Vector3d point);
Triangle2d projectTri3d(Camera3d& camera, Triangle3d tri);
Vector3d lineAndPlaneIntersection(Vector3d L_0, Vector3d L_d, Vector3d P_0, Vector3d P_n);

#endif // G3D_UTILS_H
