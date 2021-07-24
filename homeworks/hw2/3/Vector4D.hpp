#pragma once

class Vector4D {

public:
   
    Vector4D(double, double, double, double);

    Vector4D();

    void setVector(double[] );
    double& operator[](unsigned int);

    Vector4D operator+(const Vector4D&) const ;
    Vector4D& operator+=(const Vector4D&);

    Vector4D operator-(const Vector4D&) const;
    Vector4D& operator-=(const Vector4D&);

    Vector4D operator*(const Vector4D&) const;
    Vector4D& operator*=(const Vector4D&);

    Vector4D operator*(const double) const;
    Vector4D& operator*=(const double);

    Vector4D operator/(const Vector4D&) const;
    Vector4D& operator/=(const Vector4D&);

    bool operator==(const Vector4D) const;
    bool operator!=(const Vector4D) const;

    bool operator>(const Vector4D) const;
    bool operator>=(const Vector4D) const;

    bool operator<(const Vector4D) const;
    bool operator<=(const Vector4D) const;

    bool operator!() const;

    Vector4D operator-() const;

private:
    double arr[4];
    
};