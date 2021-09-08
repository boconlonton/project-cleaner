#pragma once
#include <iostream>
#include <string>

#include "map/map.h"

using namespace std;


class Cleaner
{
    protected:
        string manufacturer;
        string serial_number;
        int current_direction;
        int current_battery;
        Map data;
        CELL current_position;

    public:

        void FindPath(){
            
        };
};
