#pragma once
#include "Point.h"

class Rect
{
private:
	Point* m_point1;
	Point* m_point2;

public:
	// Default constructor
	Rect();

	// Constructor
	Rect(Point* point1, Point* point2);

	// Get point 1
	Point getPoint1() const;

	// Get point 2
	Point getPoint2() const;

	// De-constructor
	virtual ~Rect();

	// Area
	int area();
};
