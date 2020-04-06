#pragma once

class Point
{
private:
	int m_x;
	int m_y;

public:
	
	// Default constructor
	Point();

	// Constructor
	Point(int x, int y);

	// De-constructor
	virtual ~Point();

	// Assign operator
	Point& operator=(const Point& other);

	// X getter
	int getX() const;

	// Y getter
	int getY() const;
};
