#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& name, const std::string& password) :
        name(name),
        password(password),
        online(false)
    {}
// Методы доступа к данным пользователя
    const std::string& get_name() const {
        return name;
    }

    bool verify_password(const std::string& password) const {
        return password == this->password;
    }
// Методы для управления статусом пользователя (в сети или нет)
    bool is_online() const {
        return online;
    }

    void set_online(bool online) {
        this->online = online;
    }

private:
    std::string name;
    std::string password;
    bool online;
};

#endif // USER_H