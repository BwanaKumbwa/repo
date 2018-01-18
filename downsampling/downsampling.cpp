#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

int main (int argc, char** argv){
pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2 ());
pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

pcl::PCDReader reader;

std::string cloud_name;
std::cout << "Pass the name of the cloud you'd like to downsample" << std::endl;
std::cin >> cloud_name;
reader.read (cloud_name + ".pcd", *cloud); 
std::cerr << "Points before downsampling: " << cloud->width * cloud->height << std::endl;

//downsampling using voxel grid
float leaf_size;
std::cout << "Pass the size of the leaf you'd like to use" << std::endl;
std::cin >> leaf_size;
pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
sor.setInputCloud (cloud);
sor.setLeafSize (leaf_size, leaf_size, leaf_size);
sor.filter (*cloud_filtered);

std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height << std::endl;

pcl::PCDWriter writer;
writer.write (cloud_name + "_down.pcd", *cloud_filtered, Eigen::Vector4f::Zero (), Eigen::Quaternionf::Identity (), false);

return (0);
}
