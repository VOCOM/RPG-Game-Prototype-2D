#include "Vector2D.hpp"

// Constructors
Vector2D::Vector2D() :x(0.0f), y(0.0f) {

}
Vector2D::Vector2D(float x, float y) :x(x), y(y) {

}

Vector2D& Vector2D::Zero() {
	x = 0.0f;
	y = 0.0f;
	return *this;
}

// Scalar arithmetic
Vector2D Vector2D::operator+(const int& scalar) {
	return Vector2D(x + scalar, y + scalar);
}
Vector2D Vector2D::operator-(const int& scalar) {
	return Vector2D(x - scalar, y - scalar);
}
Vector2D Vector2D::operator*(const int& scalar) {
	return Vector2D(x * scalar, y * scalar);
}
Vector2D Vector2D::operator/(const int& scalar) {
	return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator+=(const int& scalar) {
	x += scalar;
	y += scalar;
	return *this;
}
Vector2D& Vector2D::operator-=(const int& scalar) {
	x -= scalar;
	y -= scalar;
	return *this;
}
Vector2D& Vector2D::operator*=(const int& scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}
Vector2D& Vector2D::operator/=(const int& scalar) {
	x /= scalar;
	y /= scalar;
	return *this;
}

// Vector arithmetic
Vector2D Vector2D::operator+(const Vector2D& vec) {
	return Vector2D(x + vec.x, y + vec.y);
}
Vector2D Vector2D::operator-(const Vector2D& vec) {
	return Vector2D(x - vec.x, y - vec.y);
}
Vector2D Vector2D::operator*(const Vector2D& vec) {
	return Vector2D(x * vec.x, y * vec.y);
}
Vector2D Vector2D::operator/(const Vector2D& vec) {
	return Vector2D(x / vec.x, y / vec.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec) {
	x += vec.x;
	y += vec.y;
	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& vec) {
	x -= vec.x;
	y -= vec.y;
	return *this;
}
Vector2D& Vector2D::operator*=(const Vector2D& vec) {
	x *= vec.x;
	y *= vec.y;
	return *this;
}
Vector2D& Vector2D::operator/=(const Vector2D& vec) {
	x /= vec.x;
	y /= vec.y;
	return *this;
}

// Output stream Operator
std::ostream& operator<<(std::ostream& os, const Vector2D& rhs) {
	os << "(" << rhs.x << "," << rhs.y << ")";
	return os;
}