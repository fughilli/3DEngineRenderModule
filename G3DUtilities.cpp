#include "G3DUtilities.h"
//#include "Camera3D.h"

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
