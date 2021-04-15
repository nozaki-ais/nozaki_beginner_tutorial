#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nozaki_beginner_tutorial/talker2.h"
#include "cmath"

#include <sstream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<nozaki_beginner_tutorial::talker2>("chatter", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    nozaki_beginner_tutorial::talker2 msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    msg.sin = sin(3.14*count/10);
    msg.cos = cos(3.14*count/10);

    ROS_INFO("%s, sin = %f, cos = %f", msg.data.c_str(),msg.sin,msg.cos);
    
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}