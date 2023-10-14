CREATE TABLE course_info (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    credit REAL NOT NULL,
    start_week INTEGER NOT NULL,
    end_week INTEGER NOT NULL,
    weekday INTEGER NOT NULL,
    start_time INTEGER NOT NULL,
    len INTEGER NOT NULL,
    location TEXT NOT NULL,
    teacher TEXT NOT NULL
);

INSERT INTO course_info (
    name, credit, start_week, end_week, weekday, start_time, len, location, teacher
)
VALUES (
    '高等数学', '3', '1', '16', '1', '3', '2', '二号楼-327', '老师A'
);

INSERT INTO course_info (
    name, credit, start_week, end_week, weekday, start_time, len, location, teacher
)
VALUES (
    '毛概', '3', '1', '16', '1', '1', '2', '四号楼-303', '老师B'
);

INSERT INTO course_info (
    name, credit, start_week, end_week, weekday, start_time, len, location, teacher
)
VALUES (
    '英语', '2', '1', '16', '1', '1', '2', '二号楼-314', '老师C'
);

INSERT INTO course_info (
    name, credit, start_week, end_week, weekday, start_time, len, location, teacher
)
VALUES (
    '网页制作', '4', '1', '16', '3', '9', '5', '二号楼-710', '老师D'
);