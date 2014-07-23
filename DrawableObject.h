#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "Camera3D.h"
#include "DisplayInterface.h"

class DrawableObject3d : public Object3d
{
public:
    virtual void draw(Camera3d& camera, DisplayInterface& _di) = 0;
};

class MeshObject3d : public DrawableObject3d
{
public:
    Triangle3d * mesh;
    uint16_t numTris;
    virtual void draw(Camera3d& camera, DisplayInterface& _di);
    virtual void draw(Camera3d& camera, DisplayInterface& _di, const Vector3d& directLight);
};

#endif // DRAWABLE_OBJECT_H
