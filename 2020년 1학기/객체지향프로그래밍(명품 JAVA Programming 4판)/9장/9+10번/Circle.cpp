#include "Circle.h"
#include "UI.h"

Circle::Circle(int radius, const Point &center) {
	this->radius = radius;
	this->center = center;
}
void Circle::draw() {
	UI::println("Circle " + to_string(radius) + " " + center.toString());
}
void Circle::move(int width, int height) {
	center.move(width, height);
}
