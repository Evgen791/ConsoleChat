#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include <map>
#include "User.h"
#include "Message.h"
                              //В данном коде реализован класс Chat, отвечающий за логику работы чата.
                              //Он предоставляет методы для регистрации пользователей, входа/выхода из системы, отправки сообщений и получения списка пользователей и сообщений.
                              //Класс также хранит информацию о пользователях (в виде карты) и о текущем авторизованном пользователе (в виде указателя).
class Chat {
public:
    Chat() :
        logged_in_user(nullptr)
    {}

    void register_user(const std::string& name, const std::string& password) {
        users.emplace(name, User(name, password));
    }

    bool login(const std::string& name, const std::string& password) {
        auto it = users.find(name);
        if (it != users.end() && it->second.verify_password(password)) {
            it->second.set_online(true);
            logged_in_user = &it->second;
            return true;
        }
        return false;
    }

    void logout() {
        if (logged_in_user) {
            logged_in_user->set_online(false);
            logged_in_user = nullptr;
        }
    }

    bool is_logged_in() const {
        return logged_in_user != nullptr;
    }

    void send_message(const std::string& text) {
        if (logged_in_user) {
            messages.emplace_back(logged_in_user->get_name(), text);
        }
    }

    std::vector<Message> get_messages() const {
        return messages;
    }

    std::vector<User> get_users() const {
        std::vector<User> online_users;
        for (const auto& it : users) {
            if (it.second.is_online()) {
                online_users.emplace_back(it.second);
            }
        }
        return online_users;
    }

private:
    std::map<std::string, User> users;
    User* logged_in_user;
    std::vector<Message> messages;
};

#endif // CHAT_H