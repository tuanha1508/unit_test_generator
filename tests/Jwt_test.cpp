**Updated Test File Content:**

```cpp
#include "Jwt.h"

TEST(JwtTest, EncodeTest) {
    const std::string secret = "my_secret";
    const std::string field = "my_field";
    const int expiry = 3600;
    const std::string issuer = "my_issuer";

    Jwt jwt(secret, expiry, issuer);
    EXPECT_EQ(field, jwt.encode(field, 123));
}

TEST(JwtTest, DecodeTest) {
    const std::string secret = "my_secret";
    const std::string token = "my_token";
    Jwt jwt(secret, expiry, issuer);
    EXPECT_EQ(jwt.decode(token), jwt::decoded_jwt<jwt::traits::kazuho_picojson>{
        .header = jwt.header(),
        .payload = jwt.payload()
    });
}
```