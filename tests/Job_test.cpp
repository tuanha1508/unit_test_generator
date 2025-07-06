#include <gtest/gtest.h>
#include "Job.h"

TEST(JobTest, FindByPrimaryKey) {
  Job job(drogon::orm::Row::empty(), 0);
  EXPECT_EQ(drogon::orm::Job::primaryKeyNumber, job.getPrimaryKey());
}

TEST(JobTest, FindByPrimaryKeyInvalid) {
  Job job(drogon::orm::Row(drogon::orm::Field::empty()), -1);
  EXPECT_EQ(-1, job.getPrimaryKey());
}

TEST(JobTest, FindByPrimaryKeyMultiple) {
  Job job1(drogon::orm::Row::empty(), 0), job2(drogon::orm::Row::empty(), 1);
  EXPECT_EQ(drogon::orm::Job::primaryKeyNumber, job1.getPrimaryKey());
  EXPECT_EQ(drogon::orm::Job::primaryKeyNumber, job2.getPrimaryKey());
}

TEST(JobTest, Insert) {
  Job job(drogon::orm::Row::empty());
  EXPECT_EQ(0, job.insert());
}

TEST(JobTest, Update) {
  Job job(drogon::orm::Row::empty(), 0);
  job.update();
  EXPECT_EQ(0, job.update());
}

TEST(JobTest, UpdateInvalid) {
  Job job(drogon::orm::Row::empty(), 1);
  EXPECT_EQ(-1, job.update());
}

TEST(JobTest, Delete) {
  Job job(drogon::orm::Row::empty(), 0);
  EXPECT_EQ(0, job.delete());
}

TEST(JobTest, GetColumnNumber) {
  EXPECT_EQ(1, Job::getColumnNumber());
}

TEST(JobTest, GetColumnName) {
  EXPECT_EQ("id", Job::getColumnName(0));
}
```