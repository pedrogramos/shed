extern "C"{
#include "libvstp.h"
}

#include <vector>
#include <cstddef>


class vstpSegment {
public:
   double x0, y0;
   double x1, y1;
};

class vstpTraj {
public:
   double x, y;
};

class VSTP{

    vstp_data * vstpdata; //return from vstp_DataInit()
    double robotRadius, gridResolution, idealDist, maxDist; // entries for previous function call
    vstp_segment * segments; // return from vstp_GetSegFromMapFile
    int numsegments; // retunr the n of segments loaded from the map file -> from vstp_GetSegFromMapFile
    int id; // return from vstp_AddSegPkg call
    int refresh; // return from vstp_RefreshGraph call
    vstp_traj * vstptraj ; // return pointer to trajectory linked list

    

public:
    VSTP();
    ~VSTP();
    
    vstp_data * init(double robotRadius, double gridResolution, double idealDist, double maxDist); 

    //void loadMap(char * fname, int * numsegments);    
    std::vector<vstpSegment>  loadMap(char * fname);

    std::vector<vstpTraj> planTrajectory(double x0, double y0, double x1, double y1, bool improved=true);
};
