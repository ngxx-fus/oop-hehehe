#ifndef MY_CUSTOMER_H
#define MY_CUSTOMER_H

#include "_added_customer_error.h"
#include "_adding_error.h"
#include "_customers.h"
#include <QMainWindow>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class my_customer; }
QT_END_NAMESPACE

class my_customer : public QMainWindow
{
    Q_OBJECT
    QVector<_customers> qv_cus;

public:
    my_customer(QWidget *parent = nullptr);

    inline QString add_UKNOWN(QString inp){
        if( inp.size() == 0) inp = "unknown";
        return inp;
    }

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
    void refresh_list_view();

    void clear_all_text_in_add_box();
    void clear_all_text_in_find_box();

    //remove a customer by phone number
    void remove_by_phoneNumber(QString cus_phoneNumber);
    //add a customer
    void add_customer(QString cus_name, QString cus_DOB, QString cus_phoneNumber, int cus_point);
    void expand_list_of_customers();
    void shorten_list_of_customers();
    void sort_by_id();
    void sort_by_name();
    void sort_by_accumulation_point();

    ~my_customer();

private slots:
    void on_pushButtonExportFile_clicked();

    void on_pushButtonADD_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButtonDelete_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::my_customer *ui;

};
#endif // MY_CUSTOMER_H