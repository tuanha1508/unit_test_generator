**Updated Test File:**

```java
public class Person {

    private String id;
    private String name;
    private String email;

    public Person(String id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    private String sqlForFindingByPrimaryKey;
    private String sqlForDeletingByPrimaryKey;
    private String sqlForInserting;

    public Person() {
        // Default constructor
    }

    public Person(String id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }

    public String sqlForFindingByPrimaryKey() {
        StringBuilder sql = new StringBuilder("SELECT * FROM person WHERE id = ?");
        return sql.toString();
    }

    public String sqlForDeletingByPrimaryKey(String id) {
        StringBuilder sql = new StringBuilder("DELETE FROM person WHERE id = ?");
        return sql.toString();
    }

    public String sqlForInserting() {
        StringBuilder sql = new StringBuilder("INSERT INTO person (id, name, email) VALUES (?, ?, ?)");
        return sql.toString();
    }

    private boolean dirtyFlag[] = new boolean[3]; // id, name, email

    public void setDirtyFlag(int index, boolean value) {
        dirtyFlag[index] = value;
    }

    public boolean isDirtyFlag(int index) {
        return dirtyFlag[index];
    }
}
```