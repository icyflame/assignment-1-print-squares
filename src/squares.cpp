#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

std_msgs::Int32 msgToPublish;
bool publishNow;

void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);

  int g = msg->data;

  msgToPublish.data = g * g;

  publishNow = true;

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "squares");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("topic_squares", 1000);
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  while (ros::ok())
  {

    if (publishNow)
    {
     chatter_pub.publish(msgToPublish);
     publishNow = false;
   }

 }

 ros::spin();

 return 0;
}
