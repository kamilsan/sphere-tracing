#include <gtest/gtest.h>

#include "Vector.hpp"

TEST(VectorTest, Constructors)
{
  const Vector a{};
  const Vector b{1.0f, 2.0f, 3.0f};

  EXPECT_EQ(a.x, 0.0f);
  EXPECT_EQ(a.y, 0.0f);
  EXPECT_EQ(a.z, 0.0f);

  EXPECT_EQ(b.x, 1.0f);
  EXPECT_EQ(b.y, 2.0f);
  EXPECT_EQ(b.z, 3.0f);
}

TEST(VectorTest, Comparison)
{
  const Vector a{2.0f, 2.0f, 4.0f};
  const Vector b{1.0f, 2.0f, 3.0f};
  const Vector c{1.0f, 2.0f, 3.0f};

  EXPECT_TRUE(a != b);
  EXPECT_TRUE(a != c);
  EXPECT_TRUE(b == c);

  EXPECT_FALSE(a == b);
  EXPECT_FALSE(a == c);
  EXPECT_FALSE(b != c);
}

TEST(VectorTest, LengthSq)
{
  const Vector a{};
  const Vector b{1.0f, 2.0f, 3.0f};

  EXPECT_FLOAT_EQ(a.lengthSq(), 0.0f);
  EXPECT_NEAR(b.lengthSq(), 14.0f, 0.0001f);
}

TEST(VectorTest, Length)
{
  const Vector a{};
  const Vector b{4.0f, 8.0f, 19.0f};

  EXPECT_FLOAT_EQ(a.length(), 0.0f);
  EXPECT_NEAR(b.length(), 21.0f, 0.0001f);
}

TEST(VectorTest, Normalization)
{
  const Vector a{4.0f, 8.0f, 19.0f};
  const Vector n = a.normalized();

  EXPECT_FLOAT_EQ(n.length(), 1.0f);
  EXPECT_NEAR(n.x, 4.0f/21.0f, 0.0001f);
  EXPECT_NEAR(n.y, 8.0f/21.0f, 0.0001f);
  EXPECT_NEAR(n.z, 19.0f/21.0f, 0.0001f);
}

TEST(VectorTest, Clone)
{
  const Vector a{1.0f, 2.0f, 3.0f};
  const Vector b = a.clone();

  EXPECT_FLOAT_EQ(a.x, b.x);
  EXPECT_FLOAT_EQ(a.y, b.y);
  EXPECT_FLOAT_EQ(a.z, b.z);
}

TEST(VectorTest, DotProduct)
{
  const Vector a{2, 1, 3};
  const Vector b{4, 6, 5};

  EXPECT_EQ(a.dot(b), 29);
}

TEST(VectorTest, CrossProduct)
{
  const Vector a{2, 1, 3};
  const Vector b{4, 6, 5};

  const Vector cross = a.cross(b);

  EXPECT_EQ(cross.x, -13);
  EXPECT_EQ(cross.y, 2);
  EXPECT_EQ(cross.z, 8);
}

TEST(VectorTest, Addition)
{
  Vector a{1, 2, 3};
  const Vector b{3, 4, 5};

  const Vector result{4, 6, 8};
  EXPECT_EQ(a + b, result);

  a += b;
  EXPECT_EQ(a, result);
}

TEST(VectorTest, Subtraction)
{
  Vector a{4, 6, 10};
  const Vector b{1, 2, 3};

  const Vector result{3, 4, 7};
  EXPECT_EQ(a - b, result);

  a -= b;
  EXPECT_EQ(a, result);
}

TEST(VectorTest, Multiplication)
{
  Vector a{1, 2, 3};
  const float scalar = -2.0f;

  const Vector result{-2, -4, -6};
  EXPECT_EQ(a * scalar, result);

  a *= scalar;
  EXPECT_EQ(a, result);
}

TEST(VectorTest, Division)
{
  Vector a{2, 4, 6};
  const float scalar = -2.0f;

  const Vector result{-1.0f, -2.0f, -3.0f};
  EXPECT_EQ(a / scalar, result);

  a /= scalar;
  EXPECT_EQ(a, result);
}