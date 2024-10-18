#pragma once
#include <iostream>

namespace Point
{
	struct Point
	{
		/**
		*@breaf Абсцисса точки.
		*/
		double x = 0;
		/**
		*@breaf Ордината точки.
		*/
		double y = 0;
		/**
		*@breaf Аппликата точки.
		*/
		double z = 0;

		/**
		*@breaf Создает экземляр класса Point.
		*@param Абсцисса точки.
		*@param Ордината точки.
		*@param Аппликата точки.
		*/
		Point(const double abscissa = 0, const double ordinate = 0, const double applicate = 0);
		/*
		*@brief оператор "==" для класса Point.
		*/
		bool operator == (const Point& point)const;
		/*
		*@brief оператор "!=" для класса Point.
		*/
		bool operator != (const Point& point)const;
		/*
		*@brief оператор "<<" для класса Point.
		*/
		friend std::ostream& operator<<(std::ostream& output, const Point& point);
		/*
		*@brief оператор ">>" для класса Point.
		*/
		friend std::istream& operator>>(std::istream& input, Point& point);

	};
}
