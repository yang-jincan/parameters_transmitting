#include<ros/ros.h>
#include<string>
#include <fstream>
#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>
#include<iostream> 
#include "parameters_trans/global_defination/global_defination.h"


using std::string;


int main (int argc,char **argv)
{
    ros::init(argc,argv,"test");
    ros::NodeHandle nh;
    std::cout<<"WORK_SPACE_PATH    "<<   WORK_SPACE_PATH<<std::endl;
    std::string config_file_path = WORK_SPACE_PATH + "/config/parameters.yaml";
    YAML::Node config_node = YAML::LoadFile(config_file_path);
    float key_frame_distance_ = config_node["key_frame_distance"].as<float>();
    float key_frame_distance1_ = config_node["key_frame_distance1"].as<float>();
    std::cout<<"distance    "<<   key_frame_distance_<<std::endl;
    std::cout<<"distance1    "<<   key_frame_distance1_<<std::endl;
    ros::spin();
    return 0;


}