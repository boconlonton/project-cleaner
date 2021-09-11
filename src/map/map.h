#pragma once
#include <iostream>

using namespace std;

struct CELL
{
    int x;
    int y;
    int type;
};


class Map
{
    public:
        int cols;
        int rows;
        CELL data[6][5];

        void ShowMap()
        {
            for (int row_idx=0; row_idx<this->rows; row_idx++)
            {
                for (int col_idx=0; col_idx<this->cols; col_idx++)
                {
                    if (data[row_idx][col_idx].type == 1) cout << "*";
                    else if (data[row_idx][col_idx].type == 4) cout << "-";
                    else if (data[row_idx][col_idx].type == 0) cout << "x";
                    else cout << " ";
                }
                cout << endl;
            }
        };

        Map(){
            this->cols = 5;
            this->rows = 6;
            for (int row_idx=0; row_idx<this->rows; row_idx++)
            {
                for (int col_idx=0; col_idx<this->cols; col_idx++)
                {
                    CELL temp;
                    temp.x = row_idx;
                    temp.y = col_idx;
                    temp.type = 3;
                    if (row_idx==0) temp.type = 4;
                    if (row_idx==5) temp.type = 4;
                    if (col_idx==0) temp.type = 4;
                    if (col_idx==4) temp.type = 4;
                    if (row_idx==1 && col_idx==1) temp.type = 1;
                    if (row_idx==3 && col_idx==2) temp.type = 1;
                    if (row_idx==1 && col_idx==2) temp.type = 1;
                    if (row_idx==3 && col_idx==3) temp.type = 1;
                    if (row_idx==1 && col_idx==3) temp.type = 0;
                    this->data[row_idx][col_idx].x = temp.x;
                    this->data[row_idx][col_idx].y = temp.y;
                    this->data[row_idx][col_idx].type = temp.type;
                }
            }
        };
        ~Map(){};
};
