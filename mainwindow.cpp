#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* -------- 表格初始设置 -------- */
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(
        { "姓名", "手机", "邮箱" });
    ui->tableWidget->horizontalHeader()
        ->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior(
        QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(
        QAbstractItemView::NoEditTriggers);

    /* -------- 信号槽连接 -------- */
    connect(ui->addButton,    &QPushButton::clicked,
            this, &MainWindow::onAddClicked);
    connect(ui->deleteButton, &QPushButton::clicked,
            this, &MainWindow::onDeleteClicked);
    connect(ui->searchButton, &QPushButton::clicked,
            this, &MainWindow::onSearchClicked);
    connect(ui->sortButton,   &QPushButton::clicked,
            this, &MainWindow::onSortByNameClicked);

    phoneBook.loadFromFile("contacts.json");
    updateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ---------- 程序关闭时保存联系人 ---------- */
void MainWindow::closeEvent(QCloseEvent *event)
{
    phoneBook.saveToFile("contacts.json");
    QMainWindow::closeEvent(event);
}

/* ---------- 私有工具：刷新表格 ---------- */
void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(0);
    const QList<Contact>& list = phoneBook.getAllContacts();

    for (const Contact& c : list) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(c.getName()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c.getPhone()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c.getEmail()));
    }
}

/* ---------- 槽：增加 ---------- */
void MainWindow::onAddClicked()
{
    QString name  = ui->nameEdit ->text().trimmed();
    QString phone = ui->phoneEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();

    if (name.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "姓名和手机不能为空");
        return;
    }

    phoneBook.addContact(Contact(name, phone, email));
    updateTable();

    ui->nameEdit ->clear();
    ui->phoneEdit->clear();
    ui->emailEdit->clear();
}

/* ---------- 槽：删除 ---------- */
void MainWindow::onDeleteClicked()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "提示", "请先选中要删除的联系人");
        return;
    }

    const QList<Contact>& list = phoneBook.getAllContacts();
    if (row < list.size())
        phoneBook.deleteContact(list[row].getName());

    updateTable();
}

/* ---------- 槽：查找（按姓名含关键字） ---------- */
void MainWindow::onSearchClicked()
{
    QString key = ui->nameEdit->text().trimmed();
    for (int r = 0; r < ui->tableWidget->rowCount(); ++r) {
        bool match = ui->tableWidget->item(r,0)
        ->text().contains(key, Qt::CaseInsensitive);
        ui->tableWidget->setRowHidden(r, !match);
    }
}

/* ---------- 槽：按姓名排序（可切换升降序） ---------- */
void MainWindow::onSortByNameClicked()
{
    phoneBook.sortByName(sortAscending);
    sortAscending = !sortAscending;
    updateTable();
}
