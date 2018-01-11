#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <ctime>

int main (int argc, char** argv)
{
srand( time( NULL ) );
pcl::PointCloud<pcl::PointXYZ> middle, output;
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  //pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2 ());
  //pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());
//pcl::PointXYZ pomocniczy;
  // Fill in the cloud data
  //pcl::PCDReader reader;

std::string cloud_name;
std::cout << "Pass the name of the cloud you'd like to cut to 2048 points" << std::endl;
std::cin >> cloud_name;
  // Replace the path below with the path where you saved your file
  //reader.read (cloud_name + ".pcd", *cloud); // Remember to download the file first!
if (pcl::io::loadPCDFile<pcl::PointXYZ> (cloud_name + ".pcd", *cloud) == -1){//* load the file
PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
return (-1);
}

  std::cerr << "PointCloud before cutting: " << cloud->width * cloud->height 
       << " data points (" << pcl::getFieldsList (*cloud) << ").";

//cutting module
int diff = cloud->width * cloud->height - 2048;
output = *cloud;

if(diff > 0){
std::cout << "Need to delete " << diff << " points" << std::endl;
output.width = 2048;
output.height = 1;
output.points.resize(output.width * output.height);
}
else if(diff < 0){
std::cout << "Need to add " << -diff << " points" << std::endl;
middle = output;
middle.width = -diff;
middle.height = 1;
middle.points.resize(middle.width * middle.height);
for(int i = 0; i < middle.width * middle.height; i++){
middle.points[i].x = middle.points[i].x + middle.points[i].x/((std::rand()%100)+100);
middle.points[i].y = middle.points[i].y + middle.points[i].y/((std::rand()%100)+100);
middle.points[i].z = middle.points[i].z + middle.points[i].z/((std::rand()%100)+100);
std::cout << middle.points[i] << " " << output.points[i] << std::endl;
};
output += middle;
};

std::cerr << "PointCloud after filtering: " << output.width * output.height << " data points " << std::endl;

pcl::io::savePCDFileASCII (cloud_name + "_2048.pcd", output);

  return (0);
}
