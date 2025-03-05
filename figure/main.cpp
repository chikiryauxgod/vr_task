#include <gtest/gtest.h>
#include "figure.h" 
#include <memory>
#include <vector>

// Test Circle
TEST(FigureTest, CircleSquare) {
    Circle circle(5); // Radius = 5
    double expected_area = 3.14 * 5 * 5; // Pi * r^2
    EXPECT_DOUBLE_EQ(circle.Square(), expected_area);
}

// Test Triangle
TEST(FigureTest, TriangleSquare) {
    Triangle triangle(4, 6); // Base = 4, Height = 6
    double expected_area = (4 * 6) / 2; // (base * height) / 2
    EXPECT_DOUBLE_EQ(triangle.Square(), expected_area);
}

// Test Rectangle
TEST(FigureTest, RectangleSquare) {
    Rectangle rectangle(4, 6); // Width = 4, Height = 6
    double expected_area = 4 * 6; // Width * Height
    EXPECT_DOUBLE_EQ(rectangle.Square(), expected_area);
}

// Test Figure comparison (operator <)
TEST(FigureTest, Comparison) {
    
    std::vector<upf> figures;
    FigureFactory factory;

    figures.push_back(factory.CreateCircle(5.0));
    figures.push_back(factory.CreateTriangle(12.0, 8.0));
    figures.push_back(factory.CreateRectangle(6.0, 8.0));

    // Sort figures based on their areas using the overloaded operator<
    std::sort(figures.begin(), figures.end(), [](const upf& a, const upf& b) {
        return *a < *b;
    });

    // After sorting, the first element should be the triangle or rectangle (simmilar)
    EXPECT_EQ(figures[0]->Square(), 48);
    // The second element should be the  triangle or rectangle again (simmilar)
    EXPECT_EQ(figures[1]->Square(), 48);
    // The last element should be the circle (largest area)
    EXPECT_DOUBLE_EQ(figures[2]->Square(), 78.5);
}

// Test Figure Factory (creation of different shapes)
TEST(FigureFactoryTest, CreateFigures) {
    FigureFactory factory;

    auto circle = factory.CreateCircle(5);
    EXPECT_DOUBLE_EQ(circle->Square(), 3.14 * 5 * 5);

    auto triangle = factory.CreateTriangle(4, 6);
    EXPECT_DOUBLE_EQ(triangle->Square(), (4 * 6) / 2);

    auto rectangle = factory.CreateRectangle(4, 6);
    EXPECT_DOUBLE_EQ(rectangle->Square(), 4 * 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
