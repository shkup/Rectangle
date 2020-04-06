#include "Rect.h"

#include <cstdlib>
using namespace std;

Rect::Rect() {
	this->m_point1 = NULL;
	this->m_point2 = NULL;
}

Rect::Rect(Point* point1, Point* point2)
{
	this->m_point1 = point1;
	this->m_point2 = point2;
}

Point Rect::getPoint1() const
{
	return *(this->m_point1);
}

Point Rect::getPoint2() const
{
	return *(this->m_point2);
}

Rect::~Rect()
{
	delete this->m_point1;
	delete this->m_point2;
}

int Rect::area()
{
	int a = abs(this->getPoint1().getX() - this->getPoint2().getX());
	int b = abs(this->getPoint1().getY() - this->getPoint2().getY());

	return a * b;
}
