#pragma once

struct GLFWmonitor;
struct GLFWwindow;

namespace veng {

gsl::span<GLFWmonitor*> GetMonitors();
glm::ivec2 GetMonitorPos(gsl::not_null<GLFWmonitor*> monitor);
glm::ivec2 GetMonitorWorkareaSize(gsl::not_null<GLFWmonitor*> monitor);
void MoveWindowToMonitor(gsl::not_null<GLFWwindow*> window, gsl::not_null<GLFWmonitor*> monitor);

}  // namespace veng
