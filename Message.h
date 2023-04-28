#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>

class Message {
public:
    Message(const std::string& sender, const std::string& text) :
        sender(sender),
        text(text),
        timestamp(std::time(nullptr)) // Устанавливаем временную метку на текущее время
    {}
 // Методы доступа к данным сообщения
    const std::string& get_sender() const {
        return sender;
    }

    const std::string& get_text() const {
        return text;
    }

    std::time_t get_timestamp() const {
        return timestamp;
    }

private:
    std::string sender; // Отправитель
    std::string text; // Текст сообщения
    std::time_t timestamp; // Временная метка
};

#endif // MESSAGE_H