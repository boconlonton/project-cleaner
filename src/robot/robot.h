#pragma once
#include <iostream>
#include <string>

#include "../map/map.h"

using namespace std;

struct Direction
{
    CELL position;
    int direction;
};


class Cleaner
{
    protected:
        string manufacturer;
        string serial_number;
        int current_battery;
        Map data;
        Direction* current;

    public:

    void SetMap(Map requirements)
    {   
        this->data = requirements;
    }

    void GetCurrent()
    {
        cout << "(" << this->current->position.x << "," << this->current->position.y << ")";
        cout << "Direction: " << current->direction;
        cout << endl;
    }

    void SetDirection(int x, int y, int direction)
    {
        this->current = new Direction;
        this->current->position.x = x;
        this->current->position.y = y;
        this->current->direction = direction;
    }

    Direction* CheckNextPosition(int direction, bool allowCleaned=false)
        {
            Direction* result = new Direction;
            int cell_check;
            switch (direction)
            {
                case 0: // Bắc
                    result->position.x = this->current->position.x - 1;
                    result->position.y = this->current->position.y;
                    result->direction = 0;
                    cell_check = this->data.data[result->position.x][result->position.y].type;
                    // Obstacle or Wall
                    if (cell_check == 1 || cell_check == 4) return NULL;
                    // Cleaned
                    else if (!allowCleaned && cell_check == 2) return NULL;
                    else return result;
                case 1: // Đông
                    result->position.x = this->current->position.x;
                    result->position.y = this->current->position.y + 1;
                    result->direction = 1;
                    cell_check = this->data.data[result->position.x][result->position.y].type;
                    // Obstacle or Wall
                    if (cell_check == 1 || cell_check == 4) return NULL;
                    // Cleaned
                    else if (!allowCleaned && cell_check == 2) return NULL;
                    else return result;
                case 2: // Nam
                    result->position.x = this->current->position.x + 1;
                    result->position.y = this->current->position.y;
                    result->direction = 2;
                    cell_check = this->data.data[result->position.x][result->position.y].type;
                    // Obstacle or Wall
                    if (cell_check == 1 || cell_check == 4) return NULL;
                    // Cleaned
                    else if (!allowCleaned && cell_check == 2) return NULL;
                    else return result;
                case 3: // Tây
                    result->position.x = this->current->position.x;
                    result->position.y = this->current->position.y - 1;
                    result->direction = 3;
                    cell_check = this->data.data[result->position.x][result->position.y].type;
                    // Obstacle or Wall
                    if (cell_check == 1 || cell_check == 4) return NULL;
                    // Cleaned
                    else if (!allowCleaned && cell_check == 2) return NULL;
                    else return result;
            }
            return NULL;
      }
        bool FindPath(){
            int instruction[4][4] = {{0,1,3,2},{1,2,0,3},{2,3,1,0},{3,0,2,1}};
            int direction;
            for (int i=0; i<4; i++)
            {
                direction = instruction[current->direction][i];
                Direction* res = CheckNextPosition(direction);
                if (res != NULL)
                {
                    this->current = res;
                    return true;
                }
            }
            for (int i=0; i<4; i++)
            {
                direction = instruction[current->direction][i];
                Direction* res = CheckNextPosition(direction, true);
                if (res != NULL)
                {
                    this->current = res;
                    return true;
                }
            }
            return false;
        };
};
