#pragma once
#include "Point.h"
namespace Vector
{
	class Vector
	{
	private:
		/*
		*@brief Вектор
		*/
		Point::Point vector;

	public:
		/**
		*@breaf Конструктор для класса вектор по двум точкам.
		*@param start-точка начала вектора.
		*@param end-точка конца вектора.
		*/
		Vector(const Point::Point& start, const Point::Point& end);
		/*
		*@brief оператор "<<" для класса Vector.
		*/
		friend std::ostream& operator<<(std::ostream& output, const Vector& vector);
		/*
		*@brief оператор "==" для класса Vector.
		*/
		bool operator == (const Vector& vector)const;
		/*
		*@brief оператор "!=" для класса Vector.
		*/
		bool operator != (const Vector& vector)const;
		/*
		*@brief оператор "+" для класса Vector.
		*@return Возвращает вектор, координаты которого равны сумме других векторов.
		*/
		Vector operator + (const Vector& other_vector);
		/*
		*@brief оператор "-" для класса Vector.
		*@return Возвращает вектор, координаты которого равны разнце других векторов.
		*/
		Vector operator - (const Vector& other_vector);
		/*
		*@brief оператор "*" для класса Vector.
		*@return Возвращает вектор, координаты которого умножены на скаляр.
		*/
		Vector operator * (const double value);
};
}
