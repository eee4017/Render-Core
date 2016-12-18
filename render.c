#include<stdio.h>
#include<string.h>
#include<time.h>
#include"type_define.h"
#include"render.h"
#include"image.h"
#include"BasicMathFunc.h"
#include"console_draw3.h"

//照相機
void set_camera(cam* camera ,cor point, cor z){
    (*camera).pt = point;
    (*camera).z = z;
}

//照相機modify
void rotate_camera(cam* camera, cor vec){
    printf("******\n");
}
void move_camera(cam* camera , cor vec){
    (*camera).pt=add((*camera).pt,vec);
}

//光源設定
light* set_light(cor center , double d){
    light l;
    l.point = center;
    l.lightness = d;
    return &l;
}
plight* set_parallellight(cor vec){
    plight pl;
    pl.point = vec;
    return &pl;
}


//填墨演算
void fill_pixel3(cam *camera,double lightness,cor a,cor b,cor c){
    double PIXEL_WIDTH=RETINA_WIDTH/PIXEL_SCREEN_WIDTH,PIXEL_LENGTH=RETINA_LENGTH/PIXEL_SCREEN_LENGTH;


    double x[4],y[4];//三角形的三個點座標轉換成Retina坐標系
    x[3]=x[0]=dot(vec(camera->O,a),camera->x),y[3]=y[0]=dot(vec(camera->O,a),camera->y);
    x[1]=dot(vec(camera->O,b),camera->x),y[1]=dot(vec(camera->O,b),camera->y);
    x[2]=dot(vec(camera->O,c),camera->x),y[2]=dot(vec(camera->O,c),camera->y);


    // Scanline Fill Algorithm
    int min_bound[PIXEL_SCREEN_WIDTH],max_bound[PIXEL_SCREEN_WIDTH];//針對每個y 最左邊的x,最右邊的x

    for(int j=0;j<PIXEL_SCREEN_WIDTH;j++)
        min_bound[j]=PIXEL_SCREEN_LENGTH-1;
    memset(max_bound,0,sizeof(max_bound));

    double m,k,Y,X;
    double max_X=(PIXEL_SCREEN_LENGTH-1)*PIXEL_LENGTH,max_Y=(PIXEL_SCREEN_WIDTH-1)*PIXEL_WIDTH;
    double low_Y,high_Y;
    int i=0,j=0;


    for(int q=0;q<3;q++){//針對每一個邊
        if(x[q+1]==x[q])x[q]+0.1;//鉛垂線強迫

        m=(y[q+1]-y[q])/(x[q+1]-x[q]);
        k=y[q]-m*x[q];

        low_Y= (y[q]<=y[q+1])? y[q]:y[q+1]; low_Y=(low_Y<0)? 0:low_Y;//選低的Y座標但不能比螢幕低
        high_Y= (y[q]>=y[q+1])? y[q]:y[q+1]; high_Y=(high_Y> max_Y)? max_Y:high_Y;

        for(j=(int)(PIXEL_SCREEN_WIDTH-high_Y/PIXEL_WIDTH);j<(int)(PIXEL_SCREEN_WIDTH-low_Y/PIXEL_WIDTH);j++){//對每一橫列的像素//座標轉像素
            Y=(PIXEL_SCREEN_WIDTH-j)*PIXEL_WIDTH;//像素轉座標
            X=(Y-k)/m;

            X=(X>0) ? X:0 ;
            X=(X<max_X) ? X:max_X ;

            i=(int)X/PIXEL_LENGTH;//座標轉像素

            min_bound[j]= (min_bound[j]<i) ? min_bound[j]:i; //min_bound[j] = std::min(min_bound[j],i)
            max_bound[j]= (max_bound[j]>i) ? max_bound[j]:i;

        }


    }

    for(j=0;j<PIXEL_SCREEN_WIDTH;j++)
        if(min_bound[j]<max_bound[j]){
            //memset [j][min] to [j][max]
            for(i=max_bound[j];i>min_bound[j];i--)
                camera->pixel[j][i]=lightness;
        }

}
void fill_pixel4(cam* camera,double lightness,cor a,cor b,cor c,cor d){
    double PIXEL_WIDTH=RETINA_WIDTH/PIXEL_SCREEN_WIDTH,PIXEL_LENGTH=RETINA_LENGTH/PIXEL_SCREEN_LENGTH;


    double x[5],y[5];
    x[4]=x[0]=dot(vec(camera->O,a),camera->x),y[4]=y[0]=dot(vec(camera->O,a),camera->y);
    x[1]=dot(vec(camera->O,b),camera->x),y[1]=dot(vec(camera->O,b),camera->y);
    x[2]=dot(vec(camera->O,c),camera->x),y[2]=dot(vec(camera->O,c),camera->y);
    x[3]=dot(vec(camera->O,d),camera->x),y[3]=dot(vec(camera->O,d),camera->y);

    // Scanline Fill Algorithm
    int min_bound[PIXEL_SCREEN_WIDTH],max_bound[PIXEL_SCREEN_WIDTH];//針對每個y 最左邊的x,最右邊的x

    for(int j=0;j<PIXEL_SCREEN_WIDTH;j++)
        min_bound[j]=PIXEL_SCREEN_LENGTH-1;
    memset(max_bound,0,sizeof(max_bound));

    double m,k,Y,X;
    double max_X=(PIXEL_SCREEN_LENGTH-1)*PIXEL_LENGTH,max_Y=(PIXEL_SCREEN_WIDTH-1)*PIXEL_WIDTH;
    double low_Y,high_Y;
    int i=0,j=0;


    for(int q=0;q<4;q++){//針對每一個邊
        if(x[q+1]==x[q])x[q]+0.1;//鉛垂線強迫

        m=(y[q+1]-y[q])/(x[q+1]-x[q]);
        k=y[q]-m*x[q];

        low_Y= (y[q]<=y[q+1])? y[q]:y[q+1]; low_Y=(low_Y<0)? 0:low_Y;//選低的Y座標但不能比螢幕低
        high_Y= (y[q]>=y[q+1])? y[q]:y[q+1]; high_Y=(high_Y> max_Y)? max_Y:high_Y;

        for(j=(int)(PIXEL_SCREEN_WIDTH-high_Y/PIXEL_WIDTH);j<(int)(PIXEL_SCREEN_WIDTH-low_Y/PIXEL_WIDTH);j++){//對每一橫列的像素//座標轉像素
            Y=(PIXEL_SCREEN_WIDTH-j)*PIXEL_WIDTH;//像素轉座標
            X=(Y-k)/m;

            X=(X>0) ? X:0 ;
            X=(X<max_X) ? X:max_X ;

            i=(int)X/PIXEL_LENGTH;//座標轉像素

            min_bound[j]= (min_bound[j]<i) ? min_bound[j]:i; //min_bound[j] = std::min(min_bound[j],i)
            max_bound[j]= (max_bound[j]>i) ? max_bound[j]:i;

        }


    }

    for(j=0;j<PIXEL_SCREEN_WIDTH;j++)
        if(min_bound[j]<max_bound[j]){
            //memset [j][min] to [j][max]
            for(i=max_bound[j];i>min_bound[j];i--)
                camera->pixel[j][i]=lightness;
        }

}

//渲染
int judge(obj *object , const cam* camera){
    cor* c = object->v;
    int tf = 0;
    while(c != NULL){//initialize NULL
        int tf2 = 1;
        cor vec;
        vec.x = (*c).x - (*camera).pt.x;
        vec.y = (*c).y - (*camera).pt.y;
        vec.z = (*c).z - (*camera).pt.z;

        cor vec1 , vec2;
        vec1.x = (*camera).O.x - (*camera).pt.x;
        vec1.y = (*camera).O.y - (*camera).pt.y;
        vec1.z = (*camera).O.z - (*camera).pt.z;
        vec2.x = vec1.x + (*camera).x.x;
        vec2.y = vec1.y + (*camera).x.y;
        vec2.z = vec1.z + (*camera).x.z;

        if(dot(vec , cross(vec2 , vec1)) > 0){
            tf2 = 0;
            continue;
        }

        vec1 = vec2;
        vec2.x = vec1.x + (*camera).y.x;
        vec2.y = vec1.y + (*camera).y.y;
        vec2.z = vec1.z + (*camera).y.z;

        if(dot(vec , cross(vec1 , vec2)) > 0){
            tf2 = 0;
            continue;
        }

        vec1 = vec2;
        vec2.x = vec1.x - (*camera).x.x;
        vec2.y = vec1.y - (*camera).x.y;
        vec2.z = vec1.z - (*camera).x.z;

        if(dot(vec , cross(vec2 , vec1)) > 0){
            tf2 = 0;
            continue;
        }

        vec1 = vec2;
        vec2.x = vec1.x - (*camera).y.x;
        vec2.y = vec1.y - (*camera).y.y;
        vec2.z = vec1.z - (*camera).y.z;

        if(dot(vec , cross(vec2 , vec1)) > 0){
            tf2 = 0;
            continue;
        }
        if(tf2 == 1){
            tf = 1;
            break;
        }else{
            c = c + 1;
        }
    }
    return tf;
}
space* make_list(const cam* camera , const space* sp){
    space *sp1;
    sp1= (space *)malloc(sizeof(space));

    sp1->length = (*sp).length;
    int step = 0;
    int i;
    for(i = 0;i < 1000;i++){
        obj* object = (*sp).s[i];
        while(object != NULL){ //initialize NULL
            if(judge(object , camera)){
                sp1->s[step++] = (*sp).s[i];
                break;
            }else{
                object = object + 1;
            }
        }
    }

    return sp1;
}
void parallellight_render(const cam *camera,const space *list,const plight *L){
    cor temp0,temp1,temp2,temp3;
    int obj_c=0,pt_c=0,face_c=0;
    double lightness;

    for(obj_c=0; obj_c < list->length ; obj_c++){//針對每個要投射的物件 obj_c=object counter

        for(face_c=0; face_c < list->s[obj_c]->f_size ; face_c++){//針對每個面產生4個點投到面上
            lightness=dot(list->s[obj_c]->vn[face_c],L->point);//亮度的決定使用diffuse方法

            if(lightness>0){//背向攝影機的面不用投射

            //對每個點做投影並塗色
            temp0 = point_point_plane_intersec(   camera->pt , list->s[obj_c]->v[  list->s[obj_c]->f[face_c].f[0][1]  ]   ,  camera->retina  );
            temp1 = point_point_plane_intersec(   camera->pt , list->s[obj_c]->v[  list->s[obj_c]->f[face_c].f[1][1]  ]   ,  camera->retina  );
            temp2 = point_point_plane_intersec(   camera->pt , list->s[obj_c]->v[  list->s[obj_c]->f[face_c].f[2][1]  ]   ,  camera->retina  );

            if(list->s[obj_c]->f->f[3][1] != -1){
                temp3 = point_point_plane_intersec(   camera->pt , list->s[obj_c]->v[  list->s[obj_c]->f[face_c].f[3][1]  ]   ,  camera->retina  );
                fill_pixel4(camera,lightness,temp0,temp1,temp2,temp3);
            }
            else fill_pixel3(camera,lightness,temp0,temp1,temp2);

            }
        }

    }
}

//顯示
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void print(const cam *camera,int scr_x,int scr_y){
    char c;
    clearScreen();

    for(int j=0;j<PIXEL_SCREEN_WIDTH;j++){
        for(int i=0;i<PIXEL_SCREEN_LENGTH;i++){
            switch ((int)camera->pixel[j][i]){
                case 0: c=' ' ; break;// redundant
                case 1: c=',' ; break;
                case 2: c='.' ; break;
                case 3: c='_' ; break;
                case 4: c='\''; break;
                case 5: c='|' ; break;
                case 6: c='/' ; break;
                case 7: c='/' ; break;
                case 8: c='`' ; break;
                case 9: c='\\'; break;
                case 10: c='|'; break;
                case 11: c='\\'; break;
                case 12: c='~'; break;
                case 13: c='\\'; break;
                case 14: c='7'; break;
                case 15: c='#'; break;
                default: c='X'; break;
            }
            drawChar(c,scr_x+i,scr_y+j,0,12);
        }
    }

    delay(FPS_delay);

    drawCmdWindow();

}


