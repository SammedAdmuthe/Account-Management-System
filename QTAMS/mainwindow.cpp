#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "FinalProject_gui_Sammed/StockAccount.h"
#include "FinalProject_gui_Sammed/BankAccount.h"
#include <Qfile>
#include <QDir>
#include <iostream>


StockAccount stockAccount(10000);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    // stockAccount.displayCurrentPortfolio();

    // double priceOfStock = stockAccount.displayPriceOfStock("GOOG");
    // ui->getBalance->setText(QString::number(priceOfStock));

    BankAccount bankAccount(10000);
    // bankAccount.viewBankTransactionHistory();
    // QFile file("stock_transaction_history.txt");
    // file.open(QFile::ReadOnly | QFile::Text);
    // ui->transaction_history_edit->appendPlainText(file.readAll());

}


void MainWindow::on_sym_textChanged()
{
        QString sym = ui->sym->toPlainText();
        double value = StockAccount::displayPriceOfStock(sym.toStdString());
        ui->sym_price->setPlainText(QString::number(value));
}


void MainWindow::on_sym_copyAvailable(bool b)
{

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->transaction_history->clear();
    QString currentPath = QDir::currentPath();
    qDebug() << "Current Working Directory:" << currentPath;
    QFile file("../../../../QTAMS/FinalProject_gui_Sammed/stock_transaction_history.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ReadFile(&file);
    // cout<<"HERE"<<endl;
    while (!ReadFile.atEnd()) {
        QString line = ReadFile.readLine();
        ui->transaction_history->appendPlainText(line);
    }
    file.close();
}


void MainWindow::on_pushButton_4_clicked()
{
    double buy_amount = ui->buy_amount->toPlainText().toDouble();
    int buy_share = ui->buy_shares->toPlainText().toInt();
    std::string buy_symbol = ui->buy_symbol->toPlainText().toStdString();
    stockAccount.buyShares(buy_symbol, buy_share, buy_amount);
    on_pushButton_3_clicked();
    on_pushButton_6_clicked();
    on_pushButton_7_clicked();
}

//Sell
void MainWindow::on_pushButton_5_clicked()
{
    double sell_amount = ui->sell_amount->toPlainText().toDouble();
    int sell_share = ui->sell_shares->toPlainText().toInt();
    std::string sell_symbol = ui->sell_symbol->toPlainText().toStdString();
    stockAccount.sellShares(sell_symbol, sell_share, sell_amount);
    on_pushButton_3_clicked();
    on_pushButton_6_clicked();
    on_pushButton_7_clicked();
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->portfolio->clear();
    QFile file("../../../../QTAMS/FinalProject_gui_Sammed/Stock_Portfolio_Info.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ReadFile(&file);
    // cout<<"HERE"<<endl;
    while (!ReadFile.atEnd()) {
        QString line = ReadFile.readLine();
        ui->portfolio->appendPlainText(line);
    }
    file.close();
}


void MainWindow::on_pushButton_7_clicked()
{
    double cash_balance = stockAccount.getBalance();
    QString qBalance = QString::number(cash_balance);
    ui->cash_balance->setText(qBalance);
}

