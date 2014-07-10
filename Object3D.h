#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "G3DUtilities.h"

class Object3d
{
protected:
    float oscale;
    Vector3d position;
    Quaternion orientation;
public:
    virtual void translate(Vector3d movVec);
    virtual void rotate(Quaternion rotQuat);
    virtual void scale(float sFactor);

    virtual Vector3d getPos(void);
    virtual Quaternion getRot(void);
    virtual float getScale(void);

    virtual void setPos(Vector3d _pos);
    virtual void setRot(Quaternion _rot);
    virtual void setScale(float _scale);
};

class DrawableObject3d : public Object3d
{
public:

//protected:
    virtual void draw(Camera3d& camera, DisplayInterface& _di);
};

class MeshObject3d : public DrawableObject3d
{
public:
    Triangle3d * mesh;
    uint16_t numTris;
//protected:
    virtual void draw(Camera3d& camera, DisplayInterface& _di);
};

#endif // OBJECT3D_H
