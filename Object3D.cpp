#include "Object3D.h"

void Object3d::rotate(Quaternion rotQuat)
{
    orientation *= rotQuat;
}

void Object3d::translate(Vector3d movVec)
{
    position += movVec;
}

void Object3d::scale(float sFactor)
{
    oscale*=sFactor;
}

Vector3d Object3d::getPos(void)
{
    return position;
}

Quaternion Object3d::getRot(void)
{
    return orientation;
}

float Object3d::getScale(void)
{
    return oscale;
}

void Object3d::setPos(Vector3d _pos)
{
    position = _pos;
}

void Object3d::setRot(Quaternion _rot)
{
    orientation = _rot;
}

void Object3d::setScale(float _scale)
{
    oscale = _scale;
}

void MeshObject3d::draw(Camera3d& camera, DisplayInterface& _di)
{
    tri_2d_t temp;
    for(int i = 0; i < numTris; i++)
    {
        temp = projectTri3d(camera, mesh[i].transform(oscale, orientation, position));
        _di.drawTri(temp, grayscaleToColor(255));
    }
}
