#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main ()
{

pcl::PointCloud<pcl::PointXYZ> cloud_a, cloud_b, output;
  
pcl::PointCloud<pcl::PointXYZ>::Ptr input (new pcl::PointCloud<pcl::PointXYZ>);
if (pcl::io::loadPCDFile<pcl::PointXYZ> ("chair_3a.pcd", *input) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }

std::cout << "Loaded "
            << input->width * input->height
            << " data points from chair_3a.pcd"
            << std::endl;

cloud_a = *input;


if (pcl::io::loadPCDFile<pcl::PointXYZ> ("chair_3b.pcd", *input) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }
std::cout << "Loaded "
            << input->width * input->height
            << " data points from chair_3a.pcd"
            << std::endl;

cloud_b = *input;

output = cloud_a + cloud_b;

std::cout << "Concatenation has "
            << output.width * output.height
            << " data points and will be saved as wynik_3.pcd"
	    << std::endl;

pcl::io::savePCDFileASCII ("wynik.pcd", output);

  return (0);
}

