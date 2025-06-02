#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QJsonObject>

class Contact {
public:
    Contact(QString name = "", QString phone = "", QString email = "") :
        name(name), phone(phone), email(email) {}

    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;

    void setName(const QString& v);
    void setPhone(const QString& v);
    void setEmail(const QString& v);

    QJsonObject toJson() const;
    static Contact fromJson(const QJsonObject& obj);

private:
    QString name;
    QString phone;
    QString email;
};

#endif // CONTACT_H
