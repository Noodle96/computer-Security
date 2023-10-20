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
    /*
    QLabel *label = new QLabel("ADFGVX Encryption Tab", this);
    label->setAlignment(Qt::AlignLeft | Qt::AlignTop); // Alinea el texto arriba a la izquierda

    QLineEdit *input = new QLineEdit(this);
    QPushButton *button = new QPushButton("Encrypt", this);
    button->setMaximumWidth(100);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(input);
    layout->addWidget(button);

    // Configurar un slot para manejar eventos del botón (por ejemplo, el clic)
    connect(button, &QPushButton::clicked, this, &ADFGVXEncryptionTab::handleEncrypt);

    setLayout(layout);
    */
        // Crear widgets
        QLabel *label1 = new QLabel("CLAVE:", this);
        QLineEdit *lineEdit = new QLineEdit(this);
        QLabel *label2 = new QLabel("TEXTO PLANO:", this);
        QPushButton *button = new QPushButton("ENCRIPTAR", this);
        QTextEdit *textEdit = new QTextEdit(this);

        button->setStyleSheet("background-color: #4CAF50; color: white;");
        // Establecer el estilo de fuente del QLabel usando una hoja de estilo
        label1->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");
        label2->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");

        // Configurar un diseño vertical para organizar los widgets
        QVBoxLayout *layout = new QVBoxLayout(this);
        // Configurar un diseño horizontal para el botón
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addStretch(1); // Agregar un espacio flexible a la izquierda del botón
        buttonLayout->addWidget(button);


        // Agregar los widgets al diseño
        layout->addWidget(label1);
        layout->addWidget(lineEdit);
        layout->addWidget(label2);
        layout->addWidget(textEdit);
        layout->addLayout(buttonLayout);
        // Alineación del texto de los labels
        label1->setAlignment(Qt::AlignLeft);
        label2->setAlignment(Qt::AlignLeft);
        // Ajustar el tamaño mínimo del textEdit
        textEdit->setMinimumSize(200, 100);
}

ADFGVXDecryptionTab::ADFGVXDecryptionTab(QWidget *parent)
    :QWidget(parent)
{
    ;
}

