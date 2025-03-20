#pragma once

struct GLFWwindow;

namespace veng {

class Window {
 public:
  Window(std::string_view name, glm::ivec2 size);
  ~Window();

 private:
  GLFWwindow* window_;
};

}  // namespace veng
