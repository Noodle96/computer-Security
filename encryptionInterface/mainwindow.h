#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include<QMessageBox>
#include<QTextEdit>
#include <QVBoxLayout>
#include<QLabel>
#include <QMenu>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
class QTabWidget;
QT_END_NAMESPACE

//! [0]
class ADFGVXEncryptionTab: public QWidget{
    Q_OBJECT // Agregar esta macro para usar señales y ranuras
public:
    explicit ADFGVXEncryptionTab(QWidget *parent = nullptr);
private slots:
    void handleEncrypt() {
        std::cout << "hola de handle" <<std::endl;
    }
    void onLineClaveTextChanged(const QString &text) {
        if (!text.isEmpty()) {
            // Si el lineEdit tiene contenido, muestra el QLabel formateado
            lineFormateado->show();
            labelFormateado->show();

        } else {
            // Si el lineEdit está vacío, oculta el QLabel formateado
            lineFormateado->hide();
            labelFormateado->hide();
        }
    }
private:
    QLineEdit *lineClave;
    QLabel *labelFormateado;
    QLineEdit *lineFormateado;

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
