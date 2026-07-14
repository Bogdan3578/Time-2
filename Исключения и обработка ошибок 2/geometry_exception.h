#pragma once
#include <stdexcept>
#include <string>
class GeometryException : public std::domain_error {
public:
    explicit GeometryException(const std::string& message);
};
