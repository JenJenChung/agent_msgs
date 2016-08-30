#include <ros/ros.h>
#include <ros/console.h>
#include "agent_msgs/AgentMembership.h"

void membershipCallback(const agent_msgs::AgentMembership& msg)
{
  
  ROS_INFO_STREAM("Membership parent: " << msg.parent << ", child: " << msg.child ) ;
  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "membership_subscriber");
  
  ros::NodeHandle nHandsub;  
  ros::Subscriber sub = nHandsub.subscribe("/membership", 10, &membershipCallback);

  ros::spin();
  return 0;
}
