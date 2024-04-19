/*
 * vect2
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#include "vect2.h"
// Start of user code  : Additional imports for vect2
// End of user code

vect2::vect2() {}
vect2::~vect2() {}

vect2::vect2(double varx, double vary) {
    x = varx;
    y = vary;
}

double vect2::getX() {
    return x;
}

void vect2::setX(double varx) {
    x = varx;
}

double vect2::getY() {
    return y;
}

void vect2::setY(double vary) {
    y = vary;
}

// Start of user code  : Additional methods
void vect2::switchSignX() {
    x *= -1;
}

void vect2::switchSignY() {
    y *= -1;
}

vect2 vect2::operator+(const vect2& vect2) const {
    return {x + vect2.x, y + vect2.y};
}

vect2 vect2::operator*(const double arg) const {
    return {x * arg, y * arg};
}

vect2 vect2::operator-(const vect2& vect2) const {
    return {x - vect2.x, y - vect2.y};
}

// End of user code