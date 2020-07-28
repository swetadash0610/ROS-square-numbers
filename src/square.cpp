#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <math.h>
ros::Publisher square_pub;
void squareCallback(const std_msgs::Int64::ConstPtr& msg)
    {    
         ros::NodeHandle n;
         int num;
         num=msg->data;
         int sq;
         sq=pow(num, 2);
         
         std_msgs::Int64 msgs;
         msgs.data=sq;
         
         square_pub =
         n.advertise<std_msgs::Int64>("square", 10);
         square_pub.publish(msgs);
    }

int main(int argc, char **argv)
{
  ros::init(argc, argv, "square");

  ros::NodeHandle n;
  ROS_INFO("Squaring!!");
  ros::Subscriber sub = n.subscribe("number", 10,squareCallback);
    
  ros::spin();
  return 0;
}
