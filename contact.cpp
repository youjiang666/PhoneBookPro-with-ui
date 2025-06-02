#include "contact.h"

QString Contact::getName() const { return name; }
QString Contact::getPhone() const { return phone; }
QString Contact::getEmail() const { return email; }

void Contact::setName(const QString& v) { name = v; }
void Contact::setPhone(const QString& v) { phone = v; }
void Contact::setEmail(const QString& v) { email = v; }

QJsonObject Contact::toJson() const {
    QJsonObject obj;
    obj["name"] = name;
    obj["phone"] = phone;
    obj["email"] = email;
    return obj;
}

Contact Contact::fromJson(const QJsonObject& obj) {
    return Contact(
        obj["name"].toString(),
        obj["phone"].toString(),
        obj["email"].toString()
        );
}
