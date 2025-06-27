import sqlite3

# Function to create a table
def create_table(cursor):
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS my_table (
            id INTEGER PRIMARY KEY,
            name TEXT,
            age INTEGER
        )
    ''')
    print("Table created successfully.")

# Function to insert values into the table
def insert_values(cursor, name, age):
    cursor.execute("INSERT INTO my_table (name, age) VALUES (?, ?)", (name, age))
    print("Values inserted successfully.")

# Function to delete a row based on values
def delete_row(cursor, name):
    cursor.execute("DELETE FROM my_table WHERE name=?", (name,))
    print("Row deleted successfully.")

# Function to display all rows of the table
def display_rows(cursor):
    cursor.execute("SELECT * FROM my_table")
    rows = cursor.fetchall()
    for row in rows:
        print(row)

# Function to update values of a specific row
def update_values(cursor, old_name, new_name, new_age):
    cursor.execute("UPDATE my_table SET name=?, age=? WHERE name=?", (new_name, new_age, old_name))
    print("Row updated successfully.")

# Function to search for a particular record in the table
def search_record(cursor, name):
    cursor.execute("SELECT * FROM my_table WHERE name=?", (name,))
    row = cursor.fetchone()
    if row:
        print("Record found:", row)
    else:
        print("Record not found.")

def main():
    connection = sqlite3.connect("my_database.db")
    cursor = connection.cursor()

    while True:
        print("\nMenu:")
        print("1. Create Table")
        print("2. Insert Values")
        print("3. Delete Row")
        print("4. Display Rows")
        print("5. Update Values")
        print("6. Search Record")
        print("7. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            create_table(cursor)
        elif choice == 2:
            name = input("Enter name: ")
            age = int(input("Enter age: "))
            insert_values(cursor, name, age)
        elif choice == 3:
            name = input("Enter name to delete row: ")
            delete_row(cursor, name)
        elif choice == 4:
            display_rows(cursor)
        elif choice == 5:
            old_name = input("Enter current name: ")
            new_name = input("Enter new name: ")
            new_age = int(input("Enter new age: "))
            update_values(cursor, old_name, new_name, new_age)
        elif choice == 6:
            name = input("Enter name to search: ")
            search_record(cursor, name)
        elif choice == 7:
            break
        else:
            print("Invalid choice. Please enter a valid option.")

    connection.commit()
    connection.close()

if __name__ == "__main__":
    main()
