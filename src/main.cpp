#include "map/map.h"
#include "robot/robot.h"

int main()
{
    Map room;
    Cleaner robot;
    room.ShowMap();
    robot.setMap(room);
    robot.setDirection(1, 3, 2);
    robot.getCurrent();
    robot.FindPath();
    robot.getCurrent();
    robot.FindPath();
    robot.getCurrent();
    robot.FindPath();
    robot.getCurrent();
    robot.FindPath();
    robot.getCurrent();
    robot.FindPath();
    robot.getCurrent();
    robot.FindPath();
    robot.getCurrent();
    robot.FindPath();
    robot.getCurrent();
    return 1;
}
