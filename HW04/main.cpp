#include "quickhull.h"
#include <vector>
using std::vector;


int main(int argc, char *argv[])
{
    auto ch = quickhull(vector<Point>{ {0,0},{1,0},{0,1},{1,1},{0.5,0.5} });
    return 0;
}
