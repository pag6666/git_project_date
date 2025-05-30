#pragma once

#include "object.h"
#include "../memory_stack/GC/Gc.h"

namespace System {
class String: public Object {
private:
    std::string value = "";
    void setupPointerFlag() {
        if (isPointerFlag)
	        System::Memory::Gc::heap.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Object)));
        else
	        System::Memory::Gc::stack.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Object)));
    }
public:
    static bool isPointerFlag;
    void* operator new(size_t size) {
        isPointerFlag = true;
        return ::operator new(size);
    }
    String():String("") { }
    String(std::string value) {
        this->value = value;
        setupPointerFlag();
    }
    String(const char value[]) {
        this->value = std::string(value);
        setupPointerFlag();
    }
    String(char* value) {
        this->value = std::string(value);
        setupPointerFlag();
    }
    std::string ToString() const override {
        return ("String: " + value);
    }
    size_t GetHashCode() const override {
        return std::hash<std::string>()(value);
    }
    std::string operator = (std::string out) {
        return value = out;
    }
    std::string operator = (const char value[]) {
        return this->value = std::string(value);
    }
    std::string operator = (char* value) {
        return this->value = std::string(value);
    }
    operator const char*() const {
        return value.c_str();
    }
    ~String() {}
};
bool System::String::isPointerFlag = false;
}