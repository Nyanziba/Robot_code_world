#include "robo_serial.hpp"

void serial_surrounding(){//カメラLiDAR
   Serial.print(surrounding[0]);
   Serial.print(',');
   Serial.print(surrounding[1]);
   Serial.print(',');
   Serial.print(surrounding[2]);
   Serial.print(',');
   Serial.print(surrounding[3]);
   Serial.print(',');
   Serial.print(surrounding[4]);
   Serial.print(',');
   Serial.print(surrounding[5]);
   Serial.print(',');
   Serial.print(surrounding[6]);
   Serial.print(',');
   Serial.print(surrounding[7]);
   Serial.print(',');
   Serial.print(surrounding[8]);
   Serial.print(',');
   Serial.print(surrounding[9]);
   Serial.print(',');
   Serial.print(surrounding[10]);
   Serial.print(',');
   Serial.print(surrounding[11]);
   Serial.print(',');
   Serial.print(surrounding[12]);
   Serial.print(',');
   Serial.print(surrounding[13]);
   Serial.print(',');
   Serial.print(surrounding[14]);
   Serial.print(',');
   Serial.print(surrounding[15]);
   Serial.println(',');
}

void serial_goal(){//ゴール方向確認
   Serial.print("blue:");
   Serial.print(gbrads);
   Serial.print("yellow:");
   Serial.println(gyrads);
}

void serial_ultrasonic(){//超音波センサ
    Serial.print("ultrasonic(F,R,L): ");
    Serial.print(ultrasonicVal[0]);
    Serial.print(',');
    Serial.print(ultrasonicVal[1]);
    Serial.print(',');
    Serial.println(ultrasonicVal[2]);
}

void serial_kaihi(){//カメラLiDARから導き出される位置
    Serial.print("x_k:");
    Serial.print(kaihi_x_k);
    Serial.print(", ");
    Serial.print("y_k:");
    Serial.print(kaihi_y_k);
    Serial.print(", ");
    Serial.print("muki_k:");
    Serial.print(kaihi_muki_k);
    Serial.print(", ");
    Serial.print("speed_k:");
    Serial.println(kaihi_speed_k);
}

void serial_RDGO(){//現在のボール情報(r,d)を表示
    Serial.print(" r:");
    Serial.print(String(ballRD[0]));
    Serial.print(" d:");
    Serial.print(String(ballRD[1]));
    Serial.print(" goRad:");
    Serial.println(goRad);
}

void serial_line(){//ラインセンサ
    Serial.print("line: ");
    Serial.print(lineVal[0]);
    Serial.print("/");
    Serial.print(lineOutVal[0]);
    Serial.print(", ");
    Serial.print(lineVal[1]);
    Serial.print("/");
    Serial.print(lineOutVal[1]);
    Serial.print(", ");
    Serial.print(lineVal[2]);
    Serial.print("/");
    Serial.print(lineOutVal[2]);
    Serial.print(", ");
    Serial.println(lineVal[3]);
    Serial.print("/");
    Serial.println(lineOutVal[3]);
}

void serial_camera_ball(){
    Serial.print("[front]");
    Serial.print(" r:");
    Serial.print(rads);
    Serial.print(" d:");
    Serial.print(fdistance);
    Serial.print("  [rigth]");
    Serial.print(" r:");
    Serial.print(radsbr);
    Serial.print(" d:");
    Serial.print(rdistance);
    Serial.print("  [left]");
    Serial.print(" r:");
    Serial.print(radsbl);
    Serial.print(" d:");
    Serial.println(ldistance);
}