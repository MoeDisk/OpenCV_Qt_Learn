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

def findCountour(img):
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
