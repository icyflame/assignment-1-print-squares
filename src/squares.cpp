#include "ros/ros.h"

#include "std_msgs/String.h"

#include <sstream>

std_msgs::String msgToPublish;
bool publishNow;

/*
void publishPresentString(){
  chatter_pub.publish(msgToPublish);
}
*/
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());

  msgToPublish.data = msg->data.c_str();

  publishNow = true;

  // ros::NodeHandle temp;
  // ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_squares", 1000);

  // publishPresentString();
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "squares");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_squares", 1000);
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  while (ros::ok())
  {

    // std_msgs::String msg;

    // std::stringstream ss;
    // ss << "hello world " << count;
    // msg.data = ss.str();

    // ROS_INFO("%s", msg.data.c_str());

    if (publishNow)
    {
     chatter_pub.publish(msgToPublish);
     publishNow = false;
   }

   ros::spinOnce();
    // loop_rate.sleep();
    // ++count;
 }

 return 0;
}
