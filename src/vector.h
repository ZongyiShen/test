#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
#include <cmath>
#include "bubbleSort.h"
using namespace std;
class Vector;
Vector centroid(Vector vec[], int sides);
double distance(Vector u, Vector v);
double area(Vector u, Vector v, Vector w);
double area(Vector a[], int sides);
double perimeter(Vector a[], int sides);
class Vector
{
public:
    Vector()
    { //default constructor
        _dim = 0;
        _v = new double[_dim];
    }
    Vector(int dim)
    {
        _v = new double[dim];
        _dim = dim;
        for (int i = 0; i < dim; i++)
        {
            _v[i] = 0;
        }
    }
    Vector(double v[], int dim)
    { //constructor
        if (v != NULL)
        {
            copy(dim, v);
        }
        else
        {
            _dim = dim;
            _v = new double[dim];
        }
    }

    Vector(Vector const &v)
    {
        copy(v._dim, v._v);
    }

    // destructor
    ~Vector()
    {
        if (_v != NULL)
        {
            delete[] _v;
        }
    }

    // constant member function
    int dim() const
    {
        return _dim;
    }

    double &at(int i) const
    {
        return _v[i - 1];
    }

    void subtract(Vector const &v)
    {
        if (_dim != v._dim)
        {
            throw string("undefined");
        }
        for (int i = 0; i < _dim; i++)
        {
            _v[i] = _v[i] - v._v[i];
        }
    }

    void add(Vector const &v)
    {
        if (_dim != v._dim)
        {
            throw string("undefined");
        }
        for (int i = 0; i < _dim; i++)
        {
            _v[i] = _v[i] + v._v[i];
        }
    }

    Vector &operator=(Vector const &u)
    {
        if (_v != NULL)
        {
            delete[] _v;
        }
        copy(u._dim, u._v);
        return *this;
    }

    Vector operator-(Vector const &v) const
    {
        if (_dim != v._dim)
        {
            throw string("undefined");
        }
        double *temp;
        temp = new double[_dim];
        for (int i = 0; i < _dim; i++)
        {
            temp[i] = _v[i] - v._v[i];
        }
        return Vector(temp, _dim);
    }

    Vector operator+(Vector const &v) const
    {
        if (_dim != v._dim)
        {
            throw string("undefined");
        }
        double *temp;
        temp = new double[_dim];
        for (int i = 0; i < _dim; i++)
        {
            temp[i] = _v[i] + v._v[i];
        }
        return Vector(temp, _dim);
    }
    double dot(Vector input)
    {
        double result = 0;
        //input.len also works, beacuse
        // input is an object of the same class
        if (_dim != input.dim())
        {
            throw string("ERROR");
        }
        for (int i = 0; i < _dim; i++)
        {
            // input.content[i] also works, beacuse
            // input is an object of the same class
            result += _v[i] * input._v[i];
        }
        return result;
    }

    double length() const
    {
        double s = 0;
        for (int i = 0; i < _dim; i++)
        {
            s += _v[i] * _v[i];
        }
        return sqrt(s);
    }
    bool larger180(Vector input)
    {
        return (this->at(1) * input.at(2) - this->at(2) * input.at(1)) >= 0;
    }
    double angle(Vector input)
    {
        double sum1 = 0, sum2 = 0;
        sum1 = this->dot(input);
        sum2 = this->length() * input.length();
        if (this->larger180(input))
        {
            return 360 - acos(sum1 / sum2) * 180 / M_PI;
        }
        return acos(sum1 / sum2) * 180 / M_PI;
    }

    friend Vector centroid(Vector vec[], int sides);
    friend double distance(Vector u, Vector v);
    friend double area(Vector u, Vector v, Vector w);
    friend double area(Vector a[], int sides);
    friend double perimeter(Vector a[], int sides);

private:
    int _dim;
    double *_v;
    void copy(int dim, double v[])
    { //initialize
        _v = new double[dim];
        _dim = dim;
        for (int i = 0; i < dim; i++)
        {
            _v[i] = v[i];
        }
    }
};
class angleComparator
{
private:
    Vector _a;
    Vector _b;

public:
    angleComparator()
    {
    }

    angleComparator(Vector &a, Vector &b)
    {
        _a = a;
        _b = b;
    }

    bool operator()(Vector &u, Vector &v)
    {
        return _b.angle(u - _a) < _b.angle(v - _a);
    }
};
Vector centroid(Vector vec[], int sides)
{ //回傳多個 vector 所組成的重心
    for (int i = 0; i < sides; i++)
    {
        if (vec[i].dim() != 2)
        {
            throw string("Error");
        }
    }
    if (vec == NULL || sides == 0)
    {
        throw string("Error");
    }
    else
    {
        Vector cent(vec[0].dim());
        for (int i = 0; i < sides; i++)
        {
            for (int j = 0; j < cent.dim(); j++)
            {
                cent._v[j] += vec[i]._v[j];
            }
        }
        for (int j = 0; j < cent.dim(); j++)
        {
            cent._v[j] /= sides;
        }
        return cent;
    }
}
double distance(Vector u, Vector v)
{
    double sum = 0;
    for (int i = 0; i < u.dim(); i++)
    {
        sum += (u.at(i + 1) - v.at(i + 1)) * (u.at(i + 1) - v.at(i + 1));
    }
    return sqrt(sum);
}
double area(Vector u, Vector v, Vector w)
{
    double s1, s2, s3;
    s1 = distance(u, v);
    s2 = distance(v, w);
    s3 = distance(w, u);
    double s = (s1 + s2 + s3) / 2;
    double area = s * (s - s1) * (s - s2) * (s - s3);
    return sqrt(area);
}
double area(Vector a[], int sides)
{
    Vector c = centroid(a, sides);
    Vector b = a[0] - c;
    angleComparator comp = angleComparator(c, b);
    BubbleSort(a, a + sides, comp);
    double ae = 0;
    for (int i = 1; i < sides - 1; i++)
    {
        ae += area(a[0], a[i], a[i + 1]);
    }
    return ae;
}
double perimeter(Vector a[], int sides)
{
    Vector c = centroid(a, sides);
    Vector b = a[0] - c;
    angleComparator comp = angleComparator(c, b);
    BubbleSort(a, a + sides, comp);
    double d = 0;
    for (int i = 0; i < sides - 1; i++)
    {
        d += distance(a[i], a[i + 1]);
    }
    d += distance(a[0], a[sides - 1]);
    return d;
}
#endif
