#include "Circle.h"

Circle::Circle()
{
	pi = 3.14159;
	radius = 0.0;
}

Circle::Circle(float radius)
{
	pi = 3.14159;
	Circle::radius = radius;
}

/* Getters */
float Circle::getRadius() const
{
	return radius;
};

float Circle::getPi() const
{
	return pi;
};

float Circle::getArea() const
{
	return pi * radius * radius;
}

float Circle::getDiameter() const
{
	return radius * 2;
}

float Circle::getCircumference() const
{
	return 2 * pi * radius;
}

/* Setters*/
void Circle::setRadius(float v)
{
	radius = v;
};

void Circle::setPi(float v)
{
	pi = v;
};