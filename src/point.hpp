#ifndef __POINT__HPP__
#define __POINT__HPP__

class Point
{
private:
    int x;
    int y;
    int z;
public:
    Point();
    Point(int, int, int);
    ~Point();

    void operator=(const Point&);

    int getX();
    int getY();
    int getZ();
    void setX(int);
    void setY(int);
    void setZ(int);



    double getDistance(Point);
    void printPoint();
    //void quicksort(array<Point, 1000>);
};



#endif