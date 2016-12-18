#include"BasicMathFunc.h"
#include"type_define.h"

/****************膀セ笲衡*******************/

cor sub(cor b,cor a){//秖搭猭
    cor res;

    res.x=b.x-a.x;
    res.y=b.y-a.y;
    res.z=b.z-a.z;

    return res;
}
cor vec(cor a,cor b){//ㄢ翴Θ秖(AB)
    cor res;

    res.x=b.x-a.x;
    res.y=b.y-a.y;
    res.z=b.z-a.z;

    return res;
}
cor add(cor a,cor b){//秖猭
    cor res;

    res.x=b.x+a.x;
    res.y=b.y+a.y;
    res.z=b.z+a.z;

    return res;
}
cor multiply(cor a,double length){//玒计縩
    cor res;

    res.x=a.x*length;
    res.y=a.y*length;
    res.z=a.z*length;

    return res;
}
cor cross(cor a,cor b){//縩//猔種⊿Τユ传翅
    cor res;

    res.x=a.y*b.z-a.z*b.y;
    res.y=a.z*b.x-a.x*b.z;
    res.z=a.x*b.y-a.y*b.x;

    return res;
}
cor line_plane_intersec(line l,plane p){//絬ユ翴//癘眔耞キ︽翅
    double k=dot(p.vec,vec(p.pt,l.pt))/dot(p.vec,l.vec);//把计Α
    return add(l.pt,multiply(l.vec,k));
}
cor point_point_plane_intersec(cor p1,cor p2,plane p){//ㄢ翴┮Θ絬籔ユ翴//癘眔耞キ︽翅
    cor x=vec(p1,p2);
    double k=dot(p.vec,vec(p.pt,p1))/dot(p.vec,x);//把计Α
    return add(p1,multiply(x,k));
}
line get_line(cor a,cor b){//abタ絬
    line l;

    l.pt=a;
    l.vec=vec(a,b);

    return l;
}
