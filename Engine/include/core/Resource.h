//
// Created by manish on 04-06-2024.
//

#ifndef RESOURCE_H
#define RESOURCE_H

#pragma once

#include <string>

// #############################################################################
//                           Resource Class Declaration
// #############################################################################

class Resource {
public:
  // Constructor & Destructor
  Resource(std::string name, std::string path);
  virtual ~Resource() = default;

  // Setters
  virtual void setName(const std::string& name) { name_ = name; }
  virtual void setPath(const std::string& path) { path_ = path; }

  // Getters
  [[nodiscard]] virtual std::string getName() const { return name_; }
  [[nodiscard]] virtual std::string getPath() const { return path_; }

protected:
  // Attributes
  std::string name_;
  std::string path_;


};

#endif // RESOURCE_H
