
#ifndef _Type_define_
#define _Type_define_

/***************************常數宣告****************************/
//CAMERA CONSTANTS
#define FPS_delay 30

//像素矩陣大小
#define PIXEL_SCREEN_WIDTH 120
#define PIXEL_SCREEN_LENGTH 160

//視網膜邊長
#define RETINA_WIDTH 160
#define RETINA_LENGTH 160

#define FOCOUS_TO_RETINA 138.56406460551018348219570732047 //80*SQRT(3)

#define MAX_ERROR 0.0001//基準誤差10^-4


/***************************struct宣告****************************/

/****************基本物件*******************/

typedef struct coordinate{//cor//座標或向量(x,y,z),或(Δx,Δy,Δz)皆適用
    double x,y,z;
}cor;
typedef struct plane{//平面由點和法向量形成
    cor pt;
    cor vec;
}plane;
typedef struct line{//直線由出發點和線向量形成
    cor pt;
    cor vec;
}line;


typedef struct face{//face//面：必須包在物件中
    int f[4][3];//每個面有4個點 每個點有3個索引(obj 檔定義 v/vt/vn ; 這裡定義成 v/vn/vt(方便以後刪掉))
}face;
typedef struct object{//obj//物件//vt可刪
    cor *v;//頂點
    int v_size;

    cor *vn;//面向量
    int vn_size;

    cor *vt;//貼圖座標(UV座標) 用不到以後可移除
    int vt_size;

    cor center;//物件中心

    face *f;//面
    int f_size;

    char *name;

    int colour;
/* 0: 黑     8: 暗灰   7: 淺灰 15: 白

   1: 暗藍   2: 暗綠   3: 暗青  4: 暗紅   5: 暗紫   6: 暗黃
   9: 亮藍  10: 亮綠  11: 亮青 12: 亮紅  13: 亮紫  14: 亮黃
*/

}obj;
typedef struct camera{//cam//物件：攝影機
    double pixel[PIXEL_SCREEN_WIDTH][PIXEL_SCREEN_LENGTH];
    plane retina;
    cor O;//原點：最左下角的點：pixel[PIXEL_SCREEN_WIDTH][0]
    cor x,y;//視網膜坐標系：x方向單位向量、y方向單位向量

    //焦點
    cor pt;
    cor z;//焦點垂平面的單位向量
}cam;

typedef struct light{//light//物件：光源
    cor point;
    double lightness;
}light;
typedef struct parallellight{//plight//物件：平行光源
    cor point;
}plight;

/****************物件空間*******************/
typedef struct space{//space//含有所有物件的空間、欲被投射的物件列表、投射所形成的多邊形列表
    int length;
    obj* s[1000];//最多1000個物件
}space;

#endif
