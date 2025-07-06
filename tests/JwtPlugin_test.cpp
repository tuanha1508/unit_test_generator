**Updated Test File**

```c++
#include <gtest/gtest.h>
#include "JwtPlugin.h"

TEST(JwtPluginTest, Init) {
  JwtPlugin plugin;
  EXPECT_EQ(Jwt{}, plugin.init());
}

TEST(JwtPluginTest, Shutdown) {
  JwtPlugin plugin;
  plugin.shutdown();
  EXPECT_EQ(nullptr, plugin.getPluginData());
}

TEST(JwtPluginTest, GetJwt) {
  JwtPlugin plugin;
  EXPECT_EQ("", plugin.getJwt());
}

TEST(JwtPluginTest, EdgeCase_InvalidJwt) {
  JwtPlugin plugin;
  plugin.config.jwt = "invalid_jwt_string";
  EXPECT_EQ(JwtError::InvalidJwt, plugin.init());
}
```