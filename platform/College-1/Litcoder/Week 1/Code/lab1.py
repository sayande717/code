def ratioArr(inArr,inArrSize):
    positiveRatio = 0
    negativeRatio = 0
    zeroRatio = 0
    for index in range(inArrSize):
        if(inArr[index]>0):
            positiveRatio+=1
        elif(inArr[index]<0):
            negativeRatio+=1
        else:
            zeroRatio+=1
    positiveRatio = positiveRatio / inArrSize
    negativeRatio = negativeRatio / inArrSize
    zeroRatio = zeroRatio / inArrSize
    print(round(positiveRatio,3))
    print(round(negativeRatio,3))
    print(round(zeroRatio,3),end='')

arrSize = int(input())
arr = input().split(' ')
for index in range(arrSize):
    arr[index] = int(arr[index])

ratioArr(arr,arrSize)
