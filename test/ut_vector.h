#include "../src/vector.h"
#include <cmath>
class PolygonTest : public ::testing::Test
{ // test fixture, PolygonTest: derived class, Test: base class
protected:
    void SetUp() override
    {
        double a[2] = {1, 0},
               b[2] = {4, 0},
               c[2] = {4, 4},
               d[2] = {1, 4},
               q[3] = {1, 2, 3},
               p[3] = {7, 8, 7};
        u[0] = Vector(a, 2);
        u[1] = Vector(b, 2);
        u[2] = Vector(c, 2);
        u[3] = Vector(d, 2);
        x = Vector(q, 3);
        y = Vector(p, 3);
    }
    Vector u[4], x, y;
};
class PolygonTest2 : public ::testing::Test
{ // test fixture, PolygonTest: derived class, Test: base class
protected:
    void SetUp() override
    {
        double a[2] = {1, 0},
               b[2] = {4, 0},
               c[2] = {4, 4},
               d[2] = {1, 4},
               e[2] = {6, 2},
               q[3] = {1, 2, 3},
               p[3] = {7, 8, 7};
        u[0] = Vector(a, 2);
        u[1] = Vector(b, 2);
        u[2] = Vector(c, 2);
        u[3] = Vector(d, 2);
        u[4] = Vector(e, 2);
        v[0] = Vector(q, 3);
        v[1] = Vector(p, 3);
    }
    Vector u[5], v[2];
};

TEST_F(PolygonTest, CHKCENTROID)
{
    Vector r = centroid(u, 4);
    ASSERT_NEAR(2.5, r.at(1), 0.01);
    ASSERT_NEAR(2, r.at(2), 0.01);
}
TEST_F(PolygonTest, CHKDISTANCE)
{
    double d = distance(u[0], u[1]);
    ASSERT_NEAR(3, d, 0.01);
    double d2 = distance(x, y);
    ASSERT_NEAR(9.3808, d2, 0.01);
}
TEST_F(PolygonTest, CHKAREA)
{
    double a = area(u[0], u[1], u[2]);
    ASSERT_NEAR(6, a, 0.01);
    double a2 = area(u[3], u[1], u[2]);
    ASSERT_NEAR(6, a2, 0.01);
}
TEST_F(PolygonTest, CHKAREA2)
{
    double a = area(u, 4);
    ASSERT_NEAR(12, a, 0.01);
}
TEST_F(PolygonTest, CHKPER)
{
    double a = perimeter(u, 4);
    ASSERT_NEAR(14, a, 0.01);
}
TEST_F(PolygonTest, CHKCENTROIDEXCEPTION)
{
    ASSERT_ANY_THROW(centroid(u, 0));
}

TEST_F(PolygonTest2, CHKAREA)
{
    double a = area(u, 5);
    ASSERT_NEAR(16, a, 0.01);
}
TEST_F(PolygonTest2, CHKCENTROIDEXCEPTION)
{
    ASSERT_ANY_THROW(centroid(v, 2));
}
