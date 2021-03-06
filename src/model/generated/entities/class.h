#pragma once

#ifndef __CLASS__H__
#define __CLASS__H__

#include <string>

namespace chronos {

class Class {

public:

    Class();

    Class(
        int p_id,
        std::string p_modified_timestamp,
        bool p_is_deleted,
        std::string p_name,
        int p_class_type_id,
        int p_course_id
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string name() const;
    int class_type_id() const;
    int course_id() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    std::string _name;
    int _class_type_id;
    int _course_id;

};

}

#endif //__CLASS__H__

