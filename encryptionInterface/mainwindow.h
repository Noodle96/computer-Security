#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include<QMessageBox>
#include<QTextEdit>
#include <QVBoxLayout>
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QTabWidget;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showMessageAbout();

private:
    Ui::MainWindow *ui;
    QTabWidget *metodo_tipo;
};
#endif // MAINWINDOW_H
