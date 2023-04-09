#pragma once
class Circle
{
private:
	float radius;
	float pi;

public:
	Circle();
	Circle(float);
	
	/* Getters */
	float getRadius() const;
	float getPi() const;
	float getArea() const;
	float getDiameter() const;
	float getCircumference() const;

	/* Setters*/
	void setRadius(float);
	void setPi(float);
};

