#ifndef ROBO_SERIAL_H
#define ROBO_SERIAL_H

#include <Arduino.h>
extern int surrounding[16];
extern int gbrads;
extern int gyrads;
extern int ultrasonicVal[3];
extern float kaihi_x_k;
extern float kaihi_y_k;
extern float kaihi_muki_k;
extern float kaihi_speed_k;
extern int *ballRD;
extern int goRad;
extern int lineVal[4];
extern int lineOutVal[4];
extern int rads;
extern int radsbr;
extern int radsbl;
extern int fdistance;
extern int rdistance;
extern int ldistance;

void serial_surrounding();
void serial_goal();
void serial_ultrasonic();
void serial_kaihi();
void serial_RDGO();
void serial_line();
void serial_camera_ball();

#endif