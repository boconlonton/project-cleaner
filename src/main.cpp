#include "map/map.h"
#include "robot/robot.h"

int main()
{
    Map room;
    Cleaner robot;
    room.ShowMap();
    robot.SetMap(room);
    robot.SetDirection(1, 3, 2);
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    robot.FindPath();
    robot.GetCurrent();
    return 1;
}
