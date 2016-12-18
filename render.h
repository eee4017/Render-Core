#ifndef __Render__
#define __Render__

/***************************函式原型宣告****************************/

//空間設定
space* set_space(void);

//物件
obj* make_object(const FILE*);
void input_object(space*,obj*);
void delete_object(obj*);

//存檔(obj)
FILE* make_file(const obj*);

//物件modify
void rotate_object(obj*,cor);//繞x,y,z轉動量(單位:弳度)
void move_object(obj*,cor);//x,y,z移動量

//照相機
void set_camera(cam*,cor,cor);//點、面向量(面向量長度即點到面距離)

//照相機modify
void rotate_camera(cam*,cor);
void move_camera(cam*,cor);

//光源設定
light* set_light(cor,double);//座標、亮度
plight* set_parallellight(cor);//光線向量(向量長度即光亮度)


//填墨演算
void fill_pixel3(cam*,double,cor,cor,cor);
void fill_pixel4(cam*,double,cor,cor,cor,cor);

//渲染
int judge(obj* , const cam*);
space* make_list(const cam*,const space*);
//void light_render(const cam*,const space*,const light*);
void parallellight_render(const cam*,const space*,const plight*);

//顯示
void delay(unsigned int );//幀延遲
void print(const cam *camera,int scr_x,int scr_y);

#endif // __Render__






