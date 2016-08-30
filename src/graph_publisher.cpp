#include <ros/ros.h>
#include "agent_msgs/UtmGraph.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "graph_publisher");

  ros::NodeHandle nHandpub;
  ros::Publisher pub = nHandpub.advertise<agent_msgs::UtmGraph>("utm_graph", 10, true);
  
  agent_msgs::UtmGraph graph ;
  
  for (size_t i = 0; i < 10; i++)
    graph.link_costs.push_back((double)i*2.0) ;
  
  pub.publish(graph) ;

  ros::spin();
  return 0;
}
