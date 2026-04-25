#include <Arduino.h>
#include "robo_mode.hpp"

unsigned long last = millis();

int k_backhome(){
  int xposition = kaihi_x_k - goPosition[0];
  int yposition = kaihi_y_k - goPosition[1];
  if(abs(xposition) <= positionRange && abs(yposition) <= positionRange) return 185;
  if(xposition >= 0 && abs(yposition) <= positionRange) return 90;
  if(xposition < 0 && abs(yposition) <= positionRange) return -90;
  if(yposition >= 0 && abs(xposition) <= positionRange) return 0;
  if(yposition < 0 && abs(xposition) <= positionRange) return 180;
  if(xposition >= 0 && yposition >= 0) return 45;
  if(xposition >= 0 && yposition < 0) return 135;
  if(xposition < 0 && yposition >= 0) return -45;
  if(xposition < 0 && yposition < 0) return -135;
  return 185;
}

int k_roboGoRad(int r, int d){
  unsigned long now = millis();
  bool lineflag = now-last > 2000;

  bool Online26 = lineVal[0] > lineOutVal[0];
  bool Online27 = lineVal[1] > lineOutVal[1];
  bool Online28 = lineVal[2] > lineOutVal[2];
  bool Online29 = lineVal[3] > lineOutVal[3];
  if(Online26 || Online27 || Online28 || Online29) last = millis();

  if(abs(r) > 181){
      return 185;
  }
  int reRad = 185;

  int *goal;
  if(atack_goal_color == "blue") goal = &gyrads;
  else if(atack_goal_color == "yellow") goal = &gbrads;

  if(abs(*goal) > 181){
    return kaihi_muki_k;
  }

  //2秒間ラインセンサが反応しなかったらゴール方向へ
  if(lineflag) return *goal;

  //ゴール方向とボールの間で止まる
  if(abs(*goal) < 181 && d != -1 && abs(r) < 181){
    if(*goal > -130 && *goal < 0){
      if(r > 80 ) return 185;
    } else if(*goal > -140 && *goal <= -130 ){
      if(r > 20 && r < 80) return 185;
    } else if(abs(*goal) > 140 && abs(*goal) < 181){
      if(abs(r) < 20) return 185;
    } else if(*goal >= 130 && *goal < 140){
      if(r < -20 && r > -80) return 185;
    } else if(*goal >= 0 && *goal < 130){
      if(r < -80 ) return 185;
    }
  }

  //ゴールは認識してるがボールが見当たらない➔ゴール中心へ
  if(d == -1){
    if(!(abs(*goal) > 160 && abs(*goal) < 181)){
      if(*goal > 0){
        r = 90;
      } else {
        r = -90;
      }
    } else {
      last = millis();
      return 185;
    }
  }

  //ゴール前ライントレース
  if( r > 0){
    if(*goal > -120 && *goal < 0){
      return 0;
    } else if(*goal > -130 && *goal <= -120 ){
      if(Online26 || Online27) reRad = -90;
      else if(Online28 || Online29) reRad = 90;
      else return 185;
    } else if(*goal > -140 && *goal <= -130 ){
      if(Online26) reRad = -135;
      else if(Online28) reRad = 45;
      else reRad = 135;
    } else if(abs(*goal) > 140 && abs(*goal) < 181){
      if(Online26 || Online29) reRad = 135;
      else if(Online27 || Online28) reRad = 45;
      else reRad = 90;
    } else if(*goal >= 130 && *goal < 140){
      if(Online27) reRad = -45;
      else if(Online29) reRad = 135;
      else reRad = 45;
    } else if(*goal >= 0 && *goal < 130){
      if(Online26 || Online27) reRad = -90;
      else if(Online28 || Online29) reRad = 90;
      else reRad = 0;
    } 
  } else if(r < 0){
    if(*goal > -130 && *goal < 0){
      if(Online26 || Online27) reRad = -90;
      else if(Online28 || Online29) reRad = 90;
      else reRad = 0;
    } else if(*goal > -140 && *goal <= -130 ){
      if(Online26) reRad = -135;
      else if(Online28) reRad = 45;
      else reRad = -45;
    } else if(abs(*goal) > 140 && abs(*goal) < 181){
      if(Online26 || Online29) reRad = -135;
      else if(Online27 || Online28) reRad = -45;
      else reRad = -90;
    } else if(*goal >= 130 && *goal < 140){
      if(Online27) reRad = -45;
      else if(Online29) reRad = 135;
      else reRad = -135;
    } else if(*goal >= 120 && *goal < 130){
      if(Online26 || Online27) reRad = -90;
      else if(Online28 || Online29) reRad = 90;
      else return 185;
    } else if(*goal >= 0 && *goal < 120){
      return 0;
    }
  }
  
  if(reRad < -180){//絶対値が180を超えないように
    reRad = 180 - (-180-reRad);
  } else if(reRad > 180){
    reRad = -180 + (reRad-180);
  }
  return reRad;
}
/*
bool k_line(){
    int *goal;
    if(atack_goal_color == "blue") goal = &gbrads;
    else if(atack_goal_color == "yellow") goal = &gyrads;
    if( r > 0){
        if(*goal > -120 && *goal < 0) {
            MoterSerialPR(powermx,30); return true;
        }else if(*goal > -130 && *goal <= -120 ) {
            MoterSerialPR(powermx,90); return true;
        }else if(*goal > -140 && *goal <= -130 ) {
            MoterSerialPR(powermx,90); return true;
        }else if(abs(*goal) > 90 && abs(*goal) < 181) {
            MoterSerialPR(powermx,60); return true;
        }
    }
    return false;
}
    */