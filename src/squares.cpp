#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

std_msgs::Int32 msgToPublish;
bool publishNow;

/*
void publishPresentInt32(){
  chatter_pub.publish(msgToPublish);
}
*/
void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);

  // int g = std::stoi(msg->data);

  // std::cout << msg->data;

  // msgToPublish.data = g * g;

  int g = msg->data;

  msgToPublish.data = g * g;

  publishNow = true;

  // ros::NodeHandle temp;
  // ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("topic_squares", 1000);

  // publishPresentInt32();
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "squares");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("topic_squares", 1000);
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  while (ros::ok())
  {

    // std_msgs::Int32 msg;

    // std::Int32stream ss;
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

 ros::spin();

 return 0;
}
