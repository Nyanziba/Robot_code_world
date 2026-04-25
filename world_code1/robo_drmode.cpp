# include "robo_mode.hpp"

int d_roboGoRad(int r, int d){
    if(drCatch){
        if(atack_goal_color == "blue") return gbrads;
        else if(atack_goal_color == "yellow") return gyrads;
    }
    if(true){
    } else if(true){
        return 180 - ((r/abs(r))*45);
    } else if(true){
        return 180;
    } else if(true){
        delay(500);
        drCatch = true;
        if(atack_goal_color == "blue") return gbrads;
        else if(atack_goal_color == "yellow") return gyrads;
    }
    return 185;
}