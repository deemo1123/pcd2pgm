#include<ros/ros.h>
#include<pcl/point_cloud.h>
#include<pcl_conversions/pcl_conversions.h>
#include<sensor_msgs/PointCloud2.h>
#include<pcl/io/pcd_io.h>
 
void 
cloudCB(const sensor_msgs::PointCloud2 &input)
{
  pcl::PointCloud<pcl::PointXYZ> cloud;
  pcl::fromROSMsg(input, cloud);//将PointCloud2转为PointXYZ
  pcl::io::savePCDFileASCII 
("/home/****/Studybj_01/StuPCL01/src/my_pcl_tutorial/data/mytest.pcd", cloud);    //保存pcd
}
int main (int argc, char **argv)
{
  ros::init (argc, argv, "subscribe");   
  ros::NodeHandle nh;
  ros::Subscriber bat_sub = nh.subscribe("/hesai/pandar", 20, cloudCB);//接收点云
  ros::spin();
  return 0;
}