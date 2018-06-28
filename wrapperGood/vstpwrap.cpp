#include "vstpwrap.h"


extern "C"{
#include <stdio.h>
#include "vstp_int.h"

}
using namespace std;

VSTP::VSTP(){
    vstpdata=NULL;
}

VSTP::~VSTP(){
    if(vstpdata!=NULL)
	vstp_DataFree(vstpdata);
}

vstp_data * VSTP::init(double robotRadius, double gridResolution, double idealDist, double maxDist){
    //printf("init\n");
    vstpdata=vstp_DataInit(robotRadius,gridResolution,idealDist,maxDist);
    
}
    
std::vector<vstpSegment> VSTP::loadMap(char * fname){
    printf("LoadMap\n");
    numsegments=0;
    std::vector<vstpSegment> segs;
    segs.clear();
    segments = vstp_GetSegFromMapFile(fname,&numsegments);
    id = vstp_AddSegPkg(vstpdata,segments,numsegments,VSTP_SEGMENT_MAP);
    refresh = vstp_RefreshGraph(vstpdata);


    for (int i=0;i<numsegments;i++){
    	vstpSegment seg;
    	seg.x0=segments[i].x0;
    	seg.y0=segments[i].y0;
    	seg.x1=segments[i].x1;
    	seg.y1=segments[i].y1;
	printf("segments: x0= %f, y0= %f, x1= %f, y1= %f \n",segments[i].x0,segments[i].y0,segments[i].x1,segments[i].y1); 	
    	segs.push_back(seg);
    }
   
     printf(" Num %d cound=%lu\n",numsegments,segs.size());
    return segs;

}

std::vector<vstpTraj> VSTP::planTrajectory(double x0, double y0, double x1, double y1, bool improved){
    int bilan;
    vstp_node *nodeTraj;
    
    printf("plan\n");

    printf("bool %d\n",improved?1:0 );

    nodeTraj = vstp_PlanTraj(vstpdata, x0, y0, x1, y1, improved?1:0, &bilan);
    
    if (vstptraj) printf("vstptraj points to something\n");
    else printf("vstptraj does not point to anything\n");
    vstptraj = vstp_ConvertTraj(nodeTraj);
   
//criação vector dos pontos da trajectoria do tipo vstpTraj
    std::vector<vstpTraj> trajVec;

//transformacao de linked list to std::vector
    while(vstptraj!=NULL){
		vstpTraj traj;
		traj.x=vstptraj->x;
		traj.y=vstptraj->y;
        printf("X: %f Y: %f \n",traj.x,traj.y );
		trajVec.push_back(traj);
		vstptraj=vstptraj->next;

	}

return trajVec;
}
