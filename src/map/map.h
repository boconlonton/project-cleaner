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
        CELL data[30][30];

        void ShowMap()
        {
            for (int row_idx=0; row_idx<this->rows; row_idx++)
            {
                for (int col_idx=0; col_idx<this->cols; col_idx++)
                {
                    if (data[row_idx][col_idx].type == 1) cout << "*";
                    else if (data[row_idx][col_idx].type == 4) cout << "-";
                    else if (data[row_idx][col_idx].type == 2) cout << "x";
                    else cout << " ";
                }
                cout << endl;
            }
        };

        Map(){
            this->cols = 30;
            this->rows = 30;
            for (int row_idx=0; row_idx<this->rows; row_idx++)
            {
                for (int col_idx=0; col_idx<this->cols; col_idx++)
                {
                    CELL temp;
                    temp.x = row_idx;
                    temp.y = col_idx;
                    temp.type = 3;
                    if (row_idx==0) temp.type = 4;
                    if (row_idx==29) temp.type = 4;
                    if (col_idx==0) temp.type = 4;
                    if (col_idx==29) temp.type = 4;
                    if (row_idx==1 && col_idx==9) temp.type = 1;
                    if (row_idx==1 && col_idx==10) temp.type = 1;
                    if (row_idx==1 && col_idx==11) temp.type = 1;
                    if (row_idx==1 && col_idx==12) temp.type = 1;
                    if (row_idx==1 && col_idx==13) temp.type = 1;
                    if (row_idx==2 && col_idx==9) temp.type = 1;
                    if (row_idx==2 && col_idx==10) temp.type = 1;
                    if (row_idx==2 && col_idx==11) temp.type = 1;
                    if (row_idx==2 && col_idx==12) temp.type = 1;
                    if (row_idx==2 && col_idx==13) temp.type = 1;
                    if (row_idx==3 && col_idx==9) temp.type = 1;
                    if (row_idx==3 && col_idx==10) temp.type = 1;
                    if (row_idx==3 && col_idx==11) temp.type = 1;
                    if (row_idx==3 && col_idx==12) temp.type = 1;
                    if (row_idx==3 && col_idx==13) temp.type = 1;
                    if (row_idx==6 && col_idx==6) temp.type = 1;
                    if (row_idx==6 && col_idx==7) temp.type = 1;
                    if (row_idx==7 && col_idx==6) temp.type = 1;
                    if (row_idx==7 && col_idx==7) temp.type = 1;
                    if (row_idx==8 && col_idx==6) temp.type = 1;
                    if (row_idx==8 && col_idx==7) temp.type = 1;
                    if (row_idx==9 && col_idx==6) temp.type = 1;
                    if (row_idx==9 && col_idx==7) temp.type = 1;
                    if (row_idx==10 && col_idx==6) temp.type = 1;
                    if (row_idx==10 && col_idx==7) temp.type = 1;
                    if (row_idx==15 && col_idx==3) temp.type = 1;
                    if (row_idx==15 && col_idx==4) temp.type = 1;
                    if (row_idx==15 && col_idx==5) temp.type = 1;
                    if (row_idx==15 && col_idx==6) temp.type = 1;
                    if (row_idx==15 && col_idx==7) temp.type = 1;
                    if (row_idx==16 && col_idx==3) temp.type = 1;
                    if (row_idx==16 && col_idx==4) temp.type = 1;
                    if (row_idx==16 && col_idx==5) temp.type = 1;
                    if (row_idx==16 && col_idx==6) temp.type = 1;
                    if (row_idx==16 && col_idx==7) temp.type = 1;
                    if (row_idx==17 && col_idx==3) temp.type = 1;
                    if (row_idx==17 && col_idx==4) temp.type = 1;
                    if (row_idx==17 && col_idx==5) temp.type = 1;
                    if (row_idx==17 && col_idx==6) temp.type = 1;
                    if (row_idx==17 && col_idx==7) temp.type = 1;
                    if (row_idx==18 && col_idx==3) temp.type = 1;
                    if (row_idx==18 && col_idx==4) temp.type = 1;
                    if (row_idx==18 && col_idx==5) temp.type = 1;
                    if (row_idx==18 && col_idx==6) temp.type = 1;
                    if (row_idx==18 && col_idx==7) temp.type = 1;
                    if (row_idx==3 && col_idx==18) temp.type = 1;
                    if (row_idx==3 && col_idx==19) temp.type = 1;
                    if (row_idx==4 && col_idx==18) temp.type = 1;
                    if (row_idx==4 && col_idx==19) temp.type = 1;
                    if (row_idx==5 && col_idx==18) temp.type = 1;
                    if (row_idx==5 && col_idx==19) temp.type = 1;
                    if (row_idx==6 && col_idx==18) temp.type = 1;
                    if (row_idx==6 && col_idx==19) temp.type = 1;
                    if (row_idx==7 && col_idx==18) temp.type = 1;
                    if (row_idx==7 && col_idx==19) temp.type = 1;
                    if (row_idx==8 && col_idx==18) temp.type = 1;
                    if (row_idx==8 && col_idx==19) temp.type = 1;
                    if (row_idx==9 && col_idx==18) temp.type = 1;
                    if (row_idx==9 && col_idx==19) temp.type = 1;
                    if (row_idx==10 && col_idx==18) temp.type = 1;
                    if (row_idx==10 && col_idx==19) temp.type = 1;
                    if (row_idx==15 && col_idx==13) temp.type = 1;
                    if (row_idx==15 && col_idx==14) temp.type = 1;
                    if (row_idx==15 && col_idx==15) temp.type = 1;
                    if (row_idx==15 && col_idx==16) temp.type = 1;
                    if (row_idx==15 && col_idx==17) temp.type = 1;
                    if (row_idx==16 && col_idx==13) temp.type = 1;
                    if (row_idx==16 && col_idx==14) temp.type = 1;
                    if (row_idx==16 && col_idx==15) temp.type = 1;
                    if (row_idx==16 && col_idx==16) temp.type = 1;
                    if (row_idx==16 && col_idx==17) temp.type = 1;
                    if (row_idx==17 && col_idx==13) temp.type = 1;
                    if (row_idx==17 && col_idx==14) temp.type = 1;
                    if (row_idx==17 && col_idx==15) temp.type = 1;
                    if (row_idx==17 && col_idx==16) temp.type = 1;
                    if (row_idx==17 && col_idx==17) temp.type = 1;
                    if (row_idx==18 && col_idx==13) temp.type = 1;
                    if (row_idx==18 && col_idx==14) temp.type = 1;
                    if (row_idx==18 && col_idx==15) temp.type = 1;
                    if (row_idx==18 && col_idx==16) temp.type = 1;
                    if (row_idx==18 && col_idx==17) temp.type = 1;
                    this->data[row_idx][col_idx].x = temp.x;
                    this->data[row_idx][col_idx].y = temp.y;
                    this->data[row_idx][col_idx].type = temp.type;
                }
            }
        };
        ~Map(){};
};
