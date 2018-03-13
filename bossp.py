#!/usr/bin/env python

'''
		# simplified style
		resp1 = add_two_ints(x, y)

		# formal style
		resp2 = add_two_ints.call(AddTwoIntsRequest(x, y))
'''
#import numpy
#import serial
import rospy
import sys
sys.path.append('/home/rmp/Downloads/vstpPy')
from RMPISR.srv import *
from geometry_msgs.msg import Point
from random import randint
#sys.path.insert(0,os.path.dirname(/home/rmp/Downloads/vstpPy/build/python))
import vstpPY



def stop_client():
	rospy.wait_for_service('stop')
	try:
		stop_ = rospy.ServiceProxy('stop', stop)
		resp1 = stop_.call()
		print "servico stop"
	except rospy.ServiceException, e:
		print "Service call failed: %s"%e


def go_client():
	rospy.wait_for_service('go')
	try:
		go_ = rospy.ServiceProxy('go', go)
		resp1 = go_.call()
		print "servico go"
	except rospy.ServiceException, e:
		print "Service call failed: %s"%e

def addpoint_client():
	rospy.wait_for_service('addpoint')
	try:
		addpoint_ = rospy.ServiceProxy('addpoint', addpoint)

		pointArray=list()
		

		for elem in range(10):
			toappend = Point()
			toappend.x=randint(0, 9)
			toappend.y=randint(0, 9)
			toappend.z=randint(0, 9)
			pointArray.append(toappend)
			print "new point:" , pointArray


		#print pointArray
		size=9

		resp1 = addpoint_.call(pointArray, True, size)
		print "servico addpoint"
	except rospy.ServiceException, e:
		print "Service call failed: %s"%e




if __name__ == "__main__":
	rospy.init_node("boss_node",anonymous=True)
	print "entrou"
	'''
	stop_client()
	rospy.sleep(2.)
	addpoint_client()	
	rospy.sleep(2.)	
	go_client()
	'''
	#vstpPY.
	#vstpPY = vstpPY.vstp_DataInit(0.74,0.6,0.2,0.1)





	rospy.spin()
