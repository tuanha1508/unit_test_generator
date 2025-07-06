#include <gtest/gtest.h>

TEST(DepartmentTest, FindByPrimaryKey) {
  Department* department = new Department(drogon::orm::Row(drogon::orm::Field::ID, 1), 0);
  EXPECT_EQ(1, department->getId()->get());
  delete department;
}

TEST(DepartmentTest, FindByPrimaryKeyInvalid) {
  Department* department = new Department(-1, 0);
  EXPECT_EQ(-1, department->getId()->get());
  delete department;
}

TEST(DepartmentTest, FindByPrimaryKeyMultiple) {
  Department* department1 = new Department(drogon::orm::Row(drogon::orm::Field::ID, 1), 0);
  Department* department2 = new Department(drogon::orm::Row(drogon::orm::Field::ID, 2), 0);
  EXPECT_EQ(1, department1->getId()->get());
  EXPECT_EQ(2, department2->getId()->get());
  delete department1;
  delete department2;
}
```