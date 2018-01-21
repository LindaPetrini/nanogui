#pragma once

/**
 * wRobotStatusSensor: widget to visualise the status of the status of the battery and the CPU.
 *
 * Author: Linda
 */

#include "nanogui/nanogui.h"
//#include "representations/sensor/r_robot_status_sensor.h"

class wRobotStatusSensor : public nanogui::Widget {
public:
  /**
   * Initialise widget that shows the status of the status of the battery and the CPU.
   * @param screen: Nanogui screen in which the widget will be placed.
   * @param robot_status_sensor: pointer to the robot status sensor representation.
   */


  //wRobotStatusSensor(nanogui::Screen* screen, rRobotStatusSensor* robot_status_sensor) : Widget(screen) {
  wRobotStatusSensor(nanogui::Screen* screen) : Widget(screen) {
    nanogui::FormHelper *robot_status_sensor_helper_ = new nanogui::FormHelper(screen);
    //nanogui::ref<nanogui::Window> window = robot_status_sensor_helper_->addWindow(Eigen::Vector2i(100, 100), robot_status_sensor->getName());
    nanogui::ref<nanogui::Window> window = robot_status_sensor_helper_->addWindow(Eigen::Vector2i(100, 100), "robot status sensor");

    //robot_status_helper_->addGroup(robot_status_sensor->getName());

    //robot_status_sensor_helper_->addVariable("battery current sensor", robot_status_sensor->battery_current_sensor_);
    //robot_status_sensor_helper_->addVariable("battery charge sensor", robot_status_sensor->battery_charge_sensor_);
    //robot_status_sensor_helper_->addVariable("battery temperature sensor", robot_status_sensor->battery_temperature_sensor_);

    bool val1 = true;
    robot_status_sensor_helper_->addVariable("battery current sensor", val1 );
    robot_status_sensor_helper_->addVariable("battery charge sensor", val1);
    robot_status_sensor_helper_->addVariable("battery temperature sensor", val1);

  }

  /**
   * The formhelper that holds the data of the widget.
   */
  nanogui::FormHelper *robot_status_sensor_helper_;
};
