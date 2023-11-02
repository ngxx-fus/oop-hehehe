#ifndef MY_CUSTOMER_H
#define MY_CUSTOMER_H

#include <QListWidgetItem>
#include <QtGui>
//#include <QtWidgets>
#include <QTableWidget>
#include <QMainWindow>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <QMainWindow>
#include <algorithm>
#include <QMenuBar>

#include "_customers.h"
#include "_time.h"

QT_BEGIN_NAMESPACE
namespace Ui { class my_customer; }
QT_END_NAMESPACE

class my_customer : public QMainWindow
{
    Q_OBJECT
    QVector<_customers> qv_cus;
    QVector< QVector<_customers>::iterator > qv_search_result;
    bool auto_save;//

public:
    my_customer(QWidget *parent = nullptr);

    //if *inp* is empty, inp = "unknown" (for DOB)
    inline QString add_UKNOWN(QString inp){return (inp.size()==0 ? "unknown" : inp);}
    //return a QVector<_customers>::iterator to element that PhoneNumber = key_PhoneNumber
    QVector<_customers>::iterator find_by_PhoneNumber(QString key_PhoneNumber);
    //return a QVector<_customers>::iterator to element that ID = key_ID
    QVector<_customers>::iterator find_by_ID(QString key_ID);
    //return a vector of QVector<_customers>::iterator consist of all elements that have name = key_Name
    QVector< QVector<_customers>::iterator > find_by_name(QString key_Name);
    //set up layout of list of customers
    void set_layout_list_view(int const max_row, int const max_column);
    //refresh list of customers
    void refresh_customers_list();
    void refresh_search_result_list();

    void clear_all_text_in_add_box();
    void clear_all_text_in_find_box();

    //remove a customer by phone number
    void remove_by_phoneNumber(QString cus_phoneNumber);

    //add a customer
    void add_customer(QString cus_name, QString cus_DOB, QString cus_phoneNumber, int cus_point);
    //view
    void expand_list_of_customers();
    void shorten_list_of_customers();
    //sort
    //mode  = 0 for acsending else descending
    void sort_by_id( bool _mode = 0 );
    //mode  = 0 for acsending else descending
    void sort_by_name( bool _mode = 0 );
    //mode  = 0 for acsending else descending
    void sort_by_accumulation_point( bool _mode = 0 );

    void save_customers();
    void load_customers();

    ~my_customer();

private slots:
//    void on_pushButtonExportFile_clicked();

    void on_pushButtonADD_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButtonCancel_clicked();

    void on_pushButton_CLOSE_SEARCH_RES_clicked();

    void on_pushButton_FIND_clicked();

    void on_pushButton_RM_MOD_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButtonUpdateInfo_clicked();

    void on_actionFactory_reset_triggered();

    void on_actionExport_season_triggered();

private:
    Ui::my_customer *ui;

};
#endif // MY_CUSTOMER_H
