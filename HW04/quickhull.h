#ifndef QUICKHULL_H
#define QUICKHULL_H

#include <vector>


struct Point
{
    double x;
    double y;
};


std::vector<size_t> quickhull(const std::vector<Point> &points);


#endif  // QUICKHULL_H
