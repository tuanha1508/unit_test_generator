**Updated test file content:**

```c++
#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include <json/json.h>

TEST(readFromStreamTest, basic) {
  Json::Value root;
  std::ifstream ifs("example.json");

  Json::CharReaderBuilder builder;
  builder["collectComments"] = true;
  JSONCPP_STRING errs;
  if (!parseFromStream(builder, ifs, &root, &errs)) {
    std::cout << errs << std::endl;
    return;
  }

  ASSERT_EQ(root["key"], "value");
}
```