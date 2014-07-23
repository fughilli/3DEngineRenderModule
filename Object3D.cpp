#include "Object3D.h"

Object3d::Object3d()
{
    oscale = 1;
    orientation = Quaternion::identity;
    position = Vector3d::zero;
}

Object3d::Object3d(float scale, Vector3d pos, Quaternion rot)
{
    oscale = scale;
    orientation = rot;
    position = pos;
}

void Object3d::rotate(const Quaternion& rotQuat)
{
    orientation *= rotQuat;
}

void Object3d::translate(const Vector3d& movVec)
{
    position += movVec;
}

void Object3d::scale(float sFactor)
{
    oscale*=sFactor;
}

Vector3d Object3d::getPos(void) const
{
    return position;
}

Quaternion Object3d::getRot(void) const
{
    return orientation;
}

float Object3d::getScale(void) const
{
    return oscale;
}

void Object3d::setPos(const Vector3d& _pos)
{
    position = _pos;
}

void Object3d::setRot(const Quaternion& _rot)
{
    orientation = _rot;
}

void Object3d::setScale(float _scale)
{
    oscale = _scale;
}
