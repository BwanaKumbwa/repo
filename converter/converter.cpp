#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

int main (int argc, char** argv){
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

pcl::PCDReader reader;

std::string cloud_name;
std::cout << "Pass the name of the cloud you'd like to convert" << std::endl;
std::cin >> cloud_name;

reader.read (cloud_name + ".pcd", *cloud);

pcl::PLYWriter writer;

writer.write (cloud_name + "_converted.pcl", *cloud);

return (0);
}
