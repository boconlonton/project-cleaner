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
        Map data;
        Direction* current;
        int current_battery;
        int battery_threshold;


    public:
        void SetMap(Map input)
        {   
            this->data = input;
        }

        void SetBatteryThreshold(int threshold)
        {
            this->battery_threshold = threshold;
        }

        bool CheckBattery(int threshold)
        {
            if (current_battery <= battery_threshold) return false;
            else return true;
        }

        void GetBattery()
        {
            cout << "Current Battery: " << this->current_battery;
        }

        void GetCurrent()
        {
            cout << "(" << this->current->position.x << "," << this->current->position.y << ")" << "\t";
            switch (current->direction)
            {
                case 0:
                    cout << "Direction: " << "North";
                    break;
                case 1:
                    cout << "Direction: " << "East";
                    break;
                case 2:
                    cout << "Direction: " << "South";
                    break;
                case 3:
                    cout << "Direction: " << "West";
                    break;
            }
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

        bool FindPath()
        {
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
