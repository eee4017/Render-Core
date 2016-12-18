#include"BasicMathFunc.h"
#include"type_define.h"

/****************�򥻹B��*******************/

cor sub(cor b,cor a){//�V�q��k
    cor res;

    res.x=b.x-a.x;
    res.y=b.y-a.y;
    res.z=b.z-a.z;

    return res;
}
cor vec(cor a,cor b){//���I�Φ����V�q(A���VB)
    cor res;

    res.x=b.x-a.x;
    res.y=b.y-a.y;
    res.z=b.z-a.z;

    return res;
}
cor add(cor a,cor b){//�V�q�[�k
    cor res;

    res.x=b.x+a.x;
    res.y=b.y+a.y;
    res.z=b.z+a.z;

    return res;
}
cor multiply(cor a,double length){//�Y�ƿn
    cor res;

    res.x=a.x*length;
    res.y=a.y*length;
    res.z=a.z*length;

    return res;
}
cor cross(cor a,cor b){//�~�n//�`�N�S���洫�߳�
    cor res;

    res.x=a.y*b.z-a.z*b.y;
    res.y=a.z*b.x-a.x*b.z;
    res.z=a.x*b.y-a.y*b.x;

    return res;
}
cor line_plane_intersec(line l,plane p){//�u�����I//�O�o���P�_�����
    double k=dot(p.vec,vec(p.pt,l.pt))/dot(p.vec,l.vec);//�ѼƦ�
    return add(l.pt,multiply(l.vec,k));
}
cor point_point_plane_intersec(cor p1,cor p2,plane p){//���I�ҧΦ����u�P�����I//�O�o���P�_�����
    cor x=vec(p1,p2);
    double k=dot(p.vec,vec(p.pt,p1))/dot(p.vec,x);//�ѼƦ�
    return add(p1,multiply(x,k));
}
line get_line(cor a,cor b){//a�Vb���������u
    line l;

    l.pt=a;
    l.vec=vec(a,b);

    return l;
}
