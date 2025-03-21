#pragma once

#include <vulkan/vulkan.h>
#include <glfw_window.h>
#include <vector>

class Window;

namespace veng {

class Graphics final {
 public:
  Graphics(gsl::not_null<Window*> window);
  ~Graphics();

 private:
  void InitializeVulkan();
  void CreateInstance();

  static gsl::span<gsl::czstring> GetSuggestedExtensions();
  static std::vector<VkExtensionProperties> GetSupportedInstanceExtensions();

  VkInstance instance_ = nullptr;
  gsl::not_null<Window*> window_;
};
}  // namespace veng
