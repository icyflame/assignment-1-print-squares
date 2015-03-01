#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "numbers");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("topic_numbers", 1000);

  ros::Rate loop_rate(10);

  int count = 0;

  std_msgs::Int32 msg;

  while (ros::ok())
  {

    msg.data = count;

    ROS_INFO("%d", msg.data);

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    ++count;
  }

  return 0;
}