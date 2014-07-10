#ifndef SCENE3D_H
#define SCENE3D_H

#include "Object3d.h"

#define MAX_OBJECTS             16

#define AO_OK                   0
#define AO_FAIL_NO_SPACE        1

class Scene
{
protected:
    Camera3d cam;

    struct Object3D_t
    {
        Object3d * ptr;
        bool used;
    } objects[MAX_OBJECTS];
public:
    Scene(void);
    void draw(void);
    uint8_t addObject(Object3d& newObject);
};

#endif // SCENE3D_H
