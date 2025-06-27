import sqlite3
conn = sqlite3.connect("clg_db")
c= conn.cursor()
while True:
    print("\nChoices: ")
    print("Enter 1 to create a table")
    print("Enter 2 to insert values")
    print("Enter 3 to delete a row")
    print("Enter 4 to display all rows")
    print("Enter 5 to update specific value of row")
    print("Enter 6 to search a value")

    choice = int(input("Enter choice: "))

    match choice:
        case 1:
                c.execute("""CREATE TABLE IF NOT EXISTS users ( id INTEGER PRIMARY KEY AUTOINCREMENT, username VARCHAR(100), email VARCHAR(200))""")
                print("Table users created with attributes ID, username and email")
        case 2:
            username = input("Enter Username to INSERT" )
            email = input("Enter Email ")
            c.execute("""INSERT INTO users (username, email) VALUES (?, ?)""", (username, email))
            print("Row added SUCCESSFULLY")
        case 3:
            username = input("Enter Username which you want to DELETE")
            c.execute("""DELETE FROM users where Username = ?""",username)
            print("Row deleted SUCCESSFULLY")
        case 4:
            c.execute("""SELECT * FROM users""")
            schema=c.fetchall();
            for i in schema:
                print(i)
        case 5:
            old_username = input("Enter which username to update " )
            new_username = input("Enter new username")
            c.execute("""UPDATE users SET usename = ? WHERE username =? """,new_username, old_username)
        case 6:
            searched_user = input("Enter username to search")
            c.execute("""SELECT * FROM users WHERE username = ? """,searched_user)
            schema=c.fetchone()
            print(schema)
        case _:
            break;
conn.commit()
conn.close()
