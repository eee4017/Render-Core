#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BasicMathFunc.h"
#include "type_define.h"
#include "render.h"

int main()
{
    cam camera;

    memset(camera.pixel,0,sizeof(camera.pixel));

    camera.pt.x=0,camera.pt.y=0,camera.pt.z=0;
    camera.O.x=-80,camera.O.y=FOCOUS_TO_RETINA,camera.O.z=-80;

    camera.x.x=1,camera.x.y=0,camera.x.z=0;
    camera.y.x=0,camera.y.y=0,camera.y.z=1;

    cor mid;
    mid.x=0,mid.y=FOCOUS_TO_RETINA,mid.z=0;
    camera.z=vec(camera.pt,mid);

    camera.retina.pt=camera.O;
    camera.retina.vec=cross(camera.y,camera.x);

    cor a,b,c,d;

    for(int i=0;i<100;i++){
        memset(camera.pixel,0,sizeof(camera.pixel));
        a.x=0,a.y=480,a.z=80;
        b.x=80,b.y=480+10*i,b.z=-80;
        c.x=-80,c.y=480,c.z=-80;
        d.x=-70,d.y=480,d.z=100;


        fill_pixel4(&camera, 10 ,
                point_point_plane_intersec(camera.pt,a,camera.retina),
                point_point_plane_intersec(camera.pt,b,camera.retina),
                point_point_plane_intersec(camera.pt,c,camera.retina),
                point_point_plane_intersec(camera.pt,d,camera.retina));

        print(&camera,0,0);
    }
    return 0;
}
