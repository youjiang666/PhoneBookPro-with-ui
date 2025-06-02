#include "phonebook.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

void PhoneBook::addContact(const Contact& contact) {
    contacts.append(contact);
}

void PhoneBook::deleteContact(const QString& name) {
    contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
                                  [&](const Contact& c) {
                                      return c.getName() == name;
                                  }), contacts.end());
}

QList<Contact> PhoneBook::searchContacts(const QString& keyword) const {
    QList<Contact> result;
    for (const Contact& c : contacts) {
        if (c.getName().contains(keyword, Qt::CaseInsensitive) ||
            c.getPhone().contains(keyword, Qt::CaseInsensitive) ||
            c.getEmail().contains(keyword, Qt::CaseInsensitive)) {
            result.append(c);
        }
    }
    return result;
}

const QList<Contact>& PhoneBook::getAllContacts() const {
    return contacts;
}

void PhoneBook::sortByName(bool ascending)
{
    std::sort(contacts.begin(), contacts.end(),
              [&](const Contact& a, const Contact& b) {
                  int result = QString::localeAwareCompare(a.getName(), b.getName());
                  return ascending ? (result < 0) : (result > 0);
              });
}

void PhoneBook::clear() {
    contacts.clear();
}

bool PhoneBook::saveToFile(const QString& filePath) {
    QJsonArray jsonArray;
    for (const Contact& c : contacts)
        jsonArray.append(c.toJson());

    QJsonDocument doc(jsonArray);
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    file.write(doc.toJson());
    return true;
}

bool PhoneBook::loadFromFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray())
        return false;

    contacts.clear();
    QJsonArray array = doc.array();
    for (const QJsonValue& val : array)
        contacts.append(Contact::fromJson(val.toObject()));

    return true;
}
