#include <gtest/gtest.h>

TEST(UtilsTest, BadRequestTest) {
  // Include necessary header files
  #include <exception>

  // Forward declaration of callback function
  void callback(void);

  // Test case for bad request with invalid callback function
  EXPECT_CALL(callback, Void())
      .WillOnce(ThrowException<std::exception>(std::exception("Invalid callback function")));

  // Test case for bad request with empty string error
  EXPECT_CALL(callback, Void())
      .WillOnce(ThrowException<std::exception>(std::exception("Empty string error")));
}

// Define callback function
void callback() {
  // Code to handle callback function
}
```