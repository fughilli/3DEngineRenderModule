#ifndef CAMERA3D_H
#define CAMERA3D_H

#include "Object3D.h"
#include "../VectorLib/Vector.h"

class Camera3d : public Object3d
{
public:
    float focalLength;
    Vector3d forward;
    Vector3d up;

    void scale(float sFactor) {}
    float getScale(void) const
    {
        return 1;
    }
    void setScale(float _scale) {}
};

#endif // CAMERA3D_H
