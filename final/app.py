from flask import Flask, render_template, request, session
from datetime import datetime, timedelta
import sqlite3

app = Flask(__name__)
app.secret_key = 'd586186a33301471217cf1d3f23d1dbb'
TIMETABLE = ["", "8:10-9:50", "", "10:10-11:50", "", "13:30-15:10", "", "15:30-17:10", "", "18:20-19:55", "", "20:00-21:35"]
START_DATE = datetime(2023, 9, 11)
COLORS = ["primary", "success", "info", "warning", "danger", "secondary"]


def get_week_data(date):
    weekday = date.weekday()
    start_day = date - timedelta(weekday)
    week_data = []

    for i in range(7):
        day = start_day + timedelta(i)
        week_data.append(day.strftime("%m-%d"))

    return week_data


def get_week_number(date):
    date = date.replace(tzinfo=None)
    diff = (date - START_DATE).days
    week_number = diff // 7 + 1

    return week_number


def get_course(cursor):
    cursor.execute("SELECT * FROM course_info")
    rows = cursor.fetchall()

    columns = [column[0] for column in cursor.description]

    course = []
    for row in rows:
        result = dict(zip(columns, row))
        course.append(result)
    return course


def add_course(cursor, course_data):
    insert_query = """
    INSERT INTO course_info (
        name, credit, start_week, end_week, weekday, start_time, len, location, teacher
    )
    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
"""
    cursor.execute(insert_query, course_data)


def check():
    name = request.form.get("course_name")
    credit = request.form.get("credit")
    start_week = request.form.get("start_week")
    end_week = request.form.get("end_week")
    weekday = request.form.get("weekday")
    start_time = request.form.get("start_time")
    len = request.form.get("len")
    location = request.form.get("location")
    teachar = request.form.get("teacher")

    course_data = [name, credit, start_week, end_week, weekday, start_time, len, location, teachar]


    if not name or not credit or not start_week or not end_week or not weekday or not start_time or not len or not location or not teachar:
        return "Please fill in all the fields"
    
    credit = float(credit)
    start_week = int(start_week)
    end_week = int(end_week)
    weekday = int(weekday)
    start_time = int(start_time)
    len = int(len)

    if start_week >= end_week:
        return "Start week should before end week"
    if weekday > 7 or weekday < 1:
        return "Weekday must be a value between 1 and 7."
    if start_time not in [1, 3, 5, 7, 9]:
        return "Start time must in [1, 3, 5, 7, 9]"
    if len not in [2, 4]:
        return "Len should in [2, 4]"

    return course_data


def close_db(conn, cursor):
    conn.commit()
    cursor.close()
    conn.close()


def generate_schedule(timetable, course, week_number):
    html = ''
    merge_cell = [False, False, False, False, False, False, False]

    for i in [1, 3, 5, 7, 9, 11]:
        html += '<tr>'
        html += f'<td class="px-1">{timetable[i]}</td>'

        for j in range(7):
            has_course = False

            for row in course:
                if row["weekday"] == j + 1 and row["start_time"] == i and row["start_week"] <= week_number <= row["end_week"]:
                    has_course = True

                    if row['len'] == 4:
                        html += f'<td rowspan=2 class="bg-{COLORS[(j + i - 1) % 6]} text-white">{row["name"]}<br />{row["credit"]}<br />{row["location"]}<br />{row["start_week"]}-{row["end_week"]}</td>'
                        merge_cell[j] = True
                    else:
                        html += f'<td class="bg-{COLORS[(j + i - 1) % 6]} text-white">{row["name"]}<br />{row["credit"]}<br />{row["location"]}<br />{row["start_week"]}-{row["end_week"]}</td>'

            if not has_course:
                if merge_cell[j]:
                    merge_cell[j] = False
                else:
                    html += '<td>&nbsp;</td>'

        merge_cell[0] = merge_cell[1]
        merge_cell[1] = False
        html += '</tr>'

    return html


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        session['today'] = datetime.today()
        date = datetime.today()
        this_day = date.strftime("%m-%d")
        week_number = get_week_number(date)
        conn = sqlite3.connect("data/course.db")
        db = conn.cursor()
        course = get_course(db)
        schedule = generate_schedule(TIMETABLE, course, week_number)
        return render_template("index.html", this_day=this_day, week_data=get_week_data(date), week_number=week_number, course=course, schedule=schedule)


@app.route("/add", methods=["GET", "POST"])
def add():
    if request.method == "GET":
        return render_template("add.html")
    
    if request.method == "POST":
        message = check()

        if isinstance(message, list):
            conn = sqlite3.connect("data/course.db")
            db = conn.cursor()
            add_course(db, message)
            close_db(conn, db)
            return render_template("success.html")
        else:
            return render_template("failure.html", message=message)
        

@app.route("/prev_week", methods=["GET", "POST"])
def prev():
    if 'today' not in session:
        session['today'] = datetime.today()
    session['today'] = session['today'] - timedelta(7)
        
    if request.method == "GET":
        date = session['today']
        this_day = datetime.today().strftime("%m-%d")
        week_number = get_week_number(date)
        conn = sqlite3.connect("data/course.db")
        db = conn.cursor()
        course = get_course(db)
        schedule = generate_schedule(TIMETABLE, course, week_number)
        return render_template("index.html", this_day=this_day, week_data=get_week_data(date), week_number=week_number, course=course, schedule=schedule)


@app.route("/next_week", methods=["GET", "POST"])
def next():
    if 'today' not in session:
        session['today'] = datetime.today()
    session['today'] = session['today'] + timedelta(7)

    if request.method == "GET":
        date = session['today']
        this_day = datetime.today().strftime("%m-%d")
        week_number = get_week_number(date)
        conn = sqlite3.connect("data/course.db")
        db = conn.cursor()
        course = get_course(db)
        schedule = generate_schedule(TIMETABLE, course, week_number)
        return render_template("index.html", this_day=this_day, week_data=get_week_data(date), week_number=week_number, course=course, schedule=schedule)


if __name__ == "__main__":
    app.run(debug=True)
