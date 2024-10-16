#pragma once
#include "Point.h"
namespace Vector
{
	class Vector
	{
	private:
		/*
		*@brief ������
		*/
		Point::Point vector;

	public:
		/**
		*@breaf ����������� ��� ������ ������ �� ���� ������.
		*@param start-����� ������ �������.
		*@param end-����� ����� �������.
		*/
		Vector(const Point::Point& start, const Point::Point& end);
		/*
		*@brief �������� "<<" ��� ������ Vector.
		*/
		friend std::ostream& operator<<(std::ostream& output, const Vector& vector);
		/*
		*@brief �������� "==" ��� ������ Vector.
		*/
		bool operator == (const Vector& vector)const;
		/*
		*@brief �������� "!=" ��� ������ Vector.
		*/
		bool operator != (const Vector& vector)const;
		/*
		*@brief �������� "+" ��� ������ Vector.
		*@return ���������� ������, ���������� �������� ����� ����� ������ ��������.
		*/
		Vector operator + (const Vector& other_vector);
		/*
		*@brief �������� "-" ��� ������ Vector.
		*@return ���������� ������, ���������� �������� ����� ������ ������ ��������.
		*/
		Vector operator - (const Vector& other_vector);
		/*
		*@brief �������� "*" ��� ������ Vector.
		*@return ���������� ������, ���������� �������� �������� �� ������.
		*/
		Vector operator * (const double value);
};
}
