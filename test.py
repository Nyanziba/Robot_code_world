import math
linex = [math.cos(1.18), math.cos(2.75), math.cos(-1.96), math.cos(-0.39)]
liney = [math.sin(1.18), math.sin(2.75), math.sin(-1.96), math.sin(-0.39)]
sensorVal = [0,0,0,20]
lineOutVal = [10,10,10,10]
kaihix = 0.0
kaihiy = 0.0
for t in range(4):
    if sensorVal[t] > lineOutVal[t]:
        kaihix += linex[t]
        kaihiy += liney[t]
print(math.atan2(kaihiy,kaihix)*(180/math.pi))
