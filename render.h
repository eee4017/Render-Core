#ifndef __Render__
#define __Render__

/***************************�禡�쫬�ŧi****************************/

//�Ŷ��]�w
space* set_space(void);

//����
obj* make_object(const FILE*);
void input_object(space*,obj*);
void delete_object(obj*);

//�s��(obj)
FILE* make_file(const obj*);

//����modify
void rotate_object(obj*,cor);//¶x,y,z��ʶq(���:�y��)
void move_object(obj*,cor);//x,y,z���ʶq

//�Ӭ۾�
void set_camera(cam*,cor,cor);//�I�B���V�q(���V�q���קY�I�쭱�Z��)

//�Ӭ۾�modify
void rotate_camera(cam*,cor);
void move_camera(cam*,cor);

//�����]�w
light* set_light(cor,double);//�y�СB�G��
plight* set_parallellight(cor);//���u�V�q(�V�q���קY���G��)


//�񾥺t��
void fill_pixel3(cam*,double,cor,cor,cor);
void fill_pixel4(cam*,double,cor,cor,cor,cor);

//��V
int judge(obj* , const cam*);
space* make_list(const cam*,const space*);
//void light_render(const cam*,const space*,const light*);
void parallellight_render(const cam*,const space*,const plight*);

//���
void delay(unsigned int );//�V����
void print(const cam *camera,int scr_x,int scr_y);

#endif // __Render__






