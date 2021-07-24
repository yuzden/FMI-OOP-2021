#include "Vector4D.hpp"

Vector4D::Vector4D(double a, double b, double c, double d) 
{
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
}

Vector4D::Vector4D()
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
}

void Vector4D::setVector(double newArr[])
{
	for (int i = 0; i < 4; i++) {
		arr[i] = newArr[i];
	}
}

double& Vector4D::operator[](unsigned int index)
{
	return arr[index];
}

Vector4D Vector4D::operator+(const Vector4D& rhs) const
{
	return Vector4D(arr[0] + rhs.arr[0], arr[1] + rhs.arr[1], arr[2] + rhs.arr[2], arr[3] + rhs.arr[3]);
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		arr[i] += rhs.arr[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const
{
	return Vector4D(arr[0] - rhs.arr[0], arr[1] - rhs.arr[1], arr[2] - rhs.arr[2], arr[3] - rhs.arr[3]);
}

Vector4D& Vector4D::operator-=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		arr[i] -= rhs.arr[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& rhs) const
{
	return Vector4D(arr[0] * rhs.arr[0], arr[1] * rhs.arr[1], arr[2] * rhs.arr[2], arr[3] * rhs.arr[3]);
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		arr[i] *= rhs.arr[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const double x) const
{
	return Vector4D(x * arr[0], x * arr[1], x * arr[2], x * arr[3]);
}

Vector4D& Vector4D::operator*=(const double x)
{
	for (int i = 0; i < 4; i++) {
		arr[i] *= x;
	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& rhs) const
{
	return Vector4D(arr[0] / rhs.arr[0], arr[1] / rhs.arr[1], arr[2] / rhs.arr[2], arr[3] / rhs.arr[3]);
}

Vector4D& Vector4D::operator/=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		arr[i] /= rhs.arr[i];
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (arr[i] != rhs.arr[i]) {
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!=(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (arr[i] != rhs.arr[i]) {
			return true;
		}
	}
	return false;
}

bool Vector4D::operator>(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (arr[i] > rhs.arr[i]) {
			return true;
		}
	}
	return false;
}

bool Vector4D::operator>=(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (arr[i] < rhs.arr[i]) {
			return false;
		}
	}
	return true;
}

bool Vector4D::operator<(const Vector4D rhs) const
{
	if (*this == rhs) return false;
	return !(*this > rhs);
}

bool Vector4D::operator<=(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (arr[i] > rhs.arr[i]) {
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!() const
{
	for (int i = 0; i < 4; i++) {
		if (arr[i] != 0) {
			return false;
		}
	}
	return true;
}

Vector4D Vector4D::operator-() const
{
	return Vector4D(-arr[0], -arr[1], -arr[2], -arr[3]);
}
