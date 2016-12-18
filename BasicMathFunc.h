#include"type_define.h"
#ifndef _BASIC_MATH_FUNCTIONS
#define _BASIC_MATH_FUNCTIONS



#define dot(a,b) (a.x*b.x+a.y*b.y+a.z*b.z)
#define distance(a,b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))
#define length(a) ((a.x)*(a.x)+(a.y)*(a.y)+(a.z)*(a.z))

cor sub(cor b,cor a);
cor vec(cor a,cor b);
cor add(cor a,cor b);
cor multiply(cor a,double length);
cor cross(cor a,cor b);
cor line_plane_intersec(line l,plane p);
cor point_point_plane_intersec(cor p1,cor p2,plane p);
line get_line(cor a,cor b);

#endif // _BASIC_MATH_FUNCTIONS

