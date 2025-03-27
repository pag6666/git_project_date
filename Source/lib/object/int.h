#pragma once

#include "object.h"
namespace System {
class Int: public Object {
private:
    int value = 0;
public:
    Int():Int(0) { }
    Int(int value) {
        this->value = value;
    }
    std::string ToString() const override {
        return ("Int: " + std::to_string(value));
    }
    size_t GetHashCode() const override {
        return std::hash<int>()(value);
    }
    int operator = (int out) {
        return value = out;
    }
    operator int() const {
        return value;
    }
    ~Int() {}
};
}