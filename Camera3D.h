#ifndef CAMERA3D_H
#define CAMERA3D_H

#include "Object3D.h"

class Camera3d : public Object3d
{
public:
    float focalLength;
    Vector3d forward;
    Vector3d up;
};

#endif // CAMERA3D_H
