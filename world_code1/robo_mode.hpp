#ifndef ROBO_MODE_H
#define ROBO_MODE_H

extern float kaihi_x_k;
extern float kaihi_y_k;
extern float kaihi_speed_k;
extern float kaihi_muki_k;
extern int lineVal[4];
extern int lineOutVal[4];
extern int goPosition[2];
extern int positionRange;
extern int powermx;
extern String atack_goal_color;
extern int gbrads;
extern int gyrads; 

int backhome();
int k_backhome();
int a_roboGoRad(int r, int d);
int k_roboGoRad(int r, int d);
//bool k_line();
void MoterSerialPR(int p,int r);

#endif