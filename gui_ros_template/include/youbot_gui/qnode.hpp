/**
 * @file /include/youbot_gui/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date December 2017
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef youbot_gui_QNODE_HPP_
#define youbot_gui_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/


#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>


#include <QtWidgets/QMainWindow>
#include <QLCDNumber>
#include "ui_main_window.h"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace youbot_gui {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:

        static double x;
        static double y;
        static double z;
        static double roll;
        static double pitch;
        static double yaw;

        static double subscriber_joint1;
        static double subscriber_joint2;
        static double subscriber_joint3;
        static double subscriber_joint4;
        static double subscriber_joint5;

        Ui::MainWindowDesign ui;


	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
        void run();
	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
	void loggingUpdated();
    	void rosShutdown();

private:
	int init_argc;
	char** init_argv;
        //ros::Publisher chatter_publisher;
        ros::Publisher armPositionsPublisher;
        ros::Publisher gripperPositionPublisher;

        ros::Subscriber armPositionsSubscriber;

    	QStringListModel logging_model;
        //MainWindow obiekt;
};

}  // namespace youbot_gui

#endif /* youbot_gui_QNODE_HPP_ */