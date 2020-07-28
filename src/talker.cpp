#include "ros/ros.h"
#include <std_msgs/Int64.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher number_pub = n.advertise<std_msgs::Int64>("number", 10);

  ros::Rate loop_rate(2);

  int count = 0;
  while (ros::ok())
  {
    
    std_msgs::Int64 msg;
    
    msg.data = count;

    ROS_INFO("Number: %li", msg.data);

    number_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
