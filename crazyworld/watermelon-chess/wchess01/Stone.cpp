#include "Stone.h"

Stone::Stone()
{

}

Stone::~Stone()
{

}

void Stone::init(int id)
{
    struct {
        int polarAngle;
        int polarDiameter;
    } pos[6] = {
        {30,  180},
        {60,  180},
        {90,  130},
        {90,  180},
        {120, 180},
        {150, 180},

        /*
        {-30,  180},
        {-60,  180},
        {-90,  130},
        {-90,  180},
        {-120, 180},
        {-150, 180},
        */
    };


    _id = id;
    _dead = false;
    _black = id<7; //前6颗为黑

    if(id < 6)
    {
        _polarAngle = pos[id].polarAngle;
        _polarDiameter = pos[id].polarDiameter;
    }
    else
    {
        _polarAngle = -pos[id-6].polarAngle;
        _polarDiameter = pos[id-6].polarDiameter;
    }
}
