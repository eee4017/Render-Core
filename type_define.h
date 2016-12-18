
#ifndef _Type_define_
#define _Type_define_

/***************************�`�ƫŧi****************************/
//CAMERA CONSTANTS
#define FPS_delay 30

//�����x�}�j�p
#define PIXEL_SCREEN_WIDTH 120
#define PIXEL_SCREEN_LENGTH 160

//���������
#define RETINA_WIDTH 160
#define RETINA_LENGTH 160

#define FOCOUS_TO_RETINA 138.56406460551018348219570732047 //80*SQRT(3)

#define MAX_ERROR 0.0001//��ǻ~�t10^-4


/***************************struct�ŧi****************************/

/****************�򥻪���*******************/

typedef struct coordinate{//cor//�y�ЩΦV�q(x,y,z),��(�Gx,�Gy,�Gz)�ҾA��
    double x,y,z;
}cor;
typedef struct plane{//�������I�M�k�V�q�Φ�
    cor pt;
    cor vec;
}plane;
typedef struct line{//���u�ѥX�o�I�M�u�V�q�Φ�
    cor pt;
    cor vec;
}line;


typedef struct face{//face//���G�����]�b����
    int f[4][3];//�C�ӭ���4���I �C���I��3�ӯ���(obj �ɩw�q v/vt/vn ; �o�̩w�q�� v/vn/vt(��K�H��R��))
}face;
typedef struct object{//obj//����//vt�i�R
    cor *v;//���I
    int v_size;

    cor *vn;//���V�q
    int vn_size;

    cor *vt;//�K�Ϯy��(UV�y��) �Τ���H��i����
    int vt_size;

    cor center;//���󤤤�

    face *f;//��
    int f_size;

    char *name;

    int colour;
/* 0: ��     8: �t��   7: �L�� 15: ��

   1: �t��   2: �t��   3: �t�C  4: �t��   5: �t��   6: �t��
   9: �G��  10: �G��  11: �G�C 12: �G��  13: �G��  14: �G��
*/

}obj;
typedef struct camera{//cam//����G��v��
    double pixel[PIXEL_SCREEN_WIDTH][PIXEL_SCREEN_LENGTH];
    plane retina;
    cor O;//���I�G�̥��U�����I�Gpixel[PIXEL_SCREEN_WIDTH][0]
    cor x,y;//���������Шt�Gx��V���V�q�By��V���V�q

    //�J�I
    cor pt;
    cor z;//�J�I�����������V�q
}cam;

typedef struct light{//light//����G����
    cor point;
    double lightness;
}light;
typedef struct parallellight{//plight//����G�������
    cor point;
}plight;

/****************����Ŷ�*******************/
typedef struct space{//space//�t���Ҧ����󪺪Ŷ��B���Q��g������C��B��g�ҧΦ����h��ΦC��
    int length;
    obj* s[1000];//�̦h1000�Ӫ���
}space;

#endif
