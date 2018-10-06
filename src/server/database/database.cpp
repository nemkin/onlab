#include "database.h"

#include <vector>

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

using namespace chronos;

Database::Database() {

    _db = QSqlDatabase::addDatabase("QPSQL");
    _db.setHostName("localhost");
    _db.setDatabaseName("timetable_planner");
    _db.setUserName("timetable_user");
    _db.setPassword("timetable_user");
}

QList<Department> Database::get_departments() {

    QList<Department> ret;

    try {

        _db.open();
        auto query = _db.exec("SELECT * FROM departments;");

        qDebug() << "Query...";
        qDebug() << query.lastQuery();
        qDebug() << query.lastError().text();

        while(query.next()) {

            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            int timestamp = query.value(2).toInt();
            bool is_deleted = query.value(3).toInt();

            Department d(id, name, timestamp, is_deleted);
            
            ret.append(d);
        }

    } catch (std::exception& e) {
        qDebug() << e.what();
    }

    _db.close();
    
    return ret;
}

void Database::test() {
    
    qDebug()<<"#################### Testing...";
    if(_db.open()) {
        qDebug() <<"Database connection works." ;
        _db.close();

    } else {
        qDebug() << _db.lastError().text();
        exit(1);
    }
}

void Database::init() {

    qDebug()<<"#################### Init...";
    std::vector<QString> creates;

    creates.push_back(
        "CREATE TABLE accounts ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "email TEXT NOT NULL UNIQUE, "
            "password_hash TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE locations ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "latitude DOUBLE PRECISION NOT NULL, "
            "longitude DOUBLE PRECISION NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE distances ( "
            "id SERIAL PRIMARY KEY, "
            "location_id_1 INTEGER REFERENCES locations(id) NOT NULL,"
            "location_id_2 INTEGER REFERENCES locations(id) NOT NULL,"
            "distance_minutes DOUBLE PRECISION NOT NULL,"
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE room_types ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "size INTEGER NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE rooms ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "room_type_id INTEGER REFERENCES room_types(id) NOT NULL, "
            "size INTEGER NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE departments ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE faculty_members ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "department_id INTEGER REFERENCES departments(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE majors ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE grades ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "major_id INTEGER REFERENCES majors(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE semester_types ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE semesters ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "semester_type_id INTEGER REFERENCES semester_types(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE courses ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "grade_id INTEGER REFERENCES grades(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE class_types ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE licenses ( "
            "id SERIAL PRIMARY KEY, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "faculty_member_id INTEGER REFERENCES faculty_members(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE classes ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL, "
            "lesson_count INTEGER NOT NULL, "
            "regularity INTEGER NOT NULL, "
            "maximum_student_count INTEGER NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    try {
        _db.open();

        for (auto create : creates) {
            auto query = _db.exec(create);
            qDebug() << "Query...";
            qDebug() << query.lastQuery();
            qDebug() << query.lastError().text();
        }

    } catch (std::exception& e) {
        qDebug() << e.what();
    }

    _db.close();
}

void Database::drop() {

    qDebug()<<"#################### Drop...";

    std::vector<QString> drops;

    drops.push_back("DROP TABLE accounts CASCADE;"); 
    drops.push_back("DROP TABLE locations CASCADE;"); 
    drops.push_back("DROP TABLE distances CASCADE;"); 
    drops.push_back("DROP TABLE room_types CASCADE;"); 
    drops.push_back("DROP TABLE rooms CASCADE;");
    drops.push_back("DROP TABLE departments CASCADE;"); 
    drops.push_back("DROP TABLE faculty_members CASCADE;"); 
    drops.push_back("DROP TABLE majors CASCADE;"); 
    drops.push_back("DROP TABLE grades CASCADE;"); 
    drops.push_back("DROP TABLE semester_types CASCADE;"); 
    drops.push_back("DROP TABLE semesters CASCADE;"); 
    drops.push_back("DROP TABLE courses CASCADE;"); 
    drops.push_back("DROP TABLE class_types CASCADE;"); 
    drops.push_back("DROP TABLE licenses CASCADE;");
    drops.push_back("DROP TABLE classes CASCADE;");

    try {
        _db.open();

        for (auto drop : drops) {
            auto query = _db.exec(drop);
            qDebug() << "Query...";
            qDebug() << query.lastQuery();
            qDebug() << query.lastError().text();
        }

    } catch (std::exception& e) {
        qDebug() << e.what();
    }

    _db.close();
}


