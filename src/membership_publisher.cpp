#include <ros/ros.h>
#include "agent_msgs/AgentMembership.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "membership_publisher");

  ros::NodeHandle nHandpub;
  ros::Publisher pub = nHandpub.advertise<agent_msgs::AgentMembership>("membership", 10, true);
  
  agent_msgs::AgentMembership msg ;
  msg.parent = 0 ;
  msg.child = 1 ;
  
  pub.publish(msg) ;

  ros::spin();
  return 0;
}
