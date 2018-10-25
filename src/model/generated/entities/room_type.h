#pragma once

#ifndef __ROOM_TYPE__H__
#define __ROOM_TYPE__H__

#include <string>

namespace chronos {

class RoomType {

public:

    RoomType();

    RoomType(
        int p_id,
        std::string p_name,
        int p_size,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    std::string name() const;
    int size() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    std::string _name;
    int _size;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__ROOM_TYPE__H__
