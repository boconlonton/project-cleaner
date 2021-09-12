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
        int uncleaned_direction = 4;


    public:
        void SetMap(Map input)
        {   
            this->data = input;
        }

        void ShowMap()
        {
            for (int row_idx=0; row_idx<this->data.rows; row_idx++)
            {
                for (int col_idx=0; col_idx<this->data.cols; col_idx++)
                {
                    if (data.data[row_idx][col_idx].type == 1) cout << "*";
                    else if (data.data[row_idx][col_idx].type == 4) cout << "-";
                    else if (data.data[row_idx][col_idx].type == 2) cout << "x";
                    else if (data.data[row_idx][col_idx].type == 0) cout << "0";
                    else cout << " ";
                }
                cout << endl;
            }
        };

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
            cout << "\t";
            switch (uncleaned_direction)
            {
                case 0:
                    cout << "Uncleaned: " << "North";
                    break;
                case 1:
                    cout << "Uncleaned: " << "East";
                    break;
                case 2:
                    cout << "Uncleaned: " << "South";
                    break;
                case 3:
                    cout << "Uncleaned: " << "West";
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

        bool CheckUncleanedOnDirection(Direction* result)
        {
            switch (result->direction)
            {
            case 0: // North
                for (int i = result->position.x; i > 0; i--)
                {
                    if (this->data.data[i][result->position.y].type == 3)
                    {
                        this->uncleaned_direction = 0;
                        return true;
                    }
                }
                break;
            case 1: // East
                for (int j = result->position.y; j < this->data.cols-1; j++)
                {
                    if (this->data.data[result->position.x][j].type == 3)
                    {
                        this->uncleaned_direction = 1;
                        return true;
                    }
                }
                break;
            case 2: // South
                for (int i = result->position.x; i < this->data.rows; i++)
                {
                    if (this->data.data[i][result->position.y].type == 3)
                    {
                        this->uncleaned_direction = 2;
                        return true;
                    }
                }
                break;
            case 3: // West
                for (int j = result->position.y; j > 0; j--)
                {
                    if (this->data.data[result->position.x][j].type == 3)
                    {
                        this->uncleaned_direction = 3;
                        return true;
                    }
                }
                break;
            }
            return false;
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
                    this->data.data[current->position.x][current->position.y].type = 2;
                    this->current = res;
                    this->data.data[res->position.x][res->position.y].type = 0;
                    return true;
                }
            }
            for (int i=0; i<4; i++)
            {
                direction = instruction[current->direction][i];
                Direction* res = CheckNextPosition(direction, true);
                if (res != NULL && CheckUncleanedOnDirection(res))
                {
                    this->data.data[current->position.x][current->position.y].type = 2;
                    this->current = res;
                    this->data.data[res->position.x][res->position.y].type = 0;
                    return true;
                }
            }
            for (int i=0; i<4; i++)
            {
                direction = instruction[current->direction][i];
                Direction* res = CheckNextPosition(direction, true);
                if (res != NULL)
                {
                    this->data.data[current->position.x][current->position.y].type = 2;
                    this->current = res;
                    this->data.data[res->position.x][res->position.y].type = 0;
                    if (this->uncleaned_direction < 4) this->current->direction = this->uncleaned_direction;
                    return true;
                }
            }
            return false;
        };
};
