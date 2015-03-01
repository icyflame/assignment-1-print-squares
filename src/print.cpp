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

  /*

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
*/
 return 0;
}
