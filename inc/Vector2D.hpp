/*****************************************************************//**
 * \file   Vector2D.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   22/01/2024
 *********************************************************************/

#pragma once
#include <ostream>

//TODO: Normalise Function

class Vector2D {
public:
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	Vector2D& Add(const Vector2D&);
	Vector2D& Subtract(const Vector2D&);
	Vector2D& Multiply(const Vector2D&);
	Vector2D& Divide(const Vector2D&);

	friend Vector2D& operator+(Vector2D&, const Vector2D&);
	friend Vector2D& operator-(Vector2D&, const Vector2D&);
	friend Vector2D& operator*(Vector2D&, const Vector2D&);
	friend Vector2D& operator/(Vector2D&, const Vector2D&);

	Vector2D& operator+=(const Vector2D&);
	Vector2D& operator-=(const Vector2D&);
	Vector2D& operator*=(const Vector2D&);
	Vector2D& operator/=(const Vector2D&);

	friend std::ostream& operator<<(std::ostream&, const Vector2D&);
};
