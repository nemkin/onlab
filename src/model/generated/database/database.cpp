#include "database.h"

#include <iostream>

using namespace chronos;

Database::Database(
    std::string p_user,
    std::string p_password,
    std::string p_host,
    std::string p_database
):
    _user(p_user),
    _db(
        "host = " + p_host + " "
        "dbname = " + p_database + " "
        "user = " + p_user + " "
        "password = " + p_password) {

}

std::vector<Timeslot> Database::get_timeslots() {

    std::vector<Timeslot> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM timeslots;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Timeslot p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Year> Database::get_years() {

    std::vector<Year> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM years;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Year p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Department> Database::get_departments() {

    std::vector<Department> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM departments;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Department p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<std::string>() // short_name
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Course> Database::get_courses() {

    std::vector<Course> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM courses;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Course p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // year_id
                i[5].as<int>() // department_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<ClassType> Database::get_class_types() {

    std::vector<ClassType> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM class_types;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            ClassType p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Location> Database::get_locations() {

    std::vector<Location> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM locations;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Location p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Room> Database::get_rooms() {

    std::vector<Room> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM rooms;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Room p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // location_id
                i[5].as<int>() // class_type_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Class> Database::get_classes() {

    std::vector<Class> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM classes;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Class p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // class_type_id
                i[5].as<int>() // course_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<FacultyMember> Database::get_faculty_members() {

    std::vector<FacultyMember> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM faculty_members;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            FacultyMember p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>() // department_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<License> Database::get_licenses() {

    std::vector<License> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM licenses;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            License p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<int>(), // course_id
                i[4].as<int>(), // class_type_id
                i[5].as<int>() // faculty_member_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

void Database::test() {

    if(_db.is_open()) {

        std::cout << "Connection successful!" << std::endl;

    } else {

        std::cout << "Connection failed." << std::endl;
    }
}

void Database::init() {

    std::vector<std::string> creates;

    creates.push_back(
        "CREATE TABLE timeslots ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE years ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE departments ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "short_name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE courses ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "year_id INTEGER REFERENCES years(id) NOT NULL, "
            "department_id INTEGER REFERENCES departments(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE class_types ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE locations ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE rooms ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "location_id INTEGER REFERENCES locations(id) NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE classes ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE faculty_members ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "department_id INTEGER REFERENCES departments(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE licenses ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "faculty_member_id INTEGER REFERENCES faculty_members(id) NOT NULL);"
    );

    try {

        pqxx::work w(_db);

        for(auto create : creates) {

            w.exec(create);
        }

        w.commit();

    } catch (std::exception& e) {

        std::cerr << e.what();
    }
}

void Database::fill() {

    std::vector<std::string> inserts;

    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, 'hétfő 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, 'hétfő 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, 'hétfő 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,4, 'hétfő 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,5, 'hétfő 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,6, 'kedd 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,7, 'kedd 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,8, 'kedd 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,9, 'kedd 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,10, 'kedd 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,11, 'szerda 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,12, 'szerda 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,13, 'szerda 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,14, 'szerda 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,15, 'szerda 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,16, 'csütörtök 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,17, 'csütörtök 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,18, 'csütörtök 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,19, 'csütörtök 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,20, 'csütörtök 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,21, 'péntek 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,22, 'péntek 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,23, 'péntek 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,24, 'péntek 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,25, 'péntek 16:15 - 18:00');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, '1. félév');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, '2. félév');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, '3. félév');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,4, '4. félév');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,5, '5. félév');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,6, '6. félév');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,7, '7. félév');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,1, 'Automatizálási és Alkalmazott Informatikai Tanszék', 'AUT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,2, 'Elektronikai Technológia Tanszék', 'ETT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,3, 'Elektronikus Eszközök Tanszéke', 'EET');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,4, 'Hálózati Rendszerek és Szolgáltatások Tanszék', 'HIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,5, 'Irányítástechnika és Informatika Tanszék', 'IIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,6, 'Méréstechnika és Információs Rendszerek Tanszék', 'MIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,7, 'Számítástudományi és Információelméleti Tanszék', 'SZIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,8, 'Szélessávú Hírközlés és Villamosságtan Tanszék', 'HVT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,9, 'Távközlési és Médiainformatikai Tanszék', 'TMIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,10, 'Villamos Energetika Tanszék', 'VET');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,11, 'Bölcsész Tanszék', 'BTK');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,12, 'Analízis Tanszék', 'MAT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,13, 'Fizika Tanszék', 'FIZ');");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,1, 'Analízis 1', 1, 12);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,2, 'A programozás alapjai 1', 1, 3);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,3, 'Bevezetés a számításelméletbe 1', 1, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,4, 'Bevezető fizika', 1, 13);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,5, 'Bevezető matematika', 1, 12);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,6, 'Digitális technika', 1, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,7, 'Fizika 1', 1, 13);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,8, 'Mérnök leszek', 1, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,9, 'Analízis 2', 2, 12);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,10, 'A programozás alapjai 2', 2, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,11, 'Bevezetés a számításelméletbe 2', 2, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,12, 'Fizika 2', 2, 13);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,13, 'Rendszermodellezés', 2, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,14, 'Számítógép architektúrák', 2, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,15, 'A programozás alapjai 3', 3, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,16, 'Adatbázisok', 3, 9);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,17, 'Kódolástechnika', 3, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,18, 'Kommunikációs hálózatok 1', 3, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,19, 'Rendszerelmélet', 3, 8);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,20, 'Szoftvertechnológia', 3, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,21, 'Valószínűségszámítás', 3, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,22, 'Algoritmuselmélet', 4, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,23, 'Kommunikációs hálózatok 2', 4, 9);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,24, 'Menedzsment és vállalkozásgazdaságtan', 4, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,25, 'Operációs rendszerek', 4, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,26, 'Számítógépes grafika', 4, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,27, 'Szoftver projekt laboratórium', 4, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,28, 'Szoftvertechnikák', 4, 1);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,29, 'IT eszközök technológiája', 5, 3);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,30, 'Mesterséges intelligencia', 5, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,31, 'Mikro- és makroökonómia', 5, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,32, 'Mobil- és webes szoftverek', 5, 1);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,33, 'Üzleti jog', 5, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,34, 'Informatikai rendszertervezés', 5, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,35, 'Ipari informatika', 5, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,36, 'Információs rendszerek üzemeltetése', 6, 9);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,37, 'IT biztonság', 6, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,38, 'Alkalmazásfejlesztési környezetek', 6, 1);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,39, 'Intelligens elosztott rendszerek', 6, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,40, 'Rendszertervezés laboratórium 1', 6, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,41, 'Deklaratív programozás', 7, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,42, 'Rendszertervezés laboratórium 2', 7, 6);");
    inserts.push_back("INSERT INTO class_types (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, 'előadás');");
    inserts.push_back("INSERT INTO class_types (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, 'gyakorlat');");
    inserts.push_back("INSERT INTO class_types (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, 'labor');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, 'A épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, 'CH épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, 'E épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,4, 'H épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,5, 'I épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,6, 'K épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,7, 'Q épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,8, 'R épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,9, 'T épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,10, 'V1 épület');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,11, 'F épület');");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,1, 'CHC14', 2, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,2, 'E1A', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,3, 'E1B', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,4, 'E1C', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,5, 'E305c', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,6, 'E306ab', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,7, 'E306cd', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,8, 'E401', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,9, 'E402', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,10, 'E403', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,11, 'E404', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,12, 'E405', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,13, 'E406', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,14, 'E407', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,15, 'F29', 11, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,16, 'H406', 4, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,17, 'IB026', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,18, 'IB027', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,19, 'IB028', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,20, 'IB134', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,21, 'IB138', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,22, 'IB139', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,23, 'IB140', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,24, 'IB141', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,25, 'IB142', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,26, 'IB144', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,27, 'IB145', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,28, 'IB146', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,29, 'IB147', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,30, 'IB310', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,31, 'IB413', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,32, 'IE007', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,33, 'IE217-1', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,34, 'IE218', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,35, 'IE219', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,36, 'IE220', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,37, 'IE221', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,38, 'IE223', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,39, 'IE224', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,40, 'IE226', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,41, 'IE320', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,42, 'IE321', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,43, 'IL105', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,44, 'IL407', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,45, 'IL408', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,46, 'K134', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,47, 'K174', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,48, 'KF51 (AUD.MAX)', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,49, 'KF81', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,50, 'KF87', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,51, 'KF88', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,52, 'QA240', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,53, 'QAF14', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,54, 'QB105', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,55, 'QB-310', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,56, 'QB311', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,57, 'QB331', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,58, 'QBF08', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,59, 'QBF10', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,60, 'QBF11', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,61, 'QBF12', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,62, 'QBF13', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,63, 'QBP', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,64, 'Q-I', 7, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,65, 'R4A', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,66, 'R4B', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,67, 'R4C', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,68, 'R4I', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,69, 'R4J', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,70, 'R4K', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,71, 'R4L', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,72, 'R4M', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,73, 'R4N', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,74, 'R4O', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,75, 'R4P', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,76, 'R504', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,77, 'R505', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,78, 'R506', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,79, 'R507', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,80, 'R508', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,81, 'R511', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,82, 'R515', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,83, 'R516', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,84, 'R517', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,85, 'T604', 9, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,86, 'V1109', 10, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,87, 'V1501', 10, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,88, 'V1502', 10, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,89, 'V1526', 10, 2);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,1, 'Analízis 1 előadás', 1, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,2, 'Analízis 1 gyakorlat', 2, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,3, 'Analízis 1 labor', 3, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,4, 'A programozás alapjai 1 előadás', 1, 2);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,5, 'A programozás alapjai 1 gyakorlat', 2, 2);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,6, 'A programozás alapjai 1 labor', 3, 2);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,7, 'Bevezetés a számításelméletbe 1 előadás', 1, 3);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,8, 'Bevezetés a számításelméletbe 1 gyakorlat', 2, 3);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,9, 'Bevezetés a számításelméletbe 1 labor', 3, 3);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,10, 'Bevezető fizika előadás', 1, 4);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,11, 'Bevezető fizika gyakorlat', 2, 4);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,12, 'Bevezető fizika labor', 3, 4);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,13, 'Bevezető matematika előadás', 1, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,14, 'Bevezető matematika gyakorlat', 2, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,15, 'Bevezető matematika labor', 3, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,16, 'Digitális technika előadás', 1, 6);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,17, 'Digitális technika gyakorlat', 2, 6);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,18, 'Digitális technika labor', 3, 6);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,19, 'Fizika 1 előadás', 1, 7);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,20, 'Fizika 1 gyakorlat', 2, 7);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,21, 'Fizika 1 labor', 3, 7);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,22, 'Mérnök leszek előadás', 1, 8);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,23, 'Mérnök leszek gyakorlat', 2, 8);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,24, 'Mérnök leszek labor', 3, 8);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,25, 'Analízis 2 előadás', 1, 9);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,26, 'Analízis 2 gyakorlat', 2, 9);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,27, 'Analízis 2 labor', 3, 9);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,28, 'A programozás alapjai 2 előadás', 1, 10);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,29, 'A programozás alapjai 2 gyakorlat', 2, 10);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,30, 'A programozás alapjai 2 labor', 3, 10);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,31, 'Bevezetés a számításelméletbe 2 előadás', 1, 11);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,32, 'Bevezetés a számításelméletbe 2 gyakorlat', 2, 11);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,33, 'Bevezetés a számításelméletbe 2 labor', 3, 11);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,34, 'Fizika 2 előadás', 1, 12);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,35, 'Fizika 2 gyakorlat', 2, 12);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,36, 'Fizika 2 labor', 3, 12);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,37, 'Rendszermodellezés előadás', 1, 13);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,38, 'Rendszermodellezés gyakorlat', 2, 13);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,39, 'Rendszermodellezés labor', 3, 13);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,40, 'Számítógép architektúrák előadás', 1, 14);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,41, 'Számítógép architektúrák gyakorlat', 2, 14);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,42, 'Számítógép architektúrák labor', 3, 14);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,43, 'A programozás alapjai 3 előadás', 1, 15);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,44, 'A programozás alapjai 3 gyakorlat', 2, 15);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,45, 'A programozás alapjai 3 labor', 3, 15);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,46, 'Adatbázisok előadás', 1, 16);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,47, 'Adatbázisok gyakorlat', 2, 16);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,48, 'Adatbázisok labor', 3, 16);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,49, 'Kódolástechnika előadás', 1, 17);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,50, 'Kódolástechnika gyakorlat', 2, 17);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,51, 'Kódolástechnika labor', 3, 17);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,52, 'Kommunikációs hálózatok 1 előadás', 1, 18);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,53, 'Kommunikációs hálózatok 1 gyakorlat', 2, 18);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,54, 'Kommunikációs hálózatok 1 labor', 3, 18);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,55, 'Rendszerelmélet előadás', 1, 19);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,56, 'Rendszerelmélet gyakorlat', 2, 19);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,57, 'Rendszerelmélet labor', 3, 19);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,58, 'Szoftvertechnológia előadás', 1, 20);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,59, 'Szoftvertechnológia gyakorlat', 2, 20);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,60, 'Szoftvertechnológia labor', 3, 20);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,61, 'Valószínűségszámítás előadás', 1, 21);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,62, 'Valószínűségszámítás gyakorlat', 2, 21);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,63, 'Valószínűségszámítás labor', 3, 21);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,64, 'Algoritmuselmélet előadás', 1, 22);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,65, 'Algoritmuselmélet gyakorlat', 2, 22);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,66, 'Algoritmuselmélet labor', 3, 22);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,67, 'Kommunikációs hálózatok 2 előadás', 1, 23);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,68, 'Kommunikációs hálózatok 2 gyakorlat', 2, 23);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,69, 'Kommunikációs hálózatok 2 labor', 3, 23);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,70, 'Menedzsment és vállalkozásgazdaságtan előadás', 1, 24);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,71, 'Menedzsment és vállalkozásgazdaságtan gyakorlat', 2, 24);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,72, 'Menedzsment és vállalkozásgazdaságtan labor', 3, 24);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,73, 'Operációs rendszerek előadás', 1, 25);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,74, 'Operációs rendszerek gyakorlat', 2, 25);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,75, 'Operációs rendszerek labor', 3, 25);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,76, 'Számítógépes grafika előadás', 1, 26);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,77, 'Számítógépes grafika gyakorlat', 2, 26);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,78, 'Számítógépes grafika labor', 3, 26);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,79, 'Szoftver projekt laboratórium előadás', 1, 27);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,80, 'Szoftver projekt laboratórium gyakorlat', 2, 27);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,81, 'Szoftver projekt laboratórium labor', 3, 27);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,82, 'Szoftvertechnikák előadás', 1, 28);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,83, 'Szoftvertechnikák gyakorlat', 2, 28);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,84, 'Szoftvertechnikák labor', 3, 28);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,85, 'IT eszközök technológiája előadás', 1, 29);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,86, 'IT eszközök technológiája gyakorlat', 2, 29);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,87, 'IT eszközök technológiája labor', 3, 29);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,88, 'Mesterséges intelligencia előadás', 1, 30);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,89, 'Mesterséges intelligencia gyakorlat', 2, 30);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,90, 'Mesterséges intelligencia labor', 3, 30);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,91, 'Mikro- és makroökonómia előadás', 1, 31);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,92, 'Mikro- és makroökonómia gyakorlat', 2, 31);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,93, 'Mikro- és makroökonómia labor', 3, 31);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,94, 'Mobil- és webes szoftverek előadás', 1, 32);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,95, 'Mobil- és webes szoftverek gyakorlat', 2, 32);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,96, 'Mobil- és webes szoftverek labor', 3, 32);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,97, 'Üzleti jog előadás', 1, 33);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,98, 'Üzleti jog gyakorlat', 2, 33);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,99, 'Üzleti jog labor', 3, 33);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,100, 'Informatikai rendszertervezés előadás', 1, 34);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,101, 'Informatikai rendszertervezés gyakorlat', 2, 34);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,102, 'Informatikai rendszertervezés labor', 3, 34);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,103, 'Ipari informatika előadás', 1, 35);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,104, 'Ipari informatika gyakorlat', 2, 35);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,105, 'Ipari informatika labor', 3, 35);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,106, 'Információs rendszerek üzemeltetése előadás', 1, 36);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,107, 'Információs rendszerek üzemeltetése gyakorlat', 2, 36);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,108, 'Információs rendszerek üzemeltetése labor', 3, 36);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,109, 'IT biztonság előadás', 1, 37);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,110, 'IT biztonság gyakorlat', 2, 37);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,111, 'IT biztonság labor', 3, 37);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,112, 'Alkalmazásfejlesztési környezetek előadás', 1, 38);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,113, 'Alkalmazásfejlesztési környezetek gyakorlat', 2, 38);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,114, 'Alkalmazásfejlesztési környezetek labor', 3, 38);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,115, 'Intelligens elosztott rendszerek előadás', 1, 39);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,116, 'Intelligens elosztott rendszerek gyakorlat', 2, 39);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,117, 'Intelligens elosztott rendszerek labor', 3, 39);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,118, 'Rendszertervezés laboratórium 1 előadás', 1, 40);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,119, 'Rendszertervezés laboratórium 1 gyakorlat', 2, 40);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,120, 'Rendszertervezés laboratórium 1 labor', 3, 40);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,121, 'Deklaratív programozás előadás', 1, 41);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,122, 'Deklaratív programozás gyakorlat', 2, 41);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,123, 'Deklaratív programozás labor', 3, 41);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,124, 'Rendszertervezés laboratórium 2 előadás', 1, 42);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,125, 'Rendszertervezés laboratórium 2 gyakorlat', 2, 42);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id) VALUES (current_timestamp,false,126, 'Rendszertervezés laboratórium 2 labor', 3, 42);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,1, 'AUT előadástartó 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,2, 'AUT előadástartó 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,3, 'AUT gyakorlattartó 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,4, 'AUT gyakorlattartó 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,5, 'AUT gyakorlattartó 3', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,6, 'AUT gyakorlattartó 4', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,7, 'AUT gyakorlattartó 5', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,8, 'AUT gyakorlattartó 6', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,9, 'AUT gyakorlattartó 7', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,10, 'AUT gyakorlattartó 8', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,11, 'AUT gyakorlattartó 9', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,12, 'AUT gyakorlattartó 10', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,13, 'AUT labortartó 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,14, 'AUT labortartó 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,15, 'AUT labortartó 3', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,16, 'AUT labortartó 4', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,17, 'AUT labortartó 5', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,18, 'AUT labortartó 6', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,19, 'AUT labortartó 7', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,20, 'AUT labortartó 8', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,21, 'AUT labortartó 9', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,22, 'AUT labortartó 10', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,23, 'ETT előadástartó 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,24, 'ETT előadástartó 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,25, 'ETT gyakorlattartó 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,26, 'ETT gyakorlattartó 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,27, 'ETT gyakorlattartó 3', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,28, 'ETT gyakorlattartó 4', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,29, 'ETT gyakorlattartó 5', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,30, 'ETT gyakorlattartó 6', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,31, 'ETT gyakorlattartó 7', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,32, 'ETT gyakorlattartó 8', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,33, 'ETT gyakorlattartó 9', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,34, 'ETT gyakorlattartó 10', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,35, 'ETT labortartó 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,36, 'ETT labortartó 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,37, 'ETT labortartó 3', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,38, 'ETT labortartó 4', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,39, 'ETT labortartó 5', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,40, 'ETT labortartó 6', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,41, 'ETT labortartó 7', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,42, 'ETT labortartó 8', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,43, 'ETT labortartó 9', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,44, 'ETT labortartó 10', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,45, 'EET előadástartó 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,46, 'EET előadástartó 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,47, 'EET gyakorlattartó 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,48, 'EET gyakorlattartó 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,49, 'EET gyakorlattartó 3', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,50, 'EET gyakorlattartó 4', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,51, 'EET gyakorlattartó 5', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,52, 'EET gyakorlattartó 6', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,53, 'EET gyakorlattartó 7', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,54, 'EET gyakorlattartó 8', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,55, 'EET gyakorlattartó 9', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,56, 'EET gyakorlattartó 10', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,57, 'EET labortartó 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,58, 'EET labortartó 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,59, 'EET labortartó 3', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,60, 'EET labortartó 4', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,61, 'EET labortartó 5', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,62, 'EET labortartó 6', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,63, 'EET labortartó 7', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,64, 'EET labortartó 8', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,65, 'EET labortartó 9', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,66, 'EET labortartó 10', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,67, 'HIT előadástartó 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,68, 'HIT előadástartó 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,69, 'HIT gyakorlattartó 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,70, 'HIT gyakorlattartó 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,71, 'HIT gyakorlattartó 3', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,72, 'HIT gyakorlattartó 4', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,73, 'HIT gyakorlattartó 5', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,74, 'HIT gyakorlattartó 6', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,75, 'HIT gyakorlattartó 7', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,76, 'HIT gyakorlattartó 8', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,77, 'HIT gyakorlattartó 9', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,78, 'HIT gyakorlattartó 10', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,79, 'HIT labortartó 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,80, 'HIT labortartó 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,81, 'HIT labortartó 3', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,82, 'HIT labortartó 4', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,83, 'HIT labortartó 5', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,84, 'HIT labortartó 6', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,85, 'HIT labortartó 7', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,86, 'HIT labortartó 8', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,87, 'HIT labortartó 9', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,88, 'HIT labortartó 10', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,89, 'IIT előadástartó 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,90, 'IIT előadástartó 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,91, 'IIT gyakorlattartó 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,92, 'IIT gyakorlattartó 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,93, 'IIT gyakorlattartó 3', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,94, 'IIT gyakorlattartó 4', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,95, 'IIT gyakorlattartó 5', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,96, 'IIT gyakorlattartó 6', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,97, 'IIT gyakorlattartó 7', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,98, 'IIT gyakorlattartó 8', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,99, 'IIT gyakorlattartó 9', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,100, 'IIT gyakorlattartó 10', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,101, 'IIT labortartó 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,102, 'IIT labortartó 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,103, 'IIT labortartó 3', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,104, 'IIT labortartó 4', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,105, 'IIT labortartó 5', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,106, 'IIT labortartó 6', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,107, 'IIT labortartó 7', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,108, 'IIT labortartó 8', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,109, 'IIT labortartó 9', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,110, 'IIT labortartó 10', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,111, 'MIT előadástartó 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,112, 'MIT előadástartó 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,113, 'MIT gyakorlattartó 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,114, 'MIT gyakorlattartó 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,115, 'MIT gyakorlattartó 3', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,116, 'MIT gyakorlattartó 4', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,117, 'MIT gyakorlattartó 5', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,118, 'MIT gyakorlattartó 6', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,119, 'MIT gyakorlattartó 7', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,120, 'MIT gyakorlattartó 8', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,121, 'MIT gyakorlattartó 9', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,122, 'MIT gyakorlattartó 10', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,123, 'MIT labortartó 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,124, 'MIT labortartó 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,125, 'MIT labortartó 3', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,126, 'MIT labortartó 4', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,127, 'MIT labortartó 5', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,128, 'MIT labortartó 6', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,129, 'MIT labortartó 7', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,130, 'MIT labortartó 8', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,131, 'MIT labortartó 9', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,132, 'MIT labortartó 10', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,133, 'SZIT előadástartó 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,134, 'SZIT előadástartó 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,135, 'SZIT gyakorlattartó 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,136, 'SZIT gyakorlattartó 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,137, 'SZIT gyakorlattartó 3', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,138, 'SZIT gyakorlattartó 4', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,139, 'SZIT gyakorlattartó 5', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,140, 'SZIT gyakorlattartó 6', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,141, 'SZIT gyakorlattartó 7', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,142, 'SZIT gyakorlattartó 8', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,143, 'SZIT gyakorlattartó 9', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,144, 'SZIT gyakorlattartó 10', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,145, 'SZIT labortartó 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,146, 'SZIT labortartó 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,147, 'SZIT labortartó 3', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,148, 'SZIT labortartó 4', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,149, 'SZIT labortartó 5', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,150, 'SZIT labortartó 6', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,151, 'SZIT labortartó 7', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,152, 'SZIT labortartó 8', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,153, 'SZIT labortartó 9', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,154, 'SZIT labortartó 10', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,155, 'HVT előadástartó 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,156, 'HVT előadástartó 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,157, 'HVT gyakorlattartó 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,158, 'HVT gyakorlattartó 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,159, 'HVT gyakorlattartó 3', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,160, 'HVT gyakorlattartó 4', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,161, 'HVT gyakorlattartó 5', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,162, 'HVT gyakorlattartó 6', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,163, 'HVT gyakorlattartó 7', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,164, 'HVT gyakorlattartó 8', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,165, 'HVT gyakorlattartó 9', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,166, 'HVT gyakorlattartó 10', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,167, 'HVT labortartó 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,168, 'HVT labortartó 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,169, 'HVT labortartó 3', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,170, 'HVT labortartó 4', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,171, 'HVT labortartó 5', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,172, 'HVT labortartó 6', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,173, 'HVT labortartó 7', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,174, 'HVT labortartó 8', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,175, 'HVT labortartó 9', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,176, 'HVT labortartó 10', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,177, 'TMIT előadástartó 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,178, 'TMIT előadástartó 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,179, 'TMIT gyakorlattartó 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,180, 'TMIT gyakorlattartó 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,181, 'TMIT gyakorlattartó 3', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,182, 'TMIT gyakorlattartó 4', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,183, 'TMIT gyakorlattartó 5', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,184, 'TMIT gyakorlattartó 6', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,185, 'TMIT gyakorlattartó 7', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,186, 'TMIT gyakorlattartó 8', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,187, 'TMIT gyakorlattartó 9', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,188, 'TMIT gyakorlattartó 10', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,189, 'TMIT labortartó 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,190, 'TMIT labortartó 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,191, 'TMIT labortartó 3', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,192, 'TMIT labortartó 4', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,193, 'TMIT labortartó 5', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,194, 'TMIT labortartó 6', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,195, 'TMIT labortartó 7', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,196, 'TMIT labortartó 8', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,197, 'TMIT labortartó 9', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,198, 'TMIT labortartó 10', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,199, 'VET előadástartó 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,200, 'VET előadástartó 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,201, 'VET gyakorlattartó 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,202, 'VET gyakorlattartó 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,203, 'VET gyakorlattartó 3', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,204, 'VET gyakorlattartó 4', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,205, 'VET gyakorlattartó 5', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,206, 'VET gyakorlattartó 6', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,207, 'VET gyakorlattartó 7', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,208, 'VET gyakorlattartó 8', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,209, 'VET gyakorlattartó 9', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,210, 'VET gyakorlattartó 10', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,211, 'VET labortartó 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,212, 'VET labortartó 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,213, 'VET labortartó 3', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,214, 'VET labortartó 4', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,215, 'VET labortartó 5', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,216, 'VET labortartó 6', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,217, 'VET labortartó 7', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,218, 'VET labortartó 8', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,219, 'VET labortartó 9', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,220, 'VET labortartó 10', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,221, 'BTK előadástartó 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,222, 'BTK előadástartó 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,223, 'BTK gyakorlattartó 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,224, 'BTK gyakorlattartó 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,225, 'BTK gyakorlattartó 3', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,226, 'BTK gyakorlattartó 4', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,227, 'BTK gyakorlattartó 5', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,228, 'BTK gyakorlattartó 6', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,229, 'BTK gyakorlattartó 7', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,230, 'BTK gyakorlattartó 8', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,231, 'BTK gyakorlattartó 9', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,232, 'BTK gyakorlattartó 10', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,233, 'BTK labortartó 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,234, 'BTK labortartó 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,235, 'BTK labortartó 3', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,236, 'BTK labortartó 4', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,237, 'BTK labortartó 5', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,238, 'BTK labortartó 6', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,239, 'BTK labortartó 7', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,240, 'BTK labortartó 8', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,241, 'BTK labortartó 9', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,242, 'BTK labortartó 10', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,243, 'MAT előadástartó 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,244, 'MAT előadástartó 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,245, 'MAT gyakorlattartó 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,246, 'MAT gyakorlattartó 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,247, 'MAT gyakorlattartó 3', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,248, 'MAT gyakorlattartó 4', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,249, 'MAT gyakorlattartó 5', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,250, 'MAT gyakorlattartó 6', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,251, 'MAT gyakorlattartó 7', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,252, 'MAT gyakorlattartó 8', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,253, 'MAT gyakorlattartó 9', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,254, 'MAT gyakorlattartó 10', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,255, 'MAT labortartó 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,256, 'MAT labortartó 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,257, 'MAT labortartó 3', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,258, 'MAT labortartó 4', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,259, 'MAT labortartó 5', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,260, 'MAT labortartó 6', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,261, 'MAT labortartó 7', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,262, 'MAT labortartó 8', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,263, 'MAT labortartó 9', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,264, 'MAT labortartó 10', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,265, 'FIZ előadástartó 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,266, 'FIZ előadástartó 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,267, 'FIZ gyakorlattartó 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,268, 'FIZ gyakorlattartó 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,269, 'FIZ gyakorlattartó 3', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,270, 'FIZ gyakorlattartó 4', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,271, 'FIZ gyakorlattartó 5', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,272, 'FIZ gyakorlattartó 6', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,273, 'FIZ gyakorlattartó 7', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,274, 'FIZ gyakorlattartó 8', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,275, 'FIZ gyakorlattartó 9', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,276, 'FIZ gyakorlattartó 10', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,277, 'FIZ labortartó 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,278, 'FIZ labortartó 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,279, 'FIZ labortartó 3', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,280, 'FIZ labortartó 4', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,281, 'FIZ labortartó 5', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,282, 'FIZ labortartó 6', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,283, 'FIZ labortartó 7', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,284, 'FIZ labortartó 8', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,285, 'FIZ labortartó 9', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,286, 'FIZ labortartó 10', 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,1, 28, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,2, 32, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,3, 38, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,4, 28, 1, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,5, 32, 1, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,6, 38, 1, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,7, 28, 2, 3);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,8, 32, 2, 3);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,9, 38, 2, 3);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,10, 28, 2, 4);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,11, 32, 2, 4);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,12, 38, 2, 4);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,13, 28, 2, 5);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,14, 32, 2, 5);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,15, 38, 2, 5);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,16, 28, 2, 6);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,17, 32, 2, 6);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,18, 38, 2, 6);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,19, 28, 2, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,20, 32, 2, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,21, 38, 2, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,22, 28, 2, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,23, 32, 2, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,24, 38, 2, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,25, 28, 2, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,26, 32, 2, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,27, 38, 2, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,28, 28, 2, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,29, 32, 2, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,30, 38, 2, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,31, 28, 2, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,32, 32, 2, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,33, 38, 2, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,34, 28, 2, 12);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,35, 32, 2, 12);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,36, 38, 2, 12);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,37, 28, 3, 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,38, 32, 3, 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,39, 38, 3, 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,40, 28, 3, 14);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,41, 32, 3, 14);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,42, 38, 3, 14);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,43, 28, 3, 15);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,44, 32, 3, 15);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,45, 38, 3, 15);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,46, 28, 3, 16);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,47, 32, 3, 16);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,48, 38, 3, 16);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,49, 28, 3, 17);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,50, 32, 3, 17);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,51, 38, 3, 17);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,52, 28, 3, 18);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,53, 32, 3, 18);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,54, 38, 3, 18);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,55, 28, 3, 19);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,56, 32, 3, 19);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,57, 38, 3, 19);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,58, 28, 3, 20);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,59, 32, 3, 20);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,60, 38, 3, 20);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,61, 28, 3, 21);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,62, 32, 3, 21);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,63, 38, 3, 21);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,64, 28, 3, 22);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,65, 32, 3, 22);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,66, 38, 3, 22);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,67, 2, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,68, 29, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,69, 2, 1, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,70, 29, 1, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,71, 2, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,72, 29, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,73, 2, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,74, 29, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,75, 2, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,76, 29, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,77, 2, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,78, 29, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,79, 2, 2, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,80, 29, 2, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,81, 2, 2, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,82, 29, 2, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,83, 2, 2, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,84, 29, 2, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,85, 2, 2, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,86, 29, 2, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,87, 2, 2, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,88, 29, 2, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,89, 2, 2, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,90, 29, 2, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,91, 2, 3, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,92, 29, 3, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,93, 2, 3, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,94, 29, 3, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,95, 2, 3, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,96, 29, 3, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,97, 2, 3, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,98, 29, 3, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,99, 2, 3, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,100, 29, 3, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,101, 2, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,102, 29, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,103, 2, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,104, 29, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,105, 2, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,106, 29, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,107, 2, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,108, 29, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,109, 2, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,110, 29, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,111, 14, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,112, 17, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,113, 18, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,114, 37, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,115, 14, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,116, 17, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,117, 18, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,118, 37, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,119, 14, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,120, 17, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,121, 18, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,122, 37, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,123, 14, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,124, 17, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,125, 18, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,126, 37, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,127, 14, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,128, 17, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,129, 18, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,130, 37, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,131, 14, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,132, 17, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,133, 18, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,134, 37, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,135, 14, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,136, 17, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,137, 18, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,138, 37, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,139, 14, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,140, 17, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,141, 18, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,142, 37, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,143, 14, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,144, 17, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,145, 18, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,146, 37, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,147, 14, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,148, 17, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,149, 18, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,150, 37, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,151, 14, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,152, 17, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,153, 18, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,154, 37, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,155, 14, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,156, 17, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,157, 18, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,158, 37, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,159, 14, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,160, 17, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,161, 18, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,162, 37, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,163, 14, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,164, 17, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,165, 18, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,166, 37, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,167, 14, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,168, 17, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,169, 18, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,170, 37, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,171, 14, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,172, 17, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,173, 18, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,174, 37, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,175, 14, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,176, 17, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,177, 18, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,178, 37, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,179, 14, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,180, 17, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,181, 18, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,182, 37, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,183, 14, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,184, 17, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,185, 18, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,186, 37, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,187, 14, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,188, 17, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,189, 18, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,190, 37, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,191, 14, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,192, 17, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,193, 18, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,194, 37, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,195, 14, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,196, 17, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,197, 18, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,198, 37, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,199, 10, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,200, 15, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,201, 20, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,202, 26, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,203, 27, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,204, 35, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,205, 10, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,206, 15, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,207, 20, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,208, 26, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,209, 27, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,210, 35, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,211, 10, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,212, 15, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,213, 20, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,214, 26, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,215, 27, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,216, 35, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,217, 10, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,218, 15, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,219, 20, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,220, 26, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,221, 27, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,222, 35, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,223, 10, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,224, 15, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,225, 20, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,226, 26, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,227, 27, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,228, 35, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,229, 10, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,230, 15, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,231, 20, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,232, 26, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,233, 27, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,234, 35, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,235, 10, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,236, 15, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,237, 20, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,238, 26, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,239, 27, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,240, 35, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,241, 10, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,242, 15, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,243, 20, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,244, 26, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,245, 27, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,246, 35, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,247, 10, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,248, 15, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,249, 20, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,250, 26, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,251, 27, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,252, 35, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,253, 10, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,254, 15, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,255, 20, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,256, 26, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,257, 27, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,258, 35, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,259, 10, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,260, 15, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,261, 20, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,262, 26, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,263, 27, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,264, 35, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,265, 10, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,266, 15, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,267, 20, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,268, 26, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,269, 27, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,270, 35, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,271, 10, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,272, 15, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,273, 20, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,274, 26, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,275, 27, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,276, 35, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,277, 10, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,278, 15, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,279, 20, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,280, 26, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,281, 27, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,282, 35, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,283, 10, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,284, 15, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,285, 20, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,286, 26, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,287, 27, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,288, 35, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,289, 10, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,290, 15, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,291, 20, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,292, 26, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,293, 27, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,294, 35, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,295, 10, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,296, 15, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,297, 20, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,298, 26, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,299, 27, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,300, 35, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,301, 10, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,302, 15, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,303, 20, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,304, 26, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,305, 27, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,306, 35, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,307, 10, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,308, 15, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,309, 20, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,310, 26, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,311, 27, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,312, 35, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,313, 10, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,314, 15, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,315, 20, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,316, 26, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,317, 27, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,318, 35, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,319, 10, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,320, 15, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,321, 20, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,322, 26, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,323, 27, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,324, 35, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,325, 10, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,326, 15, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,327, 20, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,328, 26, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,329, 27, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,330, 35, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,331, 6, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,332, 13, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,333, 25, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,334, 30, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,335, 34, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,336, 39, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,337, 40, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,338, 42, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,339, 6, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,340, 13, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,341, 25, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,342, 30, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,343, 34, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,344, 39, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,345, 40, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,346, 42, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,347, 6, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,348, 13, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,349, 25, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,350, 30, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,351, 34, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,352, 39, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,353, 40, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,354, 42, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,355, 6, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,356, 13, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,357, 25, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,358, 30, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,359, 34, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,360, 39, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,361, 40, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,362, 42, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,363, 6, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,364, 13, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,365, 25, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,366, 30, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,367, 34, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,368, 39, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,369, 40, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,370, 42, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,371, 6, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,372, 13, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,373, 25, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,374, 30, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,375, 34, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,376, 39, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,377, 40, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,378, 42, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,379, 6, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,380, 13, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,381, 25, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,382, 30, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,383, 34, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,384, 39, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,385, 40, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,386, 42, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,387, 6, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,388, 13, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,389, 25, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,390, 30, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,391, 34, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,392, 39, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,393, 40, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,394, 42, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,395, 6, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,396, 13, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,397, 25, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,398, 30, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,399, 34, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,400, 39, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,401, 40, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,402, 42, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,403, 6, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,404, 13, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,405, 25, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,406, 30, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,407, 34, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,408, 39, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,409, 40, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,410, 42, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,411, 6, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,412, 13, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,413, 25, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,414, 30, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,415, 34, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,416, 39, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,417, 40, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,418, 42, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,419, 6, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,420, 13, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,421, 25, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,422, 30, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,423, 34, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,424, 39, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,425, 40, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,426, 42, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,427, 6, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,428, 13, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,429, 25, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,430, 30, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,431, 34, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,432, 39, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,433, 40, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,434, 42, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,435, 6, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,436, 13, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,437, 25, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,438, 30, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,439, 34, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,440, 39, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,441, 40, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,442, 42, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,443, 6, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,444, 13, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,445, 25, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,446, 30, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,447, 34, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,448, 39, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,449, 40, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,450, 42, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,451, 6, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,452, 13, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,453, 25, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,454, 30, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,455, 34, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,456, 39, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,457, 40, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,458, 42, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,459, 6, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,460, 13, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,461, 25, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,462, 30, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,463, 34, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,464, 39, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,465, 40, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,466, 42, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,467, 6, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,468, 13, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,469, 25, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,470, 30, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,471, 34, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,472, 39, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,473, 40, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,474, 42, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,475, 6, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,476, 13, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,477, 25, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,478, 30, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,479, 34, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,480, 39, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,481, 40, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,482, 42, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,483, 6, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,484, 13, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,485, 25, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,486, 30, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,487, 34, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,488, 39, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,489, 40, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,490, 42, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,491, 6, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,492, 13, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,493, 25, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,494, 30, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,495, 34, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,496, 39, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,497, 40, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,498, 42, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,499, 6, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,500, 13, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,501, 25, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,502, 30, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,503, 34, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,504, 39, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,505, 40, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,506, 42, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,507, 3, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,508, 11, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,509, 21, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,510, 22, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,511, 41, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,512, 3, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,513, 11, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,514, 21, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,515, 22, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,516, 41, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,517, 3, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,518, 11, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,519, 21, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,520, 22, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,521, 41, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,522, 3, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,523, 11, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,524, 21, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,525, 22, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,526, 41, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,527, 3, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,528, 11, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,529, 21, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,530, 22, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,531, 41, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,532, 3, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,533, 11, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,534, 21, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,535, 22, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,536, 41, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,537, 3, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,538, 11, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,539, 21, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,540, 22, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,541, 41, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,542, 3, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,543, 11, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,544, 21, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,545, 22, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,546, 41, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,547, 3, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,548, 11, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,549, 21, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,550, 22, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,551, 41, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,552, 3, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,553, 11, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,554, 21, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,555, 22, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,556, 41, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,557, 3, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,558, 11, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,559, 21, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,560, 22, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,561, 41, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,562, 3, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,563, 11, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,564, 21, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,565, 22, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,566, 41, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,567, 3, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,568, 11, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,569, 21, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,570, 22, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,571, 41, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,572, 3, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,573, 11, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,574, 21, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,575, 22, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,576, 41, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,577, 3, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,578, 11, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,579, 21, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,580, 22, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,581, 41, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,582, 3, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,583, 11, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,584, 21, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,585, 22, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,586, 41, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,587, 3, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,588, 11, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,589, 21, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,590, 22, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,591, 41, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,592, 3, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,593, 11, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,594, 21, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,595, 22, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,596, 41, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,597, 3, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,598, 11, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,599, 21, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,600, 22, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,601, 41, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,602, 3, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,603, 11, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,604, 21, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,605, 22, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,606, 41, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,607, 3, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,608, 11, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,609, 21, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,610, 22, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,611, 41, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,612, 3, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,613, 11, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,614, 21, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,615, 22, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,616, 41, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,617, 19, 1, 155);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,618, 19, 1, 156);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,619, 19, 2, 157);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,620, 19, 2, 158);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,621, 19, 2, 159);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,622, 19, 2, 160);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,623, 19, 2, 161);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,624, 19, 2, 162);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,625, 19, 2, 163);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,626, 19, 2, 164);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,627, 19, 2, 165);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,628, 19, 2, 166);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,629, 19, 3, 167);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,630, 19, 3, 168);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,631, 19, 3, 169);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,632, 19, 3, 170);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,633, 19, 3, 171);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,634, 19, 3, 172);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,635, 19, 3, 173);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,636, 19, 3, 174);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,637, 19, 3, 175);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,638, 19, 3, 176);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,639, 16, 1, 177);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,640, 23, 1, 177);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,641, 36, 1, 177);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,642, 16, 1, 178);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,643, 23, 1, 178);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,644, 36, 1, 178);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,645, 16, 2, 179);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,646, 23, 2, 179);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,647, 36, 2, 179);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,648, 16, 2, 180);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,649, 23, 2, 180);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,650, 36, 2, 180);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,651, 16, 2, 181);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,652, 23, 2, 181);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,653, 36, 2, 181);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,654, 16, 2, 182);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,655, 23, 2, 182);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,656, 36, 2, 182);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,657, 16, 2, 183);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,658, 23, 2, 183);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,659, 36, 2, 183);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,660, 16, 2, 184);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,661, 23, 2, 184);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,662, 36, 2, 184);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,663, 16, 2, 185);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,664, 23, 2, 185);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,665, 36, 2, 185);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,666, 16, 2, 186);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,667, 23, 2, 186);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,668, 36, 2, 186);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,669, 16, 2, 187);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,670, 23, 2, 187);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,671, 36, 2, 187);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,672, 16, 2, 188);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,673, 23, 2, 188);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,674, 36, 2, 188);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,675, 16, 3, 189);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,676, 23, 3, 189);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,677, 36, 3, 189);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,678, 16, 3, 190);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,679, 23, 3, 190);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,680, 36, 3, 190);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,681, 16, 3, 191);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,682, 23, 3, 191);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,683, 36, 3, 191);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,684, 16, 3, 192);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,685, 23, 3, 192);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,686, 36, 3, 192);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,687, 16, 3, 193);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,688, 23, 3, 193);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,689, 36, 3, 193);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,690, 16, 3, 194);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,691, 23, 3, 194);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,692, 36, 3, 194);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,693, 16, 3, 195);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,694, 23, 3, 195);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,695, 36, 3, 195);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,696, 16, 3, 196);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,697, 23, 3, 196);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,698, 36, 3, 196);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,699, 16, 3, 197);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,700, 23, 3, 197);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,701, 36, 3, 197);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,702, 16, 3, 198);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,703, 23, 3, 198);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,704, 36, 3, 198);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,705, 8, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,706, 24, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,707, 31, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,708, 33, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,709, 8, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,710, 24, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,711, 31, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,712, 33, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,713, 8, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,714, 24, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,715, 31, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,716, 33, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,717, 8, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,718, 24, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,719, 31, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,720, 33, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,721, 8, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,722, 24, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,723, 31, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,724, 33, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,725, 8, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,726, 24, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,727, 31, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,728, 33, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,729, 8, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,730, 24, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,731, 31, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,732, 33, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,733, 8, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,734, 24, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,735, 31, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,736, 33, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,737, 8, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,738, 24, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,739, 31, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,740, 33, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,741, 8, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,742, 24, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,743, 31, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,744, 33, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,745, 8, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,746, 24, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,747, 31, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,748, 33, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,749, 8, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,750, 24, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,751, 31, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,752, 33, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,753, 8, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,754, 24, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,755, 31, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,756, 33, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,757, 8, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,758, 24, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,759, 31, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,760, 33, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,761, 8, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,762, 24, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,763, 31, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,764, 33, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,765, 8, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,766, 24, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,767, 31, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,768, 33, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,769, 8, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,770, 24, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,771, 31, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,772, 33, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,773, 8, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,774, 24, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,775, 31, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,776, 33, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,777, 8, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,778, 24, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,779, 31, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,780, 33, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,781, 8, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,782, 24, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,783, 31, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,784, 33, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,785, 8, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,786, 24, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,787, 31, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,788, 33, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,789, 8, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,790, 24, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,791, 31, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,792, 33, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,793, 1, 1, 243);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,794, 5, 1, 243);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,795, 9, 1, 243);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,796, 1, 1, 244);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,797, 5, 1, 244);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,798, 9, 1, 244);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,799, 1, 2, 245);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,800, 5, 2, 245);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,801, 9, 2, 245);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,802, 1, 2, 246);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,803, 5, 2, 246);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,804, 9, 2, 246);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,805, 1, 2, 247);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,806, 5, 2, 247);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,807, 9, 2, 247);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,808, 1, 2, 248);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,809, 5, 2, 248);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,810, 9, 2, 248);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,811, 1, 2, 249);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,812, 5, 2, 249);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,813, 9, 2, 249);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,814, 1, 2, 250);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,815, 5, 2, 250);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,816, 9, 2, 250);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,817, 1, 2, 251);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,818, 5, 2, 251);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,819, 9, 2, 251);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,820, 1, 2, 252);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,821, 5, 2, 252);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,822, 9, 2, 252);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,823, 1, 2, 253);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,824, 5, 2, 253);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,825, 9, 2, 253);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,826, 1, 2, 254);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,827, 5, 2, 254);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,828, 9, 2, 254);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,829, 1, 3, 255);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,830, 5, 3, 255);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,831, 9, 3, 255);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,832, 1, 3, 256);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,833, 5, 3, 256);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,834, 9, 3, 256);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,835, 1, 3, 257);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,836, 5, 3, 257);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,837, 9, 3, 257);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,838, 1, 3, 258);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,839, 5, 3, 258);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,840, 9, 3, 258);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,841, 1, 3, 259);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,842, 5, 3, 259);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,843, 9, 3, 259);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,844, 1, 3, 260);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,845, 5, 3, 260);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,846, 9, 3, 260);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,847, 1, 3, 261);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,848, 5, 3, 261);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,849, 9, 3, 261);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,850, 1, 3, 262);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,851, 5, 3, 262);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,852, 9, 3, 262);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,853, 1, 3, 263);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,854, 5, 3, 263);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,855, 9, 3, 263);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,856, 1, 3, 264);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,857, 5, 3, 264);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,858, 9, 3, 264);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,859, 4, 1, 265);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,860, 7, 1, 265);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,861, 12, 1, 265);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,862, 4, 1, 266);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,863, 7, 1, 266);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,864, 12, 1, 266);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,865, 4, 2, 267);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,866, 7, 2, 267);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,867, 12, 2, 267);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,868, 4, 2, 268);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,869, 7, 2, 268);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,870, 12, 2, 268);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,871, 4, 2, 269);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,872, 7, 2, 269);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,873, 12, 2, 269);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,874, 4, 2, 270);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,875, 7, 2, 270);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,876, 12, 2, 270);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,877, 4, 2, 271);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,878, 7, 2, 271);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,879, 12, 2, 271);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,880, 4, 2, 272);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,881, 7, 2, 272);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,882, 12, 2, 272);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,883, 4, 2, 273);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,884, 7, 2, 273);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,885, 12, 2, 273);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,886, 4, 2, 274);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,887, 7, 2, 274);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,888, 12, 2, 274);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,889, 4, 2, 275);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,890, 7, 2, 275);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,891, 12, 2, 275);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,892, 4, 2, 276);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,893, 7, 2, 276);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,894, 12, 2, 276);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,895, 4, 3, 277);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,896, 7, 3, 277);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,897, 12, 3, 277);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,898, 4, 3, 278);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,899, 7, 3, 278);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,900, 12, 3, 278);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,901, 4, 3, 279);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,902, 7, 3, 279);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,903, 12, 3, 279);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,904, 4, 3, 280);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,905, 7, 3, 280);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,906, 12, 3, 280);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,907, 4, 3, 281);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,908, 7, 3, 281);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,909, 12, 3, 281);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,910, 4, 3, 282);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,911, 7, 3, 282);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,912, 12, 3, 282);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,913, 4, 3, 283);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,914, 7, 3, 283);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,915, 12, 3, 283);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,916, 4, 3, 284);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,917, 7, 3, 284);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,918, 12, 3, 284);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,919, 4, 3, 285);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,920, 7, 3, 285);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,921, 12, 3, 285);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,922, 4, 3, 286);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,923, 7, 3, 286);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,924, 12, 3, 286);");
    try {

        pqxx::work w(_db);

        for(auto insert : inserts) {

            w.exec(insert);
        }

        w.commit();

    } catch (std::exception& e) {

        std::cerr << e.what();
    }
}

void Database::destroy() {

    try {

        pqxx::work w(_db);
        w.exec("DROP OWNED BY " + _user + ";");
        w.commit();

    } catch (std::exception& e) {

        std::cerr << e.what();
    }
}

