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
ADFGVXEncryptionTab::ADFGVXEncryptionTab(QWidget *parent)
    :QWidget(parent)
{
    adfgvx = ADFGVX(matrixContent);
    // Crear widgets
    QLabel *labelClave = new QLabel("CLAVE:", this);
    lineClave = new QLineEdit(this);
    labelFormateado = new QLabel("CLAVE FORMATEADA", this);
    lineFormateado = new QLineEdit("",this);

    QLabel *labelTextPlain = new QLabel("TEXTO PLANO:", this);
    textEditTextPlain = new QTextEdit(this);

    labelTextPlainLimpio = new QLabel("TEXTO PLANO FORMATEADO");
    textEditTextPlainLimpio = new QTextEdit(this);

    QLabel *labelMensajeEncriptado = new QLabel("TEXTO PLANO ENCRIPTADO", this);
    textEditTextPlainEncriptado = new QTextEdit(this);

    //AGREGADO DE CARACTERISTICA
    // Crear el QLabel formateado y ocultarlo inicialmente
    labelFormateado->hide();
    lineFormateado->hide();
    labelTextPlainLimpio->hide();
    textEditTextPlainLimpio->hide();

    buttonEncriptar->setEnabled(false);
    buttonEncriptar->setStyleSheet("background-color: red; color: white;");

    lineFormateado->setEnabled(false);
    textEditTextPlainLimpio->setEnabled(false); // to enable textEditTextPlainLimpio


    //buttonEncriptar->setStyleSheet("background-color: #4CAF50; color: white;");
    // Establecer el estilo de fuente del QLabel usando una hoja de estilo
    labelClave->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");
    labelTextPlain->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");
    labelFormateado->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");
    labelTextPlainLimpio->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");
    lineFormateado->setStyleSheet("color: rgba(0, 0, 0, 1);"); // Cambiar el color del texto
    textEditTextPlainLimpio->setStyleSheet("color: rgba(0, 0, 0, 1);"); // Cambiar el color del texto
    labelMensajeEncriptado->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");

    // Alineación del texto de los labels
    labelClave->setAlignment(Qt::AlignLeft);
    labelTextPlain->setAlignment(Qt::AlignLeft);
    labelFormateado->setAlignment(Qt::AlignLeft);
    labelMensajeEncriptado->setAlignment(Qt::AlignLeft);
    labelTextPlainLimpio->setAlignment(Qt::AlignLeft);

    lineClave->setStyleSheet("margin-bottom: 10px;"); // Agregar un margen a la derecha de lineClave
    textEditTextPlain->setStyleSheet("margin-bottom: 10px;"); // Agregar un margen a la derecha de lineClave

    // Configurar un diseño vertical para organizar los widgets
    QVBoxLayout *layout = new QVBoxLayout(this);
    // Configurar un diseño horizontal para el botón
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1); // Agregar un espacio flexible a la izquierda del botón
    buttonLayout->addWidget(buttonEncriptar);


    // Conectar la señal de edición de lineClave a una ranura personalizada
    connect(lineClave, &QLineEdit::textChanged, this, &ADFGVXEncryptionTab::onLineClaveTextChanged);
    connect(textEditTextPlain, &QTextEdit::textChanged, this, &ADFGVXEncryptionTab::onTextEditTextPlainTextChanged);
    connect(buttonEncriptar, &QPushButton::clicked, this, &ADFGVXEncryptionTab::onButtonEncriptarPressed);


    // Agregar los widgets al diseño
    layout->addWidget(labelClave);
    layout->addWidget(lineClave);
    layout->addWidget(labelFormateado);
    layout->addWidget(lineFormateado);

    layout->addWidget(labelTextPlain);
    layout->addWidget(textEditTextPlain);

    layout->addWidget(labelTextPlainLimpio);
    layout->addWidget(textEditTextPlainLimpio);

    layout->addWidget(labelMensajeEncriptado);
    layout->addWidget(textEditTextPlainEncriptado);

    layout->addLayout(buttonLayout);
}

ADFGVXDecryptionTab::ADFGVXDecryptionTab(QWidget *parent)
    :QWidget(parent)
{
    adfgvx = ADFGVX(matrixContent);
    //Crear Widgets
    labelClave = new QLabel("CLAVE:",this);
    lineEditClave = new QLineEdit(this);

    labelMensajeEncriptado = new QLabel("MENSAJE ENCRIPTADO:",this);
    textEditMensajeEncriptado = new QTextEdit(this);

    labelTextoPlano = new QLabel("TEXTO PLANO:",this);
    textEditTextoPlano = new QTextEdit(this);

    //AGREGADO DE CARACTERISTICAS
    buttonDesencriptar->setEnabled(false);
    buttonDesencriptar->setStyleSheet("background-color: red; color: white;");
    labelClave->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");
    labelMensajeEncriptado->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");
    labelTextoPlano->setStyleSheet("color: rgba(0, 0, 0, 0.75); font-weight: bold; font-style: italic;");

    // Alineación del texto de los labels
    labelClave->setAlignment(Qt::AlignLeft);
    labelMensajeEncriptado->setAlignment(Qt::AlignLeft);
    labelTextoPlano->setAlignment(Qt::AlignLeft);

    // Configurar un diseño vertical para organizar los widgets
    QVBoxLayout *layout = new QVBoxLayout(this);
    // Configurar un diseño horizontal para el botón
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1); // Agregar un espacio flexible a la izquierda del botón
    buttonLayout->addWidget(buttonDesencriptar);

    //RANURAS
    //connect(lineEditClave, &QLineEdit::textChanged, this,&ADFGVXDecryptionTab::onLineEditClaveChanged);

    // Agregar los widgets al diseño
    layout->addWidget(labelClave);
    layout->addWidget(lineEditClave);

    layout->addWidget(labelMensajeEncriptado);
    layout->addWidget(textEditMensajeEncriptado);
    layout->addLayout(buttonLayout);
    layout->addWidget(labelTextoPlano);
    layout->addWidget(textEditTextoPlano);

}

