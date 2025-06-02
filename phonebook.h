#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h"
#include <QList>
#include <QString>

class PhoneBook {
public:
    void addContact(const Contact& contact);
    void deleteContact(const QString& name);
    QList<Contact> searchContacts(const QString& keyword) const;
    const QList<Contact>& getAllContacts() const;

    void sortByName(bool ascending = true);

    void clear();

    bool saveToFile(const QString& filePath);
    bool loadFromFile(const QString& filePath);

private:
    QList<Contact> contacts;
};

#endif // PHONEBOOK_H
