#include "Vector.h"
#include "cmath"

Vector::Vector::Vector(const Point::Point& start, const Point::Point& end)
{
	Point::Point temporary(end.x - start.x, end.y - start.y, end.z - start.z);
	this->vector = temporary;
}

std::ostream& Vector::operator<<(std::ostream& output, const Vector& vector)
{
	output << vector.vector;
	return output;
}

bool Vector::Vector::operator==(const Vector& vector) const
{
	return(this->vector == vector.vector);
}

bool Vector::Vector::operator!=(const Vector& vector) const
{
	return !(*this == vector);
}

Vector::Vector Vector::Vector::operator+(const Vector& other_vector)
{
	Vector result{ *this };
	result.vector.x += other_vector.vector.x;
	result.vector.y += other_vector.vector.y;
	result.vector.z += other_vector.vector.z;
	return result;
}

Vector::Vector Vector::Vector::operator-(const Vector& other_vector)
{
	Vector result{ *this };
	result.vector.x -= other_vector.vector.x;
	result.vector.y -= other_vector.vector.y;
	result.vector.z -= other_vector.vector.z;
	return result;
}

Vector::Vector Vector::Vector::operator*(const double value)
{
	Vector result{ *this };
	result.vector.x *= value;
	result.vector.y *= value;
	result.vector.z *= value;
	return result;
}