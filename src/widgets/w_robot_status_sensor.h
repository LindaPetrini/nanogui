#pragma once

/**
 * wRobotStatusSensor: widget to visualise the status of the status of the battery and the CPU.
 *
 * Author: Linda
 */

#include "nanogui/nanogui.h"
#include <nanogui/progressbar.h>
#include <nanogui/messagedialog.h>
#include <nanogui/textbox.h>
#include <iomanip> // setprecision
#include <sstream>

using namespace nanogui;
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

    nanogui::ref<nanogui::Window> window = robot_status_sensor_helper_->addWindow(Eigen::Vector2i(100, 100), "Robot Status");

    window->setLayout(new nanogui::GroupLayout());


    float battery_current_sensor_ = 1.0f;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << battery_current_sensor_;
    std::string battery_current_string = stream.str();
    new Label(window, "Battery Current :", "sans-bold");
    TextBox *textBox = new TextBox(window);
    textBox->setEditable(true);
    textBox->setFixedSize(Vector2i(100, 20));
    textBox->setValue(battery_current_string);
    textBox->setUnits("A");
    textBox->setFontSize(16);
    textBox->setFormat("[-]?[0-9]*\\.?[0-9]+");


    new Label(window, "Battery Charge", "sans-bold");
    float battery_charge_sensor_ = 0.7f;
    stream << std::fixed << std::setprecision(0) << battery_charge_sensor_ * 100;
    std::string battery_charge_string = stream.str();
    Widget *panel = new Widget(window);
    panel->setLayout(new BoxLayout(Orientation::Vertical,
                                   Alignment::Middle, 0, 40));

    nanogui::ProgressBar *mProgress = new nanogui::ProgressBar(window);
    mProgress->setValue(battery_charge_sensor_);
    TextBox *textBox2 = new TextBox(panel);
    textBox2->setFixedSize(Vector2i(40, 20));
    textBox2->setValue(battery_charge_string);
    textBox2->setUnits("%");

    textBox2->setFontSize(14);
    textBox2->setAlignment(TextBox::Alignment::Right);


    new Label(window, "Battery Temperature", "sans-bold");
    // Widget *panel1 = new Widget(window);
    // panel1->setLayout(new BoxLayout(Orientation::Horizontal,
    //                               Alignment::Middle, 0, 40));

    nanogui::ProgressBar *mProgress2 = new nanogui::ProgressBar(window);
    float battery_temperature_sensor_ = 0.54f;

    mProgress2->setValue(battery_temperature_sensor_);
    mProgress2->setBackgroundColor(Color(0, 255, 255, 25));

    // TextBox *textBox3 = new TextBox(panel1);
    // textBox3->setFixedSize(Vector2i(40, 20));
    // textBox3->setValue(std::to_string(battery_temperature_sensor_));
    // textBox3->setUnits("%");
    //
    // textBox3->setFontSize(14);
    // textBox3->setAlignment(TextBox::Alignment::Right);


    //robot_status_sensor_helper_->addVariable("battery temperature sensor", battery_current_sensor_ = 0.8f);

  }


  /**
   * The formhelper that holds the data of the widget.
   */
  nanogui::FormHelper *robot_status_sensor_helper_;
};
