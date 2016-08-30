#include <ros/ros.h>
#include <ros/console.h>
#include <iostream>
#include "agent_msgs/UtmGraph.h"

void graphCallback(const agent_msgs::UtmGraph& msg)
{
  
  ROS_INFO_STREAM("Graph received:" ) ;
  std::cout << "Actual traversal costs: " ;
  for (size_t i = 0; i < msg.actual_traversal_costs.size(); i++)
    std::cout << msg.actual_traversal_costs[i] << " " ;
  std::cout << std::endl << "Policy output costs: " ;
  for (size_t i = 0; i < msg.policy_output_costs.size(); i++)
    std::cout << msg.policy_output_costs[i] << " " ;
  std::cout << std::endl ;
  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "graph_subscriber");
  
  ros::NodeHandle nHandsub;  
  ros::Subscriber sub = nHandsub.subscribe("/utm_graph", 10, &graphCallback);

  ros::spin();
  return 0;
}
