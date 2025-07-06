#include <gtest/gtest.h>
#include "bcrypt/crypt_blowfish.h"

TEST(BcryptTest, GetMagic) {
  const char *setting = "12345678901234567890123456789012";
  char output[128];
  size_t size = _crypt_output_magic(setting, output, 128);
  EXPECT_EQ(12, size);
  EXPECT_EQ("12345678901234567890123456789012", output);
}
```