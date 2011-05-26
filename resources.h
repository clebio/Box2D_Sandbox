/*
 * resources.h
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

 #define DEBUG

#include <math.h>
#include <cstdio>

#ifdef DEBUG
#define LOG(msg) printf("%s\n", msg);
#else
#define LOG(msg)
#endif


using namespace std;

// Class to represent points.
class Point {
private:
        double xval, yval;
public:
        // Constructor uses default arguments to allow calling with zero, one,
        // or two values.
        Point(double x = 0.0, double y = 0.0) {
                xval = x;
                yval = y;
        }

        // Extractors.
        double x() { return xval; }
        double y() { return yval; }

        // Distance to another point.  Pythagorean thm.
        double dist(Point other) {
                double xd = xval - other.xval;
                double yd = yval - other.yval;
                return sqrt(xd*xd + yd*yd);
        }
};

#endif /* RESOURCES_H_ */
