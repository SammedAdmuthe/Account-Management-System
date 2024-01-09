/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPlainTextEdit *transaction_history;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *sym;
    QTextEdit *sym_price;
    QTextEdit *buy_symbol;
    QTextEdit *buy_shares;
    QTextEdit *buy_amount;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QPushButton *pushButton_5;
    QLabel *label_9;
    QTextEdit *sell_symbol;
    QTextEdit *sell_amount;
    QLabel *label_10;
    QTextEdit *sell_shares;
    QLabel *label_4;
    QPlainTextEdit *portfolio;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QTextEdit *cash_balance;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 602);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 0, 100, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 0, 100, 32));
        transaction_history = new QPlainTextEdit(centralwidget);
        transaction_history->setObjectName("transaction_history");
        transaction_history->setGeometry(QRect(20, 150, 321, 231));
        transaction_history->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 130, 111, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 40, 91, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 90, 58, 16));
        sym = new QTextEdit(centralwidget);
        sym->setObjectName("sym");
        sym->setGeometry(QRect(270, 40, 104, 31));
        sym_price = new QTextEdit(centralwidget);
        sym_price->setObjectName("sym_price");
        sym_price->setGeometry(QRect(270, 80, 104, 31));
        sym_price->setReadOnly(true);
        buy_symbol = new QTextEdit(centralwidget);
        buy_symbol->setObjectName("buy_symbol");
        buy_symbol->setGeometry(QRect(130, 420, 104, 31));
        buy_shares = new QTextEdit(centralwidget);
        buy_shares->setObjectName("buy_shares");
        buy_shares->setGeometry(QRect(270, 420, 104, 31));
        buy_amount = new QTextEdit(centralwidget);
        buy_amount->setObjectName("buy_amount");
        buy_amount->setGeometry(QRect(410, 420, 104, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 400, 58, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(280, 400, 81, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(410, 400, 111, 16));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 120, 100, 32));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(540, 420, 100, 32));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(140, 460, 58, 16));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(540, 480, 100, 32));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(410, 460, 111, 16));
        sell_symbol = new QTextEdit(centralwidget);
        sell_symbol->setObjectName("sell_symbol");
        sell_symbol->setGeometry(QRect(130, 480, 104, 31));
        sell_amount = new QTextEdit(centralwidget);
        sell_amount->setObjectName("sell_amount");
        sell_amount->setGeometry(QRect(410, 480, 104, 31));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(280, 460, 81, 16));
        sell_shares = new QTextEdit(centralwidget);
        sell_shares->setObjectName("sell_shares");
        sell_shares->setGeometry(QRect(270, 480, 104, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 130, 111, 16));
        portfolio = new QPlainTextEdit(centralwidget);
        portfolio->setObjectName("portfolio");
        portfolio->setGeometry(QRect(460, 150, 321, 231));
        portfolio->setReadOnly(true);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(630, 120, 100, 32));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(460, 40, 100, 32));
        cash_balance = new QTextEdit(centralwidget);
        cash_balance->setObjectName("cash_balance");
        cash_balance->setGeometry(QRect(570, 40, 104, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Bank Account", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Stock Account", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Transaction Logs", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter Symbol", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "No of shares", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Maximum Amount", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "BUY", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "SELL", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "SELL", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Minimum Amount", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "SELL", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Portfolio", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Cash Balance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
