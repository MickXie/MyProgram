#include <iostream>
using namespace std;

class Matrix
{
private:
    int m[2][2];

public:
    Matrix(int a11 = 0, int a12 = 0, int a21 = 0, int a22 = 0)
    {
        m[0][0] = a11;
        m[0][1] = a12;
        m[1][0] = a21;
        m[1][1] = a22;
    }

    Matrix operator+(const Matrix &rhs) const
    {
        return Matrix(
            m[0][0] + rhs.m[0][0],
            m[0][1] + rhs.m[0][1],
            m[1][0] + rhs.m[1][0],
            m[1][1] + rhs.m[1][1]);
    }

    Matrix operator-(const Matrix &rhs) const
    {
        return Matrix(
            m[0][0] - rhs.m[0][0],
            m[0][1] - rhs.m[0][1],
            m[1][0] - rhs.m[1][0],
            m[1][1] - rhs.m[1][1]);
    }

    Matrix operator*(const Matrix &rhs) const
    {
        return Matrix(
            m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0],
            m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1],
            m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0],
            m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1]);
    }

    Matrix operator-() const
    {
        return Matrix(
            -m[0][0],
            -m[0][1],
            -m[1][0],
            -m[1][1]);
    }

    friend Matrix operator*(int k, const Matrix &A)
    {
        return Matrix(
            k * A.m[0][0],
            k * A.m[0][1],
            k * A.m[1][0],
            k * A.m[1][1]);
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &A)
    {
        os << "[ " << A.m[0][0] << " " << A.m[0][1] << " ]" << std::endl;
        os << "[ " << A.m[1][0] << " " << A.m[1][1] << " ]" << std::endl;
        return os;
    }
};

int main()
{
    int a11, a12, a21, a22,
        b11, b12, b21, b22;
    std::cin >> a11 >> a12 >> a21 >> a22 >> b11 >> b12 >> b21 >> b22;
    Matrix A(a11, a12, a21, a22),
        B(b11, b12, b21, b22);
    std::cout << A + B << std::endl;
    std::cout << A - B << std::endl;
    std::cout << A * B << std::endl;
    std::cout << -A << std::endl;
    std::cout << 2 * B << std::endl;
    return 0;
}