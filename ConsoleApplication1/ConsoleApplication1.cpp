# mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    QString filePath;
};

#endif // MAINWINDOW_H


# mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filePath = "../../test141/config.ini";
    QFile file(filePath);
    file.open(QFile::ReadOnly);
    while (!file.atEnd()) {
        qDebug() << file.readLine();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


# config.ini
windowwidth = 1100
windowheight = 900
