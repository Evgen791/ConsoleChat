#include <iostream>
#include <string>
#include "Chat.h"

void print_users(const Chat& chat) {
    std::cout << "Users online:" << std::endl;
    auto users = chat.get_users();
    for (const auto& user : users) {
        std::cout << user.get_name() << std::endl;
    }
}

void print_messages(const Chat& chat) {
    std::cout << "Messages:" << std::endl;
    auto messages = chat.get_messages();
    for (const auto& message : messages) 
    {
        std::time_t timestamp = message.get_timestamp();
        std::cout << "[" << std::asctime(std::localtime(&timestamp)) << "] " << message.get_sender()
                  << ": " << message.get_text() << std::endl;
    }
}

int main() {
    Chat chat;

    std::string command;
    std::string username;
    std::string password;
    std::string message;

    while(true) {
        std::cout << "Welcome console chat)!"<<std::endl;
        std::cout <<"Enter command (register, login, logout, send, users, messages, quit): ";
        std::cin >> command;

        if (command == "register") {
            std::cout << "Enter username and password: ";
            std::cin >> username >> password;
            chat.register_user(username, password);
        }
        else if (command == "login") {
            std::cout << "Enter username and password: ";
            std::cin >> username >> password;
            if (chat.login(username, password)) {
                std::cout << "Logged in as " << username << std::endl;
            }
            else {
                std::cout << "Invalid username or password" << std::endl;
            }
        }
        else if (command == "logout") {
            chat.logout();
            std::cout << "Logged out" << std::endl;
        }
        else if (command == "send") {
            if (chat.is_logged_in()) {
                std::cout << "Enter message: ";
                std::getline(std::cin >> std::ws, message);
                chat.send_message(message);
            }
            else {
                std::cout << "You need to log in first" << std::endl;
            }
        } 
            else if (command == "users") 
            { print_users(chat); }
            else if (command == "messages") 
            { print_messages(chat); }
            else if (command == "quit") 
            { break; } 
            else { std::cout << "Invalid command" << std::endl; } }

return 0;
}