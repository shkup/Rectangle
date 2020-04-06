#include "Point.h"
#include<stdexcept>

Point::Point() {

}

Point::Point(int x, int y) {
	this->m_x = x;
	this->m_y = y;
}

int Point::getX() const{
	return m_x;
}

int Point::getY() const {
	return m_y;
}

// Assignment operator
Point& Point::operator=(const Point& other)
{
	this->m_x = other.getX();
	this->m_y = other.getY();

	return *this;
}

Point::~Point() {

}