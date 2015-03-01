#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

void chatterCallbackNumbers(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("Numbers: [%d]", msg->data);
}

void chatterCallbackSquares(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("Squares: [%d]", msg->data);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "print");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallbackNumbers);
  ros::Subscriber sub1 = n.subscribe("topic_squares", 1000, chatterCallbackSquares);

  ros::spin();

  return 0;
}
