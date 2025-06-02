#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "phonebook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onAddClicked();
    void onDeleteClicked();
    void onSearchClicked();
    void onSortByNameClicked();

private:
    void updateTable();

    Ui::MainWindow *ui;
    PhoneBook phoneBook;
    bool sortAscending = true;
};

#endif // MAINWINDOW_H
