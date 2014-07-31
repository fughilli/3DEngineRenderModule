#include "G3DUtilities.h"
//#include "Camera3D.h"

#include <limits>

Vector3d Triangle3d::normal(void)
    {
        return ((B-A).cross(C-A)).unit();
    }

    Triangle3d Triangle3d::transform(float scale, const Quaternion& rot, const Vector3d& trans)
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

    Triangle3d Triangle3d::center()
    {
        Triangle3d ret = *this;

        Vector3d average = (A + B + C) / 3;
        ret.A -= average;
        ret.B -= average;
        ret.C -= average;

        return ret;
    }

Vector3d lineAndPlaneIntersection(Vector3d L_0, Vector3d L_d, Vector3d P_0, Vector3d P_n)
{
    float _fac = (P_0 - L_0).dot(P_n)/L_d.dot(P_n);
    return (L_0 + (L_d * _fac));
}

Triangle2d projectTri3d(Camera3d& camera, Triangle3d tri)
{
    Vector3d L_0, L_d, P_0, P_n, Z_v, U_v, C_u, C_r;

    Triangle2d ret_tri;

    P_0 = camera.getPos();
    P_n = Vector3d::zero - camera.forward.rotate(camera.getRot());
    C_u = Vector3d::zero - camera.up.rotate(camera.getRot());
    C_r = C_u.cross(P_n);

    P_n *= camera.focalLength;

    L_0 = tri.A;
    L_d = ((P_n + P_0) - tri.A).unit();

    Z_v = lineAndPlaneIntersection(L_0, L_d, P_0, P_n);

    ret_tri.A.x = (Z_v - P_0).dot(C_r);
    ret_tri.A.y = (Z_v - P_0).dot(C_u);

    L_0 = tri.B;
    L_d = ((P_n + P_0) - tri.B).unit();

    Z_v = lineAndPlaneIntersection(L_0, L_d, P_0, P_n);

    ret_tri.B.x = (Z_v - P_0).dot(C_r);
    ret_tri.B.y = (Z_v - P_0).dot(C_u);

    L_0 = tri.C;
    L_d = ((P_n + P_0) - tri.C).unit();

    Z_v = lineAndPlaneIntersection(L_0, L_d, P_0, P_n);

    ret_tri.C.x = (Z_v - P_0).dot(C_r);
    ret_tri.C.y = (Z_v - P_0).dot(C_u);

    return ret_tri;
}

Vector2d projectPoint3d(Camera3d& camera, Vector3d point)
{
    Vector3d L_0, L_d, P_0, P_n, Z_v, U_v, C_u, C_r;

    Vector2d ret_vec;

    P_0 = camera.getPos();
    P_n = Vector3d::zero - camera.forward.rotate(camera.getRot());
    C_u = camera.up.rotate(camera.getRot());
    C_r = C_u.cross(P_n);

    P_n *= camera.focalLength;

    L_0 = point;
    L_d = ((P_n + P_0) - point).unit();

    Z_v = lineAndPlaneIntersection(L_0, L_d, P_0, P_n);

    ret_vec.x = (Z_v - P_0).dot(C_r);
    ret_vec.y = (Z_v - P_0).dot(C_u);

    return ret_vec;
}

Vector3d rayAndTriangleIntersection(Vector3d R_0, Vector3d R_d, Triangle3d tri)
{
    Vector3d AB = (tri.B - tri.A).unit();
    Vector3d BC = (tri.B - tri.C).unit();
    Vector3d CA = (tri.C - tri.A).unit();
    
    Vector3d norm = tri.normal();
    
    Vector3d point = lineAndPlaneIntersection(R_0, R_d, tri.A, tri.normal());

    if ((point - R_0).dot(R_d) >= 0)
    {
        Vector3d AP = (point - tri.A).unit();
        Vector3d BP = (point - tri.B).unit();
        Vector3d CP = (point - tri.C).unit();
        
        int a = AP.cross(AB).dot(tri.normal());
        int b = BP.cross(BC).dot(tri.normal());
        int c = CP.cross(CA).dot(tri.normal());   

        if ((a >= 0) == (b >= 0) == (c >= 0))
        {
            return point;
        }
        else
        {
            float nan = std::numeric_limits<double>::quiet_NaN();
            return Vector3d(nan, nan, nan);
        }
    }
    else
    {
            float nan = std::numeric_limits<double>::quiet_NaN();
            return Vector3d(nan, nan, nan);
    }
}

