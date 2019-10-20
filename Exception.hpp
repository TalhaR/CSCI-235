#pragma once

#include <stdexcept>
#include <string>

class Exception : public std::logic_error {
public:
    Exception(const std::string& msg = "") : std::logic_error("Out of Bounds: " + msg) {}
};