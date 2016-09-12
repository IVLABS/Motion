//date:12/9/16
//written by-sakshi
//receives data from csv file and published on a node with custom msg int64[10]
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <readCSV.cpp>
#include "swayat/angles10.h"

int main(int argc, char **argv)
{
   readCSV file;//object of class readCSV
   vect2d data;//2d vector,int
   int row=10;//row that we want to read from csv file
   int col=10;//col that we want to read from csv file
   data=file.storeCSV2array("/home/sakshi/.ros/try1.csv",row,col);//by default,the path is taken from .ros
  

//initialising node

   ros::init(argc, argv, "angle_parser");//node name=angle_parser
   ros::NodeHandle n;
   ros::Publisher ang_pub = n.advertise<swayat::angles10>("angle_to_motor", 10);//topic name=angle_to_motor
   


   swayat::angles10 arr;
   int no_of_cycles=9;
   int k=0;
   while (ros::ok())
   {
   if (k<no_of_cycles)
     {
      for(int i=0;i<row;i++)
        { 
          ros::Rate loop_rate(100);
          ROS_INFO("row=%d",i);
          for(int j=0;j<col;j++)
             {
               angles10.angle2motor[j]=data[i][j];//putting values from data to arr row by row
             }
          ang_pub.publish(arr);//publishing to topic angle_to_motor
          ROS_INFO("published");
          
          loop_rate.sleep();
        }
     //ros::spinOnce();
     k++;   
     }    
   }
return 0;
}