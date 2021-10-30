import cv2
import numpy as np
im = cv2.imread("task2.jfif", 1)
np.shape(im)
y = np.shape(im)[0]//4
x = np.shape(im)[1]//4
col_dict = {"yellow":[255,255,0], "green":[0, 128, 1], "white":[255, 255, 255], "blue": [0, 0, 254], "red": [254, 0, 0], "orange":[254, 165, 0]}    #Dictionary containing name and corresponding RGB values.(Sufficient only for this picture)

def color(lst, dct):                #This function finds the name of the color closest to the RGB value obtained from the image.
    minimum = 25000
    for i in range(len(dct)):
        d = abs(lst[0]-list(dct.values())[i][0]) + abs(lst[1]- list(dct.values())[i][1])+ abs(lst[2]- list(dct.values())[i][2])
        if d<=minimum:
            minimum = d
            name = list(dct.keys())[i]
    return name

for i in range(1,4):
    for j in range(1,4):
        rgb = list(im[y*i][x*j])[::-1]
        string = color(rgb, col_dict)
        str_col = (0, 0, 255)
        l = list(str_col)[::-1]
        diff = abs(rgb[0]-l[0])+abs(rgb[1]-l[1])+abs(rgb[2]-l[2]) 
        if diff<50:
            str_col=(255,0,0)
        coord = (y*j + (j-2)*40 - 40, x*i + (i-2)*40)   #Formula to normalise the coordinates so that text is printed at the center of the colored box
        cv2.putText(im, string, coord, cv2.FONT_HERSHEY_SIMPLEX, 1, str_col , 2) #Text not visible for the center box coz its red
        j=j+1
    i=i+1

cv2.imshow("image", im)
cv2.waitKey(0)
cv2.destroyAllWindows()
