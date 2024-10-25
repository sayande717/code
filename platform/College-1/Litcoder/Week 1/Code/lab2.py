def calculateTime(hours,devices):
    timeDuration = 4
    if(hours < timeDuration):
        print("Invalid Input",end='')
        return
    noOfDevices = int(hours / timeDuration)
    if(noOfDevices>devices):
        noOfDevices=devices
    remainingDevices = (devices - noOfDevices)

    print(noOfDevices)
    print(remainingDevices,end='')

a = int(input())
b = int(input())
calculateTime(a,b)
