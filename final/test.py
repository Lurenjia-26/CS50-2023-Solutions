import sqlite3

def main():
    conn = sqlite3.connect("data/course.db")
    db = conn.cursor()
#     db.execute('''CREATE TABLE course_info (
#     id INTEGER PRIMARY KEY AUTOINCREMENT,
#     name TEXT NOT NULL,
#     credit REAL NOT NULL,
#     start_week INTEGER NOT NULL,
#     end_week INTEGER NOT NULL,
#     weekday INTEGER NOT NULL,
#     start_time INTEGER NOT NULL,
#     len INTEGER NOT NULL,
#     location TEXT NOT NULL,
#     teacher TEXT NOT NULL
# );''')

    # db.execute("INSERT INTO course_info (name, credit, start_week, end_week, weekday, start_time, len, location, teacher)\
    #            VALUES ('高等数学', '3', '1', '16', '13', '31', '2', '二号楼-327', '老师A')")

    # db.execute("INSERT INTO course_info (name, credit, start_week, end_week, weekday, start_time, len, location, teacher)\
    #            VALUES ('毛概', '3', '1', '16', '1', '1', '2', '四号楼-303', '老师B')")
    # conn.commit()

    # db.execute("INSERT INTO course_info (name, credit, start_week, end_week, weekday, start_time, len, location, teacher)\
    #            VALUES ('英语', '2', '1', '16', '2', '1', '2', '二号楼-314', '老师C')")
    # conn.commit()

    course = db.execute("SELECT * FROM course_info")

    print(course)
    for row in course:
        print(row)

if __name__ == "__main__":
    main()