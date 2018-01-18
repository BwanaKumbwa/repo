#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main (){

pcl::PointCloud<pcl::PointXYZ> cloud_a, cloud_b, output;

std::string cloud_name;
std::cout << "Pass the name of the cloud you'd like to concatenate (assumption: there are two clouds to concatenate - namea and nameb)" << std::endl;
std::cin >> cloud_name;

pcl::PointCloud<pcl::PointXYZ>::Ptr input (new pcl::PointCloud<pcl::PointXYZ>);
if (pcl::io::loadPCDFile<pcl::PointXYZ> (cloud_name + "a.pcd", *input) == -1) //* load the file
{
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
}

std::cout << "Loaded " << input->width * input->height << " data points from " << cloud_name << "a.pcd" << std::endl;

cloud_a = *input;

if (pcl::io::loadPCDFile<pcl::PointXYZ> (cloud_name + "b.pcd", *input) == -1)
{
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
}

std::cout << "Loaded " << input->width * input->height << " data points from" << cloud_name << "b.pcd" << std::endl;

cloud_b = *input;

output = cloud_a + cloud_b;

std::cout << "Concatenation has " << output.width * output.height << " data points and will be saved as " << cloud_name <<".pcd" << std::endl;

pcl::io::savePCDFileASCII (cloud_name + ".pcd", output);

return (0);
}

