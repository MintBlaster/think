// Created by manish on 05-06-2024.

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../../include/core/Scene.h"
#include <vector>
#include <utility>  // For std::pair

// #############################################################################
//                         Scene Manager Implementation
// #############################################################################

class SceneManager {
public:
  // Constructor will create a default test scene.
  SceneManager();

  // Singleton instance getter
  static SceneManager& getInstance();

  // Scene management functions
  Scene* createScene(const std::string& name);
  void removeScene(const std::string& name);
  void setCurrentScene(const std::string& name);
  [[nodiscard]] Scene* getCurrentScene() const;
  [[nodiscard]] Scene* getScene(const std::string& name) const;

private:
  // Attributes
  std::vector<std::pair<std::string, std::unique_ptr<Scene>>> scenes_;
  Scene* currentScene_;
};

#endif // SCENE_MANAGER_H
