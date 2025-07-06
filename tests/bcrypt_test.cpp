#include <gtest/gtest.h>
#include "bcrypt/bcrypt.h"

TEST(BcryptTest, GenerateSalt) {
  int workfactor = 16;
  char salt[BCRYPT_HASHSIZE];
  EXPECT_EQ(bcrypt_gensalt(workfactor, salt), 0);
}

TEST(BcryptTest, HashPassword) {
  const char *passwd = "thepassword";
  const char salt[BCRYPT_HASHSIZE] = "secret_salt";
  EXPECT_EQ(bcrypt_hashpw(passwd, salt, hash), 0);
  EXPECT_EQ(strcmp(hash, "expectedhash"), 0);
}

TEST(BcryptTest, CheckPassword) {
  const char *passwd = "thepassword";
  const char hash[BCRYPT_HASHSIZE] = "expectedhash";
  EXPECT_EQ(bcrypt_checkpw(passwd, hash), 0);
}

TEST(BcryptTest, EdgeCaseEmptyPassword) {
  const char *passwd = "";
  const char *hash;
  EXPECT_EQ(bcrypt_checkpw(passwd, hash), 0);
}

TEST(BcryptTest, EdgeCaseEmptySalt) {
  const char *passwd = "thepassword";
  char salt[BCRYPT_HASHSIZE] = "";
  EXPECT_EQ(bcrypt_hashpw(passwd, salt, hash), 0);
}

TEST(BcryptTest, EdgeCaseInvalidSaltLength) {
  const char *passwd = "thepassword";
  const char salt[BCRYPT_HASHSIZE + 1] = "secret_salt";
  EXPECT_EQ(bcrypt_hashpw(passwd, salt, hash), 0);
}
```

**Updated Test File:**

```cpp
#include <gtest/gtest.h>
#include "bcrypt/bcrypt.h"

TEST(BcryptTest, GenerateSalt) {
  int workfactor = 16;
  char salt[BCRYPT_HASHSIZE];
  EXPECT_EQ(bcrypt_gensalt(workfactor, salt), 0);
}

TEST(BcryptTest, HashPassword) {
  const char *passwd = "thepassword";
  const char salt[BCRYPT_HASHSIZE] = "secret_salt";
  EXPECT_EQ(bcrypt_hashpw(passwd, salt, hash), 0);
  EXPECT_EQ(strcmp(hash, "expectedhash"), 0);
}

TEST(BcryptTest, CheckPassword) {
  const char *passwd = "thepassword";
  const char hash[BCRYPT_HASHSIZE] = "expectedhash";
  EXPECT_EQ(bcrypt_checkpw(passwd, hash), 0);
}

TEST(BcryptTest, EdgeCaseEmptyPassword) {
  const char *passwd = "";
  EXPECT_EQ(bcrypt_checkpw(passwd, nullptr), 0);
}

TEST(BcryptTest, EdgeCaseEmptySalt) {
  const char *passwd = "thepassword";
  char salt[BCRYPT_HASHSIZE] = "";
  EXPECT_EQ(bcrypt_hashpw(passwd, salt, hash), 0);
}

TEST(BcryptTest, EdgeCaseInvalidSaltLength) {
  const char *passwd = "thepassword";
  const char salt[BCRYPT_HASHSIZE + 1] = "secret_salt";
  EXPECT_EQ(bcrypt_hashpw(passwd, salt, hash), 0);
}
```