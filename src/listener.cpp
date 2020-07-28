#include "ros/ros.h"
#include "std_msgs/Int64.h"

void showCallback(const std_msgs::Int64::ConstPtr& msgs)
{ 
  ROS_INFO("The square is: %li",msgs->data );
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ROS_INFO("blah blah");
  ros::Subscriber sub = n.subscribe("square", 10, showCallback);
  if(sub){
     ROS_INFO("subscriber valid");
  }
  else{
     ROS_INFO("subscriber invalid");
     }
  
  ros::spin();

  return 0;
}
