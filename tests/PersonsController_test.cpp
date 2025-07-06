#include "PersonsController.h"

TEST(PersonsController_Get, "Get all persons") {
    // Arrange
    PersonsController personsController;

    // Act
    HttpResponsePtr response = personsController.get(HttpRequestPtr());

    // Assert
    ASSERT_EQ(200, response->getStatusCode());
    ASSERT_EQ(nullptr, response->getHeader("Content-Type"));
}

TEST(PersonsController_Get_EmptyList, "Get all persons with empty list") {
    // Arrange
    PersonsController personsController;
    personsController.persons = std::vector<Person>();

    // Act
    HttpResponsePtr response = personsController.get(HttpRequestPtr());

    // Assert
    ASSERT_EQ(200, response->getStatusCode());
    ASSERT_EQ(nullptr, response->getHeader("Content-Type"));
}
```