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

	Vector2D& Zero();

	// Scalar arithmetic
	Vector2D operator+(const int&);
	Vector2D operator-(const int&);
	Vector2D operator*(const int&);
	Vector2D operator/(const int&);

	Vector2D& operator+=(const int&);
	Vector2D& operator-=(const int&);
	Vector2D& operator*=(const int&);
	Vector2D& operator/=(const int&);

	// Vector arithmetic
	Vector2D operator+(const Vector2D&);
	Vector2D operator-(const Vector2D&);
	Vector2D operator*(const Vector2D&);
	Vector2D operator/(const Vector2D&);
	
	Vector2D& operator+=(const Vector2D&);
	Vector2D& operator-=(const Vector2D&);
	Vector2D& operator*=(const Vector2D&);
	Vector2D& operator/=(const Vector2D&);

	friend std::ostream& operator<<(std::ostream&, const Vector2D&);
};
