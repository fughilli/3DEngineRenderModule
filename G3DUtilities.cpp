#include "Energia.h"
#include "G3DUtilities.h"
#include "Camera3D.h"

Vector3d lineAndPlaneIntersection(Vector3d L_0, Vector3d L_d, Vector3d P_0, Vector3d P_n)
{
    float _fac = (P_0 - L_0).dot(P_n)/L_d.dot(P_n);
    return (L_0 + ((_fac) * L_d));
}

tri_2d_t projectTri3d(Camera3d& camera, Triangle3d tri)
{
    Vector3d L_0, L_d, P_0, P_n, Z_v, U_v, C_u, C_r;

    tri_2d_t ret_tri;

    P_0 = camera.getPos();
    P_n = -camera.forward.rotate(camera.getRot());
    C_u = camera.up.rotate(camera.getRot());
    C_r = C_u.cross(P_n);

    P_n *= camera.focalLength;

    L_0 = tri.A;
    L_d = ((P_n + P_0) - tri.A).unit();

    Z_v = lineAndPlaneIntersection(L_0, L_d, P_0, P_n);

    ret_tri.x1 = (Z_v - P_0).dot(C_r);
    ret_tri.y1 = (Z_v - P_0).dot(C_u);

    L_0 = tri.B;
    L_d = ((P_n + P_0) - tri.B).unit();

    Z_v = lineAndPlaneIntersection(L_0, L_d, P_0, P_n);

    ret_tri.x2 = (Z_v - P_0).dot(C_r);
    ret_tri.y2 = (Z_v - P_0).dot(C_u);

    L_0 = tri.C;
    L_d = ((P_n + P_0) - tri.C).unit();

    Z_v = lineAndPlaneIntersection(L_0, L_d, P_0, P_n);

    ret_tri.x3 = (Z_v - P_0).dot(C_r);
    ret_tri.y3 = (Z_v - P_0).dot(C_u);

    return ret_tri;
}

Vector2d projectPoint3d(Camera3d& camera, Vector3d point)
{
    Vector3d L_0, L_d, P_0, P_n, Z_v, U_v, C_u, C_r;

    Vector2d ret_vec;

    P_0 = camera.getPos();
    P_n = -camera.forward.rotate(camera.getRot());
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
