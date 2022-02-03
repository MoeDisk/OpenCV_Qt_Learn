import cv2

img=cv2.imread('test1.jpg')
img=cv2.resize(img,(300,300))
img=cv2.resize(img,(0,0),fx=0.5,fy=0.5)
cv2.imshow('img',img)
cv2.waitKey(0)

cap=cv2.VideoCapture('test1.mp4')
cap=cv2.VideoCapture(1)
while True:
	ret,frame=cap.read()
	if ret:
		frame=cv2.resize(frame,(0,0),fx=0.4,fy=0.4)
		cv2.imshow('video',frame)
	else:
		break
	if cv2.waitKey(1) == ord('q'):
		break
		
=====

import cv2
import numpy as np
import random

img=cv2.imread('test1.jpg')
print(img)
print(type(img))
print(img.shape)

img=np.empty((300,300,3),np.uint8)
for row in range(300):
	for col in range(300):
		img[row][col]=[random.randint(0,255),random.randint(0,255),random.randint(0,255)]
cv2.imshow('img',img)
cv2.waitKey(0)

newimg=img[:150,:200]
cv2.imshow('newimg',newimg)

=====

import cv2
import numpy as np

kernel=np.ones((3,3),np.uint8))
kernel1=np.ones((3,3),np.uint8))
img=cv2.imread('test1.jpg')
img=cv2.resize(img,(0,0),fx=0.5,fy=0.5)

gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
blur=cv2.GaussianBlur(img,(15,15),10)
canny=cv2.Canny(img,150,200)
dilate=cv2.dilate(canny,kernel,iterations=2)
erode=cv2.erode(dilate,kernel1,iterations=2)

cv2.imshow('img',img)
cv2.waitKey(0)


=====

import cv2
import numpy as np

np.zeros((600,600,3),np.uint8)
cv2.line(img,(0,0),(img.shape[1],img.shape[0]),(255,0,0),2)
cv2.rectangle(img,(0,0),(400,300),(0,0,255),cv2.FILLED)
cv2.circle(img,(300,400),30,(255,0,0),4)
cv2.putText(img,'Hello',(100,500),cv2.FONT_,1,(255,255,0),2)

cv2.imshow('img',img)
cv2.waitKey(0)

=====

import cv2

def empty(v):
	pass

cv2.namedWindow('TrackBar')
cv2.resizeWindow('TrackBar',640,320)
cv2.createTrackBar('Hue Min','TrackBar',0,179,empty)
cv2.createTrackBar('Hue Max','TrackBar',179,179,empty)
cv2.createTrackBar('Sat Min','TrackBar',0,255,empty)
cv2.createTrackBar('Sat Max','TrackBar',255,255,empty)
cv2.createTrackBar('Val Min','TrackBar',0,255,empty)
cv2.createTrackBar('Val Max','TrackBar',255,255,empty)
hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
while True:
	h_min=cv2.getTrackbarPos('Hue Min','TrackBar')
	h_max=cv2.getTrackbarPos('Hue Max','TrackBar')
	s_min=cv2.getTrackbarPos('Sat Min','TrackBar')
	s_max=cv2.getTrackbarPos('Sat Max','TrackBar')
	v_min=cv2.getTrackbarPos('Val Min','TrackBar')
	v_max=cv2.getTrackbarPos('Val Max','TrackBar')
	print(h_min,h_max,s_min,s_max,v_min,v_max)
	lower=np.array([h_min,s_min,v_min])
	upper=np.array([h_max,s_max,v_max])
	mask=cv2.inRange(hsv,lower,upper)
	cv2.bitwise_and(img,img,mask=mask)
	cv2.waitKey(1)
	cv2,inRange(hsv,lower,upper)

cv2.imshow('img',img)
cv2.imshow('hsv',hsv)
cv2.imshow('mask',mask)
cv2.waitKey(0)

=====

import cv2

img=cv2.imread('test1.jpg')
imgContour=img.copy()
img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
canny=cv2.Canny(img,150,200)
contours,hierarchy=cv2,findContours(canny,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
for cnt in contours()
	cv2.drawContours(imgContour,cnt,-1,(255,0,0),4)
    area=cv2.contourArea(cnt)
    if area > 500:
        print(cv2.contourArea(cnt))
        peri=print(cv2.arcLength(cnt,True)
        vertices=cv2.approxPloyDP(cnt,peri*0.02,True)
        corners=print(len(vertices))
        x,y,w,h=cv2.boundingRect(vertices)
        cv2.rectAngle(imgContour,(x,y),(x+w,y+h),(0,255,0),4)
        if corners==3:
            cv2.putText(imgContour,'triangle',(x,y-5),cv2.FONT_,1,(0,0,255),2)
        elif corners==4:
            cv2.putText(imgContour,'rectangle',(x,y-5),cv2.FONT_,1,(0,0,255),2)
        elif corners==5:
            cv2.putText(imgContour,'pentagon',(x,y-5),cv2.FONT_,1,(0,0,255),2)
        elif corners>=6:
            cv2.putText(imgContour,'circle',(x,y-5),cv2.FONT_,1,(0,0,255),2)
cv2.imshow('imgContour',imgContour)
cv2.imshow('canny',canny)
cv2.waitKey(0)

=====

import cv2

img=cv2.imread('test1.jpg')
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
faceCascade=cv2.CascadeClassifier('face_detect.xml')
faceRect=faceCascade.detectMultiScale(gray,1.1,3)
print(len(faceRect))
for(x,y,w,h) in faceRect
    cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)

cv2.imshow('img',img)
cv2.waitKey(0)

=====

import cv2
import numpy as np

cap=cv2.VideoCapture(1)

penColorHSV=[[[86,121,205,111,245,255]
              [46,78,172,71,255,255]
              [22,70,214,31,255,255]]

penColorBGR=[[255.0.0],[0,255,0],[0,0,255]]

drawPoints=[]

def findPen(img):
    ret,img=cap.read()
    hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    for i in range(len(penColorHSV)):
    lower=np.array([penColorHSV[i][:3])
    upper=np.array([penColorHSV[i][3:6])
    mask=cv2.inRange(hsv,lower,upper)
    result=cv2.bitwise_and(img,img,mask=mask)
    penx,peny=findCountour(mask)
    cv2.circle(imgContour,(penx,peny),10,penColorBGR[i],cv2.FILLED)
    if peny!==-1:
        drawPoints.append([penx,peny,i])
    #cv2.imshow('result',result)

def findCountour(img):
#contours,hierarchy=cv2,findContours(canny,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
x,y,w,h=-1,-1,-1,-1
for cnt in contours()
	cv2.drawContours(imgContour,cnt,-1,(255,0,0),4)
    area=cv2.contourArea(cnt)
    if area > 500:
        peri=print(cv2.arcLength(cnt,True)
        vertices=cv2.approxPloyDP(cnt,peri*0.02,True)
        x,y,w,h=cv2.boundingRect(vertices)
        return x+w//2,y

def draw(drawpoints):
    for point in drawpoints:
        cv2.circle(imgContour,(point[0],point[1]),10,penColorBGR[point[2]],cv2.FILLED)

while True:
    ret,frame=cap.read()
    if ret:
        imgContour=frame.copy()
        cv2.imshow('video',frame)
        findPen(frame)
        draw(drawPoints)
        cv2.imshow('contour',imgContour)
    else:
        break
    if cv2.waitKey(10)==ord('q'):
        break
