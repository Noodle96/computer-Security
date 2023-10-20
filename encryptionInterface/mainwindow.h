#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "adfgvx.h"
#include <QMainWindow>

#include <iostream>
#include<QMessageBox>
#include<QTextEdit>
#include <QVBoxLayout>
#include<QLabel>
#include <QMenu>
#include <QLineEdit>
#include <QPushButton>

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
        QString contenidoLineClave = lineClave->text();
        claveFormateada = contenidoLineClave.toStdString();
        //MAIN FUNTION
        if(!claveFormateada.empty() && !textFormateado.empty() ){
            buttonEncriptar->setStyleSheet("background-color: #4CAF50; color: white;"); // Estilo por defecto
            buttonEncriptar->setEnabled(true);
        }else{
            buttonEncriptar->setEnabled(false);
            buttonEncriptar->setStyleSheet("background-color: red; color: white;");
        }
        if (!text.isEmpty()) {
            //uso adfgvx solo para procesar contenidoLineClave
            adfgvx.preprocesado(claveFormateada);

            // Si el lineEdit tiene contenido, muestra el QLabel formateado
            labelFormateado->show();
            lineFormateado->show();
            lineFormateado->setText(QString::fromStdString(claveFormateada));
        } else {
            // Si el lineEdit está vacío, oculta el QLabel formateado
            lineFormateado->hide();
            labelFormateado->hide();
        }
    }

    void onTextEditTextPlainTextChanged() {
        QString contenidoTextEditPlainText = textEditTextPlain->toPlainText();
        textFormateado = contenidoTextEditPlainText.toStdString();
        //MAIN FUNTION
        if(!claveFormateada.empty() && !textFormateado.empty() ){
            buttonEncriptar->setStyleSheet("background-color: #4CAF50; color: white;"); // Estilo por defecto
            buttonEncriptar->setEnabled(true);
        }
        else{
            buttonEncriptar->setEnabled(false);
            buttonEncriptar->setStyleSheet("background-color: red; color: white;");
        }
        if (!textEditTextPlain->toPlainText().isEmpty()) {
            //uso adfgvx solo para procesar contenidoLineClave
            adfgvx.preprocesado(textFormateado);

            // Si el lineEdit tiene contenido, muestra el QLabel formateado
            labelTextPlainLimpio->show();
            textEditTextPlainLimpio->show();
            textEditTextPlainLimpio->setText(QString::fromStdString(textFormateado));
        } else {
            // Si el lineEdit está vacío, oculta el QLabel formateado
            textEditTextPlainLimpio->hide();
            labelTextPlainLimpio->hide();
        }
    }

private:
    string claveFormateada;
    string textFormateado;
    ADFGVX adfgvx;

    QLineEdit *lineClave;
    QLabel *labelFormateado;
    QLineEdit *lineFormateado;

    QTextEdit *textEditTextPlain;

    QLabel *labelTextPlainLimpio;
    QTextEdit *textEditTextPlainLimpio;
    QPushButton *buttonEncriptar = new QPushButton("ENCRIPTAR", this);

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
