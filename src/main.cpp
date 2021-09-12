#include "map/map.h"
#include "robot/robot.h"

int main()
{
    Map room;
    Cleaner robot;
    int control;
    room.ShowMap();
    robot.SetMap(room);
    robot.SetDirection(1, 3, 2);
    robot.GetCurrent();
    while (true)
    {
        robot.FindPath();
        robot.GetCurrent();
        robot.ShowMap();
        cout << "Stop (1/0)?";
        cin >> control;
        if (control == 0) break; 
    }
    return 1;
}
