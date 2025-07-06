**Updated Test File:**

```cpp
#include "DepartmentsController_test.cpp"

TEST(DepartmentsController_test, get_valid_departments_response) {
  // Arrange
  DepartmentsController departmentsController;
  HttpRequestPtr req(new HttpRequest());
  req->setMethod(GET);
  req->setRequestUri("/departments/1");

  // Act
  departmentsController.get(req, [](HttpResponsePtr res) {
    ASSERT_EQ(200, res->getStatusCode());
    EXPECT_EQ("{\"id\":1,\"name\":\"Marketing\"}", res->getStringBody());
  });

  // Assert
}
```