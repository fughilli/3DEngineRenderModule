#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <stdint.h>
#include "../VectorLib/Vector.h"

//class Camera3d;
//class DisplayInterface;
//class Triangle3d;

class Object3d
{
protected:
    float oscale;
    Vector3d position;
    Quaternion orientation;
public:
    Object3d();
    Object3d(float scale, Vector3d pos, Quaternion rot);

    virtual void translate(const Vector3d& movVec);
    virtual void rotate(const Quaternion& rotQuat);
    virtual void scale(float sFactor);

    virtual Vector3d getPos(void) const;
    virtual Quaternion getRot(void) const;
    virtual float getScale(void) const;

    virtual void setPos(const Vector3d& _pos);
    virtual void setRot(const Quaternion& _rot);
    virtual void setScale(float _scale);
};

#endif // OBJECT3D_H
