#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nozaki_beginner_tutorial/sin.h"
#include "cmath"

#include <sstream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<nozaki_beginner_tutorial::sin>("chatter", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    nozaki_beginner_tutorial::sin msg;

    msg.data = sin(double(3.14*count/10));

    ROS_INFO("%f", msg.data);
    
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}