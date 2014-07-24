#include "DrawableObject.h"

void MeshObject3d::draw(Camera3d& camera, DisplayInterface& _di)
{
    draw(camera, _di, Vector3d::one);
}

void MeshObject3d::draw(Camera3d& camera, DisplayInterface& _di, const Vector3d& directLight)
{
    Triangle2d temp;
    for(int i = 0; i < numTris; i++)
    {
        Triangle3d modifiedMeshTri = mesh[i].transform(oscale, orientation, position);
        //if(modifiedMeshTri.normal().dot(camera.forward.rotate(camera.getRot())) < 0)
        //{
            temp = projectTri3d(camera, modifiedMeshTri);
            _di.drawTri(temp, grayscaleToColor((directLight.unit().dot(modifiedMeshTri.normal()) + 1)*128), false);
        //}
    }
}
