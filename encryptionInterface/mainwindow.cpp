#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *fileMenu = new QMenu(tr("&File"),this);
    QAction *quitAction = fileMenu->addAction(tr("&Exit"));
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction, &QAction::triggered, this, &MainWindow::close);

    QMenu *helpMenu = new QMenu(tr("&Help"),this);
    QAction *aboutAction = helpMenu->addAction((tr("&About")));
    //aboutAction->setShortcut(QKeySequence::any);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showMessageAbout);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(helpMenu);

    metodo_tipo = new QTabWidget;
    setCentralWidget(metodo_tipo);
    setWindowTitle(tr("Order Form"));

    //QVBoxLayout *editor = new QVBoxLayout;
    //int tabIndex = metodo_tipo->addTab(editor, "alea");
    //metodo_tipo->setCurrentIndex(tabIndex);

    QWidget *tab1 = new QWidget;
    QLabel *label1 = new QLabel("Contenido de la Pestaña 1");
                     tab1->setLayout(new QVBoxLayout);
    tab1->layout()->addWidget(label1);
    metodo_tipo->addTab(tab1, "Pestaña 1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMessageAbout(){
    //std::cout << "desde show message" << std::endl;
    QMessageBox::about(this, "About us","Developed by NoYellowTeam");
    return;
}
