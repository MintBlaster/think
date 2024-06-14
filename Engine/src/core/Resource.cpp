// Created by manish on 04-06-2024.

#include "../../include/core/Resource.h"

#include <utility>

// #############################################################################
//                           Resource Class Implementation
// #############################################################################

Resource::Resource(std::string name, std::string path) : name_(std::move(name)), path_(std::move(path)) {}