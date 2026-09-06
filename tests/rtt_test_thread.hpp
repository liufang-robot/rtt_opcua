#pragma once

#include <rtt/rtt-config.h>

#if defined(OROPKG_OS_XENOMAI) && CONFIG_XENO_VERSION_MAJOR >= 3
#include <alchemy/task.h>

#include <cerrno>
#endif

namespace RTT::opcua::test {

inline int initializeRttThreadContext() {
#if defined(OROPKG_OS_XENOMAI) && CONFIG_XENO_VERSION_MAJOR >= 3
  if (rt_task_self() != nullptr) {
    return 0;
  }
  const int result = rt_task_shadow(nullptr, nullptr, 0, 0);
  return result == -EBUSY ? 0 : result;
#else
  return 0;
#endif
}

} // namespace RTT::opcua::test
