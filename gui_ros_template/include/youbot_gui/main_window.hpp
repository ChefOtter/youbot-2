/**
 * @file /include/youbot_gui/main_window.hpp
 *
 * @brief Qt based gui for youbot_gui.
 *
 * @date December 2017
 **/

#ifndef youbot_gui_MAIN_WINDOW_H
#define youbot_gui_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include <QLCDNumber>
#include "ui_main_window.h"
#include "qnode.hpp"


/*****************************************************************************
** Namespace
*****************************************************************************/

namespace youbot_gui {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/

class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
        //MainWindow();
	~MainWindow();

	void closeEvent(QCloseEvent *event);


        static double joint_1;
        static double joint_2;
        static double joint_3;
        static double joint_4;
        static double joint_5;

	void showQ1PlusMsg();
	void showQ1MinusMsg();
	void runYoubotDriver();
       // static void refresh_value(bool check); //dziala wykonywanie funkcji ale bez obiektow
      //  void refresh_value(bool check);

public Q_SLOTS:
        void on_run_driver_clicked(bool check);
        void on_connect_master_clicked(bool check);
        void on_fold_clicked(bool check);
        void on_candle_clicked(bool check);

        void on_save_clicked(bool check);
        void on_edit_list_clicked(bool check);
        void on_edit_clicked(bool check);
        void on_execute_clicked(bool check);

        void on_x_plus_clicked(bool check);
        void on_x_minus_clicked(bool check);
        void on_y_plus_clicked(bool check);
        void on_y_minus_clicked(bool check);
        void on_z_plus_clicked(bool check);
        void on_z_minus_clicked(bool check);

        void on_q1_plus_clicked(bool check);
        void on_q1_minus_clicked(bool check);
        void on_q2_plus_clicked(bool check);
        void on_q2_minus_clicked(bool check);
        void on_q3_plus_clicked(bool check);
        void on_q3_minus_clicked(bool check);
        void on_q4_plus_clicked(bool check);
        void on_q4_minus_clicked(bool check);
        void on_q5_plus_clicked(bool check);
        void on_q5_minus_clicked(bool check);




        void updateLoggingView(); // no idea why this can't connect automatically



private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace youbot_gui

#endif // youbot_gui_MAIN_WINDOW_H