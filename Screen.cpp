#include "Screen.h"

Screen::Screen(int width ,int height): width(0), height(0) {
	this->width = width;
	this->height = height;



}
int Screen::getWidth() const {
	return width;
}
int Screen::getHeight() const {
	return height;
}
void Screen::setWidth(int width) {
	this->width = width;
}
void Screen::setHeight(int height) {
	this->height = height;
}
