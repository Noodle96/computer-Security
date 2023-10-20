#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/*
#include <iostream>
#include<QMessageBox>
#include<QTextEdit>
#include <QVBoxLayout>
#include<QLabel>
#include <QMenu>
*/
QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
class QTabWidget;
QT_END_NAMESPACE

//! [0]
class ADFGVXEncryptionTab: public QWidget{
    Q_OBJECT
public:
    explicit ADFGVXEncryptionTab(QWidget *parent = nullptr);
};
//! [0]

//! [1]
class ADFGVXDecryptionTab: public QWidget{
    Q_OBJECT
public:
    explicit ADFGVXDecryptionTab(QWidget *parent = nullptr);
};
//! [1]

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    //~MainWindow();
public slots:
    void showMessageAbout();

private:
    QTabWidget *tabWidget;
};
#endif // MAINWINDOW_H
