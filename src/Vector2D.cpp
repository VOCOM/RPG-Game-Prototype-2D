#include "Vector2D.hpp"

Vector2D::Vector2D() :x(0.0f), y(0.0f) {

}

Vector2D::Vector2D(float x, float y) :x(x), y(y) {

}

Vector2D& Vector2D::Zero() {
	x = 0.0f;
	y = 0.0f;
	return *this;
}

// Arithmetic Operations
Vector2D& Vector2D::Add(const Vector2D& vec) {
	x += vec.x;
	y += vec.y;
	return *this;
}
Vector2D& Vector2D::Subtract(const Vector2D& vec) {
	x -= vec.x;
	y -= vec.y;
	return *this;
}
Vector2D& Vector2D::Multiply(const Vector2D& vec) {
	x *= vec.x;
	y *= vec.y;
	return *this;
}
Vector2D& Vector2D::Divide(const Vector2D& vec) {
	x /= vec.x;
	y /= vec.y;
	return *this;
}

// Vector Arithmetic Operators
Vector2D& operator+(Vector2D& lhs, const Vector2D& rhs) {
	return lhs.Add(rhs);
}
Vector2D& operator-(Vector2D& lhs, const Vector2D& rhs) {
	return lhs.Subtract(rhs);
}
Vector2D& operator*(Vector2D& lhs, const Vector2D& rhs) {
	return lhs.Multiply(rhs);
}
Vector2D& operator/(Vector2D& lhs, const Vector2D& rhs) {
	return lhs.Divide(rhs);
}

// Scalar Arithmetic Operators
Vector2D& Vector2D::operator*(const int& scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}

// Compound Assignment Operators
Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
	return this->Add(rhs);
}
Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
	return this->Subtract(rhs);
}
Vector2D& Vector2D::operator*=(const Vector2D& rhs) {
	return this->Multiply(rhs);
}
Vector2D& Vector2D::operator/=(const Vector2D& rhs) {
	return this->Divide(rhs);
}

// Output stream Operator
std::ostream& operator<<(std::ostream& os, const Vector2D& rhs) {
	os << "(" << rhs.x << "," << rhs.y << ")";
	return os;
}