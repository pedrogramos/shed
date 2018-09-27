#!/usr/bin/env python

rot1_1 = {'local':["Lab: Mobile Robotics"], 'pose':[0.91,10.2]}
rot1_2 = {'local':["Lab: Immersive Systems"], 'pose':[0.91,25.8]}
rot1_3 = {'local':["Lab: Computer Vision"], 'pose':[0.91,28.55]}
tour1_dic = [rot1_1,rot1_2,rot1_3]


a= len(tour1_dic)
print a

print tour1_dic[0]['local']
print tour1_dic[1]['local']
print tour1_dic[2]['local']