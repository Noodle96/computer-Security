#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //! [0]
    //ui->setupUi(this);
    // Crear el widget central
    QWidget *centralWidget = new QWidget(this);

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


    //! [0]

    //! [1]
    tabWidget = new QTabWidget;
    tabWidget->addTab(new ADFGVXEncryptionTab(), tr("ADFGVX Encryption"));
    tabWidget->addTab(new ADFGVXDecryptionTab(), tr("ADFGVX Decryption") );
    //! [1]

    //![2]
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(tabWidget);
    setCentralWidget(centralWidget);

    //setLayout(mainLayout);
    //![2]
}

//MainWindow::~MainWindow()
//{
    //delete ui;
//}

void MainWindow::showMessageAbout(){
    //std::cout << "desde show message" << std::endl;
    QMessageBox::about(this, "About us","Developed by NoYellowTeam");
    return;
}

ADFGVXEncryptionTab::ADFGVXEncryptionTab(QWidget *parent)
    :QWidget(parent)
{
    ;
}

ADFGVXDecryptionTab::ADFGVXDecryptionTab(QWidget *parent)
    :QWidget(parent)
{
    ;
}

